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

Position strToPosition(string& str) { //function to turn string into Position
    if (str == "OL") return OL;
    else if (str == "QB") return QB;
    else if (str == "RB") return RB;
    else if (str == "WR") return WR;
    else if (str == "TE") return TE;
    else if (str == "DL") return DL;
    else if (str == "DE") return DE;
    else if (str == "LB") return LB;
    else if (str == "CB") return CB;
    else if (str == "S") return S;
    else if (str == "K") return K;
}




