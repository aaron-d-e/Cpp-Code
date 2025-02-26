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

int main(){

    ItemInfo item;
    char* test = new char[6];
    test[0] = '1';
    test[1] = '2';
    test[2] = '.';
    test[3] = '4';
    test[4] = '5';
    test[5] = '\0';
    char* test2 = new char[6];
    char* descriptiontest = new char[9];
    descriptiontest[0] = 'B';
    descriptiontest[1] = 'o';
    descriptiontest[2] = 'o';
    descriptiontest[3] = 'k';
    descriptiontest[4] = 'B';
    descriptiontest[5] = 'y';
    descriptiontest[6] = 'R';
    descriptiontest[7] = 'M';
    descriptiontest[8] = '\0';


    item.setItemId(test);
    item.setDescription(descriptiontest);
    item.setManCost(test);
    item.setSellPrice(test);

    cout << "item ID" << endl;
    cout << item.getItemId() << endl << endl;

    cout << "item description" << endl;
    cout << item.getDescription() << endl << endl;

    cout << "item manCost" << endl;
    cout << item.getManCost() << endl << endl;

    cout << "item sellPrice" << endl;
    cout << item.getSellPrice() << endl << endl;


    cout << "strtlen test" << endl;
    cout << stuCstrLen(test) << endl << endl;;

    cout << "strtodbl test" << endl;
    cout << stuCstrToDbl(test) << endl << endl;

    cout << "dbltostr test" << endl;
    stuDblToCstr(test2, 123.23);
    cout << endl;

    cout << "printcstring test" << endl;
    printCString(cout, descriptiontest);
    cout << endl;

    delete[] test;
    delete[] test2;

    return 0;
}