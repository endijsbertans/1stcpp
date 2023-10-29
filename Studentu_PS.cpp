//
// Created by Endijs on 29.10.2023.
//

#include <fstream>
#include <sstream>
#include <iostream>
#include <vector>
#include "Studentu_PS.h"
#include "Students.h"
#include "Studiju_kurss.h"

Studentu_PS::Studentu_PS()
    : studenti{}{}

bool Studentu_PS::meklet_studentu_pec_id(const string &id) const{

    for (auto &s : studenti){
        if (s.get_id() == id) {
            return true;
        }
    }
    return false;
}

Students &Studentu_PS::students_pec_id(const string &id) {
    for (auto &s : studenti){
        if (s.get_id() == id) {
            return s;
        }
    }
    throw runtime_error{"students nav atrasts: " + id};
}

const Students &Studentu_PS::students_pec_id(const string &id) const {
    for (const auto &s : studenti){
        if (s.get_id() == id) {
            return s;
        }
    }
    throw runtime_error{"students nav atrasts: " + id};
}

void Studentu_PS::pievienot_studentu(const Students &jauns_students) {
    if(meklet_studentu_pec_id(jauns_students.get_id()))
        throw runtime_error{"students jau eksiste: " + jauns_students.get_id()};
    studenti.push_back(jauns_students);
}

void Studentu_PS::pievienot_studentu(const string& id, const string& grupa, const string& vards, int studiju_gads){
    if(meklet_studentu_pec_id(id))
        throw runtime_error{"students jau eksiste: " + id};
    studenti.push_back({id, grupa, vards, studiju_gads});
    cout << endl << vards <<  " pievienots\n";
}

// Funkcija, kas katram studentam no studentu saraksta izvada studenta
// identifikatoru, vārdu, viņa studiju kursu nosaukumus un atzīmes
void Studentu_PS::izvadit_info_par_studentiem() {
    for (auto &s : studenti){
        s.izvadit_ekrana();
    }
}
//Funkcija, kas katram studentam no studentu saraksta izvada identifikatoru,
//studenta vārdu, vidējo atzīmi un vidējo svērto atzīmi.
void Studentu_PS::izvadit_studentu_vid_atzimes() {
    for (auto &s : studenti){
        s.izvadit_ekrana_vid_atzimes();
    }
}
//Funkcija, kas katram studentam izvada visu informāciju par studentu, ieskaitot
//informāciju par studiju kursiem.
void Studentu_PS::izvadit_visu_studentu_info() {
    for (auto &s : studenti){
        s.izvadit_ekrana_visu();
    }
}

void Studentu_PS::studenta_pievienosna() {
    string id;
    string grupa;
    string vards;
    int studiju_gads;
    cout << "Ievadiet studenta id: ";
    cin >> id;
    cout << "Ievadiet studenta grupu: ";
    cin >> grupa;
    cout << "Ievadiet studenta vardu: ";
    cin >> vards;
    cout << "Ievadiet studenta studiju gadu: ";
    cin >> studiju_gads;
    pievienot_studentu(id, grupa, vards, studiju_gads);
}
void Studentu_PS::atrast_studentu_ar_id(){
    Students atrastais;
    string id;
    cout << "Ievadiet studenta id: ";
    cin >> id;
    atrastais = students_pec_id(id);
    atrastais.izvadit_ekrana_visu();
}
Studiju_kurss &Studentu_PS::atrast_studentu_kursu_pec_id(const string &id){
    for ( auto &x: kursi_no_faila) {
        if (x.get_id() == id) {
            return x;
        }
    }
    throw runtime_error("Kurss nav atrasts: " + id);
}
void Studentu_PS::kursu_pievienosana(){
    string kursu_id, stud_id;
    string nosaukums;
    int kred_punkti;
    int atzime;
    cout << "Ievadiet studenta id: ";
    cin >> stud_id;
    students_pec_id(stud_id).izvadit_ekrana();
    for(auto &x : kursi_no_faila){
        x.kursa_informacija();
    }
    cout << "Ievadiet vēlamā kursa id: \n";
    cin >> kursu_id;
    students_pec_id(stud_id).pievienot_kursu(atrast_studentu_kursu_pec_id(kursu_id));
    //students_pec_id(id).pievienot_kursu(Studiju_kurss{id, nosaukums, kred_punkti, atzime});
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
        kursi_no_faila.push_back({id, nosaukums, kred_punkti});
    }
    inputFile.close();
}
void Studentu_PS::ievadit_atzimi_kursam(){
    string stud_id, kursa_id;
    Studentu_PS atz{};
    int atzime;
    cout << "Ievadiet studenta id: ";
    cin >> stud_id;
    students_pec_id(stud_id).izvadit_ekrana_visu();
    cout << "Ievadiet kursa id: ";
    cin >> kursa_id;
    students_pec_id(stud_id).kurss_pec_nosaukuma(kursa_id).kursa_informacija();
    cout << "Ievadiet atzīmi: ";
    cin >> atzime;
    students_pec_id(stud_id).kurss_pec_nosaukuma(kursa_id).set_atzime(atzime);

}
void Studentu_PS::pilna_izvade(){
    for(auto &x : studenti){
        x.izvadit_ekrana_visu();
    }
}
void Studentu_PS::izvadit_id_vards_vid_atzime(){
    for(auto &x : studenti){
        x.izvadit_ekrana_vid_atzimes();
    }
}

void Studentu_PS::saskarne_ar_lietotaju() {
    bool stradat = true;
    int izvele;
    ievadit_kursus_no_faila();
    do{
        //system("clear");
        izvades_iespejas();
        cin >> izvele;
        switch(izvele){
            case 1:
                cout << "\nIzvēlēts Studenta saraksta papildinasana (1) \n";
                studenta_pievienosna();
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
                cout << "\nIzvēlētsVisa studentu saraksta izvadīšana pilna (5)\n";
                pilna_izvade();
                pauze_pec_case_izpildes();
                break;
            case 6:
                cout << "\nVisa studentu saraksta izvadīšana ar nepilnu informāciju (6)\n";
                izvadit_id_vards_vid_atzime();
                pauze_pec_case_izpildes();
                break;
            case 7:

                break;
            case 8:

                break;
            case 9:
                stradat = false;
                break;
            default:
                cout << "Nepareiza ievade" << endl;
                break;
        }
    }while(stradat);
}



void izvades_iespejas(){
    cout << "Studenta saraksta papildinasana (1)" << endl
         << "Studenta meklēšana (2)" << endl
         << "Studiju kursa pievienošana (3)" << endl
         << "Atzīmes ievadīšana (4)" << endl
         << "Visa studentu saraksta izvadīšana pilna (5)" << endl
         << "Visa studentu saraksta izvadīšana ar nepilnu informāciju (6)" << endl
         << "Visa studenta saraksta izveidošana pilna (7)" << endl
         << "Studentu saraksta kārtošana (8)" << endl
         << "Beigt darbu (9)" << endl;
};

void pauze_pec_case_izpildes(){
    string tmp;
    cout << "Ievadiet jebkuru simbolu, lai turpinātu" << endl;
    cin >> tmp;
}

