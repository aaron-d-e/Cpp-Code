/**
* file: proj4-ItemInfo.cpp
 * author: Aaron Evans
 * course: CSI 1440
 * assignment: project 4
 * due date: 2/23/2025
 *
 * date modified:  2/25/2025
 *    - file created
 * date modified: 2/26/2025
 *    - worked on functionalites
 * date modified: 3/5/2024
 *    - added correct item names
 *
 * This class provides a container for products contained in a produce service dump.
 */

 #include "proj4-ItemInfo.h"
 #include <iostream>
 using namespace std;
 int JSONItem = 0;

double stuCstrToDbl(const char *str){ // tested and works
    int count = 0;
    int sign = 1;
    double power;
    double digit;

    if (str[count] == '-') { //if a negative is found then multiply -1
        sign = -1;
        count++;
    }
    for (digit = 0; str[count] >= '0' && str[count] <= '9'; count++) { //for loop until '.' is found
        digit = 10 * digit + str[count] - '0';
    }
    if (str[count] == '.') { //add count to 'skip' '.'
        count++;
    }
    for (power = 1; str[count] >= '0' && str[count] <= '9'; count++) {// for loop for after '.' which then divided by powers of 10
        digit = 10 * digit + str[count] - '0';
        power *= 10;
    }

    return sign*digit/power;
}

void stuDblToCstr(char *cstr, double num){ //tested and works with minimal value error
    int count = 0;
    int truncate = 2; //amount of values after the decimal point
    int whole;
    double decimal;
    whole = num;
    decimal = num - whole;

    while (whole > 0) {
        cstr[count] = (whole % 10) + '0';
        whole /= 10;
        count++;
    }

    char* temp = new char[count];
    for (int i = 0; i < count; i++) {
        temp[i] = cstr[count - i - 1];
    }
    for (int i = 0; i < count; i++) {
        cstr[i] = temp[i];
    }
    delete[] temp;
    cstr[count] = '.'; // append '.' to cstr
    count++;

    for (int i = 0; i < truncate; i++){
        int temp;
        decimal *= 10;
        temp = decimal;
        cstr[count] = (temp % 10) + '0';

        count++;
    }

    cstr[count] = '\0';
}

void stuCstrCpy(char *dest, const char *src){
    while (*src != '\0') {
        *dest = *src;
        dest++;
        src++;
    }
    *dest = '\0';

}

int stuCstrLen(const char *src){ //tested and works

    int count = 0;
    while (src[count] != '\0') {
        count++;
    }
    return count;
}

ostream& printCString(ostream &out, const char *src){ //tested and works
    int size = stuCstrLen(src);
    for (int i = 0; i < size; i++) {
        out.put(src[i]);
    }
    return out;
}

void ItemInfo::setItemId(const char *num) { //tested and works
    itemId = stuCstrToDbl(num);
}

void ItemInfo::setDescription(const char *cstr) { //tested and works
    int size = stuCstrLen(cstr);

    for (int i = 0; i < size; i++) {
        description[i] = cstr[i];
    }
    description[size] = '\0';
}

void ItemInfo::setManCost(const char *num) { //tested and works
    manCost = stuCstrToDbl(num);
}

void ItemInfo::setSellPrice(const char *num) { //tested and works
    sellPrice = stuCstrToDbl(num);
}

int ItemInfo::getItemId() { //tested and works
    return itemId;
}

double ItemInfo::getManCost() { //tested and works
    return manCost;
}

double ItemInfo::getSellPrice() { //tested and works
    return sellPrice;
}

const char* ItemInfo::getDescription() { //tested and works
    return description;
}

void ItemInfo::toAmazonJSON(ostream &out) { //works
    char write[20];
    if (JSONItem == 0) {
        printCString(out, "\t\"firstItem\": {");
        out.put('\n');
        JSONItem++;
    }
    else if (JSONItem == 1) {
        printCString(out, "\t\"secondItem\": {");
        out.put('\n');
        JSONItem++;
    }
    else if (JSONItem == 2) {
        printCString(out, "\t\"thirdItem\": {");
        out.put('\n');
        JSONItem++;
    }
    else if (JSONItem == 3) {
        printCString(out, "\t\"fourthItem\": {");
        out.put('\n');
        JSONItem++;
    }
    else if (JSONItem == 4) {
        printCString(out, "\t\"fifthItem\": {");
        out.put('\n');
        JSONItem++;
    }
    else {
        printCString(out, "\t\"Item5+\": {");
        out.put('\n');
        JSONItem++;
    }

    printCString(cout, "\t\t\"itemId\": ");
    stuDblToCstr(write, itemId);
    for (int i = 0; write[i] != '.'; i++) {
        out.put(write[i]);
    }
    out.put(',');
    out.put('\n');

    printCString(cout, "\t\t\"description\": ");
    out.put('\"');
    printCString(cout, description);
    out.put('\"');
    out.put(',');
    out.put('\n');

    printCString(cout, "\t\t\"manPrice\": ");
    stuDblToCstr(write, manCost);
    printCString(out, write);
    out.put(',');
    out.put('\n');

    printCString(cout, "\t\t\"sellPrice\": ");
    stuDblToCstr(write, sellPrice);
    printCString(out, write);
    out.put('\n');

    printCString(cout, "\t},");
    out.put('\n');
}
void ItemInfo::displayItemInfo(ostream &out) { //FIX ME
    char write[20];
    stuDblToCstr(write, itemId);
    printCString(out, "Item ID: ");
    for (int i = 0; write[i] != '.'; i++) {
        out.put(write[i]);
    }
    out.put('\n');

    printCString(out, "Description: ");
    printCString(out, description);
    out.put('\n');

    printCString(out, "Man Cost: ");
    stuDblToCstr(write, manCost);
    printCString(out, write);
    out.put('\n');

    printCString(out, "Sell Price: ");
    stuDblToCstr(write, sellPrice);
    printCString(out, write);
    out.put('\n');

    printCString(out, "Profit: ");
    stuDblToCstr(write, calcProfit());
    printCString(out, write);
    out.put('\n');

}

double ItemInfo::calcProfit() {
    double profit = sellPrice - manCost;
    return profit;
};



















