/*
 * librdkafka - The Apache Kafka C/C++ library
 *
 * Copyright (c) 2017 Magnus Edenhill
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * 1. Redistributions of source code must retain the above copyright notice,
 *    this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright notice,
 *    this list of conditions and the following disclaimer in the documentation
 *    and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 */

#ifndef _RDSTRINGBUILDER_H_
#define _RDSTRINGBUILDER_H_

struct str_builder;
typedef struct str_builder str_builder_t;

/**
 * @brief String builder utility to efficiently build strings
 * see https://nachtimwald.com/2017/02/26/efficient-c-string-builder/ for
 * implementation details
 */
str_builder_t *str_builder_create(void);
void str_builder_destroy(str_builder_t *sb);

/** Add a string to the builder.
 *
 * param[in,out] sb  Builder.
 * param[in]     str String to add.
 * param[in]     len Length of string to add. If 0, strlen will be called
 *                internally to determine length.
 */
void str_builder_add_str(str_builder_t *sb, const char *str, size_t len);

/** Add a character to the builder.
 *
 * param[in,out] sb Builder.
 * param[in]     c  Character.
 */
void str_builder_add_char(str_builder_t *sb, char c);

/** Add an integer as to the builder.
 *
 * param[in,out] sb  Builder.
 * param[in]     val Int to add.
 */
void str_builder_add_int(str_builder_t *sb, int val);

/** Clear the builder.
 *
 * param[in,out] sb  Builder.
 */
void str_builder_clear(str_builder_t *sb);

/** Remove data from the end of the builder.
 *
 * param[in,out] sb  Builder.
 * param[in]     len The new length of the string.
 *                    Anything after this length is removed.
 */
void str_builder_truncate(str_builder_t *sb, size_t len);

/** Remove data from the beginning of the builder.
 *
 * param[in,out] sb  Builder.
 * param[in]     len The length to remove.
 */
void str_builder_drop(str_builder_t *sb, size_t len);

/** The length of the string contained in the builder.
 *
 * param[in] sb Builder.
 *
 * return Length.
 */
size_t str_builder_len(const str_builder_t *sb);

/** A pointer to the internal buffer with the builder's string data.
 *
 * The data is guaranteed to be NULL terminated.
 *
 * param[in] sb Builder.
 *
 * return Pointer to internal string data.
 */
const char *str_builder_peek(const str_builder_t *sb);

/** Return a copy of the string data.
 *
 * param[in]  sb  Builder.
 * param[out] len Length of returned data. Can be NULL if not needed.
 *
 * return Copy of the internal string data.
 */
char *str_builder_dump(const str_builder_t *sb, size_t *len);


#endif /* _RDSTRINGBUILDER_H_ */