#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

#include "array_helpers.h"
#include "sort_helpers.h"
#include "sort.h"


static unsigned int min_pos_from(int a[], unsigned int i, unsigned int length) {
    unsigned int min_pos = i;
    for (unsigned int j = i + 1; j < length; ++j) {
        if (!goes_before(a[min_pos],a[j])) {
            min_pos = j;
        }
    }
    return (min_pos);
}

void selection_sort(int a[], unsigned int length) {
    for (unsigned int i = 0u; i < length; ++i) {
        unsigned int min_pos = min_pos_from(a, i, length);
        swap(a, i, min_pos);
    }
}


static void insert(int a[], unsigned int i) {
    /* copiá acá la implementación que hiciste en el ejercicio 1 */
        while (i > 0 && goes_before(a[i], a[i-1])){
        swap(a, (i-1), i);
        i = i-1;
    }
}

void insertion_sort(int a[], unsigned int length) {
    for (unsigned int i = 1u; i < length; ++i) {
        insert(a, i);
    }
}


static unsigned int partition(int a[], unsigned int izq, unsigned int der) {
    /* copiá acá la implementación que hiciste en el ejercicio 3 */
    unsigned int i, j;
    i = izq+1;
    j = der;
    while (i <= j){
    
        
        if (goes_before(a[izq], a[i]) && goes_before(a[j], a[izq])) {
            swap(a, i, j);
        }
        else{
        
            if (goes_before(a[i], a[izq])) {
                i++;
            }
            if (goes_before(a[izq], a[j])) {
                j--;
            }
        
        }
    
    }
    swap(a, izq, j);
    return j;
}

static void quick_sort_rec(int a[], unsigned int izq, unsigned int der) {
    /* copiá acá la implementación que hiciste en el ejercicio 2 */
     unsigned int pivot = partition(a, izq, der);
    if (pivot > izq){             
        quick_sort_rec(a, izq, pivot-1);
    }
    if (pivot < der){             
        quick_sort_rec(a, pivot+1, der);
    }
}

void quick_sort(int a[], unsigned int length) {
    quick_sort_rec(a, 0u, (length == 0u) ? 0u : length - 1u);
}
