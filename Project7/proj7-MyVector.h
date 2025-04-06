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
 
#include "proj7-ContainterIfc.h"
#include "iostream"
using namespace std;
template <class T>
class MyVector : public ContainerIfc<T> {
public:
  MyVector (); 
  ~MyVector (); 
  MyVector (const MyVector&); 
  MyVector<T>& operator = (const MyVector&); 
  MyVector<T>& pushFront(T);
  MyVector<T>& pushBack(T); 
  MyVector<T>& popFront(T&); //throws BADINDEX 
  MyVector<T>& popBack(T&); //throws BADINDEX
  T  front(); //throws BADINDEX
  T  back(); //throws BADINDEX
  T&  operator [](int); //throws BADINDEX
  int getSize(); 
  bool isEmpty(); 
  void erase();  

private:
  T  *data;
  int size;
  int capacity;
  void grow(); 
  void shiftRight(); 
  void shiftLeft();
};

/**
 * MyVector
 *
 * Default class constructor that initializes a MyVector object with
 * size = 0, capacity = 10, and allocates memory for data.
 *
 * Parameters:
 * none
 *
 * Output:
 * return: nothing
 * reference parameters: none
 * stream: none
 */
template <class T>
MyVector<T>::MyVector(){ 
	size = 0;
	capacity = 10;
	data = new T[capacity];
}
/**
 * ~MyVector
 *
 * Destructor that releases the memory allocated to the MyVector.
 *
 * Parameters:
 * none
 *
 * Output:
 * return: nothing
 * reference parameters: none
 * stream: none
 */
template <class T>
MyVector<T>::~MyVector(){
	delete[] data;	
}
/**
 * MyVector(const MyVector & v)
 *
 * Copy constructor that creates a deep copy of another MyVector object.
 *
 * Parameters:
 * v: the MyVector object to copy
 *
 * Output:
 * return: nothing
 * reference parameters: none
 * stream: none
 */
template <class T>
MyVector<T>::MyVector(const MyVector& cpy){
	this->size = cpy.size;
	this->capacity = cpy.capacity;
	this->data = new T[capacity];
	for(int i = 0; i < size; i++){
		this->data[i] = cpy.data[i];
	}
}
/**
 * operator=
 *
 * Overloaded assignment operator that makes the current object
 * an exact deep copy of another MyVector object.
 *
 * Parameters:
 * v: the MyVector object to copy from
 *
 * Output:
 * return: a reference to the current MyVector object
 * reference parameters: none
 * stream: none
 */
template <class T>
MyVector<T>& MyVector<T>::operator = (const MyVector& cpy){
	if(this != &cpy){
		delete[] data;
		this->size = cpy.size;
		this->capacity = cpy.capacity;
		data = new T[capacity];
		for(int i = 0; i < size; i++){
			this->data[i] = cpy.data[i];
		}
	}
	return *this;
}
/**
 * shiftRight
 *
 * This function shifts all values in the array one space to the right,
 * making room at the beginning of the array.
 *
 * Parameters:
 * none
 *
 * Output:
 * return: nothing
 * reference parameters: none
 * stream: none
 */
template <class T>
void MyVector<T>::shiftRight(){
	for(int i = size; i > 0; i--){
		data[i] = data[i-1];
	}
}
/**
 * shiftLeft
 *
 * This function shifts all values in the array one space to the left,
 * effectively removing the first element.
 *
 * Parameters:
 * none
 *
 * Output:
 * return: nothing
 * reference parameters: none
 * stream: none
 */
template <class T>
void MyVector<T>::shiftLeft(){
	for(int i = 0; i < size; i++){
		data[i] = data[i+1];
	}
}

/**
 * pushFront
 *
 * Adds a data element to the front of the MyVector. If the vector is full,
 * its capacity is doubled. All existing elements are shifted to the right.
 *
 * Parameters:
 * e: the element to insert at the front
 *
 * Output:
 * return: a reference to the MyVector object
 * reference parameters: none
 * stream: none
 */
template <class T>
MyVector<T>& MyVector<T>::pushFront(T item){
	if(size == capacity){
		grow();
	}
	shiftRight();
	data[0] = item;

	size++;
	return *this;
}
/**
 * pushBack
 *
 * Adds a data element to the back of the MyVector. If the vector is full,
 * its capacity is doubled before adding the element.
 *
 * Parameters:
 * e: the element to insert at the back
 *
 * Output:
 * return: a reference to the MyVector object
 * reference parameters: none
 * stream: none
 */
