/**
* file: proj6-sequentialMain3.cpp
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

int main(){
	bool fileRead = false;
	ifstream pfile;
	ofstream opfile;
	string name, choice;
	int age;

	cout << "Would you like the read the data from a file? " << endl;
	cin >> choice;
	cin.ignore(3,'\n');
  	
	if( choice == "yes" ) {
    	fileRead = true;
    	pfile.open("iperson.txt");
    	if( !pfile ) {
      		cerr << "Can't open person.txt for read." << endl;
      		return 1;
    	}
  	}

	opfile.open("operson.txt");

	choice = "yes";
	if( fileRead){
		getline(pfile, name);
		pfile >> age;
		pfile.ignore('\n');
		if(!pfile){
			choice = "no";
		}
	}

	while(choice != "no"){
		if(!fileRead){
			cout << "Please enter your name followed by your age." << endl;
			getline(cin, name);
			cin >> age;
			cin.ignore(3,'\n');
		}

		opfile << name << endl;
		opfile << age << endl;

		if(!fileRead){
			cout << "Do you want to read in another person (yes/no)? " << endl;
			cin >> choice;
			cin.ignore(3,'\n');	
		}
		else{
			getline(cin, name);
			cin >> age;
			cin.ignore('\n');
			if(!pfile){
				choice = "no";
			}
		}
	}

	if(fileRead){
		pfile.close();
	}
	opfile.close();

	return 0;	
}

