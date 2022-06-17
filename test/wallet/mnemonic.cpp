/**
 * Copyright (c) 2011-2017 libbitcoin developers (see AUTHORS)
 *
 * This file is part of libbitcoin.
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Affero General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Affero General Public License for more details.
 *
 * You should have received a copy of the GNU Affero General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#include "mnemonic.hpp"

#include <boost/test/unit_test.hpp>
#include <algorithm>
#include <bitcoin/system.hpp>

using namespace bc;
using namespace bc::wallet;

bool intersects(dictionary alpha, dictionary beta)
{
    return std::any_of(alpha.begin(), alpha.end(),
        [&](const char* test_right)
        {
#if defined _MSC_VER && (!defined NDEBUG)
            // MSVC build error mitigation.
            return std::find_if(beta.begin(), beta.end(),
            [&](const char test_left[])
            {
                return (std::strcmp(test_left, test_right) == 0);
            }) != std::end(beta);
#else
            return std::find(beta.begin(), beta.end(),
                test_right) != std::end(beta);
#endif
        });
}

dictionary::size_type intersection_count(dictionary alpha, dictionary beta)
{
    return std::count_if(alpha.begin(), alpha.end(),
        [&](const char* test_right)
        {
#if defined _MSC_VER && (!defined NDEBUG)
            // MSVC build error mitigation.
            return std::find_if(beta.begin(), beta.end(),
                [&](const char test_left[])
                {
                    return (std::strcmp(test_left, test_right) == 0);
                }) != std::end(beta);
#else
            return std::find(beta.begin(), beta.end(),
                    test_right) != std::end(beta);
#endif

        });
}

BOOST_AUTO_TEST_SUITE(mnemonic_tests)

BOOST_AUTO_TEST_CASE(mnemonic__decode_mnemonic__no_passphrase)
{
    for (const auto& vector: mnemonic_no_passphrase)
    {
        const auto words = split(vector.mnemonic, ",");
        BOOST_REQUIRE(validate_mnemonic(words, vector.language));
        const auto seed = decode_mnemonic(words);
        BOOST_REQUIRE_EQUAL(encode_base16(seed), vector.seed);
    }
}

#ifdef WITH_ICU

BOOST_AUTO_TEST_CASE(mnemonic__decode_mnemonic__trezor)
{
    for (const auto& vector: mnemonic_trezor_vectors)
    {
        const auto words = split(vector.mnemonic, ",");
        BOOST_REQUIRE(validate_mnemonic(words));
        const auto seed = decode_mnemonic(words, vector.passphrase);
        BOOST_REQUIRE_EQUAL(encode_base16(seed), vector.seed);
    }
}

BOOST_AUTO_TEST_CASE(mnemonic__decode_mnemonic__bx)
{
    for (const auto& vector: mnemonic_bx_to_seed_vectors)
    {
        const auto words = split(vector.mnemonic, ",");
        BOOST_REQUIRE(validate_mnemonic(words, vector.language));
        const auto seed = decode_mnemonic(words, vector.passphrase);
        BOOST_REQUIRE_EQUAL(encode_base16(seed), vector.seed);
    }
}

#endif

BOOST_AUTO_TEST_CASE(mnemonic__create_mnemonic__trezor)
{
    for (const mnemonic_result& vector: mnemonic_trezor_vectors)
    {
        data_chunk entropy;
        decode_base16(entropy, vector.entropy);
        const auto mnemonic = create_mnemonic(entropy, vector.language);
        BOOST_REQUIRE(mnemonic.size() > 0);
        BOOST_REQUIRE_EQUAL(join(mnemonic, ","), vector.mnemonic);
        BOOST_REQUIRE(validate_mnemonic(mnemonic));
    }
}

BOOST_AUTO_TEST_CASE(mnemonic__create_mnemonic__bx)
{
    for (const mnemonic_result& vector: mnemonic_bx_new_vectors)
    {
        data_chunk entropy;
        decode_base16(entropy, vector.entropy);
        const auto mnemonic = create_mnemonic(entropy, vector.language);
        BOOST_REQUIRE(mnemonic.size() > 0);
        BOOST_REQUIRE_EQUAL(join(mnemonic, ","), vector.mnemonic);
        BOOST_REQUIRE(validate_mnemonic(mnemonic, vector.language));
    }
}

BOOST_AUTO_TEST_CASE(mnemonic__validate_mnemonic__invalid)
{
    for (const auto& mnemonic: invalid_mnemonic_tests)
    {
        const auto words = split(mnemonic, ",");
        BOOST_REQUIRE(!validate_mnemonic(words));
    }
}

BOOST_AUTO_TEST_CASE(mnemonic__create_mnemonic__tiny)
{
    const data_chunk entropy(4, 0xa9);
    const auto mnemonic = create_mnemonic(entropy);
    BOOST_REQUIRE_EQUAL(mnemonic.size(), 3u);
    BOOST_REQUIRE(validate_mnemonic(mnemonic));
}

BOOST_AUTO_TEST_CASE(mnemonic__create_mnemonic__giant)
{
    const data_chunk entropy(1024, 0xa9);
    const auto mnemonic = create_mnemonic(entropy);
    BOOST_REQUIRE_EQUAL(mnemonic.size(), 768u);
    BOOST_REQUIRE(validate_mnemonic(mnemonic));
}

BOOST_AUTO_TEST_CASE(mnemonic__dictionary__en_es__no_intersection)
{
    const auto intersection = intersects(language::en, language::es);
    BOOST_REQUIRE(!intersection);
}

BOOST_AUTO_TEST_CASE(mnemonic__dictionary__it_en__no_intersection)
{
    const auto intersection = intersects(language::it, language::en);
    BOOST_REQUIRE(!intersection);
}

BOOST_AUTO_TEST_CASE(mnemonic__dictionary__fr_es__no_intersection)
{
    const auto intersection = intersects(language::fr, language::es);
    BOOST_REQUIRE(!intersection);
}

BOOST_AUTO_TEST_CASE(mnemonic__dictionary__it_es__no_intersection)
{
    const auto intersection = intersects(language::it, language::es);
    BOOST_REQUIRE(!intersection);
}

BOOST_AUTO_TEST_CASE(mnemonic__dictionary__fr_it__no_intersection)
{
    const auto intersection = intersects(language::fr, language::it);
    BOOST_REQUIRE(!intersection);
}

BOOST_AUTO_TEST_CASE(mnemonic__dictionary__cs_pt__no_intersection)
{
    const auto intersection = intersects(language::cs, language::pt);
    BOOST_REQUIRE(!intersection);
}

BOOST_AUTO_TEST_CASE(mnemonic__dictionary__ko_zh_Hans__no_intersection)
{
    const auto intersection = intersects(language::ko, language::zh_Hans);
    BOOST_REQUIRE(!intersection);
}

BOOST_AUTO_TEST_CASE(mnemonic__dictionary__zh_Hans_Hant__1275_intersections)
{
    const auto intersections = intersection_count(language::zh_Hans, language::zh_Hant);
    BOOST_REQUIRE_EQUAL(intersections, 1275u);
}

BOOST_AUTO_TEST_SUITE_END()
