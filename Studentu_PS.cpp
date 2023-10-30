//
// Created by Endijs on 29.10.2023.
//

#include <fstream>
#include <sstream>
#include <iostream>
#include <vector>
#include <algorithm>
#include "Studentu_PS.h"
#include "Students.h"
#include "Studiju_kurss.h"

Studentu_PS::Studentu_PS()
        : studenti{} {}

bool Studentu_PS::vai_ir_studenti_ievaditi() const {
    if (studenti.empty()) {
        cout << "Nav studentu" << endl;
        return false;
    } else {
        return true;
    }
}

bool Studentu_PS::meklet_studentu_pec_id(const string &id) const {
    for (auto &s: studenti) {
        if (s.get_id() == id) {
            return true;
        }
    }
    return false;
}

Students &Studentu_PS::students_pec_id(const string &id) {
    for (auto &s: studenti) {
        if (s.get_id() == id) {
            return s;
        }
    }
    throw runtime_error{"students nav atrasts: " + id};
}

const Students &Studentu_PS::students_pec_id(const string &id) const {

    for (const auto &s: studenti) {
        if (s.get_id() == id) {
            return s;
        }
    }
    throw runtime_error{"students ar id nav atrasts: " + id};

}

void Studentu_PS::pievienot_studentu(const Students &jauns_students) {
    if (meklet_studentu_pec_id(jauns_students.get_id()))
        throw runtime_error{"students ar id jau eksiste: " + jauns_students.get_id()};
    studenti.push_back(jauns_students);
    cout << endl << jauns_students.get_vards() << " pievienots\n";
}


void Studentu_PS::studenta_pievienosna_interaktivs() {

    Students jauns{};
    string id;
    string grupa;
    string vards;
    int studiju_gads;

    cout << "Ievadiet studenta id: ";
    cin >> id;
    jauns.set_id(id);

    cout << "Ievadiet studenta grupu: ";
    cin >> grupa;
    jauns.set_grupa(grupa);

    cout << "Ievadiet studenta vardu: ";
    cin >> vards;
    jauns.set_vards(vards);

    cout << "Ievadiet studenta studiju gadu: ";
    cin >> studiju_gads;
    jauns.set_studiju_gads(studiju_gads);

    pievienot_studentu(jauns);

}

// Funkcija, kas katram studentam no studentu saraksta izvada studenta
// identifikatoru, vārdu, viņa studiju kursu nosaukumus un atzīmes
void Studentu_PS::izvadit_info_par_studentiem() {
    if (vai_ir_studenti_ievaditi()) {
        for (auto &s: studenti) {
            s.izvadit_ekrana_kursus_atzimes();
        }
    }
}

//Funkcija, kas katram studentam no studentu saraksta izvada identifikatoru,
//studenta vārdu, vidējo atzīmi un vidējo svērto atzīmi.
void Studentu_PS::izvadit_studentu_vid_atzimes() {
    if (vai_ir_studenti_ievaditi()) {
        for (auto &s: studenti) {
            s.izvadit_ekrana_vid_atzimes();
        }
    }
}

//Funkcija, kas katram studentam izvada visu informāciju par studentu, ieskaitot
//informāciju par studiju kursiem.
void Studentu_PS::izvadit_visu_studentu_info() {
    if (vai_ir_studenti_ievaditi()) {
        for (auto &s: studenti) {
            s.izvadit_ekrana_visu();
        }
    }
}


void Studentu_PS::atrast_studentu_ar_id() {
    if (vai_ir_studenti_ievaditi()) {
        Students atrastais;
        string id;
        cout << "Ievadiet studenta id: ";
        cin >> id;
        atrastais = students_pec_id(id);
        atrastais.izvadit_ekrana_visu();
    }
}

Studiju_kurss &Studentu_PS::atrast_studentu_kursu_pec_id(const string &id) {
    for (auto &x: kursi_no_faila) {
        if (x.get_id() == id) {
            return x;
        }
    }
    throw runtime_error("Kurss nav atrasts: " + id);
}

void Studentu_PS::kursu_pievienosana() {
    if (vai_ir_studenti_ievaditi()) {
        string kursu_id, stud_id;
        string nosaukums;
        int kred_punkti;
        int atzime;

        cout << "Ievadiet studenta id: ";
        cin >> stud_id;
        students_pec_id(stud_id).izvadit_ekrana_kursus_atzimes();
        for (auto &x: kursi_no_faila) {
            x.kursa_informacija_id_nosaukums_kp();
        }
        cout << "Ievadiet vēlamā kursa id: \n";
        cin >> kursu_id;
        students_pec_id(stud_id).pievienot_kursu(atrast_studentu_kursu_pec_id(kursu_id));

    }
}

