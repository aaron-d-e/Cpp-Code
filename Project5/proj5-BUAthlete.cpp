//
// Created by aaron on 3/18/2025.
//

#include "proj5-BUAthlete.h"

void BUAthlete::setEvaluation(int num) {
    evaluation = num;
}

void BUAthlete::setPosition(Position pos) {
    bestFit = pos;
}

int BUAthlete::getEvaluation() {
    return evaluation;
}

Position BUAthlete::getPosition() {
    return bestFit;
}

string BUAthlete::toString() {

    ostringstream stream;

    stream << NCAAAthlete::toString(); //could cause problems
    stream << "Evaluation: " << getEvaluation() << endl;
    stream << "Position: " << getPosition() << endl;

    return stream.str();
}