template <class T>
MyVector<T>& MyVector<T>::pushBack(T item){
	if(size == capacity){
		grow();
	}
	data[size] = item;
	size++;
	return *this;
}
/**
 * popFront
 *
 * Removes the element at the front of the MyVector and assigns it to e.
 * If the vector is empty, an error occurs.
 *
 * Parameters:
 * e: the reference variable to store the removed element
 *
 * Output:
 * return: a reference to the MyVector object
 * reference parameters: e
 * stream: none
 */
template <class T>
MyVector<T>& MyVector<T>::popFront(T& item){
	if(!isEmpty()){
		item = data[0];
		shiftLeft();
		size--;
	}	
	else{
		throw BADINDEX();
	}
	return *this;
}
/**
 * popBack
 *
 * Removes the element at the end of the MyVector and assigns it to e.
 * If the vector is empty, an error occurs.
 *
 * Parameters:
 * e: the reference variable to store the removed element
 *
 * Output:
 * return: a reference to the MyVector object
 * reference parameters: e
 * stream: none
 */
template <class T>
MyVector<T>& MyVector<T>::popBack(T& item){
	if(!isEmpty()){
		item = data[size-1];
		size--;
	}
	else{
		throw BADINDEX();
	}
	return *this;
}
/**
 * front
 *
 * Returns a copy of the first data element in the MyVector.
 * If the vector is empty, an error occurs.
 *
 * Parameters:
 * none
 *
 * Output:
 * return: a copy of the first element
 * reference parameters: none
 * stream: none
 */
template <class T>
T MyVector<T>::front(){
	if(!isEmpty()){
		return data[0];
	}
	else{
		throw BADINDEX();
	}
}
/**
 * back
 *
 * Returns a copy of the last data element in the MyVector.
 * If the vector is empty, an error occurs.
 *
 * Parameters:
 * none
 *
 * Output:
 * return: a copy of the last element
 * reference parameters: none
 * stream: none
 */
template <class T>
T MyVector<T>::back(){
	if(!isEmpty()){
		return data[size - 1];
	}
	else{
		throw BADINDEX();
	}
}
/**
 * operator[]
 *
 * Returns a reference to the element at index n in the MyVector.
 * If n is out of bounds (n >= size or n < 0), an error occurs.
 *
 * Parameters:
 * n: the index of the element to retrieve
 *
 * Output:
 * return: a reference to the element at index n
 * reference parameters: none
 * stream: none
 */
template <class T>
T& MyVector<T>::operator [](int index){
	if(!isEmpty()){
		return data[index];
	}
	else{
		throw BADINDEX();
	}
}
/**
 * getSize
 *
 * Returns the number of elements currently stored in the MyVector.
 *
 * Parameters:
 * none
 *
 * Output:
 * return: the number of elements in the vector
 * reference parameters: none
 * stream: none
 */
template <class T>
int MyVector<T>::getSize(){
	return size;
}
/**
 * isEmpty
 *
 * Returns true if the MyVector is empty, false otherwise.
 *
 * Parameters:
 * none
 *
 * Output:
 * return: true if empty, false otherwise
 * reference parameters: none
 * stream: none
 */
template <class T>
bool MyVector<T>::isEmpty(){
	return (size == 0);
}
/**
 * erase
 *
 * Removes all elements from the MyVector.
 *
 * Parameters:
 * none
 *
 * Output:
 * return: nothing
 * reference parameters: none
 * stream: none
 */
template <class T>
void MyVector<T>::erase(){
	size = 0;
}
/**
 * grow
 *
 * This function increases the capacity of the data array by doubling its
 * previous value and reallocating memory accordingly.
 *
 * Parameters:
 * none
 *
 * Output:
 * return: nothing
 * reference parameters: none
 * stream: none
 */
template <class T>
void MyVector<T>::grow(){
	capacity+=10;
	T *temp = new T[capacity];
	for(int i = 0; i < size; i++){
		temp[i] = data[i];
	}
	delete[] data;
	data = temp;
}

