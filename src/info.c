#include "../dynarray.h"

size_t dynarray_length(DynArray *array) {
    return array->length;
}

size_t dynarray_totalCapacity(DynArray *array) {
    return array->capacity;
}