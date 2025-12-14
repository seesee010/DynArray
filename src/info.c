/*
 * DynArray - A small dynamic array library in C
 * Copyright (C) 2025 seesee010
 *
 * you can redistribute it and/or
 * modify it under the terms of the GNU General Public License 2.0
 */

#include "../dynarray.h"

size_t dynarray_length(DynArray *array) {
    return array->length;
}

size_t dynarray_totalCapacity(DynArray *array) {
    return array->capacity;
}