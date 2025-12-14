/*
 * DynArray - A small dynamic array library in C
 * Copyright (C) 2025 seesee010
 *
 * you can redistribute it and/or
 * modify it under the terms of the GNU General Public License 2.0
 */

#include "../dynarray.h"

size_t dynarray_get(DynArray *array, size_t index) {
    
    if (array == NULL) {
        return -1;
    }

    void *ptr = (array->data + index * array->element_size);

    return (size_t)ptr;
}

bool dynarray_set(DynArray *array, size_t index, void *value) {
    
    if (array == NULL) {
        return false;
    }

    if (index >= array->capacity) {
        array->length++;
        return false;
    }

    // i hate myself
    ((DynArray **)array->data)[index] = (DynArray*)value;

    return true;
}