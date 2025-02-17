#include "proj2-arrayFunctions.h"

void bubbleSort(int *array, int size){
    for(int i = 0; i < size; i++){
        for(int j = 0; j < size - i - 1; j++){
            if(array[j] > array[j+1]){
                swap(array[j], array[j+1]);
            }
        }
    }
}

int largestValue(int *array, int size){
    int max = array[0];
    for(int i = 0; i < size; i++){
        if(array[i] > max){
            max = array[i];
        }
    }
    return max;
}

int smallestValue(int *array, int size){
    int min = array[0];
    for(int i = 0; i < size; i++){
        if(array[i] < min){
            min = array[i];
        }
    }
    return min;
}

double averageValue(int *array, int size){
    double sum = 0;
    for(int i = 0; i < size; i++){
        sum += array[i];
    }
    return sum / size;
}

int medianValue(int *array, int size){
    bubbleSort(array, size);
        return array[size / 2];   
}