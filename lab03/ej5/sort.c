/*
  @file sort.c
  @brief sort functions implementation
*/

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include "helpers.h"
#include "sort.h"
#include "player.h"

bool goes_before(player_t x, player_t y){
    if (x->rank <= y->rank){
        return true;
    }
    return false;
}

bool array_is_sorted(player_t atp[], unsigned int length) {
    unsigned int i = 1u;
    while (i < length && goes_before(atp[i - 1u], atp[i])) {
        i++;
    }
    return (i == length);
}

void sort(player_t a[], unsigned int length) {
        for (unsigned int i = 0; i<length-1 ;i++){
            player_t min = a[i];
            int pos = i;
            for (unsigned int j = i+1; j<length ;j++){
                if (goes_before(a[j], min)){
                    min = a[j];
                    pos = j; 
                }
            }
        array_swap(a, pos, i);
    }
}

