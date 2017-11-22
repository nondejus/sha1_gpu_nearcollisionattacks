/*****
  Copyright (C) 2016 Marc Stevens, Centrum Wiskunde & Informatica (CWI), Amsterdam.

  This file is part of sha1freestart80 source-code and released under the MIT License
*****/

#define HASHCLASH_BUILD

#include <stdlib.h>

#include "sha1detail.hpp"

namespace hc {

#ifndef SHA1DETAIL_INLINE_IMPL

	const uint32_t sha1_iv[] = { 0x67452301, 0xEFCDAB89, 0x98BADCFE, 0x10325476, 0xC3D2E1F0 };
	const uint32_t sha1_ac[] = { 0x5A827999, 0x6ED9EBA1, 0x8F1BBCDC, 0xCA62C1D6 };

#endif

	#define HASHCLASH_SHA1COMPRESS_ROUND1_STEP(a, b, c, d, e, m, t) \
	    e += rotate_left(a, 5) + sha1_f1(b,c,d) + 0x5A827999 + m[t]; b = rotate_left(b, 30);
	#define HASHCLASH_SHA1COMPRESS_ROUND2_STEP(a, b, c, d, e, m, t) \
	    e += rotate_left(a, 5) + sha1_f2(b,c,d) + 0x6ED9EBA1 + m[t]; b = rotate_left(b, 30);
	#define HASHCLASH_SHA1COMPRESS_ROUND3_STEP(a, b, c, d, e, m, t) \
	    e += rotate_left(a, 5) + sha1_f3(b,c,d) + 0x8F1BBCDC + m[t]; b = rotate_left(b, 30);
	#define HASHCLASH_SHA1COMPRESS_ROUND4_STEP(a, b, c, d, e, m, t) \
	    e += rotate_left(a, 5) + sha1_f4(b,c,d) + 0xCA62C1D6 + m[t]; b = rotate_left(b, 30);
	
