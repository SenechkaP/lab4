#define _CRT_SECURE_NO_WARNINGS

#include "fio.h"
#include "funcs.h"
#include "date.h"
#include <iomanip>

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

    reception &operator=(reception &);

    friend std::istream &operator>>(std::istream &, reception &);

    friend std::ostream &operator<<(std::ostream &, reception &);

    int get_patients();

    void set_patients(int);

    const char* get_date();

    date get_appointment();

    void set_date(int, int, int);

    void make_appointment();
};