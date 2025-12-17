/*
 * DynArray - A small dynamic array library in C
 * Copyright (C) 2025 seesee010
 *
 * you can redistribute it and/or
 * modify it under the terms of the GNU General Public License 2.0
 */

#include "../dynarray.h"
#include <iso646.h>
#include <stddef.h>
#include <stdlib.h>
#include <sys/types.h>

// relative
bool dynarray_inc(DynArray *array, size_t size) {
    
    if (array == NULL) {
        return false;
    }
    
    if (size  == 0) {
        return true;
    }

    void *temp = realloc(array->data, (array->capacity + size) * array->element_size);

    if (temp == NULL) {
        return false;
    }

    // ptr is still here!
    array->data = temp;
    array->capacity += size;

    return true;
}

bool dynarray_dec(DynArray *array, size_t size) {

    if (array == NULL) {
        return false;
    }
    
    if (size  == 0) {
        return true;
    }

    if (size > array->capacity) {
        return false;
    }

    size_t temp_size = array->capacity - size;

    if (temp_size < array->length) {
        return false;
    }

    void *temp = realloc(array->data, temp_size * array->element_size);

    if (temp == NULL) {
        return false;
    }

    // ptr is still here!
    array->data = temp;
    array->capacity -= size;

    return true;
}

// absolute
bool dynarray_setSize(DynArray *array, size_t size) {
    if (array == NULL) {
        return false;
    }

    if (size == 0) {
        return false;
    }

    void *temp = realloc(array->data, size * array->element_size);

    if (temp == NULL) {
        return false;
    }

    array->data = temp;
    array->capacity = size;

    return true;
}

bool dynarray_setSize_safe(DynArray *array, size_t size) {

    if (size < array->length) {
        return false;
    }

    return dynarray_setSize(array, size);
}

// push / pop
bool dynarray_push(DynArray *array, void *value) {

    bool isOk;
    if (array == NULL) {
        return false;
    }

    // make array bigger
    if (array->length >= array->capacity) {
        isOk = dynarray_inc(array, array->capacity);

        if (!isOk) {
            return false;
        }

        array->capacity *= array->capacity;
    }

    array->length++;
    isOk = dynarray_set(array, array->length, value);

    return isOk;
}

bool dynarray_pop(DynArray *array, size_t size) {
    bool isOk;
    if (array == NULL) {
        return false;
    }

    // make array smaller
    isOk =  dynarray_dec(array, size);
    array->length -= size;

    return isOk;
}

bool dynarray_fit(DynArray *array, DynArray *otherArray) {
    
    if (otherArray == NULL) {
        return false;
    }
    
    size_t otherSize = otherArray->capacity;

    if (array->capacity == otherSize) {
        array->capacity = otherSize;
        return true;
    }

    return dynarray_setSize(array, otherSize);
}

bool dynarray_insert(DynArray *array, size_t index, void *value) {
    size_t temp;

    // 1. inc data
    // 2. every index += 1
    // 3. index = value

    if (array->length >= array->capacity) {
        if (!dynarray_inc(array, array->capacity)) {
            return false;
        }
    }

    // shift all data after and index += 1
    size_t length_for = array->length;
    for (size_t i = length_for; i > index; i--) {
        temp = (size_t)dynarray_get(array, i-1);

        dynarray_set(array, i, (void*)temp);
    }

    if (!dynarray_set(array, index, value)) {
        return false;
    }

    array->length++;

    return true;
}

bool dynarray_clear(DynArray *array, void *value) {
    for (size_t i = 0; i < array->length; i++) {
        dynarray_set(array, i, value);
    }
    return true;
}