/**
 * file: proj1-testmain.cpp
 * author: Aaron Evans
 * course: CSI 1440
 * assignment: project 1
 * due date: 1/26/2025
 *
 * date modified: 1/25/2025
 * - began test main
 *
 * date modified: 1/25/2025
 * - created test cases
*/

#include <iostream>
#include <sstream>
#include "proj1-person.h"

using namespace std;

const int peopleCount = 5;

int main(){

Person user1 = {"Nathan Austin", 31};
Person user2 = {"Bob Smith", 19};
Person user3 = {"Lucy Stephens", 18};
Person user4 = {"Meghan Lynn Padilla", 20};
Person user5 = {"Shakira", 42};

Person user6 = {"Aaron Evans", 19};
Person user7 = {"Julio Martinez", 21};
Person user8 = {"Erick Martinez", 18};
Person user9 = {"Luke Tanner", 23};
Person user0 = {"Jackson Hill", 19};

Person userA = {"Professor Aars", 21};
Person userB = {"Professor Booth", 20};
Person userC = {"Professor John", 22};
Person userD = {"Aaron Evans", 19};
Person userE = {"Visual Studio Code", 23};

Person peopleTest1[peopleCount] = {user1, user2, user3, user4, user5};
Person *referenceTest1[peopleCount];

for(int i = 0; i < 5; i++){
    referenceTest1[i] = &peopleTest1[i];
}


cout << "Starting Test 1...(Sorting by name, then age)" << endl;

sortPersonArrayByName(referenceTest1, 5);
cout << "People sorted by name." << endl;
for(int i = 0; i < 5; i++){
    displayAPerson(cout, referenceTest1[i]);
}

sortPersonArrayByAge(referenceTest1, 5);
cout << "People sorted by age." << endl;
for(int i = 0; i < 5; i++){
    displayAPerson(cout, referenceTest1[i]);
}


cout << "Linear Search for test array 1. Enter a name to search(type 'no more' to move on to next test): ";
string input1;
getline(cin, input1);
while(input1 != "no more"){

       if(findAPerson(referenceTest1, 5, input1) == nullptr){
             cout << "No Match" << endl;
         }
         else{
             displayAPerson(cout, findAPerson(referenceTest1, 5, input1)); 
         }
         cout << "Enter another name(type 'no more' to move on): ";
         getline(cin, input1);
     }


Person peopleTest2[peopleCount] = {user6, user7, user8, user9, user0};
Person *referenceTest2[peopleCount];

for(int i = 0; i < 5; i++){
    referenceTest2[i] = &peopleTest2[i];
}


cout << "Starting Test 2...(Sorting by name alone)" << endl;

sortPersonArrayByName(referenceTest2, 5);
for(int i = 0; i < 5; i++){
    displayAPerson(cout, referenceTest2[i]);
}

cout << "Linear Search for test array 2. Enter a name to search(type 'no more' to move on to next test): ";
string input2;
getline(cin, input2);
while(input2 != "no more"){

       if(findAPerson(referenceTest2, 5, input2) == nullptr){
             cout << "No Match" << endl;
         }
         else{
             displayAPerson(cout, findAPerson(referenceTest2, 5, input2)); 
         }
         cout << "Enter another name(type 'no more' to move on): ";
         getline(cin, input2);
     }


Person peopleTest3[peopleCount] = {userA, userB, userC, userD, userE};
Person *referenceTest3[peopleCount];

for(int i = 0; i < 5; i++){
    referenceTest3[i] = &peopleTest3[i];
}


cout << "Starting Test 3...(Sorting by age alone)" << endl;

sortPersonArrayByAge(referenceTest3, 5);
for(int i = 0; i < 5; i++){
    displayAPerson(cout, referenceTest3[i]);
}

cout << "Linear Search for test array 3. Enter a name to search(type 'no more' to move on to next test): ";
string input3;
getline(cin, input3);
while(input3 != "no more"){

       if(findAPerson(referenceTest3, 5, input3) == nullptr){
             cout << "No Match" << endl;
         }
         else{
             displayAPerson(cout, findAPerson(referenceTest3, 5, input3)); 
         }
         cout << "Enter another name(type 'no more' to move on): ";
         getline(cin, input3);
     }

    string line;
    stringstream ss;
    Person people[peopleCount];
    Person* reference[peopleCount];
    int count = 0;

    ss << "Aaron Evans, 19 \n";
    ss << "Julio Martinez, 19 \n";
    ss << "Erick Martinez, 18 \n";
    ss << "Jackson Hill, 19 \n";
    ss << "Visual Studio Code, 25 \n";

    cout << "Starting Test 4...(Testing getting people from stream)" << endl;

    while(getline(ss, line)){
        Person user;
        stringstream stream(line);
        getAPersonFromStream(stream, &user);
        
        people[count] = user;

        
        ++count;
    }

    ss.clear();
    ss.str("");

    for(int i = 0; i < count; i++){
        reference[i] = &people[i];
    }

    for(int i = 0; i < count; i++){
        displayAPerson(cout, reference[i]);
    }

    cout << "End of all test...Shutting down." << endl;


    return 0;
}