/* First, the standard lib includes, alphabetically ordered */
#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

/* Maximum allowed length of the array */
#define MAX_SIZE 100000

unsigned int array_from_file(int array[], unsigned int max_size) {
       int length;
       int elem;
       max_size = max_size;
       printf("Ingrese la cantidad de elementos del arreglo: ");
       scanf("%d", &length);
       for (int i = 0; i<length;i++){
            printf("Ingrese el elemento en la posicion %d: ", i);
            scanf("%d", &elem);
            array[i] = elem;
       }
       return length;

}

void array_dump(int a[], unsigned int length) {
    a = a;
    int dump[length];
    for (unsigned int i = 0; i<length ; i++){
        dump[i] = a[i];
        printf("%d ", dump[i]);
    }
    printf("\n");
}


int main() {
    /* create an array of MAX_SIZE elements */
    int array[MAX_SIZE];
    
    /* parse the file to fill the array and obtain the actual length */
    unsigned int length = array_from_file(array, MAX_SIZE);

    /*dumping the array*/
    array_dump(array, length);
    
    return EXIT_SUCCESS;
}