void Studentu_PS::ievadit_kursus_no_faila() {
    string id, nosaukums;
    int kred_punkti;

    ifstream inputFile("C:/Users/cice3/CLionProjects/homework1/kursi.txt");
    if (!inputFile.is_open()) {
        cout << "Kļūda kursi.txt atveršanā" << endl;
        return;
    }
    string line;
    while (getline(inputFile, line)) {
        istringstream iss(line);
        iss >> id >> nosaukums >> kred_punkti;

        kursi_no_faila.push_back({id, nosaukums, kred_punkti, -1});
    }
    inputFile.close();
}

void Studentu_PS::ievadit_atzimi_kursam() {
    string stud_id, kursa_id;
    int atzime;

    cout << "Ievadiet studenta id: ";
    cin >> stud_id;
    students_pec_id(stud_id).izvadit_ekrana_visu();

    cout << "Ievadiet kursa id: ";
    cin >> kursa_id;
    students_pec_id(stud_id).kurss_pec_id(kursa_id);

    cout << "Ievadiet atzīmi: ";
    cin >> atzime;
    students_pec_id(stud_id).kurss_pec_id(kursa_id).set_atzime(atzime);

    cout << "Studentam " << stud_id << " pievienota atzīme " << atzime << "kursā ar id " << kursa_id << endl;
}


bool salidzinat_videjo(Students &a, Students &b) {
    return a.videja_sverta_atzime() > b.videja_sverta_atzime();
}

void Studentu_PS::studenta_saraksta_kartosana() {
    if (vai_ir_studenti_ievaditi()) {
        sort(studenti.begin(), studenti.end(), salidzinat_videjo);
    }
}

void Studentu_PS::saskarne_ar_lietotaju() {
    bool stradat = true;
    int izvele;
    ievadit_kursus_no_faila();
    do {
        //system("clear");
        izvades_iespejas();
        cin >> izvele;
        switch (izvele) {
            case 1:
                cout << "\nIzvēlēts Studenta saraksta papildinasana (1) \n";
                studenta_pievienosna_interaktivs();
                pauze_pec_case_izpildes();
                break;
            case 2:
                cout << "\nIzvēlēts Studenta meklēšana pēc id(2)\n";
                atrast_studentu_ar_id();
                pauze_pec_case_izpildes();
                break;
            case 3:
                cout << "\nizvēlēts Studiju kursa pievienošana (3)\n";
                kursu_pievienosana();
                pauze_pec_case_izpildes();
                break;
            case 4:
                cout << "\nizvēlēts Atzīmes ievadīšana (4)\n";
                ievadit_atzimi_kursam();
                pauze_pec_case_izpildes();
                break;
            case 5:
                cout << "\nIzvēlēts visa studentu saraksta izvadīšana pilna (5)\n";
                izvadit_visu_studentu_info();
                pauze_pec_case_izpildes();
                break;
            case 6:
                cout << "\nIzvēlēts visa studentu saraksta izvadīšana ar nepilnu informāciju (6)\n";
                izvadit_studentu_vid_atzimes();
                pauze_pec_case_izpildes();
                break;
            case 7:
                cout << "\n Izvēlēts studentu saraksta kārtošana (7)\n";
                studenta_saraksta_kartosana();
                pauze_pec_case_izpildes();
                break;
            case 8:
                stradat = false;
                break;
            default:
                cout << "Nepareiza ievade" << endl;
                break;
        }
    } while (stradat);
}


void izvades_iespejas() {
    cout << "Studenta saraksta papildinasana (1)" << endl
         << "Studenta meklēšana (2)" << endl
         << "Studiju kursa pievienošana (3)" << endl
         << "Atzīmes ievadīšana (4)" << endl
         << "Visa studentu saraksta izvadīšana pilna (5)" << endl
         << "Visa studentu saraksta izvadīšana ar nepilnu informāciju (6)" << endl
         << "Studentu saraksta kārtošana (7)" << endl
         << "Beigt darbu (8)" << endl;
};

void pauze_pec_case_izpildes() {
    string tmp;
    cout << "Ievadiet jebkuru simbolu, lai turpinātu" << endl;
    cin >> tmp;
}

