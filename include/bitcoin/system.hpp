///////////////////////////////////////////////////////////////////////////////
// Copyright (c) 2014-2023 libbitcoin-system developers (see COPYING).
//
//        GENERATED SOURCE CODE, DO NOT EDIT EXCEPT EXPERIMENTALLY
//
///////////////////////////////////////////////////////////////////////////////
#ifndef LIBBITCOIN_SYSTEM_HPP
#define LIBBITCOIN_SYSTEM_HPP

/**
 * API Users: Include only this header. Direct use of other headers is fragile
 * and unsupported as header organization is subject to change.
 *
 * Maintainers: Do not include this header internal to this library.
 */

#include <bitcoin/system/boost.hpp>
#include <bitcoin/system/constants.hpp>
#include <bitcoin/system/constraints.hpp>
#include <bitcoin/system/define.hpp>
#include <bitcoin/system/exceptions.hpp>
#include <bitcoin/system/funclets.hpp>
#include <bitcoin/system/have.hpp>
#include <bitcoin/system/literals.hpp>
#include <bitcoin/system/settings.hpp>
#include <bitcoin/system/typelets.hpp>
#include <bitcoin/system/types.hpp>
#include <bitcoin/system/version.hpp>
#include <bitcoin/system/warnings.hpp>
#include <bitcoin/system/chain/block.hpp>
#include <bitcoin/system/chain/chain.hpp>
#include <bitcoin/system/chain/chain_state.hpp>
#include <bitcoin/system/chain/checkpoint.hpp>
#include <bitcoin/system/chain/compact.hpp>
#include <bitcoin/system/chain/context.hpp>
#include <bitcoin/system/chain/header.hpp>
#include <bitcoin/system/chain/input.hpp>
#include <bitcoin/system/chain/operation.hpp>
#include <bitcoin/system/chain/output.hpp>
#include <bitcoin/system/chain/point.hpp>
#include <bitcoin/system/chain/prevout.hpp>
#include <bitcoin/system/chain/script.hpp>
#include <bitcoin/system/chain/stripper.hpp>
#include <bitcoin/system/chain/transaction.hpp>
#include <bitcoin/system/chain/witness.hpp>
#include <bitcoin/system/chain/enums/coverage.hpp>
#include <bitcoin/system/chain/enums/flags.hpp>
#include <bitcoin/system/chain/enums/magic_numbers.hpp>
#include <bitcoin/system/chain/enums/numbers.hpp>
#include <bitcoin/system/chain/enums/opcode.hpp>
#include <bitcoin/system/chain/enums/policy.hpp>
#include <bitcoin/system/chain/enums/script_pattern.hpp>
#include <bitcoin/system/chain/enums/script_version.hpp>
#include <bitcoin/system/chain/enums/selection.hpp>
#include <bitcoin/system/config/base16.hpp>
#include <bitcoin/system/config/base2.hpp>
#include <bitcoin/system/config/base32.hpp>
#include <bitcoin/system/config/base58.hpp>
#include <bitcoin/system/config/base64.hpp>
#include <bitcoin/system/config/base85.hpp>
#include <bitcoin/system/config/block.hpp>
#include <bitcoin/system/config/config.hpp>
#include <bitcoin/system/config/hash160.hpp>
#include <bitcoin/system/config/hash256.hpp>
#include <bitcoin/system/config/header.hpp>
#include <bitcoin/system/config/input.hpp>
#include <bitcoin/system/config/output.hpp>
#include <bitcoin/system/config/parameter.hpp>
#include <bitcoin/system/config/parser.hpp>
#include <bitcoin/system/config/point.hpp>
#include <bitcoin/system/config/printer.hpp>
#include <bitcoin/system/config/script.hpp>
#include <bitcoin/system/config/transaction.hpp>
#include <bitcoin/system/crypto/aes256.hpp>
#include <bitcoin/system/crypto/crypto.hpp>
#include <bitcoin/system/crypto/der_parser.hpp>
#include <bitcoin/system/crypto/golomb_coding.hpp>
#include <bitcoin/system/crypto/pseudo_random.hpp>
#include <bitcoin/system/crypto/ring_signature.hpp>
#include <bitcoin/system/crypto/secp256k1.hpp>
#include <bitcoin/system/data/array_cast.hpp>
#include <bitcoin/system/data/byte_cast.hpp>
#include <bitcoin/system/data/collection.hpp>
#include <bitcoin/system/data/data.hpp>
#include <bitcoin/system/data/data_array.hpp>
#include <bitcoin/system/data/data_chunk.hpp>
#include <bitcoin/system/data/data_reference.hpp>
#include <bitcoin/system/data/data_slab.hpp>
#include <bitcoin/system/data/data_slice.hpp>
#include <bitcoin/system/data/exclusive_slice.hpp>
#include <bitcoin/system/data/external_ptr.hpp>
#include <bitcoin/system/data/iterable.hpp>
#include <bitcoin/system/data/memory.hpp>
#include <bitcoin/system/data/no_fill_allocator.hpp>
#include <bitcoin/system/data/string.hpp>
#include <bitcoin/system/endian/batch.hpp>
#include <bitcoin/system/endian/endian.hpp>
#include <bitcoin/system/endian/integers.hpp>
#include <bitcoin/system/endian/integrals.hpp>
#include <bitcoin/system/endian/minimal.hpp>
#include <bitcoin/system/endian/nominal.hpp>
#include <bitcoin/system/endian/stream.hpp>
#include <bitcoin/system/endian/swaps.hpp>
#include <bitcoin/system/endian/uintx_t.hpp>
#include <bitcoin/system/endian/unsafe.hpp>
#include <bitcoin/system/error/block_error_t.hpp>
#include <bitcoin/system/error/error.hpp>
#include <bitcoin/system/error/error_t.hpp>
#include <bitcoin/system/error/macros.hpp>
#include <bitcoin/system/error/op_error_t.hpp>
#include <bitcoin/system/error/script_error_t.hpp>
#include <bitcoin/system/error/transaction_error_t.hpp>
#include <bitcoin/system/hash/accumulator.hpp>
#include <bitcoin/system/hash/algorithm.hpp>
#include <bitcoin/system/hash/algorithms.hpp>
#include <bitcoin/system/hash/checksum.hpp>
#include <bitcoin/system/hash/functions.hpp>
#include <bitcoin/system/hash/hash.hpp>
#include <bitcoin/system/hash/hmac.hpp>
#include <bitcoin/system/hash/pbkd.hpp>
#include <bitcoin/system/hash/scrypt.hpp>
#include <bitcoin/system/hash/siphash.hpp>
#include <bitcoin/system/hash/rmd/algorithm.hpp>
#include <bitcoin/system/hash/rmd/rmd.hpp>
#include <bitcoin/system/hash/rmd/rmd128.hpp>
#include <bitcoin/system/hash/rmd/rmd160.hpp>
#include <bitcoin/system/hash/sha/algorithm.hpp>
#include <bitcoin/system/hash/sha/sha.hpp>
#include <bitcoin/system/hash/sha/sha160.hpp>
#include <bitcoin/system/hash/sha/sha256.hpp>
#include <bitcoin/system/hash/sha/sha512.hpp>
#include <bitcoin/system/intrinsics/byteswap.hpp>
#include <bitcoin/system/intrinsics/haves.hpp>
#include <bitcoin/system/intrinsics/intrinsics.hpp>
#include <bitcoin/system/intrinsics/rotate.hpp>
#include <bitcoin/system/intrinsics/arm/arm.hpp>
#include <bitcoin/system/intrinsics/arm/functional.hpp>
#include <bitcoin/system/intrinsics/arm/sha.hpp>
#include <bitcoin/system/intrinsics/xcpu/cpuid.hpp>
#include <bitcoin/system/intrinsics/xcpu/defines.hpp>
#include <bitcoin/system/intrinsics/xcpu/functional_128.hpp>
#include <bitcoin/system/intrinsics/xcpu/functional_256.hpp>
#include <bitcoin/system/intrinsics/xcpu/functional_512.hpp>
#include <bitcoin/system/intrinsics/xcpu/sha.hpp>
#include <bitcoin/system/intrinsics/xcpu/xcpu.hpp>
#include <bitcoin/system/machine/interpreter.hpp>
#include <bitcoin/system/machine/machine.hpp>
#include <bitcoin/system/machine/number.hpp>
#include <bitcoin/system/machine/program.hpp>
#include <bitcoin/system/machine/stack.hpp>
#include <bitcoin/system/math/addition.hpp>
#include <bitcoin/system/math/bits.hpp>
#include <bitcoin/system/math/bytes.hpp>
#include <bitcoin/system/math/byteswap.hpp>
#include <bitcoin/system/math/cast.hpp>
#include <bitcoin/system/math/division.hpp>
#include <bitcoin/system/math/functional.hpp>
#include <bitcoin/system/math/limits.hpp>
#include <bitcoin/system/math/logarithm.hpp>
#include <bitcoin/system/math/math.hpp>
#include <bitcoin/system/math/overflow.hpp>
#include <bitcoin/system/math/power.hpp>
#include <bitcoin/system/math/rotate.hpp>
#include <bitcoin/system/math/sign.hpp>
#include <bitcoin/system/radix/base_10.hpp>
#include <bitcoin/system/radix/base_16.hpp>
#include <bitcoin/system/radix/base_2048.hpp>
#include <bitcoin/system/radix/base_2n.hpp>
#include <bitcoin/system/radix/base_32.hpp>
#include <bitcoin/system/radix/base_58.hpp>
#include <bitcoin/system/radix/base_64.hpp>
#include <bitcoin/system/radix/base_85.hpp>
#include <bitcoin/system/radix/radix.hpp>
#include <bitcoin/system/serial/deserialize.hpp>
#include <bitcoin/system/serial/props.hpp>
#include <bitcoin/system/serial/serial.hpp>
#include <bitcoin/system/serial/serialize.hpp>
#include <bitcoin/system/stream/binary.hpp>
#include <bitcoin/system/stream/device.hpp>
#include <bitcoin/system/stream/make_stream.hpp>
#include <bitcoin/system/stream/make_streamer.hpp>
#include <bitcoin/system/stream/stream.hpp>
#include <bitcoin/system/stream/stream_result.hpp>
#include <bitcoin/system/stream/streamers.hpp>
#include <bitcoin/system/stream/streams.hpp>
#include <bitcoin/system/stream/devices/copy_sink.hpp>
#include <bitcoin/system/stream/devices/copy_source.hpp>
#include <bitcoin/system/stream/devices/flip_sink.hpp>
#include <bitcoin/system/stream/devices/push_sink.hpp>
#include <bitcoin/system/stream/iostream/iostream.hpp>
#include <bitcoin/system/stream/iostream/istream.hpp>
#include <bitcoin/system/stream/iostream/ostream.hpp>
#include <bitcoin/system/stream/streamers/bit_flipper.hpp>
#include <bitcoin/system/stream/streamers/bit_reader.hpp>
#include <bitcoin/system/stream/streamers/bit_writer.hpp>
#include <bitcoin/system/stream/streamers/byte_flipper.hpp>
#include <bitcoin/system/stream/streamers/byte_reader.hpp>
#include <bitcoin/system/stream/streamers/byte_writer.hpp>
#include <bitcoin/system/stream/streamers/sha256_writer.hpp>
#include <bitcoin/system/stream/streamers/sha256x2_writer.hpp>
#include <bitcoin/system/stream/streamers/interfaces/bitflipper.hpp>
#include <bitcoin/system/stream/streamers/interfaces/bitreader.hpp>
#include <bitcoin/system/stream/streamers/interfaces/bitwriter.hpp>
#include <bitcoin/system/stream/streamers/interfaces/byteflipper.hpp>
#include <bitcoin/system/stream/streamers/interfaces/bytereader.hpp>
#include <bitcoin/system/stream/streamers/interfaces/bytewriter.hpp>
#include <bitcoin/system/unicode/ascii.hpp>
#include <bitcoin/system/unicode/code_points.hpp>
#include <bitcoin/system/unicode/conversion.hpp>
#include <bitcoin/system/unicode/normalization.hpp>
#include <bitcoin/system/unicode/unicode.hpp>
#include <bitcoin/system/unicode/utf8_everywhere/console_streambuf.hpp>
#include <bitcoin/system/unicode/utf8_everywhere/environment.hpp>
#include <bitcoin/system/unicode/utf8_everywhere/ifstream.hpp>
#include <bitcoin/system/unicode/utf8_everywhere/ofstream.hpp>
#include <bitcoin/system/unicode/utf8_everywhere/paths.hpp>
#include <bitcoin/system/unicode/utf8_everywhere/stdio.hpp>
#include <bitcoin/system/unicode/utf8_everywhere/unicode_istream.hpp>
#include <bitcoin/system/unicode/utf8_everywhere/unicode_ostream.hpp>
#include <bitcoin/system/unicode/utf8_everywhere/unicode_streambuf.hpp>
#include <bitcoin/system/unicode/utf8_everywhere/utf8_everywhere.hpp>
#include <bitcoin/system/wallet/context.hpp>
#include <bitcoin/system/wallet/message.hpp>
#include <bitcoin/system/wallet/neutrino_filter.hpp>
#include <bitcoin/system/wallet/point_value.hpp>
#include <bitcoin/system/wallet/points_value.hpp>
#include <bitcoin/system/wallet/wallet.hpp>
#include <bitcoin/system/wallet/addresses/bitcoin_uri.hpp>
#include <bitcoin/system/wallet/addresses/checked.hpp>
#include <bitcoin/system/wallet/addresses/payment_address.hpp>
#include <bitcoin/system/wallet/addresses/qr_code.hpp>
#include <bitcoin/system/wallet/addresses/stealth_address.hpp>
#include <bitcoin/system/wallet/addresses/stealth_receiver.hpp>
#include <bitcoin/system/wallet/addresses/stealth_sender.hpp>
#include <bitcoin/system/wallet/addresses/tiff.hpp>
#include <bitcoin/system/wallet/addresses/uri.hpp>
#include <bitcoin/system/wallet/addresses/uri_reader.hpp>
#include <bitcoin/system/wallet/addresses/witness_address.hpp>
#include <bitcoin/system/wallet/keys/ec_point.hpp>
#include <bitcoin/system/wallet/keys/ec_private.hpp>
#include <bitcoin/system/wallet/keys/ec_public.hpp>
#include <bitcoin/system/wallet/keys/ec_scalar.hpp>
#include <bitcoin/system/wallet/keys/ek_private.hpp>
#include <bitcoin/system/wallet/keys/ek_public.hpp>
#include <bitcoin/system/wallet/keys/ek_token.hpp>
#include <bitcoin/system/wallet/keys/encrypted_keys.hpp>
#include <bitcoin/system/wallet/keys/hd_private.hpp>
#include <bitcoin/system/wallet/keys/hd_public.hpp>
#include <bitcoin/system/wallet/keys/mini_keys.hpp>
#include <bitcoin/system/wallet/keys/stealth.hpp>
#include <bitcoin/system/wallet/mnemonics/electrum.hpp>
#include <bitcoin/system/wallet/mnemonics/electrum_v1.hpp>
#include <bitcoin/system/wallet/mnemonics/mnemonic.hpp>
#include <bitcoin/system/words/dictionaries.hpp>
#include <bitcoin/system/words/dictionary.hpp>
#include <bitcoin/system/words/language.hpp>
#include <bitcoin/system/words/languages.hpp>
#include <bitcoin/system/words/words.hpp>
#include <bitcoin/system/words/catalogs/electrum.hpp>
#include <bitcoin/system/words/catalogs/electrum_v1.hpp>
#include <bitcoin/system/words/catalogs/mnemonic.hpp>

#endif