	void sha1compress(uint32_t ihv[5], const uint32_t block[16])
	{
		uint32_t me[80];
		sha1_me(me, block);

		uint32_t a = ihv[0]; uint32_t b = ihv[1]; uint32_t c = ihv[2]; uint32_t d = ihv[3]; uint32_t e = ihv[4];

		HASHCLASH_SHA1COMPRESS_ROUND1_STEP( a, b, c, d, e, me,  0 );
		HASHCLASH_SHA1COMPRESS_ROUND1_STEP( e, a, b, c, d, me,  1 );
		HASHCLASH_SHA1COMPRESS_ROUND1_STEP( d, e, a, b, c, me,  2 );
		HASHCLASH_SHA1COMPRESS_ROUND1_STEP( c, d, e, a, b, me,  3 );
		HASHCLASH_SHA1COMPRESS_ROUND1_STEP( b, c, d, e, a, me,  4 );
		HASHCLASH_SHA1COMPRESS_ROUND1_STEP( a, b, c, d, e, me,  5 );
		HASHCLASH_SHA1COMPRESS_ROUND1_STEP( e, a, b, c, d, me,  6 );
		HASHCLASH_SHA1COMPRESS_ROUND1_STEP( d, e, a, b, c, me,  7 );
		HASHCLASH_SHA1COMPRESS_ROUND1_STEP( c, d, e, a, b, me,  8 );
		HASHCLASH_SHA1COMPRESS_ROUND1_STEP( b, c, d, e, a, me,  9 );
		HASHCLASH_SHA1COMPRESS_ROUND1_STEP( a, b, c, d, e, me, 10 );
		HASHCLASH_SHA1COMPRESS_ROUND1_STEP( e, a, b, c, d, me, 11 );
		HASHCLASH_SHA1COMPRESS_ROUND1_STEP( d, e, a, b, c, me, 12 );
		HASHCLASH_SHA1COMPRESS_ROUND1_STEP( c, d, e, a, b, me, 13 );
		HASHCLASH_SHA1COMPRESS_ROUND1_STEP( b, c, d, e, a, me, 14 );
		HASHCLASH_SHA1COMPRESS_ROUND1_STEP( a, b, c, d, e, me, 15 );
		HASHCLASH_SHA1COMPRESS_ROUND1_STEP( e, a, b, c, d, me, 16 );
		HASHCLASH_SHA1COMPRESS_ROUND1_STEP( d, e, a, b, c, me, 17 );
		HASHCLASH_SHA1COMPRESS_ROUND1_STEP( c, d, e, a, b, me, 18 );
		HASHCLASH_SHA1COMPRESS_ROUND1_STEP( b, c, d, e, a, me, 19 );

		HASHCLASH_SHA1COMPRESS_ROUND2_STEP( a, b, c, d, e, me, 20 );
		HASHCLASH_SHA1COMPRESS_ROUND2_STEP( e, a, b, c, d, me, 21 );
		HASHCLASH_SHA1COMPRESS_ROUND2_STEP( d, e, a, b, c, me, 22 );
		HASHCLASH_SHA1COMPRESS_ROUND2_STEP( c, d, e, a, b, me, 23 );
		HASHCLASH_SHA1COMPRESS_ROUND2_STEP( b, c, d, e, a, me, 24 );
		HASHCLASH_SHA1COMPRESS_ROUND2_STEP( a, b, c, d, e, me, 25 );
		HASHCLASH_SHA1COMPRESS_ROUND2_STEP( e, a, b, c, d, me, 26 );
		HASHCLASH_SHA1COMPRESS_ROUND2_STEP( d, e, a, b, c, me, 27 );
		HASHCLASH_SHA1COMPRESS_ROUND2_STEP( c, d, e, a, b, me, 28 );
		HASHCLASH_SHA1COMPRESS_ROUND2_STEP( b, c, d, e, a, me, 29 );
		HASHCLASH_SHA1COMPRESS_ROUND2_STEP( a, b, c, d, e, me, 30 );
		HASHCLASH_SHA1COMPRESS_ROUND2_STEP( e, a, b, c, d, me, 31 );
		HASHCLASH_SHA1COMPRESS_ROUND2_STEP( d, e, a, b, c, me, 32 );
		HASHCLASH_SHA1COMPRESS_ROUND2_STEP( c, d, e, a, b, me, 33 );
		HASHCLASH_SHA1COMPRESS_ROUND2_STEP( b, c, d, e, a, me, 34 );
		HASHCLASH_SHA1COMPRESS_ROUND2_STEP( a, b, c, d, e, me, 35 );
		HASHCLASH_SHA1COMPRESS_ROUND2_STEP( e, a, b, c, d, me, 36 );
		HASHCLASH_SHA1COMPRESS_ROUND2_STEP( d, e, a, b, c, me, 37 );
		HASHCLASH_SHA1COMPRESS_ROUND2_STEP( c, d, e, a, b, me, 38 );
		HASHCLASH_SHA1COMPRESS_ROUND2_STEP( b, c, d, e, a, me, 39 );

		HASHCLASH_SHA1COMPRESS_ROUND3_STEP( a, b, c, d, e, me, 40 );
		HASHCLASH_SHA1COMPRESS_ROUND3_STEP( e, a, b, c, d, me, 41 );
		HASHCLASH_SHA1COMPRESS_ROUND3_STEP( d, e, a, b, c, me, 42 );
		HASHCLASH_SHA1COMPRESS_ROUND3_STEP( c, d, e, a, b, me, 43 );
		HASHCLASH_SHA1COMPRESS_ROUND3_STEP( b, c, d, e, a, me, 44 );
		HASHCLASH_SHA1COMPRESS_ROUND3_STEP( a, b, c, d, e, me, 45 );
		HASHCLASH_SHA1COMPRESS_ROUND3_STEP( e, a, b, c, d, me, 46 );
		HASHCLASH_SHA1COMPRESS_ROUND3_STEP( d, e, a, b, c, me, 47 );
		HASHCLASH_SHA1COMPRESS_ROUND3_STEP( c, d, e, a, b, me, 48 );
		HASHCLASH_SHA1COMPRESS_ROUND3_STEP( b, c, d, e, a, me, 49 );
		HASHCLASH_SHA1COMPRESS_ROUND3_STEP( a, b, c, d, e, me, 50 );
		HASHCLASH_SHA1COMPRESS_ROUND3_STEP( e, a, b, c, d, me, 51 );
		HASHCLASH_SHA1COMPRESS_ROUND3_STEP( d, e, a, b, c, me, 52 );
		HASHCLASH_SHA1COMPRESS_ROUND3_STEP( c, d, e, a, b, me, 53 );
		HASHCLASH_SHA1COMPRESS_ROUND3_STEP( b, c, d, e, a, me, 54 );
		HASHCLASH_SHA1COMPRESS_ROUND3_STEP( a, b, c, d, e, me, 55 );
		HASHCLASH_SHA1COMPRESS_ROUND3_STEP( e, a, b, c, d, me, 56 );
		HASHCLASH_SHA1COMPRESS_ROUND3_STEP( d, e, a, b, c, me, 57 );
		HASHCLASH_SHA1COMPRESS_ROUND3_STEP( c, d, e, a, b, me, 58 );
		HASHCLASH_SHA1COMPRESS_ROUND3_STEP( b, c, d, e, a, me, 59 );

		HASHCLASH_SHA1COMPRESS_ROUND4_STEP( a, b, c, d, e, me, 60 );
		HASHCLASH_SHA1COMPRESS_ROUND4_STEP( e, a, b, c, d, me, 61 );
		HASHCLASH_SHA1COMPRESS_ROUND4_STEP( d, e, a, b, c, me, 62 );
		HASHCLASH_SHA1COMPRESS_ROUND4_STEP( c, d, e, a, b, me, 63 );
		HASHCLASH_SHA1COMPRESS_ROUND4_STEP( b, c, d, e, a, me, 64 );
		HASHCLASH_SHA1COMPRESS_ROUND4_STEP( a, b, c, d, e, me, 65 );
		HASHCLASH_SHA1COMPRESS_ROUND4_STEP( e, a, b, c, d, me, 66 );
		HASHCLASH_SHA1COMPRESS_ROUND4_STEP( d, e, a, b, c, me, 67 );
		HASHCLASH_SHA1COMPRESS_ROUND4_STEP( c, d, e, a, b, me, 68 );
		HASHCLASH_SHA1COMPRESS_ROUND4_STEP( b, c, d, e, a, me, 69 );
		HASHCLASH_SHA1COMPRESS_ROUND4_STEP( a, b, c, d, e, me, 70 );
		HASHCLASH_SHA1COMPRESS_ROUND4_STEP( e, a, b, c, d, me, 71 );
		HASHCLASH_SHA1COMPRESS_ROUND4_STEP( d, e, a, b, c, me, 72 );
		HASHCLASH_SHA1COMPRESS_ROUND4_STEP( c, d, e, a, b, me, 73 );
		HASHCLASH_SHA1COMPRESS_ROUND4_STEP( b, c, d, e, a, me, 74 );
		HASHCLASH_SHA1COMPRESS_ROUND4_STEP( a, b, c, d, e, me, 75 );
		HASHCLASH_SHA1COMPRESS_ROUND4_STEP( e, a, b, c, d, me, 76 );
		HASHCLASH_SHA1COMPRESS_ROUND4_STEP( d, e, a, b, c, me, 77 );
		HASHCLASH_SHA1COMPRESS_ROUND4_STEP( c, d, e, a, b, me, 78 );
		HASHCLASH_SHA1COMPRESS_ROUND4_STEP( b, c, d, e, a, me, 79 );

		ihv[0] += a; ihv[1] += b; ihv[2] += c; ihv[3] += d; ihv[4] += e;
	}

