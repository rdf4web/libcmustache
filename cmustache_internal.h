/**
 * Copyright (c) 2020, Artem V. Andreev
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 */

#ifndef CMUSTACHE_INTERNAL_H
#define CMUSTACHE_INTERNAL_H 1
#ifdef __cplusplus
extern "C"
{
#endif /* __cplusplus */

#ifndef IN_LIBCMUSTACHE
#error "This is an internal header!!!"
#endif

#include "cmustache_obj.h"
#include <stdio.h>

typedef int (*cmustache_parser_fn)(cmustache_context *ctx);

typedef struct cmustache_parser_state {
    FILE *input;
    FILE *output;
    struct {
        FILE *stream;
        char *data;
        size_t size;
        off_t offset;
    } scratch;
    struct {
        const char *data;
        size_t len;
    } prefix;
    cmustache_parser_fn parse;
    struct {
        char *start;
        char *end;
        bool own;
    } tags;
    bool xml_escape;
} cmustache_parser_state;

struct cmustache_context {
    cmustache_parser_state *parser;
    cmustache_obj *current;
    cmustache_context *chain;
};

#ifdef __cplusplus
}
#endif /* __cplusplus */
#endif /* CMUSTACHE_INTERNAL_H */
