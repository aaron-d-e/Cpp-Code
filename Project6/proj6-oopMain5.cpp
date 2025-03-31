/**
* file: proj6-oopMain5.cpp
* author: Aaron Evans
* course: CSI 1440
* assignment: project 6
* due date: 3/30/2025
*
* date modified: 3/30/2025
* - started and finished project
*/

#include <iostream>
#include <fstream>
using namespace std;

const int PLIST_SIZE = 10;

class Person{
protected:
	string name;
	int age;

public:
/**
* getName
*
* This function returns the name of a Person object
*
* Parameters:
*
* Output:
* return: name
* reference parameters: none
* stream: none
*/
	string getName() { return name; }
/**
* readPerson
*
* This function read person information
*
* Parameters:
* istream: reference to a istream variable
*
* Output:
* return: void
* reference parameters: none
* stream: none
*/
	void readPerson(istream &);
/**
* writePerson
*
* This function writes person info to stream
*
* Parameters:
* ostream: reference to ostream variable
*
* Output:
* return: void
* reference parameters: none
* stream: none
*/
	void writePerson(ostream &);
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

class Customer{
protected:
	double shippingRate;
	string name;
	int age;
public:
	Customer();
/**
* getName
*
* This function returns the name of a Person object
*
* Parameters:
*
* Output:
* return: name
* reference parameters: none
* stream: none
*/
	string getName(){return name;}
/**
* readPerson
*
* This function read person information
*
* Parameters:
* istream: reference to a istream variable
*
* Output:
* return: void
* reference parameters: none
* stream: none
*/
	void readPerson(istream &);
/**
* writePerson
*
* This function writes person info to stream
*
* Parameters:
* ostream: reference to ostream variable
*
* Output:
* return: void
* reference parameters: none
* stream: none
*/
	void writePerson(ostream &);
/**
* getShippingRate
*
* This function returns shipping rate of customer
*
* Parameters:
*
* Output:
* return: double
* reference parameters: none
* stream: none
*/
	double getShippingRate();
};

Customer::Customer() {
	shippingRate = 5.0;
}

double Customer::getShippingRate(){
	return shippingRate;
}

void Customer::readPerson(istream &in){
	getline(in, name);
	in >> age;
	in.ignore(3, '\n');
	in >> shippingRate;
	cin.ignore(3, '\n');
}

void Customer::writePerson(ostream &out){
	out << name << endl;
	out << age << endl;
	out << shippingRate << endl;
}

class MegaCustomer{
protected:
	string name;
	int age;
	double shippingRate;
public:
/**
* getName
*
* This function returns the name of a Person object
*
* Parameters:
*
* Output:
* return: name
* reference parameters: none
* stream: none
*/
	string getName() {return name;}
/**
* readPerson
*
* This function read person information
*
* Parameters:
* istream: reference to a istream variable
*
* Output:
* return: void
* reference parameters: none
* stream: none
*/
	void readPerson(istream &);
/**
* writePerson
*
* This function writes person info to stream
*
* Parameters:
* ostream: reference to ostream variable
*
* Output:
* return: void
* reference parameters: none
* stream: none
*/
	void writePerson(ostream &);
/**
* getShippingRate
*
* This function returns shipping rate of customer
*
* Parameters:
*
* Output:
* return: double
* reference parameters: none
* stream: none
*/
	double getShippingRate() {return shippingRate;}
	MegaCustomer();
};

MegaCustomer::MegaCustomer() {
	shippingRate = 0;
}

void MegaCustomer::writePerson(ostream &out){
	out << name << endl;
	out << age << endl;
	out << shippingRate << endl;
}

void MegaCustomer::readPerson(istream &in){
	getline(in, name);
	in >> age;
	in.ignore(3,'\n');
}

int findPerson(Person *pList[], string name){
	int pos = -1, index = 0;

	while(pos == -1 && index < PLIST_SIZE){
		if(pList[index]->getName() == name){
			pos = index;
		}
		index++;
	}
	return pos;
}

int findCustomer(Customer *cList[], string name){
	int pos = -1, index = 0;

	while(pos == -1 && index < PLIST_SIZE){
		if(cList[index]->getName() == name){
			pos = index;
		}
		index++;
	}
	return pos;
}

int findMega(MegaCustomer *mList[], string name){
	int pos = -1, index = 0;

	while(pos == -1 && index < PLIST_SIZE){
		if(mList[index]->getName() == name){
			pos = index;
		}
		index++;
	}
	return pos;
}


int main() {

  Person **pList = new Person *[PLIST_SIZE]();
  Customer **cList = new Customer *[PLIST_SIZE]();
  MegaCustomer **mList = new MegaCustomer *[PLIST_SIZE]();
  
  string choice, pTypeChoice, msg = "Please enter your name followed by your age.";
  int index = 0;
  bool fileRead = false;
  ifstream pfile;
  ofstream opfile;

  cout << "This is oopMain5.cpp" << endl;

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
    cout << "What type of Person? (person/customer/mega)" << endl;
    cin >> pTypeChoice;
    cin.ignore(3, '\n');
  }

