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


	cout << "File length before (delete me later): " << fileLength << endl;
	
	//checks if empty file then prints the input integer
	if(fileLength == 0){
		file.write(reinterpret_cast<char*>(&input), sizeof(input));	
	}
	else {
		int compareValue;
		int iter = 1;
		file.seekg(-iter * sizeInt, ios::end);
		file.read(reinterpret_cast<char*>(&compareValue), sizeInt);
		cout << "VAlUE " << compareValue << endl; 
		while(compareValue > input && (file.tellg() >= 4)){
			file.seekg(-iter * sizeInt, ios::end);
			cout << "get index: " << file.tellg() << endl;
			file.read(reinterpret_cast<char*>(&compareValue), sizeInt);
			iter++;
		}
		cout << file.tellg() << endl;
		cout << file.tellp() << endl;
	}
	// file size after all operations
	file.seekg(0, ios::end);
	fileLength = file.tellg();
	file.seekg(0, ios::beg);

	int output;
	int iter2;
	while(file.tellg() <= fileLength){
		cout << file.tellg() << endl;
		file.read(reinterpret_cast<char*>(&output), sizeInt);
		cout << "Output: " << output << " ";
		file.seekg(4 * iter2, ios::beg);
		iter2++;
	}
	cout << endl;

	cout << "File length after (delete me later): " << fileLength << endl;

	return 0;
}
