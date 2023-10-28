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
    Studiju_kurss s1{"6666", "Datorsistēmas", 2};
    Studiju_kurss it{"1231", "Informācijas tehnoloģijas", 5, 10};
    Studiju_kurss dss{"4444", "Datoru sistēmu sastāvdaļas", 4, 5};
    //cout << dt << endl << s1 << endl << it << endl << dss << endl;
    it.kursa_informacija();
    s1.kursa_informacija();
    cout << "\nStudiju kurss tests pabeigts!" << endl << endl << endl;
}
void students_tests() {
    cout << "sākas students tests\n";
    Students s1{};
    Students s2{"1242", "T21", "Kurts", 2};
    Students s3{"2102", "ITB", "Endijs", 2,
                {
                 {"521", "IKT", 2, 10},
                 {"123", "Informācijas tehnoloģijas", 2, 10},
                 {"555", "Datoru sistēmu sastāvdaļas", 4, 5}
                }
    };
    Students s4{"2132", "Tulk", "Kārlis", 4,
                {
                        {"421", "tulkosana", 2, 10},

                }
    };
    //cout << "izvada studenta identifikatoru, vārdu, viņa studiju kursu nosaukumus un atzīmes\n";
    //s3.izvadit_ekrana();
    //cout << " izvada identifikatoru studenta vārdu, vidējo atzīmi un vidējo svērto atzīmi\n";
    //s3.izvadit_ekrana_vid_atzimes();
    cout << "visa info par s3\n";
    s3.izvadit_ekrana_visu();
    s3.set_studiju_gads(3);
    cout << "visa info par s3 \n";
    s3.izvadit_ekrana_visu();
    cout << "kurss ar nosaukumu IKT (1 - true, 0 - false): " << s3.vai_ir_kurss("IKT") << endl;
    cout << "Students tests pabeigts!" << endl << endl << endl;
    // izvada no s3 kursu pec nosaukuma ikt
    cout << s3.kurss_pec_nosaukuma("IKT");
    cout << "s3[1] = \n" << s3[1] << endl;
    //s3[1] = s4[0];
    s3.izvadit_ekrana_visu();
    s3.pievienot_kursu(s4[0]);
    s3.pievienot_kursu(s4[0]);
    s3.izvadit_ekrana_visu();
}

#endif //HOMEWORK1_TESTI_H
