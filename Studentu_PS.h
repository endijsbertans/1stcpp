//
// Created by Endijs on 29.10.2023.
//

#ifndef HOMEWORK1_STUDENTU_PS_H
#define HOMEWORK1_STUDENTU_PS_H

#include <vector>
#include <string>
#include "Students.h"
#include "Studiju_kurss.h"
class Studentu_PS {
private:
    vector<Students> studenti{};
public:
    Studentu_PS();
    vector<Studiju_kurss> kursi_no_faila{};
    bool meklet_studentu_pec_id(const string& id) const;
    Students& students_pec_id(const string& id);
    const Students& students_pec_id(const string& id) const;
    void pievienot_studentu(const Students& jauns_students);
    void pievienot_studentu(const string& id, const string& grupa, const string& vards, int studiju_gads);

    void izvadit_info_par_studentiem();
    void izvadit_studentu_vid_atzimes();
    void izvadit_visu_studentu_info();

    void atrast_studentu_ar_id();
    void kursu_pievienosana();
    void studenta_pievienosna();
    void saskarne_ar_lietotaju();

    void ievadit_kursus_no_faila();
    Studiju_kurss &atrast_studentu_kursu_pec_id(const string &id);
    void ievadit_atzimi_kursam();
    void pilna_izvade();
    void izvadit_id_vards_vid_atzime();
};
void izvades_iespejas();
void pauze_pec_case_izpildes();
#endif //HOMEWORK1_STUDENTU_PS_H
