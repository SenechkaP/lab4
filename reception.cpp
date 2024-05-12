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
    char patients_buff[256];

    fio new_initials;
    is >> new_initials;

    bool condition = true;

    long patients;
    while (condition) {
        std::cout << "Введите число пациентов\n\n";
        is >> patients_buff;

        try {
            patients = check_int(patients_buff);
        }

        catch (int code) {
            std::cout << "Число пациентов - целое число\n\n";
            continue;
        }
        condition = false;
    }

    date new_date;
    is >> new_date;

    recep.set_fam(new_initials.get_fam());
    recep.set_name(new_initials.get_name());
    recep.set_patients(patients);
    recep.set_date(new_date.get_day(), new_date.get_month(), new_date.get_year());

    return is;
}

std::ostream &operator<<(std::ostream &os, reception &recep) {
    os << std::left << std::setw(30) << recep.get_fam() << std::setw(30)
       << recep.get_name() << std::setw(30)
       << recep.get_patients() << std::setw(30) << recep.get_date() << std::endl;
    return os;
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

void reception::make_appointment() {
    if (this->patients == 0) {
        throw "У данного врача нет свободных мест для записи\n\n";
    } else {
        this->patients -= 1;
    }
}