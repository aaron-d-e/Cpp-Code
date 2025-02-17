#include "proj2-arrayFunctions.h"
#include <fstream>


int main(){

    ifstream inFile;
    int size;
    string line;
    string filename = "arrays.txt";

    inFile.open(filename);

    if(!inFile.is_open()){
        cout << "File failed to open." << endl;
        return 1;
    }
    

    while(inFile.good()){

        inFile >> size; //reads size of array

        int *arr = new int[size]; //creates dynamic array with size grabbed
        int num;

        for(int i = 0; i < size; i++){ //reads the next n numbers and adds to allocated array;
            inFile >> num;
            arr[i] = num;
        }
    
    bubbleSort(arr, size);

    cout << "Largest Value: " << largestValue(arr, size) << endl;
    cout << "Smallest Value: " << smallestValue(arr, size) << endl;
    cout << "Average Value: " << averageValue(arr, size) << endl;
    cout << "Median Value: " << medianValue(arr, size) << endl;

    for(int i = 0; i < size; i++){
        cout << arr[i] << endl;
    }


    delete[] arr; //deletes allocated array
    }


    inFile.close();


    return 0;
}