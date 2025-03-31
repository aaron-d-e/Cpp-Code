/**
* file: proj6-oopMain3.cpp
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

class Person {
protected:
  string name;
  int age;

public:
  string getName() { return name; }
  virtual void readPerson(istream &);
  virtual void writePerson(ostream &);
};

void Person::readPerson(istream &in) {
  getline(in, name);
  in >> age;
  in.ignore(3, '\n');
}

void Person::writePerson(ostream &out) {
  out << name << endl;
  out << age << endl;
}

void requestInfo(ostream &out, string msg) {
  out << msg << endl;
}

string readAgain(ostream &out, istream &in) {
  string choice;

  out << "Do you want to read in another person (yes/no)? " << endl;
  in >> choice;
  in.ignore(3, '\n');

  return choice;
}



class Customer : public Person {
protected:
  double shippingRate;

public:
  Customer();
  double getShippingRate();
  void readPerson(istream &);
  void writePerson(ostream &);
};

Customer::Customer() {
  shippingRate = 5.0;
}

double Customer::getShippingRate() {
  return shippingRate;
}

void Customer::readPerson(istream &in) {
  Person::readPerson(in);
  in >> shippingRate;
  in.ignore(3, '\n');
}

void Customer::writePerson(ostream &out) {
  Person::writePerson(out);
  out << shippingRate << endl;
}

int findPerson(Person *pList[], string name) {
  int pos = -1, index = 0;

  while (pos == -1 && index < PLIST_SIZE) {
    if (pList[index]->getName() == name) {
      pos = index;
    }
    index++;
  }

  return pos;
}

int main() {
  Person **pList = new Person *[PLIST_SIZE];
  string choice, pTypeChoice, msg = "Please enter your name followed by your age.";
  int index = 0;
  bool fileRead = false;
  ifstream pfile;
  ofstream opfile;

  cout << "This is oopMain3.cpp. " << endl;

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
    pfile.ignore(3, '\n');
  } else {
    cout << "What type of Person? (person/customer)" << endl;
    cin >> pTypeChoice;
    cin.ignore(3, '\n');
  }

  if (pTypeChoice == "person") {
    for (int i = 0; i < PLIST_SIZE; i++) {
      pList[i] = new Person;
    }
  } else {
    for (int i = 0; i < PLIST_SIZE; i++) {
      pList[i] = new Customer;
    }
    msg = "Please enter your name followed by your age then shipping rate.";
  }

  opfile.open("operson.txt");

  choice = "yes";
  if (fileRead) {
    pList[index]->readPerson(pfile);
    if (!pfile) {
      choice = "no";
    }
  }

  while (choice != "no" && index < PLIST_SIZE) {
    if (!fileRead) {
      requestInfo(cout, msg);
      pList[index]->readPerson(cin);
    }

    pList[index]->writePerson(opfile);

    index++;
    if (!fileRead) {
      choice = readAgain(cout, cin);
    } else {
      pList[index]->readPerson(pfile);
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
    pList[index]->writePerson(cout);
  } else {
    cout << "Couldn't find your person: " << choice << endl;
  }

  return 0;
}
