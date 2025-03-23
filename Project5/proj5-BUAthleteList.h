#ifndef PROJ5_BUATHLETELIST_H
#define PROJ5_BUATHLETELIST_H
#include "proj5-BUAthlete.h"

int partitionID(BUAthlete* a, int lo, int hi);

void qSortID(BUAthlete* a, int lo, int hi);

int partitionEVAL(BUAthlete* a, int lo, int hi);

void qSortEVAL(BUAthlete* a, int lo, int hi);

class BUAthleteList {

protected:
    BUAthlete* list;
    int capacity;
    int size;
    void resizeArray();

public:
    BUAthleteList(); //WORkS
    ~BUAthleteList(); //WORKS
    BUAthleteList(const BUAthleteList&); //TEST
    BUAthleteList& operator=(const BUAthleteList&); //TEST

    void addNCAAAthlete(int, string, string, string); //WORKS
    void setBUInfo(int, Position, int); //WORKS
    int findById(int); //FIX ME
    void sortByID(); //TEST
    void sortByPosition(); //TEST
    void sortByEvaluation(); //TEST
    BUAthlete& operator[](int ndx);
    string toString(); //WORKS
};

#endif
