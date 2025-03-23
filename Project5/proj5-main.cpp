#include <iostream>
#include <fstream>
#include <string>
#include "proj5-BUAthleteList.h"
using namespace std;

int main(){

    BUAthleteList list;
    ifstream NCAAFile;
    ifstream BUFile;
    string str;
    int id;
    string name;
    string decision;
    string school;
    int size = 0;
    int searchID;
    string pos;
    int eval;

    NCAAFile.open("proj5-NCAAAthlete.csv");

    if (!NCAAFile.is_open()) {
        cout << "Failed to open NCAAFile." << endl;
        exit(1);
    }

    NCAAFile >> id;
    while (NCAAFile) {
        NCAAFile.ignore();
        getline(NCAAFile, name, ',' );
        getline(NCAAFile, decision, ',');
        NCAAFile >> school;
        NCAAFile.ignore();
        list.addNCAAAthlete(id, name, decision, school);
        size++;

        NCAAFile >> id;
    }
    NCAAFile.close();

    list.sortByID();

    BUFile.open("proj5-BUAthlete.csv");
    if (!BUFile.is_open()) {
        cout << "Failed to open BUFile." << endl;
        exit(1);
    }


    while (BUFile >> searchID) {
        int index;
        BUFile.ignore();
        getline(BUFile, pos, ',');
        BUFile >> eval;


        index = list.findById(searchID);
        if (index != -1) {
            list.setBUInfo(index, strToPosition(pos) , eval);
        }
        else {
            cout << "Player: " << searchID << "does not exist." << endl;
        }

    }


    cout << list.toString();

    return 0;
}
