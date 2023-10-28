//
// Created by Endijs on 10/28/2023.
//

#include "Studiju_kurss.h"
#include <string>
#include <cassert>
#include <iostream>
using namespace std;

Studiju_kurss::Studiju_kurss()
    : id{""}, nosaukums{""}, kred_punkti{0}, atzime{-1} {}

Studiju_kurss::Studiju_kurss(const string &id, const string &nosaukums, int kred_punkti)
    : id{id}, nosaukums{nosaukums}, kred_punkti{parbaudit_kp(kred_punkti)}{}

Studiju_kurss::Studiju_kurss(const string &id, const string &nosaukums, int kred_punkti, int atzime)
    : id{id}, nosaukums{nosaukums}, kred_punkti{parbaudit_kp(kred_punkti)}, atzime{parbaudit_atz(atzime)}{}

int Studiju_kurss::parbaudit_kp(int kred_punkti) {
    assert(kred_punkti > 0);
    return kred_punkti;
}

int Studiju_kurss::parbaudit_atz(int atzime) {
    assert(atzime >= -1 && atzime <= 10);
    return atzime;
}

const string &Studiju_kurss::get_id() const {
    return id;
}

const string &Studiju_kurss::get_nosaukums() const {
    return nosaukums;
}

int Studiju_kurss::get_kred_punkti() const {
    return kred_punkti;
}

int Studiju_kurss::get_atzime() const {
    return atzime;
}

void Studiju_kurss::set_id(const string &id) {
    Studiju_kurss::id = id;
}

void Studiju_kurss::set_nosaukums(const string &nosaukums) {
    this -> nosaukums = nosaukums;
}

void Studiju_kurss::set_kred_punkti(int kred_punkti) {
    this -> kred_punkti = kred_punkti;
}

void Studiju_kurss::set_atzime(int atzime) {
    Studiju_kurss::atzime = atzime;
}

ostream &operator<<(ostream &out, const Studiju_kurss &s) {
    out << "Id: " << s.id << "\n Nos: " << s.nosaukums << "\n Kp: " << s.kred_punkti << "\n atzīme: " << s.atzime;
    return out;
}

void Studiju_kurss::kursa_informacija() {
    cout << "Id: " << id << "\n Nos: " << nosaukums << "\n Kp: " << kred_punkti;

}
