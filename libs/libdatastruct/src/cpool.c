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

#include <data_struct/cpool.h>
#include <assert.h>
#include <errno.h>

bool
cpool_init(cpool_t *p, uint32_t start, uint32_t end)
{
    assert(p);
    assert(end > start);
    p->start = start;
    p->end   = end;
    p->size  = ((end - start + 7) / 8);
    p->list  = kmalloc(p->size);
    if (!p->list) { return(false); }
    memset(p->list, 0, p->size);
}

void
cpool_release(cpool_t *p) {
    if (!p) { return; }
    if (p->list) { free(p->list); p->list = NULL; }
    p->start = p->end = p->size = 0;
}

uint32_t
cpool_alloc(cpool_t *p)
{
    assert(p);
    int i1, i2;
    for (i1 = 0; i1 < p->size; i1++)
    {
        if (p->list[i1] < 0xFF) { break; }
    }
    if (i1 == p->size) { return(0); }

    i2 = 0;
    while (i2 < 8)
    {
        if ((p->list[i1] & (1 << i2)) == 0) { break; }
        i2++;
    }
    p->list[i1] |= 1 << i2;
    return(p->start + (i1 * 8) + i2);
}

void
cpool_free(cpool_t *p, uint32_t idx)
{
    int i1, i2;
    idx -= p->start;
    i1 = idx / 8;
    i2 = (idx - i1 * 8) % 8;
    p->list[i1] &= (uint8_t )((~i2) & 0xFF);
}

bool
cpool_check(cpool_t *p, uint32_t idx)
{
    int i1, i2;
    idx -= p->start;
    i1 = idx / 8;
    i2 = (idx - i1 * 8) % 8;
    return((p->list[i1] & (uint8_t )i2) ? 1 : 0);
}
