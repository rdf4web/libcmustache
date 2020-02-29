/**
 * Copyright (c) 2020, Artem V. Andreev
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 */

#ifndef CMUSTACHE_TOOLS_H
#define CMUSTACHE_TOOLS_H 1
#ifdef __cplusplus
extern "C"
{
#endif /* __cplusplus */

#include <wchar.h>
#include <stdarg.h>
#include "cmustache_obj.h"

extern int cmustache_putc(const cmustache_context *ctx, int ch,
                          bool escape);
extern int cmustache_putwc(const cmustache_context *ctx, wchar_t wch,
                           bool escape);

extern int cmustache_puts(const cmustache_context *ctx, const char *str,
                          bool escape);
extern int cmustache_putws(const cmustache_context *ctx, const wchar_t *str,
                           bool escape);

extern int cmustache_printf(const cmustache_context *ctx, const char *fmt,
                            ...);
extern int cmustache_vprintf(const cmustache_context *ctx, const char *fmt,
                             va_list args);

#ifdef __cplusplus
}
#endif /* __cplusplus */
#endif /* CMUSTACHE_TOOLS_H */
