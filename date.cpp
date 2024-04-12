#define _CRT_SECURE_NO_WARNINGS

#include "date.h"

date::date() {}

date::~date(){}

date::date(int day, int month, int year) {
    this->day = day;
    this->month = month;
    this->year = year;
}

void date::set_date(int day, int month, int year) {
    this->day = day;
    this->month = month;
    this->year = year;
}

date &date::operator=(date &other_date) {
    if (&other_date != this) {
        this->day = other_date.get_day();
        this->month = other_date.get_month();
        this->year = other_date.get_year();
    }
    return *this;
}

int date::get_day() {
    return this->day;
}

int date::get_month() {
    return this->month;
}

int date::get_year() {
    return this->year;
}

const char *date::get_date() {
    int dateLength = 10;

    char *dateStr = new char[dateLength];

    dateStr[0] = day / 10 + '0';
    dateStr[1] = day % 10 + '0';
    dateStr[2] = '.';

    dateStr[3] = month / 10 + '0';
    dateStr[4] = month % 10 + '0';
    dateStr[5] = '.';

    dateStr[6] = year / 1000 + '0';
    dateStr[7] = (year % 1000) / 100 + '0';
    dateStr[8] = (year % 100) / 10 + '0';
    dateStr[9] = year % 10 + '0';

    dateStr[10] = '\0';

    return dateStr;
}