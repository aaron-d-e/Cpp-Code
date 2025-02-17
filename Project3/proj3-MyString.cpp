#include "proj3-MyString.h"


MyString::MyString(){
    size = 0;
    capacity = MIN_CAPACITY;
    data = new char[capacity];
    data[0] = '\0';
}

MyString::MyString(const char * str){
    size = 0;
    while(str[size] != '\0'){
        size++;
    }
    capacity = MIN_CAPACITY;

    while(size >= capacity){
        capacity *= 2;
    }

    data = new char[capacity];
    for(int i = 0; i < size; i++){
        data[i] = str[i];
    }
    data[size] = '\0';
}

MyString::~MyString(){
    //cout << "Destructor called" << endl;
    delete[] data;
    data = nullptr;
}

MyString::MyString(const MyString & origObject){
    //cout << "Copy Constructor Called" << endl;
    size = origObject.size;
    capacity = origObject.capacity;
    data = new char[capacity];
    for(int i = 0; i < size; i++){
        data[i] = origObject.data[i];
    }
    data[size] = '\0';
}

int MyString::length( )const { 
    return size;
}

MyString& MyString::operator = (const MyString& that){ 
    //cout << "operator = used" << endl;
    if(this != &that){
        delete[] data;
        this->size = that.size;
        this->capacity = that.capacity;
        this->data = new char[capacity];
        for(int i = 0; i < size; i++){
            data[i] = that.data[i];
        }
    }
    data[size] = '\0';
    return *this;
}

bool MyString::operator == (const MyString& that) const{ 
    //cout << "operator == used" << endl;
    bool flag;
    if(this->size != that.size){
        flag = false;
    }
    else{
        flag = true;
    }
    for(int i = 0; (i < this->size) && flag; i++){
        if(data[i] != that.data[i]){
            flag = false;
        }
    }
    return flag;
}


char& MyString::operator [ ] (int index){ 
    //cout << "operator [] used" << endl;
    return this->data[index];
}

void MyString::operator += (const MyString& otherstr){ 
    //cout << "operator += used" << endl;
    while((size + otherstr.size) >= capacity){
        capacity *= 2;
    }
    char* temp = new char[capacity];
    
    for(int i = 0; i < size; i++){
        temp[i] = data[i];
    }
    for(int i = 0; i < otherstr.size; i++){
        temp[size+i] = otherstr.data[i];
    }
    delete[] data;
    data = new char[capacity];
    size += otherstr.size;

    for(int i = 0; i < size;i++){
        data[i] = temp[i];
    }
    delete[] temp;
    temp = nullptr;
    data[size] = '\0';
}

MyString MyString::operator + (const MyString& otherstr) const{
    MyString result(*this);
    // delete[] result.data;
    // result.capacity = size + otherstr.size + 1;
    // while(result.size + otherstr.size >= result.capacity){
    //     result.capacity *= 2;
    // }
    // result.data = new char[capacity];
    // for(int i = 0; i < this->size; i++){
    //     result.data[i] = this->data[i];
    // }
    // for(int i = 0; i < otherstr.size; i++){
    //     result.data[size + i] = otherstr.data[i];
    // }
    // result.size = this->size + otherstr.size;
    // result.data[result.size] = '\0';
    result += otherstr;
    result[result.size] = '\0';
    return result;

}

void MyString::getline(istream& is, char delimit){
    //cout << "getline function called" << endl;
    char ch;
    int streamsize = 0;

    int i = 0;
    while((ch = is.get()) != EOF && ch != delimit){
        this->data[i] = ch;
        if(this->size + 1 >= this->capacity){
            capacity *= 2;
            char* temp = new char[capacity];
            
            for(int i = 0; i < size; i++){
                temp[i] = data[i];
            }
            delete[] data;
            data = new char[capacity];
            for(int i = 0; i < size; i++){
                data[i] = temp[i];    
            }
            delete[] temp;
            temp = nullptr;
        }           
            i++;
            streamsize = i;
    }

    this->data[streamsize] = '\0';
}

ostream& operator<< (ostream& os, MyString& str){
    //cout << "operator << used" << endl;
    os << str.data;
    return os;
}


