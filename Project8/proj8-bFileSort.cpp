/*
 * file: proj8-bFileSort.cpp
 * author: Aaron Evans
 * course: CSI 1440
 * assignment: project 8
 * due date: 04/14/2025
 *
 * date modified: 04/08/2025
 * - initial git commit and file setup
 */ 

#include <iostream>
#include <fstream>
using namespace std;

int main(){
	int sizeInt = sizeof(int);
	int input;
	int fileLength;
	int currentVal;

	fstream file("sortedInts", ios::binary | ios::in | ios::out);

	if(!file.is_open()){
		cout << "Error. File not open." << endl;
		exit(1);
	}

	cout << "Enter a variable: " << endl;
	cin >> input;

	//initialize file size before any operations
	file.seekg(0, ios::end);
	fileLength = file.tellg();
	file.seekg(0, ios::beg);

	//checks if empty file then prints the input integer
	if(fileLength == 0){
		cout << "if entered" << endl;
		file.write(reinterpret_cast<char*>(&input), sizeof(input));	
	}
	else{
		file.seekg(-1 * sizeInt, ios::end);
		file.read(reinterpret_cast<char*>(&currentVal), sizeInt);
		if(currentVal <= input){
			cout << "else-if entered" << endl;
			file.seekp(0, ios::end);
			file.write(reinterpret_cast<char*>(&input), sizeInt);
		}
		else{
			int i = (fileLength / 4) - 1;
			cout << "else-else entered" << endl;

			while(i >= 0){

				file.seekg(i + sizeInt, ios::beg);
				file.read(reinterpret_cast<char*>(&currentVal), sizeInt);

				if(input >= currentVal){
					break;
				}

				file.seekp((i + 1) * sizeInt, ios::beg);
				file.write(reinterpret_cast<char*>(&currentVal), sizeInt);
				i--;

			}
			file.seekp((i + 1) * sizeInt, ios::beg);
			file.write(reinterpret_cast<char*>(&input), sizeInt);
		}
	}


	file.seekg(0, ios::beg);
	int printVal;
	cout << "File Output." << endl;
	file.read(reinterpret_cast<char*>(&printVal), sizeInt);
	while(file.good()){
		cout << printVal << " ";
		file.read(reinterpret_cast<char*>(&printVal), sizeInt);
	}
	cout << endl;

	file.close();

	return 0;
}
