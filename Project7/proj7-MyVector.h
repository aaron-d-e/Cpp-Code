#include "proj7-ContainterIfc.h"

template <class T>
class MyVector : public ContainerIfc<T> {
public:
  MyVector ();
  ~MyVector ();
  MyVector (const MyVector&);
  MyVector<T>& operator = (const MyVector&);
  MyVector<T>& pushFront(T);
  MyVector<T>& pushBack(T);
  MyVector<T>& popFront(T&);
  MyVector<T>& popBack(T&);
  T  front();
  T  back();
  T&  operator [](int);
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

template <class T>
MyVector<T>::MyVector(){
	size = 0;
	capacity = 10;
	data = new T[capacity];
}
template <class T>
MyVector<T>::~MyVector(){
	delete[] data;	
}
template <class T>
MyVector<T>::MyVector(const MyVector& cpy){
	this->size = cpy.capacity;
	this->capacity = cpy.capacity;
	this->data = new T[capacity];
	for(int i = 0; i < size; i++){
		this->data[i] = cpy.data[i];
	}
}
template <class T>
MyVector<T>& MyVector<T>::operator = (const MyVector& cpy){
	if(this != &cpy){
		delete[] data;
		this->size = cpy.size;
		this->capacity = cpy.size;
		data = new T[capacity];
		for(int i = 0; i < size; i++){
			this->data[i] = cpy.data[i];
		}
	}
	return *this;
}
template <class T>
MyVector<T>& MyVector<T>::pushFront(T item){
		
}
template <class T>
MyVector<T>& MyVector<T>::pushBack(T item){
	if(size == capacity){
		//resize
	}
	data[size] = item;
	size++;
	return *this;
}
template <class T>
MyVector<T>& MyVector<T>::popFront(T& item){
	if(!isEmpty()){
		//do popfront
	}	
	else{
		throw BADINDEX();
	}
}
template <class T>
MyVector<T>& MyVector<T>::popBack(T& item){
	if(!isEmpty()){
		item = data[size-1];
		size--;
	}
	else{
		throw BADINDEX();
	}
}
template <class T>
T MyVector<T>::front(){
	if(!isEmpty()){
		return data[0];
	}
	else{
		throw BADINDEX();
	}
}
template <class T>
T MyVector<T>::back(){
	if(!isEmpty()){
		return data[size - 1];
	}
	else{
		throw BADINDEX();
	}
}
template <class T>
T& MyVector<T>::operator [](int index){
	if(!isEmpty()){
		return data[index];
	}
	else{
		throw BADINDEX();
	}
}
template <class T>
int MyVector<T>::getSize(){
	return size;
}
template <class T>
bool MyVector<T>::isEmpty(){
	return (size == 0);
}
template <class T>
void MyVector<T>::erase(){
	for(int i = 0; i < size; i++){
		delete data[i];
	}	
	size = 0;
}
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
