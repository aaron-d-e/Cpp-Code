/**
 * file: proj7-MyVector.h
 * author: Aaron Evans
 * course: CSI 1440
 * assignment: project 7
 * due date: 4/6/2025
 * 
 * Data Modified:
 * 4/1/2025
 * - implemented basic functionality
 * 
 * 4/4/2025
 * - fixed some minor bugs
 * 
 * 4/5/2025
 * - added comments and polished
 */

#include <iostream>
#include "proj7-MyVector.h"
using namespace std;

template <class T>
void printContents(MyVector<T> obj);

int main(){

	MyVector<int> a;
	int val;

	cout << "Testing default constructor..." << endl;
	cout << "Size: " << a.getSize() << " should be 0" << endl;

	cout << "Testing pushBack()..." << endl;
	for(int i = 0; i < 10; i++){
		a.pushBack(i);
	}
	printContents(a);
	cout << "Should be:" << endl;
	cout << "0\t1\t2\t3\t4\t5\t6\t7\t8\t9\n" << endl;
	cout << endl;

	cout << "Testing overload assignment operator..." << endl;
	MyVector<int> b;
	b = a;
	printContents(b);
	cout << "Should be: " << endl;
	printContents(a);
	cout << endl;

	cout << "Testing popBack()..." << endl;
	while(!a.isEmpty()){
		a.popBack(val);
		cout << val << "\t";
}
	cout << endl;
	cout << "Should be \n9\t8\t7\t6\t5\t4\t3\t2\t1\t0" <<endl;
	cout << endl;

	cout << "Testing operator[]..." << endl;
	try{
		a[2] = 6;
		cout << "Should not see this message" << endl;
	}catch (BADINDEX){
		cout << "Should see this message." << endl;
	}
	cout << endl;

	cout << "Re-inserting values into vector" << endl;	
	for(int i = 0; i < 10; i++){
		a.pushBack(i);
	}
	printContents(a);
	cout << "Should See: " << endl;
	for(int i = 0; i < 10; i++){
		cout << i << "\t";
	}
	cout << endl;
	cout << endl;


	cout << "Testing pushFront()..." << endl;
	a.pushFront(20);
	printContents(a);
	cout << "Should see 20...then the rest of contents" << endl;
	cout << endl;

	cout << "Testing front()..." << endl;
	cout << a.front() << endl;
	cout << "Should see:" << endl;
	cout << "20" << endl;
	cout << endl;

	cout << "Testing back()..." << endl;
	cout << a.back() << endl;
	cout << "Should see:" << endl;
	cout << "9" << endl;
	cout << endl;

	return 0;
}

template <class T>
void printContents(MyVector<T> obj){
	int test;
	while(!obj.isEmpty()){
		obj.popFront(test);
		cout << test << "\t";
	}
	cout << endl;
}

