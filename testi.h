//
// Created by Endijs on 10/28/2023.
//

#ifndef HOMEWORK1_TESTI_H
#define HOMEWORK1_TESTI_H
//
// Created by Endijs on 10/28/2023.
//
#include <iostream>
#include <vector>
#include "Studiju_kurss.h"
using namespace std;

void studiju_kurss_tests() {
    Studiju_kurss dt{};
    Studiju_kurss s1{"Datorsistēmas", "Datorsistēmas", 2};
    Studiju_kurss it{"Informācijas tehnoloģijas", "Informācijas tehnoloģijas", 5, 10};
    Studiju_kurss dss{"Datoru sistēmu sastāvdaļas", "Datoru sistēmu sastāvdaļas", 4, 5};
    cout << dt << endl << s1 << endl << it << endl << dss << endl;
    it.kursa_informacija();

}

#endif //HOMEWORK1_TESTI_H