	void sha1compress_me(uint32_t ihv[5], const uint32_t me[80])
	{
		uint32_t a = ihv[0]; uint32_t b = ihv[1]; uint32_t c = ihv[2]; uint32_t d = ihv[3]; uint32_t e = ihv[4];

		HASHCLASH_SHA1COMPRESS_ROUND1_STEP( a, b, c, d, e, me,  0 );
		HASHCLASH_SHA1COMPRESS_ROUND1_STEP( e, a, b, c, d, me,  1 );
		HASHCLASH_SHA1COMPRESS_ROUND1_STEP( d, e, a, b, c, me,  2 );
		HASHCLASH_SHA1COMPRESS_ROUND1_STEP( c, d, e, a, b, me,  3 );
		HASHCLASH_SHA1COMPRESS_ROUND1_STEP( b, c, d, e, a, me,  4 );
		HASHCLASH_SHA1COMPRESS_ROUND1_STEP( a, b, c, d, e, me,  5 );
		HASHCLASH_SHA1COMPRESS_ROUND1_STEP( e, a, b, c, d, me,  6 );
		HASHCLASH_SHA1COMPRESS_ROUND1_STEP( d, e, a, b, c, me,  7 );
		HASHCLASH_SHA1COMPRESS_ROUND1_STEP( c, d, e, a, b, me,  8 );
		HASHCLASH_SHA1COMPRESS_ROUND1_STEP( b, c, d, e, a, me,  9 );
		HASHCLASH_SHA1COMPRESS_ROUND1_STEP( a, b, c, d, e, me, 10 );
		HASHCLASH_SHA1COMPRESS_ROUND1_STEP( e, a, b, c, d, me, 11 );
		HASHCLASH_SHA1COMPRESS_ROUND1_STEP( d, e, a, b, c, me, 12 );
		HASHCLASH_SHA1COMPRESS_ROUND1_STEP( c, d, e, a, b, me, 13 );
		HASHCLASH_SHA1COMPRESS_ROUND1_STEP( b, c, d, e, a, me, 14 );
		HASHCLASH_SHA1COMPRESS_ROUND1_STEP( a, b, c, d, e, me, 15 );
		HASHCLASH_SHA1COMPRESS_ROUND1_STEP( e, a, b, c, d, me, 16 );
		HASHCLASH_SHA1COMPRESS_ROUND1_STEP( d, e, a, b, c, me, 17 );
		HASHCLASH_SHA1COMPRESS_ROUND1_STEP( c, d, e, a, b, me, 18 );
		HASHCLASH_SHA1COMPRESS_ROUND1_STEP( b, c, d, e, a, me, 19 );

		HASHCLASH_SHA1COMPRESS_ROUND2_STEP( a, b, c, d, e, me, 20 );
		HASHCLASH_SHA1COMPRESS_ROUND2_STEP( e, a, b, c, d, me, 21 );
		HASHCLASH_SHA1COMPRESS_ROUND2_STEP( d, e, a, b, c, me, 22 );
		HASHCLASH_SHA1COMPRESS_ROUND2_STEP( c, d, e, a, b, me, 23 );
		HASHCLASH_SHA1COMPRESS_ROUND2_STEP( b, c, d, e, a, me, 24 );
		HASHCLASH_SHA1COMPRESS_ROUND2_STEP( a, b, c, d, e, me, 25 );
		HASHCLASH_SHA1COMPRESS_ROUND2_STEP( e, a, b, c, d, me, 26 );
		HASHCLASH_SHA1COMPRESS_ROUND2_STEP( d, e, a, b, c, me, 27 );
		HASHCLASH_SHA1COMPRESS_ROUND2_STEP( c, d, e, a, b, me, 28 );
		HASHCLASH_SHA1COMPRESS_ROUND2_STEP( b, c, d, e, a, me, 29 );
		HASHCLASH_SHA1COMPRESS_ROUND2_STEP( a, b, c, d, e, me, 30 );
		HASHCLASH_SHA1COMPRESS_ROUND2_STEP( e, a, b, c, d, me, 31 );
		HASHCLASH_SHA1COMPRESS_ROUND2_STEP( d, e, a, b, c, me, 32 );
		HASHCLASH_SHA1COMPRESS_ROUND2_STEP( c, d, e, a, b, me, 33 );
		HASHCLASH_SHA1COMPRESS_ROUND2_STEP( b, c, d, e, a, me, 34 );
		HASHCLASH_SHA1COMPRESS_ROUND2_STEP( a, b, c, d, e, me, 35 );
		HASHCLASH_SHA1COMPRESS_ROUND2_STEP( e, a, b, c, d, me, 36 );
		HASHCLASH_SHA1COMPRESS_ROUND2_STEP( d, e, a, b, c, me, 37 );
		HASHCLASH_SHA1COMPRESS_ROUND2_STEP( c, d, e, a, b, me, 38 );
		HASHCLASH_SHA1COMPRESS_ROUND2_STEP( b, c, d, e, a, me, 39 );

		HASHCLASH_SHA1COMPRESS_ROUND3_STEP( a, b, c, d, e, me, 40 );
		HASHCLASH_SHA1COMPRESS_ROUND3_STEP( e, a, b, c, d, me, 41 );
		HASHCLASH_SHA1COMPRESS_ROUND3_STEP( d, e, a, b, c, me, 42 );
		HASHCLASH_SHA1COMPRESS_ROUND3_STEP( c, d, e, a, b, me, 43 );
		HASHCLASH_SHA1COMPRESS_ROUND3_STEP( b, c, d, e, a, me, 44 );
		HASHCLASH_SHA1COMPRESS_ROUND3_STEP( a, b, c, d, e, me, 45 );
		HASHCLASH_SHA1COMPRESS_ROUND3_STEP( e, a, b, c, d, me, 46 );
		HASHCLASH_SHA1COMPRESS_ROUND3_STEP( d, e, a, b, c, me, 47 );
		HASHCLASH_SHA1COMPRESS_ROUND3_STEP( c, d, e, a, b, me, 48 );
		HASHCLASH_SHA1COMPRESS_ROUND3_STEP( b, c, d, e, a, me, 49 );
		HASHCLASH_SHA1COMPRESS_ROUND3_STEP( a, b, c, d, e, me, 50 );
		HASHCLASH_SHA1COMPRESS_ROUND3_STEP( e, a, b, c, d, me, 51 );
		HASHCLASH_SHA1COMPRESS_ROUND3_STEP( d, e, a, b, c, me, 52 );
		HASHCLASH_SHA1COMPRESS_ROUND3_STEP( c, d, e, a, b, me, 53 );
		HASHCLASH_SHA1COMPRESS_ROUND3_STEP( b, c, d, e, a, me, 54 );
		HASHCLASH_SHA1COMPRESS_ROUND3_STEP( a, b, c, d, e, me, 55 );
		HASHCLASH_SHA1COMPRESS_ROUND3_STEP( e, a, b, c, d, me, 56 );
		HASHCLASH_SHA1COMPRESS_ROUND3_STEP( d, e, a, b, c, me, 57 );
		HASHCLASH_SHA1COMPRESS_ROUND3_STEP( c, d, e, a, b, me, 58 );
		HASHCLASH_SHA1COMPRESS_ROUND3_STEP( b, c, d, e, a, me, 59 );

		HASHCLASH_SHA1COMPRESS_ROUND4_STEP( a, b, c, d, e, me, 60 );
		HASHCLASH_SHA1COMPRESS_ROUND4_STEP( e, a, b, c, d, me, 61 );
		HASHCLASH_SHA1COMPRESS_ROUND4_STEP( d, e, a, b, c, me, 62 );
		HASHCLASH_SHA1COMPRESS_ROUND4_STEP( c, d, e, a, b, me, 63 );
		HASHCLASH_SHA1COMPRESS_ROUND4_STEP( b, c, d, e, a, me, 64 );
		HASHCLASH_SHA1COMPRESS_ROUND4_STEP( a, b, c, d, e, me, 65 );
		HASHCLASH_SHA1COMPRESS_ROUND4_STEP( e, a, b, c, d, me, 66 );
		HASHCLASH_SHA1COMPRESS_ROUND4_STEP( d, e, a, b, c, me, 67 );
		HASHCLASH_SHA1COMPRESS_ROUND4_STEP( c, d, e, a, b, me, 68 );
		HASHCLASH_SHA1COMPRESS_ROUND4_STEP( b, c, d, e, a, me, 69 );
		HASHCLASH_SHA1COMPRESS_ROUND4_STEP( a, b, c, d, e, me, 70 );
		HASHCLASH_SHA1COMPRESS_ROUND4_STEP( e, a, b, c, d, me, 71 );
		HASHCLASH_SHA1COMPRESS_ROUND4_STEP( d, e, a, b, c, me, 72 );
		HASHCLASH_SHA1COMPRESS_ROUND4_STEP( c, d, e, a, b, me, 73 );
		HASHCLASH_SHA1COMPRESS_ROUND4_STEP( b, c, d, e, a, me, 74 );
		HASHCLASH_SHA1COMPRESS_ROUND4_STEP( a, b, c, d, e, me, 75 );
		HASHCLASH_SHA1COMPRESS_ROUND4_STEP( e, a, b, c, d, me, 76 );
		HASHCLASH_SHA1COMPRESS_ROUND4_STEP( d, e, a, b, c, me, 77 );
		HASHCLASH_SHA1COMPRESS_ROUND4_STEP( c, d, e, a, b, me, 78 );
		HASHCLASH_SHA1COMPRESS_ROUND4_STEP( b, c, d, e, a, me, 79 );

		ihv[0] += a; ihv[1] += b; ihv[2] += c; ihv[3] += d; ihv[4] += e;
	}

} // namespace hash