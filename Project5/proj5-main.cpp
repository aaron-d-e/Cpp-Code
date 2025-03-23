#include <iostream>
#include "proj5-BUAthleteList.h"
using namespace std;

int main(){

    BUAthleteList list;

    list.addNCAAAthlete(1234, "AARON", "yes", "Baylor");
    list.setBUInfo(0, QB, 5);
    list.addNCAAAthlete(5678, "ERICK", "no", "Baylor");
    list.setBUInfo(1, OL, 5);
    list.addNCAAAthlete(5678, "JESSE", "yes", "Utah");
    list.setBUInfo(2, CB, 3);


     cout << list.toString();
    return 0;
}