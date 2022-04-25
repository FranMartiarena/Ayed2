#include "array_helpers.h"
#include <assert.h>

#include <stdio.h>
#include <stdlib.h>

unsigned int array_from_file(int array[], unsigned int max_size, const char *filepath) {
        max_size = max_size;
        int number;
        int counter = 0;
        unsigned int length;
        FILE * fp;
        fp = fopen (filepath, "r");
        while (1)
        {
            
            if (fscanf(fp, "%d", &number) != 1){
                break;
            }        // file finished or there was an error
            if (counter == 0){
                length = number;    
            }
            else{
                array[counter-1] = number; 
            }
            counter++;
        }
        
        fclose(fp);
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
    mybool var = array_is_sorted(a, length);
    
    if (var == true){
        printf("El arreglo esta ordenado.\n ");
    }
    else{
        printf("El arreglo no esta ordenado.\n ");
    }
}

mybool array_is_sorted(int a[], unsigned int length){

    for (unsigned int i = 0; i < length-1; i++){
        if (a[i] > a[i+1]){
            return false;
        }
    
    }
    return true;
    
}
