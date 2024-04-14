#define _CRT_SECURE_NO_WARNINGS

#include "date.h"

date::date() {}

date::~date() {}

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

bool date::operator==(date other_date) {
    return day == other_date.day && month == other_date.month && year == other_date.year;
}

bool date::operator>(date other_date) {
    if (year != other_date.year) {
        return year > other_date.year;
    } else if (month != other_date.month) {
        return month > other_date.month;
    } else {
//        std::cout << "мы здесь\n";
        return day > other_date.day;
    }
}

std::istream &operator>>(std::istream &is, date &cur_date) {
    char day_buff[256];
    char month_buff[256];
    char year_buff[256];

    bool condition = true;

    while (condition) {
        std::cout << "Введите день, месяц, год даты приема\n";
        is >> day_buff >> month_buff >> year_buff;

        long day = check_int(day_buff);
        long month = check_int(month_buff);
        long year = check_int(year_buff);

        std::cout << std::endl;

        if (!(day >= 1 && day <= 31 && month >= 1 && month <= 12 && year >= 0)) {
            std::cout << "Введите данные корректно\n\n";
        } else {
            cur_date.set_date(day, month, year);
            condition = false;
        }
    }
    return is;
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