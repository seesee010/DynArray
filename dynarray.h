/*
 * DynArray - A small dynamic array library in C
 * Copyright (C) 2025 seesee010
 *
 * you can redistribute it and/or
 * modify it under the terms of the GNU General Public License 2.0
 */

#pragma once

#include <stdint.h>
#include <stddef.h> // size_t
#include <stdbool.h>
#include <stdlib.h> // malloc, free, etc...

// ========================
// ===== Struct Def =======
// ========================

// custom DynArray
typedef struct {
    void *data;

    size_t element_size;
    size_t capacity;
    size_t length;
} DynArray;

// ========================
// ===== Core =============
// ========================

DynArray *dynarray_create(size_t element_size, size_t length);
void dynarray_free(DynArray *array);

// ========================
// ===== Modify Size ======
// ========================

    // relative
bool dynarray_inc(DynArray *array, size_t size);
bool dynarray_dec(DynArray *array, size_t size);
    
    // absolute
bool dynarray_setSize(DynArray *array, size_t size);
bool dynarray_setSize_safe(DynArray *array, size_t size);

    // add data at the end of array (array_size gets bigger!)
bool dynarray_push(DynArray *array, void *value);
bool dynarray_pop(DynArray *array, size_t size);

    // new DynArray size = otherArray size
bool dynarray_fit(DynArray *array, DynArray *otherArray);

bool dynarray_insert(DynArray *array, size_t index, void *value);

bool dynarray_clear(DynArray *array, void *value);

// ========================
// ===== Access ===========
// ========================

size_t dynarray_get(DynArray *array, size_t index);
bool dynarray_set(DynArray *array, size_t index, void *value);

// ========================
// ===== Info =============
// ========================

size_t dynarray_length(DynArray *array);
size_t dynarray_capacity(DynArray *array);
size_t dynarray_elementSize(DynArray *array);
void *dynarray_data(DynArray *array);
size_t size(DynArray *array);