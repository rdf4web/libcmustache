/**
 * Copyright (c) 2020, Artem V. Andreev
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 */

#include "cmustache_internal.h"
#include "cmustache_tools.h"

int
cmustache_putc(const cmustache_context *ctx, int ch, bool escape)
{
}

int
cmustache_putwc(const cmustache_context *ctx, wchar_t wch, bool escape)
{
}

int
cmustache_puts(const cmustache_context *ctx, const char *str, bool escape)
{
}

int
cmustache_putws(const cmustache_context *ctx, const wchar_t *str, bool escape)
{
}

int
cmustache_printf(const cmustache_context *ctx, const char *fmt, ...)
{
    va_list args;
    int rc;

    va_start(args, fmt);
    rc = cmustache_vprintf(ctx, fmt, args);
    va_end(args);

    return rc;
}

int
cmustache_vprintf(const cmustache_context *ctx, const char *fmt, va_list args)
{
}
