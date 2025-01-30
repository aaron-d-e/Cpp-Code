#ifndef PROJ1_PERSON_H
#define PROJ1_PERSON_H

#include <iostream>
#include <string>

using namespace std;

struct Person {
  string name;
  int age;
};
/**
 * fgetAPersonFromStream
 *
 * This function gets a Person object from stream (aka file)
 *
 * Parameters:
 * istream variable(inFile), and Person *(Person object variable)
 *
 * Output:
 * return: istream passed
 * reference parameters: istream
 * stream: file stream
 */
istream &getAPersonFromStream(istream &, Person *); // reads a single Person from the stream
/**
 * sortPersonArrayByAge
 *
 * sorts array of pointers by age
 *
 * Parameters:
 * Person **(reference array) and int(size)
 *
 * Output:
 * return: sorted array
 * reference parameters: void
 * stream: none
 */
void sortPersonArrayByAge(Person **, int); // implements selection sort ascending order
/**
 * sortPersonArrayByName
 *
 * this function sorts array by name
 *
 * Parameters:
 * Person** (reference array) and int(size)
 *
 * Output:
 * return: sorted array
 * reference parameters: none
 * stream: none
 */
void sortPersonArrayByName(Person **, int); // implements bubble sort ascending order
/**
 * findAPerson
 *
 * this funtion finds a person in an array
 *
 * Parameters:
 * Person **(reference array), int(size), string(name to search)
 *
 * Output:
 * return: Person*
 * reference parameters: none
 * stream: none
 */
Person * findAPerson(Person **, int, string); // implements linear search
/**
 * displayAPerson
 *
 * This function displays person to a stream (cout)
 *
 * Parameters:
 * ostream reference variable(cout) and Person* person[i]
 *
 * Output:
 * return: void
 * reference parameters: ostream
 * stream: none
 */
void displayAPerson(ostream &, const Person *); // writes a single Person to the stream


#endif