  if (pTypeChoice == "person") {
    for (int i = 0; i < PLIST_SIZE; i++) {
      pList[i] = new Person;
    }
  } else if(pTypeChoice == "customer"){
    for (int i = 0; i < PLIST_SIZE; i++) {
      cList[i] = new Customer;
    }   
    msg = "Please enter your name followed by your age then shipping rate.";
  } else {   
    for( int i = 0; i < PLIST_SIZE; i++ ) {
      mList[i] = new MegaCustomer;
    }
  }

  opfile.open("operson.txt");

  choice = "yes";

  if (fileRead) {
	  if(pTypeChoice == "person"){
    		pList[index]->readPerson(pfile);
	  }
	  else if(pTypeChoice == "customer"){
			cList[index]->readPerson(pfile);
	  }
	  else if(pTypeChoice == "mega"){
			mList[index]->readPerson(pfile);
	  }
	  
    if (!pfile) {
      choice = "no";
    }
  }

  while (choice != "no" && index < PLIST_SIZE) {
    if (!fileRead) {
      requestInfo(cout, msg);
	  if(pTypeChoice == "person"){
      		pList[index]->readPerson(cin);
	  }
	  else if(pTypeChoice == "customer"){
			cList[index]->readPerson(cin);
	  }
	  else if(pTypeChoice == "mega"){
			mList[index]->readPerson(cin);
	  }
    }
	if(pTypeChoice == "person"){
    	pList[index]->writePerson(opfile);
	}
	else if(pTypeChoice == "customer"){
		cList[index]->writePerson(opfile);
	}
	else if(pTypeChoice == "mega"){
		mList[index]->writePerson(opfile);
	}

    index++;
    if (!fileRead) {
      choice = readAgain(cout, cin);
    } else {
		if(pTypeChoice == "person"){
      		pList[index]->readPerson(pfile);
		}
		else if(pTypeChoice == "customer"){
			cList[index]->readPerson(pfile);
		}
		else if(pTypeChoice == "mega"){
			mList[index]->readPerson(pfile);
		}
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

  if (pList[0] && (index = findPerson(pList, choice)) != -1) {
    cout << "Found your person: " << endl;
    pList[index]->writePerson(cout);
  }
  else if(cList[0] && (index = findCustomer(cList, choice)) != -1){
	  cout << "Found your person: " << endl;
	  cList[index]->writePerson(cout);
  }
  else if(mList[0] && (index = findMega(mList, choice)) != -1){
		cout << "Found your Person: " << endl;
		mList[index]->writePerson(cout);
  }
  else {
    cout << "Couldn't find your person: " << choice << endl;
  }

  for( int i = 0; i < PLIST_SIZE; i++ ){
	    if (pList[i]) delete pList[i];
    	if (cList[i]) delete cList[i];
    	if (mList[i]) delete mList[i];
  }
  delete [] pList;
  delete [] cList;
  delete [] mList;

  return 0;
}

