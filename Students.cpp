//
// Created by Endijs on 10/28/2023.
//

#include "Students.h"
#include <vector>
#include "Studiju_kurss.h"
#include <iostream>
#include <cassert>
#include <iomanip>
#include <string>

using namespace std;

Students::Students()
        : id{""}, grupa{""}, vards{""}, studiju_gads{1} {
    Studiju_kurss a{};
    studiju_kursi.push_back(a);
}

Students::Students(const string &id, const string &grupa, const string &vards, int studiju_gads)
        : id{id}, grupa{grupa}, vards{vards}, studiju_gads{parbaudit_sg(studiju_gads)} {}

Students::Students(const string &id, const string &grupa, const string &vards, int studiju_gads,
                   const vector<Studiju_kurss> &studiju_kursi)
        : id{id}, grupa{grupa}, vards{vards}, studiju_gads{parbaudit_sg(studiju_gads)}, studiju_kursi{studiju_kursi} {}

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
    throw runtime_error("Kurss nav atrasts: " + nosaukums);
}

const Studiju_kurss &Students::kurss_pec_nosaukuma(const string &nosaukums) const {
    for (const auto &x: studiju_kursi) {
        if (x.get_nosaukums() == nosaukums) {
            return x;
        }
    }
    throw runtime_error("Kurss nav atrasts: " + nosaukums);
}

Studiju_kurss &Students::kurss_pec_id(const string &k_id) {
    for (auto &x: studiju_kursi) {
        //cout << "x id = " << x.get_id() << endl;
        //cout << "k id = " << k_id << endl;
        if (x.get_id() == k_id) {
            return x;
        }
    }
    throw runtime_error("Kurss nav atrasts: " + id);
}

const Studiju_kurss &Students::kurss_pec_id(const string &k_id) const {

    for (const auto &x: studiju_kursi) {
        if (x.get_id() == k_id) {
            return x;
        }
    }
    throw runtime_error("Kurss nav atrasts: " + id);
}

bool Students::vai_ir_kurss(const string &nosaukums) {
    for (const auto &x: studiju_kursi) {
        if (x.get_nosaukums() == nosaukums) {
            return true;
        }
    }
    return false;
}


Studiju_kurss &Students::operator[](int i) {
    assert(i >= 0 && i < studiju_kursi.size());
    return studiju_kursi.at(i);
}

const Studiju_kurss &Students::operator[](int i) const {
    assert(i >= 0 && i < studiju_kursi.size());
    return studiju_kursi.at(i);
}

void Students::pievienot_kursu(const Studiju_kurss &kurss) {
    if (vai_ir_kurss((kurss.get_nosaukums()))) {
        throw runtime_error{"kurss jau pastāv: " + kurss.get_nosaukums()};
    } else {
        studiju_kursi.push_back(kurss);
    }
}

void Students::pievienot_kursus(const vector<Studiju_kurss> &kursi) {
    for (const auto &x: kursi) {
        if (id == x.get_id()) {
            throw runtime_error{"kurss jau pastāv: " + x.get_nosaukums()};
        } else {
            studiju_kursi.push_back(x);
        }

    }
}

double Students::videja_atzime() {
    double videjais{};
    double kop_prieksmeti{};

    for (const auto &x: studiju_kursi) {
        if (x.get_atzime() == -1) {
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

    for (const auto &x: studiju_kursi) {
        if (x.get_atzime() == -1) {
            continue;
        }
        videjais += (x.get_atzime() * x.get_kred_punkti());
        kop_kp += x.get_kred_punkti();
    }
    videjais /= kop_kp;

    return videjais;
}

void Students::izvadit_ekrana_kursus_atzimes() {
    cout << "Id: " << id << endl
         << "Vārds: " << vards << endl;
    if (parbaudit_vai_ievaditi_kursi_un_atzimes()) {
        cout << "Kursi: " << endl;
        for (const auto &x: studiju_kursi) {
            if (x.get_nosaukums() == "") {
                continue;
            } else {
                x.kursa_informacija_ar_atzimi();
            }
        }
    } else {
        cout << "!!Nav ievadīti kursi, kursus nerādīs!!\n";
    }

}

void Students::izvadit_ekrana_vid_atzimes() {
    if (parbaudit_vai_ievaditi_kursi_un_atzimes()) {
        cout << fixed << setw(12) << left << "pers id:" << " | " << setw(20) << left << "vārds:" << " | " << setw(15)
             << left << "Vid atzīme:" << " | " << setw(20) << left << "Videja Svērtā atzīme::" << endl;
        cout << fixed << setw(12) << left << id << " | " << setw(20) << left << vards << " | " << setw(15) << left
             << videja_atzime() << " | " << setw(20) << left << videja_sverta_atzime() << endl;
    } else {
        cout << "!!Nav ievadīti kursi, vidējo nērādīs!!\n";
    }
}

void Students::izvadit_ekrana_visu() {

    cout << "Studiju gads: " << studiju_gads << endl;
    izvadit_ekrana_kursus_atzimes();

    izvadit_ekrana_vid_atzimes();

    cout << "\n---------------------------------\n";
}

bool Students::parbaudit_vai_ievaditi_kursi_un_atzimes() {
    for (const auto &x: studiju_kursi) {
        if (studiju_kursi.size() < 2) {
            return false;
        } else if (x.get_atzime() == -1) {
            continue;
        }
    }
    return true;
}
