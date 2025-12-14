// core.c
#include "../dynarray.h"

DynArray *dynarray_create(size_t element_size, size_t length) {
    
    // 32 Bytes
    DynArray *array = malloc(sizeof(DynArray));

    if (array == NULL) {

        return NULL;
    }

    array->length = 0;

    if (element_size == 0) {
        goto err_norm;
    }

    array->element_size = element_size;

    array->capacity = length;

    array->data = malloc(element_size * length);

    if (array->data == NULL) {
        goto err_data;
    }

    return array;

    err_data:
        free(array->data);
    err_norm:
        free(array);
    return NULL; 
}

void dynarray_free(DynArray *array) {
    free(array->data);
    free(array);
}