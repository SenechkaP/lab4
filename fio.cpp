#define _CRT_SECURE_NO_WARNINGS

#include "fio.h"

fio::fio() {
    this->fam = nullptr;
    this->name = nullptr;
}

fio::fio(char *fam, char *name) {
    this->fam = new char[strlen(fam) + 1];
    this->name = new char[strlen(name) + 1];
    strcpy(this->fam, fam);
    strcpy(this->name, name);
}

fio::fio(fio &other_fio) {
    this->fam = other_fio.get_fam();
    this->name = other_fio.get_name();
}

fio::~fio() {
    delete[]fam;
    delete[]name;
//    std::cout << "deleted";
}

fio &fio::operator=(fio &other_fio) {
    if (&other_fio != this) {
        this->set_fam(other_fio.get_fam());
        this->set_name(other_fio.get_name());
    }
    return *this;
}

bool fio::operator==(fio &other_fio) {
    if ((strcmp(this->get_fam(), other_fio.get_fam()) == 0) && (strcmp(this->get_name(), other_fio.get_name()) == 0)) {
        return true;
    } else {
        return false;
    }
}

std::istream &operator>>(std::istream &is, fio &fio) {
    char fam_buff[256];
    char name_buff[256];

    std::cout << "Введите фамилию, имя:\n";
    std::cin >> fam_buff >> name_buff;

    while (!(check_str(fam_buff), check_str(name_buff))) {
        std::cout <<"Введите фамилию и имя корректно\n\n";
        std::cin >> fam_buff >> name_buff;
    }

    fio.set_fam(fam_buff);
    fio.set_name(name_buff);

    return is;
}

char *fio::get_fam() {
    char *fam_return = new char[strlen(this->fam) + 1];
    strcpy(fam_return, this->fam);
    return fam_return;
}

void fio::set_fam(char *fam) {
    if (this->fam) {
        delete[]this->fam;
    }
    this->fam = new char[strlen(fam) + 1];
    strcpy(this->fam, fam);
}

char *fio::get_name() {
    char *name_return = new char[strlen(this->name) + 1];
    strcpy(name_return, this->name);
    return name_return;
}

void fio::set_name(char *name) {
    if (this->name) {
        delete[]this->name;
    }
    this->name = new char[strlen(name) + 1];
    strcpy(this->name, name);
}