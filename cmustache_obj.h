/**
 * Copyright (c) 2020, Artem V. Andreev
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 */

#ifndef CMUSTACHE_OBJ_H
#define CMUSTACHE_OBJ_H 1
#ifdef __cplusplus
extern "C"
{
#endif /* __cplusplus */

#include <stdbool.h>
#include <stdlib.h>
#include <limits.h>

typedef struct cmustache_context cmustache_context;
typedef struct cmustache_object cmustache_object;

typedef struct cmustache_type {
    const char *id;
    void (*destroy)(cmustache_object *obj);
    void (*interpolate)(const cmustache_context *ctx,
                        const cmustache_object *obj,
                        bool escape);
    cmustache_object *(*reduce)(const cmustache_object *obj);
    void (*enumerate)(const cmustache_context *ctx,
                      const cmustache_object *obj);
    bool (*isnull)(const cmustache_object *obj);
    cmustache_object *(*lookup)(const cmustache_object *obj,
                                const char *name);
    cmustache_object *(*lookup2)(const cmustache_object *obj,
                                 const char *name,
                                 const char *section);
} cmustache_type;

struct cmustache_object {
    const cmustache_type *type;
    unsigned refcnt;
};

static inline cmustache_object *
cmustache_use(cmustache_object *obj)
{
    if (obj != NULL && obj->refcnt != UINT_MAX)
        obj->refcnt++;
    return obj;
}

static inline void
cmustache_release(cmustache_object *obj)
{
    if (obj == NULL || obj->refcnt == UINT_MAX)
        return;
    if (obj->refcnt-- == 1)
    {
        if (obj->type->destroy != NULL)
            obj->type->destroy(obj);
        free(obj);
    }
}
#ifdef __cplusplus
}
#endif /* __cplusplus */
#endif /* CMUSTACHE_OBJ_H */
