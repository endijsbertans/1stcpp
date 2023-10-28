//
// Created by Endijs on 10/28/2023.
//

#include "Students.h"
#include <vector>
#include "Studiju_kurss.h"
#include <iostream>
#include <cassert>
#include <iomanip>
using namespace std;

Students::Students()
    : id{""}, grupa{""}, vards{""}, studiju_gads{1}, studiju_kursi{}{}

Students::Students(const string &id, const string &grupa, const string &vards, int studiju_gads)
    : id{id}, grupa{grupa}, vards{vards}, studiju_gads{parbaudit_sg(studiju_gads)}{}

Students::Students(const string &id, const string &grupa, const string &vards, int studiju_gads,const vector<Studiju_kurss> &studiju_kursi)
    : id{id}, grupa{grupa}, vards{vards}, studiju_gads{parbaudit_sg(studiju_gads)}, studiju_kursi{studiju_kursi}{}

int Students::parbaudit_sg(int studiju_gads) {
    assert(studiju_gads >= 1 && studiju_gads <= 4);
    return studiju_gads;
}

const string &Students::get_id() const {
    return id;
}

const string &Students::get_grupa() const {
    return grupa;
}

const string &Students::get_vards() const {
    return vards;
}

int Students::get_studiju_gads() const {
    return studiju_gads;
}

const vector<Studiju_kurss> &Students::get_studiju_kursi() const {
    return studiju_kursi;
}

void Students::set_id(const string &id) {
    Students::id = id;
}

void Students::set_grupa(const string &grupa) {
    Students::grupa = grupa;
}

void Students::set_vards(const string &vards) {
    Students::vards = vards;
}

void Students::set_studiju_gads(int studijuGads) {
    studiju_gads = studijuGads;
}

void Students::set_studiju_kursi(const vector<Studiju_kurss> &studijuKursi) {
    studiju_kursi = studijuKursi;
}

Studiju_kurss &Students::kurss_pec_nosaukuma(const string &nosaukums) {

    for (auto &x: studiju_kursi) {
        if (x.get_nosaukums() == nosaukums) {
            return x;
        }
    }
    throw runtime_error("Course not found: " + nosaukums);

}

const Studiju_kurss &Students::kurss_pec_nosaukuma(const string &nosaukums) const {
    for (const auto &x: studiju_kursi) {
        if (x.get_nosaukums() == nosaukums) {
            return x;
        }
    }
    throw runtime_error("Course not found: " + nosaukums);
}

bool Students::vai_ir_kurss(const string &nosaukums) {
    for(const auto& x : studiju_kursi){
        if(x.get_nosaukums() == nosaukums ){
            return true;
        }
    }
    return false;
}


Studiju_kurss& Students::operator[](int i) {
    assert(i >= 0 && i < studiju_kursi.size());
    return studiju_kursi.at(i);
}

const Studiju_kurss& Students::operator[](int i) const {
    assert(i >= 0 && i < studiju_kursi.size());
    return studiju_kursi.at(i);
}

void Students::pievienot_kursu(const Studiju_kurss &kurss) {
    if(vai_ir_kurss((kurss.get_nosaukums()))){
        //throw string{"Course already exists: " + kurss.get_nosaukums()};
    }else{
        studiju_kursi.push_back(kurss);
    }
}

void Students::pievienot_kursus(const vector<Studiju_kurss> &kursi) {
    for(const auto& x : kursi){
        if(id == x.get_id()){
            throw string{"Course already exists: " + x.get_id()};
        } else {
            studiju_kursi.push_back(x);
        }

    }
}

double Students::videja_atzime() {
    double videjais{};
    double kop_prieksmeti{};
    for(const auto& x : studiju_kursi){
        if(x.get_atzime() == -1){
            continue;
        }
        videjais += x.get_atzime();
        kop_prieksmeti++;
    }
    videjais /= kop_prieksmeti;
    return videjais;
}

double Students::videja_sverta_atzime() {
    double videjais{};
    int kop_kp{};

    for(const auto& x : studiju_kursi){
        if(x.get_atzime() == -1){
            continue;
        }
        videjais += ( x.get_atzime() * x.get_kred_punkti() );
        kop_kp += x.get_kred_punkti() ;
    }
    videjais /= kop_kp;
    return videjais;
}

void Students::izvadit_ekrana() {
    cout << "Id: " << id << endl
         << "Vārds: " << vards << endl
         << "Kursi: " << endl;
    for(const auto& x : studiju_kursi){
        cout << setw(40) << left <<"Kursa nosaukums: " << " | " << left << setw(20) << "Kursa atzīme: " << endl
             << setw(40) << left << x.get_nosaukums() << " | " << left << setw(20) << x.get_atzime() << "\n---" << endl;
    }
}

void Students::izvadit_ekrana_vid_atzimes() {

    cout << fixed << setw(12) << left << "pers id:" << " | " << setw(20) << left << "vārds:" << " | " << setw(15) << left << "Vid atzīme:" << " | " << setw(20) << left << "Videja Svērtā atzīme::" << endl;
    cout << fixed << setw(12) << left << id << " | " << setw(20) << left << vards << " | " << setw(15) << left << videja_atzime() << " | " << setw(20) << left << videja_sverta_atzime() << endl;
    cout << "---" << endl;
}

void Students::izvadit_ekrana_visu() {

    cout << "Kursi: " << endl;

    for(const auto& x : studiju_kursi){
        cout << fixed << setw(12) << left << "Kursa id:" << " | " << setw(40) << left << "Kursa nosaukums:" << " | " << setw(15) << left << "Kursa atzīme:" << " | " << setw(20) << left << "Kursa kredītpunkti:" << endl;
        cout << fixed << setw(12) << left << x.get_id() << " | " << setw(40) << left << x.get_nosaukums() << " | " << setw(15) << left << x.get_atzime() << " | " << setw(20) << left << x.get_kred_punkti() << endl;
        cout << "---" << endl;
    }
    cout << fixed << setw(12) << left << "pers id:" << " | " << setw(20) << left << "vārds:" << " | " << setw(15) << left << "Grupa:" << " | " << setw(20) << left << "Studiju gads:" << " | " << setw(15) << left << "Vid atzīme:" << " | " << setw(20) << left << "Videja Svērtā atzīme::" << endl;;
    cout << fixed << setw(12) << left << id << " | " << setw(20) << left << vards << " | " << setw(15) << left << grupa << " | " << setw(20) << left << studiju_gads  <<" | " << setw(15) << left << videja_atzime() << " | " << setw(20) << left << videja_sverta_atzime() << endl;

    cout << "\n---------------------------------\n";
}
