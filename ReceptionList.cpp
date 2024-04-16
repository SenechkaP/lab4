#define _CRT_SECURE_NO_WARNINGS

#include "ReceptionList.h"

ReceptionList::ReceptionList() {
    this->all_receptions = new reception[5];
    this->total_receptions = 0;
    this->capacity = 5;
}

ReceptionList::ReceptionList(int n) {
    this->all_receptions = new reception[n];
    this->total_receptions = 0;
    this->capacity = n;
}

ReceptionList::~ReceptionList() {
    delete[]this->all_receptions;
}

ReceptionList &ReceptionList::operator=(ReceptionList &other_list) {
    total_receptions = other_list.get_total_receptions();
    capacity = other_list.get_capacity();
    reception *array = other_list.get_array();
    all_receptions = new reception[total_receptions];

    for (int i = 0; i < total_receptions; i++) {
        all_receptions[i] = array[i];
    }
    return *this;
}

int ReceptionList::get_total_receptions() {
    return total_receptions;
}

int ReceptionList::get_capacity() {
    return capacity;
}

reception *ReceptionList::get_array() {
    return all_receptions;
}

void ReceptionList::add_reception(reception &rec) {
    if (total_receptions + 1 > capacity) {
        reception *temp = new reception[(total_receptions * 3) / 2 + 1];
        for (int i = 0; i < total_receptions; i++) {
            temp[i] = all_receptions[i];
        }
        delete[] all_receptions;
        all_receptions = temp;
        capacity = total_receptions * 3 / 2 + 1;
    }
    all_receptions[total_receptions] = rec;
    total_receptions += 1;
    std::cout << "Запись о приеме добавлена\n";
}

void ReceptionList::print_receptions() {
    if (total_receptions == 0) {
        std::cout << "Нет записей о приемах в базе\n";
        return;
    }
    std::cout << std::left << std::setw(30) << "Фамилия" << std::setw(30) << "Имя" << std::setw(30) << "Число пациентов"
              << std::setw(30)
              << "Дата приема" << std::endl << std::endl;

    for (int i = 0; i < total_receptions; i++) {
        std::cout << std::left << std::setw(30) << all_receptions[i].get_fam() << std::setw(30)
                  << all_receptions[i].get_name() << std::setw(30)
                  << all_receptions[i].get_patients() << std::setw(30) << all_receptions[i].get_date() << std::endl;
    }
}

void ReceptionList::bubbleSort() {
    for (int i = 0; i < total_receptions - 1; i++) {
        for (int j = 0; j < total_receptions - i - 1; j++) {
//            std::cout << "сортировка\n";
            if (all_receptions[j].get_appointment() > all_receptions[j + 1].get_appointment()) {
                reception temp = all_receptions[j];
                all_receptions[j] = all_receptions[j + 1];
                all_receptions[j + 1] = temp;
            }
        }
    }
}

reception *ReceptionList::find_by_fio(fio &initials) {
    for (int i = 0; i < total_receptions; i++) {
        if (all_receptions[i] == initials) {
            return &all_receptions[i];
        }
    }
    return nullptr;
}

ReceptionList *ReceptionList::find_by_date(date &period) {
    int num_founded = 0;
    ReceptionList *found_receptions = new ReceptionList(capacity);

    for (int i = 0; i < total_receptions; i++) {
        if (period == all_receptions[i].get_appointment()) {
            found_receptions->all_receptions[num_founded] = all_receptions[i];
            num_founded += 1;
        }
    }
    found_receptions->total_receptions = num_founded;
    return found_receptions;
}

void ReceptionList::processFile(char *file_name) {
    std::ifstream file(file_name);

    if (!file.is_open()) {
        std::cout << "Невозможно открыть файл" << std::endl;
        return;
    }

    int temp_total = 0;
    char line[256];
    char fam_buff[256];
    char name_buff[256];
    int patients_buff;
    int day_buff;
    int month_buff;
    int year_buff;

    if (file.getline(line, sizeof(line))) {
        std::stringstream ss(line);
        ss >> temp_total;
    } else {
        std::cout << "Файл пустой" << std::endl;
        return;
    }

    reception *temp_receptions = new reception[temp_total];

    int index = 0;
    while (file.getline(line, sizeof(line)) && index < temp_total) {
        std::stringstream ss(line);
        ss >> fam_buff >> name_buff >> patients_buff >> day_buff >> month_buff >> year_buff;

        temp_receptions[index].set_fam(fam_buff);
        temp_receptions[index].set_name(name_buff);
        temp_receptions[index].set_patients(patients_buff);
        temp_receptions[index].set_date(day_buff, month_buff, year_buff);

        index++;
    }

    file.close();

    all_receptions = temp_receptions;
    total_receptions = temp_total;
    capacity = temp_total;
}

void ReceptionList::save(char *file_name) {
    std::ofstream file(file_name);

    if (!file.is_open()) {
        std::cout << "Невозможно открыть файл" << std::endl;
        return;
    }

    file << total_receptions << std::endl;

    for (int i = 0; i < total_receptions; i++) {
        date date_to_save = all_receptions[i].get_appointment();
        file << all_receptions[i].get_fam() << " " << all_receptions[i].get_name() << " "
             << all_receptions[i].get_patients() << " " << date_to_save.get_day()
             << " " << date_to_save.get_month() << " " << date_to_save.get_year() << std::endl;
    }

    file.close();
    std::cout << "Данные сохранены" << std::endl;
}