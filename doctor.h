#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include "fio.h"
#include "funcs.h"

const char specs[3][21] = {"терапевт", "кардиолог", "стоматолог"};

const char quals[3][13] = {"высшая", "первая", "вторая"};

enum SpecType {
    TER = 1,
    CAR = 2,
    STO = 3
};

enum QualType {
    HIGH,
    FIRST,
    SECOND
};

class doctor: public fio{
private:
    char *name;
    char *fam;
    SpecType spec;
    QualType qual;
    static int count;
public:
    doctor();

    doctor(char *, char *, SpecType, QualType);

    doctor(doctor &);

    ~doctor();

    doctor &operator=(doctor &);

    friend std::istream &operator>>(std::istream &, doctor &);

//    bool operator==(fio &);

    SpecType get_enum_spec();

    const char *get_spec();

    void set_spec(SpecType);

    QualType get_enum_qual();

    const char *get_qual();

    void set_qual(QualType);

    static int get_count();

    static void count_up();
};