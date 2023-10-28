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
#include "Students.h"
using namespace std;

void studiju_kurss_tests() {
    Studiju_kurss dt{};
    Studiju_kurss s1{"Datorsistēmas", "Datorsistēmas", 2};
    Studiju_kurss it{"Informācijas tehnoloģijas", "Informācijas tehnoloģijas", 5, 10};
    Studiju_kurss dss{"Datoru sistēmu sastāvdaļas", "Datoru sistēmu sastāvdaļas", 4, 5};
    cout << dt << endl << s1 << endl << it << endl << dss << endl;
    it.kursa_informacija();
    cout << "\nStudiju kurss tests pabeigts!" << endl << endl << endl;
}
void students_tests() {
    Students s1{};
    Students s2{"1242", "T21", "Kurts", 1};
    Students s3{"2102", "ITB", "Endijs", 2,
                {
                 {"521", "IKT", 2, 10},
                 {"123", "Informācijas tehnoloģijas", 5, 10},
                 {"555", "Datoru sistēmu sastāvdaļas", 4, 5}
                }
    };
    cout << "izvada studenta identifikatoru, vārdu, viņa studiju kursu nosaukumus un atzīmes\n";
    s3.izvadit_ekrana();
    cout << " izvada identifikatoru studenta vārdu, vidējo atzīmi un vidējo svērto atzīmi\n";
    s3.izvadit_ekrana_vid_atzimes();
    cout << "all info\n";
    s3.izvadit_ekrana_visu();
    cout << "Students tests pabeigts!" << endl << endl << endl;
}

#endif //HOMEWORK1_TESTI_H
