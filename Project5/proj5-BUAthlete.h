//
// Created by aaron on 3/18/2025.
//

#ifndef PROJ5_BUATHLETE_H
#define PROJ5_BUATHLETE_H
#include "proj5-NCAAAthlete.h"
#include <sstream>
#include <iostream>

enum Position {OL, QB, RB, WR, TE, DL, DE, LB, CB, S, K};

class BUAthlete : public NCAAAthlete {

protected:
    int evaluation;
    Position bestFit;

public:
    void setEvaluation(int); //WORKS
    void setPosition(Position); //WORKS
    int getEvaluation(); //WORKS
    Position getPosition(); //WORKS
    string toString(); //WORKS
};

#endif //PROJ5_BUATHLETE_H
