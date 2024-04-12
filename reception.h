#define _CRT_SECURE_NO_WARNINGS

#include "fio.h"
#include "funcs.h"
#include "date.h"

class reception: public fio {
private:
    char *name;
    char *fam;
    int patients;
    date appointment;
public:
    reception();

    reception(char*, char*, int, date);

    ~reception();

    friend std::istream &operator>>(std::istream &, reception &);

    int get_patients();

    void set_patients(int);

    const char* get_date();

    void set_date(int, int, int);
};