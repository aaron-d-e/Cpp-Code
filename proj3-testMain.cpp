#include "proj3-MyString.h"
#include <iostream>
#include <sstream>
using namespace std;

int main(){

    MyString string1test1("This is String 1.");
    MyString string2test1("This is String 1.");
    MyString getlinetest;

    MyString PlusTest1;
    MyString PlusTest2;

    cout << "Starting Test One..." << endl;

    cout << "Comparison Test with String 1 and 2" << endl;
    cout << boolalpha << (string1test1 == string2test1) << endl;

    PlusTest1 = string1test1 + string2test1;
    cout << "Plus Operator Test: " << endl;
    cout << PlusTest1 << endl;

    string1test1 += string2test1;

    cout << "Plus Equal Operator Test: " << endl;
    cout << string1test1 << endl;

    istringstream teststream("Professor Aars Project 3");
    cout << "Getline Test" << endl;
    getlinetest.getline(teststream, '\n');
    cout << getlinetest << endl;



    MyString string5test1("The quick brown fox.");
    MyString string6test1("jumps over the lazy dog.");
    MyString lengthTest;

    cout << "Starting Test Two..." << endl;

    // Assignment Operator Test
    string5test1 = string6test1;
    cout << "Assignment Test: " << endl;
    cout << string5test1 << endl;

    // Test the += operator again
    string5test1 += " And runs away.";
    cout << "Plus Equal Operator Test: " << endl;
    cout << string5test1 << endl;

    // Comparison Test for equality
    cout << "Comparison Test with String 5 and 6" << endl;
    cout << boolalpha << (string5test1 == string6test1) << endl;

    // Length Test (assuming your MyString class has a length method)
    cout << "Length Test for String 5: " << endl;
    cout << "Length: " << string5test1.length() << endl;



    return 0;
}