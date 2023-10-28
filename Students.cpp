//
// Created by Endijs on 10/28/2023.
//

#include "Students.h"
#include <vector>
#include "Studiju_kurss.h"
#include <iostream>
#include <cassert>

using namespace std;

Students::Students()
    : id{""}, grupa{""}, vards{""}, studiju_gads{1}, studiju_kursi{}{}

Students::Students(const string &id, const string &grupa, const string &vards, int studiju_gads)
    : id{id}, grupa{grupa}, vards{vards}, studiju_gads{studiju_gads}{}

Students::Students(const string &id, const string &grupa, const string &vards, int studiju_gads,const vector<Studiju_kurss> &studiju_kursi)
    : id{id}, grupa{grupa}, vards{vards}, studiju_gads{studiju_gads}, studiju_kursi{studiju_kursi}{}

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

bool Students::vai_ir_kurss_id(const string &id) {
    for(const auto& x : studiju_kursi){
        if(x.get_id() == id){
            return true;
        }
    }
    return false;
}

bool Students::vai_ir_kurss_nos(const string &nosaukums) {
    for(const auto& x : studiju_kursi){
        if(x.get_id() == id ){
            return true;
        }
    }
    return false;
}
