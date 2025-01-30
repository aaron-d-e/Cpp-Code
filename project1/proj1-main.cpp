/**
 * file: proj1-main.cpp
 * author: Aaron Evans
 * course: CSI 1440
 * assignment: project 1
 * due date: 1/26/2025
 *
 * date modified: 1/23/2025
 * - began project
 *
 * date modified: 1/25/2025
 * - fixed bugs and finished project
*/

#include <iostream>
#include <fstream>
#include <iomanip>
#include "proj1-person.h"
using namespace std;

const int peopleCount = 25;

int main(){

    Person thePeople[peopleCount];
    Person *referenceToThePeople[peopleCount];
    ifstream inFile;
    string filename = "people.txt";
    string search;
    string line;
    //Person user;
    int count = 0;

    //Person temp;
    inFile.open(filename);

    while(inFile){

        if(count > 24){ //acounts for if there's too many people
            cout << "Too Many People" << endl;
            exit(1);
        }

        Person user;
        getAPersonFromStream(inFile, &user); // get Person into user
        thePeople[count] = user; // enters user into array


        count++;

    }

    inFile.close();

    for(int i = 0; i < count; i++){
        referenceToThePeople[i] = &thePeople[i];
    }


    sortPersonArrayByAge(referenceToThePeople, count); // sort by age
    
    cout << "Now displaying people sorted by age." << endl;
    for(int i = 0; i < count; i++){
       displayAPerson(cout, referenceToThePeople[i]);
    }


    sortPersonArrayByName(referenceToThePeople, count); // sort by name

    cout << "Now displaying people sorted by name." << endl;
    for(int i = 0; i < count; i++){
       displayAPerson(cout, referenceToThePeople[i]);
    }


    cout << "Enter a name you would like to search(type 'no more' to quit): "; // linear search
    getline(cin, search);
    while(search != "no more"){
        if(findAPerson(referenceToThePeople, count, search) == nullptr){
            cout << "No Match" << endl;
        }
        else{
            displayAPerson(cout, findAPerson(referenceToThePeople, count, search)); 
        }
        cout << "Enter another name(type 'no more' to quit): ";
        getline(cin, search);
    }

return 0;

};