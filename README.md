# DynArray
![Version](https://img.shields.io/badge/version-1.0.0-blue)
[![License: GPL-2.0](https://img.shields.io/badge/License-GPL--2.0-blue.svg)](LICENSE)

A fancy C lib designed to make life easier by using dymanic arrays!

Just a very small lib.

## How 2 Use it
You can use the lib by including the `dynarray.h`.

## What are the features?

```c
// ========================
// ===== Core =============
// ========================

DynArray *dynarray_create(size_t element_size, size_t length);
void dynarray_free(DynArray *array);

// ========================
// ===== Modify Size ======
// ========================

    // relative

/*
Increase the size of an array by size_t size
*/
bool dynarray_inc(DynArray *array, size_t size);

/*
Decrease the size of an array by size_t size
*/
bool dynarray_dec(DynArray *array, size_t size);
    
    // absolute

/*
Set the size of an array by size_t size
*/
bool dynarray_setSize(DynArray *array, size_t size);

/*
safer dynarray_setSize ...
*/
bool dynarray_setSize_safe(DynArray *array, size_t size);

    // add data at the end of array (array_size gets bigger!)

/*
Push any value at the array
*/
bool dynarray_push(DynArray *array, void *value);

/*
Pop any value down of array
*/
bool dynarray_pop(DynArray *array, size_t size);

    // new DynArray size = otherArray size

/*
Fit the size_t size of an array to the size_t size of array2
*/
bool dynarray_fit(DynArray *array, DynArray *otherArray);

/*
Set *value at any possible index of the array
*/
bool dynarray_insert(DynArray *array, size_t index, void *value);

/*
Replace every value with void *value in array
*/
bool dynarray_clear(DynArray *array, void *value);

// ========================
// ===== Access ===========
// ========================

/*
Get any value from possible index from array
*/
size_t dynarray_get(DynArray *array, size_t index);

/*
Is array set? (is array at index set to value?)
*/
bool dynarray_set(DynArray *array, size_t index, void *value);

// ========================
// ===== Info =============
// ========================

/*
Get length of array back
*/
size_t dynarray_length(DynArray *array);

/*
Get capacity of array back
*/
size_t dynarray_capacity(DynArray *array);

/*
Get element size of array back
*/
size_t dynarray_elementSize(DynArray *array);

/*
Get data of array back
*/
void *dynarray_data(DynArray *array);

/*
Get size of array back
*/
size_t size(DynArray *array);
```

## License?
License is set to GPL-2.0, see License file for more information.
