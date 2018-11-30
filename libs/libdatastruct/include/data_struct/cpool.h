/*
 * Copyright 2016, Data61
 * Commonwealth Scientific and Industrial Research Organisation (CSIRO)
 * ABN 41 687 119 230.
 *
 * This software may be distributed and modified according to the terms of
 * the BSD 2-Clause license. Note that NO WARRANTY is provided.
 * See "LICENSE_BSD2.txt" for details.
 *
 * @TAG(D61_BSD)
 */

#ifndef _CALLOCPOOL_H_
#define _CALLOCPOOL_H_

#ifndef kmalloc
    #include <stdlib.h>
    #include <stdint.h>
    #define kmalloc malloc
    #define krealloc realloc
    #define kfree free
#endif

#include <string.h>
#include <stdbool.h>

typedef struct cpool_s {
    uint32_t start;
    uint32_t end;
    uint32_t size;
    uint8_t *list;
} cpool_t;

// end is not inclusive
bool cpool_init(cpool_t *p, uint32_t start, uint32_t end);

void cpool_release(cpool_t *p);

uint32_t cpool_alloc(cpool_t *p);

void cpool_free(cpool_t *p, uint32_t obj);

bool cpool_check(cpool_t *p, uint32_t obj);

#endif /* _CALLOCPOOL_H_ */
