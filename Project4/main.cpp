/**
* file: proj4-main.cpp
 * author: Aaron Evans
 * course: CSI 1440
 * assignment: project 4
 * due date: 2/23/2025
 *
 * date modified:  2/25/2025
 *    - file created
 * date modified: 3/2/2025
 *    - finished main driver
 * date modified: 3/5/2024
 *    - added correct file name and finished project
 * This file is the main driver for the program
 */
#include "proj4-ItemInfo.h"
#include <iostream>
#include <fstream>
using namespace std;



void resizeArray(ItemInfo**);
void sortArray(ItemInfo*, int);
void printTopFive(ItemInfo*, int, ostream&);
int CAPACITY = 2;

int main() {
    ifstream inFile;
    ItemInfo* arr = new ItemInfo[CAPACITY];
    char buffer[500];
    int count = 0;
    char ch;
    int arrayItem = 0;


    inFile.open("proj4-productServices.csv");
    if (!inFile.is_open()) {
        printCString(cout, "Error.");
        exit(1);
    }
    int num = 0;
    while (inFile) {
        switch (num) {
            case 0:
                while ((ch = inFile.get()) != ',' ) {
                    buffer[count] = ch;
                    count++;
                }
                buffer[count] = '\0';
                arr[arrayItem].setItemId(buffer);
                count = 0;
                num++;
                break;
            case 1:
                while ((ch = inFile.get()) != ',') {
                    buffer[count] = ch;
                    count++;
                }
                buffer[count] = '\0';
                arr[arrayItem].setDescription(buffer);
                count = 0;
                num++;
                break;
            case 2:
                while ((ch = inFile.get()) != ',') {
                    buffer[count] = ch;
                    count++;
                }
                buffer[count] = '\0';
                arr[arrayItem].setManCost(buffer);
                count = 0;
                num++;
                break;
            case 3:
                while ((ch = inFile.get()) != '\n' && ch != EOF) {
                    buffer[count] = ch;
                    count++;
                }
                buffer[count] = '\0';
                arr[arrayItem].setSellPrice(buffer);
                count = 0;
                num = 0;
                arrayItem++;
                break;
            default:
                printCString(cout, "Does Not Work. Exiting");
                exit(1);
        }
        if (arrayItem == CAPACITY) {
            resizeArray(&arr);
        }

    }

    printTopFive(arr, arrayItem, cout);

    delete[] arr;
    return 0;
}

void resizeArray(ItemInfo** arr) {
    CAPACITY += 2;
    ItemInfo* temp = new ItemInfo[CAPACITY];
    for (int i = 0; i < CAPACITY - 2; i++) {
        temp[i] = (*arr)[i];
    }
    delete[] *arr;
    *arr = temp;
}

void sortArray(ItemInfo* arr, int size) {
    ItemInfo temp;
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j].calcProfit() < arr[j+1].calcProfit() ) {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

void printTopFive(ItemInfo* arr, int size, ostream& out) {
    printCString(cout, "\"AaronStore\": [");
    out.put('\n');

    for (int i = 0; (i < size) && (i < 5) ; i++) {
        arr[i].toAmazonJSON(cout);
    }
    out.put(']');
}

