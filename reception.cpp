#define _CRT_SECURE_NO_WARNINGS

#include "reception.h"

reception::reception() {}

reception::~reception() {}

reception::reception(char *fam, char *name, int patients, date some_date) {
    this->set_fam(fam);
    this->set_name(name);
    this->patients = patients;
    this->appointment = some_date;
}

reception &reception::operator=(reception &rep) {
    if (&rep != this) {
        this->set_fam(rep.get_fam());
        this->set_name(rep.get_name());
        this->patients = rep.get_patients();
        this->appointment = rep.appointment;
    }
    return *this;
}

std::istream &operator>>(std::istream &is, reception &recep) {
    char fam_buff[256];
    char name_buff[256];
    char patients_buff[256];
    char day_buff[256];
    char month_buff[256];
    char year_buff[256];

    bool condition = true;

    while (condition) {
        std::cout << "Введите фамилию, имя (доктора), число пациентов, день, месяц, год даты приема\n";
        is >> fam_buff >> name_buff >> patients_buff >> day_buff >> month_buff >> year_buff;

        long day = check_int(day_buff);
        long month = check_int(month_buff);
        long year = check_int(year_buff);
        long patients = check_int(patients_buff);

        std::cout << std::endl;

        if (!(check_str(fam_buff) && check_str(name_buff) && day >= 1 && day <= 31 && month >= 1 && month <= 12 &&
              year >= 0 && patients >= 0)) {
            std::cout << "Введите данные корректно\n\n";
        } else {
            recep.set_fam(fam_buff);
            recep.set_name(name_buff);
            recep.set_patients(patients);
            recep.set_date(day, month, year);
            condition = false;
        }
    }
    return is;
}

int reception::get_patients() {
    return this->patients;
}

void reception::set_patients(int patients) {
    this->patients = patients;
}

const char *reception::get_date() {
    return this->appointment.get_date();
}

date reception::get_appointment() {
    return this->appointment;
}

void reception::set_date(int day, int month, int year) {
    this->appointment.set_date(day, month, year);
}