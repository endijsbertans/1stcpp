//
// Created by Endijs on 10/28/2023.
//

#ifndef HOMEWORK1_STUDENTS_H
#define HOMEWORK1_STUDENTS_H
#include "Studiju_kurss.h"
#include <vector>
class Students {
private:
    string id;
    string grupa;
    string vards;
    int studiju_gads;
    vector<Studiju_kurss> studiju_kursi{};
public:
    Students();
    Students(const string& id, const string& grupa, const string& vards, int studiju_gads);
    Students(const string& id, const string& grupa, const string& vards, int studiju_gads, const vector<Studiju_kurss>& studiju_kursi);
    // parbaudes
    int parbaudit_sg(int studiju_gads);
    // getters
    const string &get_id() const;
    const string &get_grupa() const;
    const string &get_vards() const;
    int get_studiju_gads() const;
    const vector<Studiju_kurss> &get_studiju_kursi() const;
    // setters
    void set_id(const string &id);
    void set_grupa(const string &grupa);
    void set_vards(const string &vards);
    void set_studiju_gads(int studijuGads);
    void set_studiju_kursi(const vector<Studiju_kurss> &studijuKursi);
    // meklēšana

    bool vai_ir_kurss(const string& nosaukums);
    Studiju_kurss& kurss_pec_nosaukuma(const string& nosaukums);
    const Studiju_kurss& kurss_pec_nosaukuma(const string& nosaukums) const;

    Studiju_kurss& operator[](int i);
    const Studiju_kurss& operator[](int i) const;

    void pievienot_kursu(const Studiju_kurss& kurss);
    void pievienot_kursus(const vector<Studiju_kurss>& kursi);
    double videja_atzime();
    double videja_sverta_atzime();

    void izvadit_ekrana();
    void izvadit_ekrana_vid_atzimes();
        void izvadit_ekrana_visu();
};


#endif //HOMEWORK1_STUDENTS_H
