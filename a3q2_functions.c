#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "a3q2_header.h"

//Global variable for heap size
int size = 20;
/*
 * The downHeap function performs the downheap algorithm.
 * The key at the passed position is swapped with the key of it's child with the smallest value.
 * If the key is smaller, than both of it's children's keys then no swap happens.
 * After swap, the downHeap is called again to the new position of the swapped key and it terminates when it's value is smaller than both children.
*/
void downHeap(int key[20], int pos, int array[20][10]){

    while (isParent(pos)) {
        int left = 2 * pos + 1;
        int right = 2 * pos + 2;
        int larger = left;

        // Find the larger child
        if (right < size && key[right] > key[left]) {
            larger = right;
        }

        // If the parent is >= to the larger child, break
        if (key[pos] >= key[larger]) {
            break;
        }

        // Swap the parent with the larger child
        swap(pos, larger, key, array);
        pos = larger;
    }
}


// The isParent function returns true if the passed position has a child or false if there's no child
bool isParent(int keyPos){
   return (2 * keyPos + 1) < size;
}

// The swap function swaps 2 rows in the 2D array and the key array. It receives the position of the 2 rows to be swapped, the key array, and the 2D array in its arguements.
void swap(int key1Pos, int key2Pos, int key[20], int array[20][10]){
    // Swap keys
    int tempKey = key[key1Pos];
    key[key1Pos] = key[key2Pos];
    key[key2Pos] = tempKey;

    // Swap rows in the array
    for (int i = 0; i < 10; i++) {
        int temp = array[key1Pos][i];
        array[key1Pos][i] = array[key2Pos][i];
        array[key2Pos][i] = temp;
}
}
