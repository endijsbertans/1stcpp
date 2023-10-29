//
// Created by Endijs on 10/28/2023.
//

#ifndef HOMEWORK1_STUDIJU_KURSS_H
#define HOMEWORK1_STUDIJU_KURSS_H

#include <string>
#include <iostream>

using namespace std;

class Studiju_kurss {
private:
    string id;
    string nosaukums;
    int kred_punkti;
    int atzime;
public:
    // constructors
    Studiju_kurss();
    Studiju_kurss(const string &id, const string &nosaukums, int kred_punkti);
    Studiju_kurss(const string &id, const string &nosaukums, int kred_punkti, int atzime);

    // parbaudes
    int parbaudit_kp(int kred_punkti);
    int parbaudit_atz(int atzime);

    // getters
    const string &get_id() const;
    const string &get_nosaukums() const;
    int get_kred_punkti() const;
    int get_atzime() const;

    // setters
    void set_id(const string &id);
    void set_nosaukums(const string &nosaukums);
    void set_kred_punkti(int kred_punkti);
    void set_atzime(int atzime);

    // operators
    void kursa_informacija() const;
    friend std::ostream &operator<<(std::ostream &out, const Studiju_kurss &s);

};


#endif //HOMEWORK1_STUDIJU_KURSS_H
