#define _CRT_SECURE_NO_WARNINGS

#include "DoctorList.h"

DoctorList::DoctorList() {
    this->all_doctors = new doctor[5];
    this->total_doctors = 0;
    this->capacity = 5;
}

DoctorList::DoctorList(int n) {
    this->all_doctors = new doctor[n];
    this->total_doctors = 0;
    this->capacity = n;
}

DoctorList::~DoctorList() {
    delete[]this->all_doctors;
}

DoctorList &DoctorList::operator=(DoctorList &other_list) {
    total_doctors = other_list.get_total_doctors();
    capacity = other_list.get_capacity();
    doctor *array = other_list.get_array();
    all_doctors = new doctor[total_doctors];

    for (int i = 0; i < total_doctors; i++) {
        all_doctors[i] = array[i];
    }
    return *this;
}

int DoctorList::get_total_doctors() {
    return total_doctors;
}

int DoctorList::get_capacity() {
    return capacity;
}

doctor *DoctorList::get_array() {
    return all_doctors;
}

void DoctorList::add_doctor(doctor &doc) {
    if (total_doctors + 1 > capacity) {
//        std::cout << "пополнение\n";
        doctor *temp = new doctor[(total_doctors * 3) / 2 + 1];
        for (int i = 0; i < total_doctors; i++) {
            temp[i] = all_doctors[i];
        }
        delete[] all_doctors;
        all_doctors = temp;
        capacity = total_doctors * 3 / 2 + 1;
//        std::cout << capacity << " (capacity)\n";
    }
    all_doctors[total_doctors] = doc;
    total_doctors += 1;
}

void DoctorList::print_doctors() {
    if (total_doctors == 0) {
        std::cout << "Нет записей о докторах в базе\n";
        return;
    }
    std::cout << std::left << std::setw(30) << "Фамилия" << std::setw(30) << "Имя" << std::setw(30) << "Специальность"
              << std::setw(30)
              << "Квалификация" << std::endl << std::endl;

    for (int i = 0; i < total_doctors; i++) {
        std::cout << std::left << std::setw(30) << all_doctors[i].get_fam() << std::setw(30)
                  << all_doctors[i].get_name() << std::setw(30)
                  << all_doctors[i].get_spec() << std::setw(30) << all_doctors[i].get_qual() << std::endl;
    }
}

void DoctorList::bubbleSort() {
    for (int i = 0; i < total_doctors - 1; i++) {
        for (int j = 0; j < total_doctors - i - 1; j++) {
            if (strcmp(all_doctors[j].get_fam(), all_doctors[j + 1].get_fam()) > 0) {
                doctor temp = all_doctors[j];
                all_doctors[j] = all_doctors[j + 1];
                all_doctors[j + 1] = temp;
            }
        }
    }
}

doctor *DoctorList::find_doctor(fio &initials) {
    for (int i = 0; i < total_doctors; i++) {
        if (all_doctors[i] == initials) {
            return &all_doctors[i];
        }
    }
    return nullptr;
}

DoctorList DoctorList::find_spec(int spec) {
    int num_founded = 0;
    DoctorList found_doctors(capacity);

    for (int i = 0; i < total_doctors; i++) {
        if (spec == all_doctors[i].get_enum_spec()) {
            found_doctors.all_doctors[num_founded] = all_doctors[i];
            num_founded += 1;
        }
    }
    found_doctors.total_doctors = num_founded;
    return found_doctors;
}

DoctorList DoctorList::find_qual(int qual) {
    int num_founded = 0;
    DoctorList found_doctors(capacity);

    for (int i = 0; i < total_doctors; i++) {
        if (qual == all_doctors[i].get_enum_qual()) {
            found_doctors.all_doctors[num_founded] = all_doctors[i];
            num_founded += 1;
        }
    }
    found_doctors.total_doctors = num_founded;
    return found_doctors;
}

void DoctorList::processFile(char *file_name) {
    std::ifstream file(file_name);

    if (!file.is_open()) {
        std::cout << "Невозможно открыть файл" << std::endl;
        return;
    }

    int temp_total = 0;
    char line[256];
    char fam_buff[256];
    char name_buff[256];
    int spec_buff;
    int qual_buff;

    if (file.getline(line, sizeof(line))) {
        std::stringstream ss(line);
        ss >> temp_total;
    } else {
        std::cout << "Файл пустой" << std::endl;
        return;
    }

    doctor *temp_doctors = new doctor[temp_total];

    int index = 0;
    while (file.getline(line, sizeof(line)) && index < temp_total) {
        std::stringstream ss(line);
        ss >> fam_buff >> name_buff >> spec_buff >> qual_buff;

        SpecType new_spec = static_cast<SpecType>(spec_buff);
        QualType new_qual = static_cast<QualType>(qual_buff);

        temp_doctors[index].set_fam(fam_buff);
        temp_doctors[index].set_name(name_buff);
        temp_doctors[index].set_spec(new_spec);
        temp_doctors[index].set_qual(new_qual);
        doctor::count_up();

        index++;
        std::cout << "добавление\n";
    }

    file.close();

    all_doctors = temp_doctors;
    total_doctors = temp_total;
    capacity = temp_total;
}

void DoctorList::save(char *file_name) {
    std::ofstream file(file_name);

    if (!file.is_open()) {
        std::cout << "Невозможно открыть файл" << std::endl;
        return;
    }

    file << total_doctors << std::endl;

    for (int i = 0; i < total_doctors; i++) {
        file << all_doctors[i].get_fam() << " " << all_doctors[i].get_name() << " " << all_doctors[i].get_enum_spec()
             << " " << all_doctors[i].get_enum_qual() << std::endl;
    }

    file.close();
    std::cout << "Данные сохранены" << std::endl;
}