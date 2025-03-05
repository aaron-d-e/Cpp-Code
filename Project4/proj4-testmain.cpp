/**
* file: proj4-testmain.cpp
 * author: Aaron Evans
 * course: CSI 1440
 * assignment: project 4
 * due date: 2/23/2025
 *
 * date modified:  2/25/2025
 *    - file created
 *
 * This file acts as a testing driver
 */

 #include "proj4-ItemInfo.h"
 #include <iostream>
 using namespace std;

void resizeArray(ItemInfo**);
void sortArray(ItemInfo*, int);
void printTopFive(ItemInfo*, int, ostream&);

int CAPACITY = 2;

int main(){

    ItemInfo items[5];
    char test[40];

    items[0].setItemId("12345");
    items[0].setDescription("BookByRM");
    items[0].setManCost("1.25");
    items[0].setSellPrice("19.99");

    cout.put('\n');
    printCString(cout, "Testing Display Info: \n");
    items[0].displayItemInfo(cout);
    printCString(cout, "\nTesting JSON PRINT: \n");
    items[0].toAmazonJSON(cout);

    printCString(cout, "\nTesting Double To String: \n");
    stuDblToCstr(test, 12345);
    printCString(cout, test);
    cout.put('\n');

    printCString(cout, "\nTesting String Copy: \n");
    stuCstrCpy(test, "ABCDEFGH");
    printCString(cout, test);
    cout.put('\n');

    //START OF ITEM 2;

    items[1].setItemId("67890");
    items[1].setDescription("LaptopByTech");
    items[1].setManCost("599.99");
    items[1].setSellPrice("1299.99");

    cout.put('\n');
    printCString(cout, "Testing Display Info: \n");
    items[1].displayItemInfo(cout);
    printCString(cout, "\nTesting JSON PRINT: \n");
    items[1].toAmazonJSON(cout);

    printCString(cout, "\nTesting Double To String: \n");
    stuDblToCstr(test, 67890);
    printCString(cout, test);
    cout.put('\n');

    printCString(cout, "\nTesting String Copy: \n");
    stuCstrCpy(test, "XYZ98765");
    printCString(cout, test);
    cout.put('\n');

    //START OF TEST 3;

    items[2].setItemId("54321");
    items[2].setDescription("HeadphonesBySoundCo");
    items[2].setManCost("49.99");
    items[2].setSellPrice("129.99");

    cout.put('\n');
    printCString(cout, "Testing Display Info: \n");
    items[2].displayItemInfo(cout);
    printCString(cout, "\nTesting JSON PRINT: \n");
    items[2].toAmazonJSON(cout);

    printCString(cout, "\nTesting Double To String: \n");
    stuDblToCstr(test, 54321);
    printCString(cout, test);
    cout.put('\n');

    printCString(cout, "\nTesting String Copy: \n");
    stuCstrCpy(test, "BASSBOOST");
    printCString(cout, test);
    cout.put('\n');

    //START OF TEST 4;

    items[3].setItemId("98765");
    items[3].setDescription("SmartwatchByFit");
    items[3].setManCost("149.99");
    items[3].setSellPrice("299.99");

    cout.put('\n');
    printCString(cout, "Testing Display Info: \n");
    items[3].displayItemInfo(cout);
    printCString(cout, "\nTesting JSON PRINT: \n");
    items[3].toAmazonJSON(cout);

    printCString(cout, "\nTesting Double To String: \n");
    stuDblToCstr(test, 98765);
    printCString(cout, test);
    cout.put('\n');

    printCString(cout, "\nTesting String Copy: \n");
    stuCstrCpy(test, "WATCHMODE");
    printCString(cout, test);
    cout.put('\n');

    //START OF TEST 5;

    items[4].setItemId("24680");
    items[4].setDescription("TabletByMobiTech");
    items[4].setManCost("199.99");
    items[4].setSellPrice("499.99");

    cout.put('\n');
    printCString(cout, "Testing Display Info: \n");
    items[4].displayItemInfo(cout);
    printCString(cout, "\nTesting JSON PRINT: \n");
    items[4].toAmazonJSON(cout);

    printCString(cout, "\nTesting Double To String: \n");
    stuDblToCstr(test, 24680);
    printCString(cout, test);
    cout.put('\n');

    printCString(cout, "\nTesting String Copy: \n");
    stuCstrCpy(test, "ANDROIDTAB");
    printCString(cout, test);
    cout.put('\n');

    sortArray(items, 5);
    printTopFive(items, 5, cout);


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
