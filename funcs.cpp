#define _CRT_SECURE_NO_WARNINGS

#include "funcs.h"

int check_str(char *str) {
    for (int i = 0; str[i] != '\0'; i++) {
        if (!isalpha(str[i])) {
            throw -1;
        }
    }
    return 1;
}

long check_int(char *input) {
    long result;
    char *endptr;

    result = strtol(input, &endptr, 10);

    if (*endptr != '\0') {
        throw -1;
    }
    return result;
}

long check_spec(char *input) {
    long result;
    char *endptr;

    result = strtol(input, &endptr, 10);

    if (*endptr != '\0') {
        throw -1;
    } else if (result < 1 || result > 3) {
        throw "Нет такой специальности\n\n";
    }

    return result;
}

long check_qual(char *input) {
    long result;
    char *endptr;

    result = strtol(input, &endptr, 10);

    if (*endptr != '\0') {
        throw -1;
    } else if (result < 0 || result > 2) {
        throw "Нет такой квалификации\n\n";
    }

    return result;
}

int check_date(long day, long month, long year) {
    if (day < 1 || day > 31 || month < 1 || month > 12 || year < 0) {
        throw "Введите дату корректно\n\n";
    } else if (month == 2 && day > 29) {
        throw "В феврале максимум 29 дней\n\n";
    } else if (month == 2 && day == 29 && year % 4 != 0) {
        throw "В не високосном году в феврале 28 дней\n\n";
    }

    return 1;
}