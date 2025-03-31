/**
* file: proj6-modularMain3.cpp
* author: Aaron Evans
* course: CSI 1440
* assignment: project 6
* due date: 3/30/2025
*
* date modified: 3/30/2025
* - started and finished the program
* - felt cool because i started learning neovim
*/

#include <iostream>
#include <fstream>
using namespace std;

const int PLIST_SIZE = 10;

struct Person{
	string name;
	int age;
};
/**
* readPerson
*
* This function reads name and age from input
*
* Parameters:
* in: istream
* p: reference to Person
*
* Output:
* return: void
* reference parameters: none
* stream: none
*/
void readPerson(istream& in, Person& p){
	getline(in, p.name);
	cin >> p.age;
}
/**
* writePerson
*
* This function outputs name and age to stream
*
* Parameters:
* out: ostream
* p: reference to Person
*
* Output:
* return: void
* reference parameters: none
* stream: none
*/
void writePerson(ostream &out, Person& p){
	out << p.name << endl;
	out << p.age << endl;
}
/**
* requestInfo
*
* This function prints msg to stream
*
* Parameters:
* out: ostream
* msg: string
*
* Output:
* return: void
* reference parameters: none
* stream: none
*/
void requestInfo(ostream &out, string msg){
	out << msg << endl;
}
/**
* readAgain
*
* This function reads the choice from user again
*
* Parameters:
* out: ostream
* in: istream
*
* Output:
* return: string
* reference parameters: none
* stream: none
*/
string readAgain(ostream &out, istream &in){
	string choice;

	out << "Do you want to read in another person (yes/no)? " << endl;
	in >> choice;
	in.ignore(3, '\n');

	return choice;
}

struct Customer{
	string name;
	int age;
	double shippingRate = 5.0;
};
/*
* readCustomer
*
* This function reads customer info
*
* Parameters:
* in: istream
* c: reference to Customer
*
* Output:
* return: void
* reference parameters: none
* stream: none
*/
void readCustomer(istream &in, Customer& c){
	getline(in, c.name);
	in >> c.age;
	in >> c.shippingRate;
	in.ignore(3, '\n');
}
/**
* writeCustomer
*
* This function writes customer to stream
*
* Parameters:
* out: ostream
* c: reference to Customer
*
* Output:
* return: void
* reference parameters: none
* stream: none
*/
void writeCustomer(ostream &out, Customer& c){
	out << c.name << endl;
	out << c.age << endl;
	out << c.shippingRate << endl;
}
/**
* findPerson
*
* This function finds person from array
*
* Parameters:
* pList[]: Person array
* name: string
*
* Output:
* return: int
* reference parameters: none
* stream: none
*/
int findPerson(Person pList[], string name){
	int pos = -1, index = 0;
	while(pos == -1 && index < PLIST_SIZE){
		if(pList[index].name == name){
			pos = index;
		}
		index++;
	}

	return pos;
}
/**
* findCustomer
*
* This function finds Customer from array
*
* Parameters:
* pList[]: Customer array
* name: string
*
* Output:
* return: int
* reference parameters: none
* stream: none
*/
int findCustomer(Customer pList[], string name){
	int pos = -1, index = 0;

	while(pos == -1 && index < PLIST_SIZE){
		if(pList[index].name == name){
			pos = index;
		}
		index++;
	}
	return pos;
}

int main() {
  	Person pList[PLIST_SIZE];
  	Customer cList[PLIST_SIZE];
  	string choice, pTypeChoice;
	int index = 0;
	bool fileRead = false;
  	ifstream pfile;
  	ofstream opfile;

	cout << "This is modularMain3.cpp. " << endl;

  cout << "Would you like to read the data from a file (yes/no)? " << endl;
  cin >> choice;
  cin.ignore(3, '\n');

  if (choice == "yes") {
    fileRead = true;
    pfile.open("iperson.txt");
    if (!pfile) {
      cerr << "Can't open person.txt for read." << endl;
      return 1;
    }

    pfile >> pTypeChoice;
    pfile.ignore(3, '\n');
  } else {
    cout << "What type of Person? (person/customer)" << endl;
    cin >> pTypeChoice;
    cin.ignore(3, '\n');
  }

  if( pTypeChoice == "person" ) {
    opfile.open("operson.txt");
    choice = "yes";

    if (fileRead) {
      readPerson(pfile, pList[index]);
      if (!pfile) {
        choice = "no";
      }
    }

    while (choice != "no" && index < PLIST_SIZE) {
      if (!fileRead) {
        requestInfo(cout, "Please enter your name followed by your age.");
        readPerson(cin, pList[index]);
      }

      writePerson(opfile, pList[index]);

      index++;
      if (!fileRead) {
        choice = readAgain(cout, cin);
      } else {
        readPerson(pfile, pList[index]);
        if (!pfile) {
          choice = "no";
        }
      }
    }

    if (fileRead) {
      pfile.close();
    }
    opfile.close();

    cout << "Which person are you looking for? " << endl;
    getline(cin, choice);

    if ((index = findPerson(pList, choice)) != -1) {
      cout << "Found your person: " << endl;
      writePerson(cout, pList[index]);
    } else {
      cout << "Couldn't find your person: " << choice << endl;
    }
  } else {
    opfile.open("ocustomer.txt");
    choice = "yes";

    if (fileRead) {
      readCustomer(pfile, cList[index]);
      if (!pfile) {
        choice = "no";
      }
    }

    while (choice != "no" && index < PLIST_SIZE) {
      if (!fileRead) {
        requestInfo(cout, "Please enter your name followed by your age then shipping rate");
        readCustomer(cin, cList[index]);
      }

      writeCustomer(opfile, cList[index]);

      index++;
      if (!fileRead) {
        choice = readAgain(cout, cin);
      } else {
        readCustomer(pfile, cList[index]);
        if (!pfile) {
          choice = "no";
        }
      }
    }

    if (fileRead) {
      pfile.close();
    }
    opfile.close();

    cout << "Which person are you looking for? " << endl;
    getline(cin, choice);

    if ((index = findCustomer(cList, choice)) != -1) {
      cout << "Found your person: " << endl;
      writeCustomer(cout, cList[index]);
    } else {
      cout << "Couldn't find your person: " << choice << endl;
    }
  }

  return 0;
}

