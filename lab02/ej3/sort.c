#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

#include "array_helpers.h"
#include "sort_helpers.h"
#include "sort.h"

int vabs(double numero)
{
    if (numero < 0)
    {
        return numero * -1;
    }
    return numero;
}

static unsigned int partition(int a[], unsigned int izq, unsigned int der) {
    unsigned int i, j;
    i = izq+1;
    j = der;
    while (i <= j){
    
        
        if ((vabs(a[i]) > vabs(a[izq])) && (vabs(a[j]) < vabs(a[izq]))) {
            swap(a, i, j);
        }
        else{
        
            if (vabs(a[i]) <= vabs(a[izq])) {
                i++;
            }
            if (vabs(a[j]) >= vabs(a[izq])) {
                j--;
            }
        
        }
    
    }
    swap(a, izq, j);
    return j;
    
}

static void quick_sort_rec(int a[], unsigned int izq, unsigned int der) {
    unsigned int pivot = partition(a, izq, der);
    if (pivot > izq){             
        quick_sort_rec(a, izq, pivot-1);
    }
    if (pivot < der){             
        quick_sort_rec(a, pivot+1, der);
    }
}


void quick_sort(int a[], unsigned int length) {
    quick_sort_rec(a, 0, (length == 0) ? 0 : length - 1);
}

