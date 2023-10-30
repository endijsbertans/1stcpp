#include <iostream>
#include <vector>
#include "Studiju_kurss.h"
#include "testi.h"
#include "Studentu_PS.h"
#include "Students.h"

using namespace std;

int main() {

    studiju_kurss_tests();
    students_tests();
    test_of_studentPS();
    Studentu_PS studenti{};
    studenti.saskarne_ar_lietotaju();
    return 0;
}
