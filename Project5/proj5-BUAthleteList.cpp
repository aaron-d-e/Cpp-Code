#include "proj5-BUAthleteList.h"

BUAthleteList::BUAthleteList(){
    capacity = 2;
    size = 0;
    list = new BUAthlete[capacity];
}
BUAthleteList::~BUAthleteList(){
    delete[] list;
}
BUAthleteList::BUAthleteList(const BUAthleteList& cpy){
    this->capacity = cpy.capacity;
    this->size = cpy.size;
    list = new BUAthlete[this->capacity];
    for(int i = 0; i < size; i++){
        list[i] = cpy.list[i];
    }
}
BUAthleteList& BUAthleteList::operator=(const BUAthleteList& cpy){
    if(this != &cpy){
        delete[] list;
        this->capacity = cpy.capacity;
        this->size = cpy.size;
        list = new BUAthlete[this->capacity];
        for(int i = 0; i < size; i++){
            list[i].setID(cpy.list[i].getID());
            list[i].setName(cpy.list[i].getName());
            list[i].setSchool(cpy.list[i].getSchool());
            if (cpy.list[i].getLOI()) {
                list[i].setLOI("yes");
            }
            else {
                list[i].setLOI("no");
            }
            list[i].setEvaluation(cpy.list[i].getEvaluation());
            list[i].setPosition(cpy.list[i].getPosition());

        }
    }
    return *this;
}
void BUAthleteList::addNCAAAthlete(int ID, string name, string LOI, string school){
    if (size == capacity) {
        capacity += 2;
        BUAthlete* temp = new BUAthlete[capacity];
        for (int i = 0; i < size; i++) {
            temp[i] = list[i];
        }
        delete[] list;
        list = temp;
    }

    BUAthlete ath;
    ath.setID(ID);
    ath.setName(name);
    ath.setLOI(LOI);
    ath.setSchool(school);

    list[size] = ath;
    size++;
}

void BUAthleteList::setBUInfo(int index, Position pos, int eval){
    list[index].setEvaluation(eval);
    list[index].setPosition(pos);
}

string BUAthleteList::toString(){
    ostringstream stream;

    for(int i = 0; i < size; i++){
        stream << "[ " << i << " ]" << endl;

        stream << list[i].BUAthlete::toString();
    }
    return stream.str();
}

BUAthlete& BUAthleteList::operator[](int ndx) {
    return list[ndx];
}

int BUAthleteList::findById(int id) {
    int lo = 0;
    int hi = size - 1;
    while (lo <= hi) {
        int mid = lo + (hi - lo) / 2;

        if (list[mid].getID() == id) {
            return mid;
        }
        if (list[mid].getID() < id) {
            lo = hi + 1;
        }
        else {
            hi = mid - 1;
        }
    }

    return -1;
}

void BUAthleteList::sortByID() {
    qSortID(list, 0, size - 1);
}

void BUAthleteList::sortByPosition() {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (list[j].getPosition() < list[j+1].getPosition()) {
                swap(list[j], list[j+1]);
            }
        }
    }
}

void BUAthleteList::sortByEvaluation() {
    qSortEVAL(list, 0, size - 1);
}

int partitionID(BUAthlete* a, int lo, int hi) {
    BUAthlete pV = a[lo];
    int pI = lo;

    for (int pos = lo + 1; pos <= hi; pos++) {
        if (a[pos].getID() < pV.getID()) {
            swap(a[pos],a[pI + 1]);
            swap(a[pI],a[pI + 1]);
            pI++;
        }
    }
    return pI;
}

void qSortID(BUAthlete* a, int lo, int hi) {
    if (lo >= hi) {
        return;
    }
    int p = partitionID(a,lo,hi);
    qSortID(a,lo,p-1);
    qSortID(a,p+1,hi);
}

int partitionEVAL(BUAthlete* a, int lo, int hi) {
    BUAthlete pV = a[lo];
    int pI = lo;

    for (int pos = lo + 1; pos <= hi; pos++) {
        if (a[pos].getEvaluation() < pV.getEvaluation()) {
            swap(a[pos],a[pI + 1]);
            swap(a[pI],a[pI + 1]);
            pI++;
        }
    }
    return pI;
}

void qSortEVAL(BUAthlete* a, int lo, int hi) {
    if (lo >= hi) {
        return;
    }
    int p = partitionEVAL(a,lo,hi);
    qSortEVAL(a,lo,p-1);
    qSortEVAL(a,p+1,hi);
}

void BUAthleteList::resizeArray() {

}
