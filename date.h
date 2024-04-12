#define _CRT_SECURE_NO_WARNINGS

#include "funcs.h"
#include <iostream>

class date {
private:
    int day;
    int month;
    int year;
public:
    date();

    date(int, int, int);

    ~date();

    date &operator=(date &);

    const char* get_date();

    int get_day();

    int get_month();

    int get_year();

    void set_date(int, int, int);
};