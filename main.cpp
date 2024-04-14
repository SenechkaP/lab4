#define _CRT_SECURE_NO_WARNINGS

#include "main.h"

using namespace std;

int main() {
    setlocale(LC_ALL, "Russian");
    char file_name1[256] = "doctors.txt";
    char file_name2[256] = "receptions.txt";

    DoctorList doctor_list;
    doctor_list.processFile(file_name1);

    ReceptionList reception_list;
    reception_list.processFile(file_name2);

    bool condition = true;
    while (condition) {
        cout << "Добавить нового доктора..................1\n"
                "Вывести информацию о всех докторах.......2\n"
                "Отсортировать докторов по фамилии........3\n"
                "Найти доктора по фамилии и имени.........4\n"
                "Найти доктора по специальности...........5\n"
                "Найти доктора по квалификации............6\n\n"
                "Добавить новую запись приема.............7\n"
                "Вывести информацию о всех приемах........8\n"
                "Отсортировать приемы по дате.............9\n"
                "Найти прием по фамилии и имени доктора...10\n"
                "Найти прием по дате......................11\n\n"
                "Завершить программу......................12\n\n"
                "Введите номер функции: ";
        char input[256];
        long command;

        cin >> input;
        command = check_int(input);

        if (command == -1) {
            cout << "Ошибка. Введите целое число.\n\n";
            continue;
        }
        cout << endl;

        switch (command) {
            case 1: {
                doctor doc_to_add;
                cin >> doc_to_add;
                doctor_list.add_doctor(doc_to_add);
                cout << endl;
                break;
            }
            case 2:
                doctor_list.print_doctors();
                cout << endl;
                break;
            case 3:
                doctor_list.bubbleSort();
                cout << "Данные отсортированы\n\n";
                break;
            case 4: {
                fio initials;
                cin >> initials;
                doctor *founded_doc = doctor_list.find_doctor(initials);
                if (!founded_doc) {
                    cout << "Доктор не найден\n\n";
                } else {
                    cout << "Доктор найден:\n\n";
                    cout << founded_doc->get_fam() << " " << founded_doc->get_name() << ", " << founded_doc->get_spec()
                         << ", " << founded_doc->get_qual() << " квалификация" << endl << endl;
                }
                break;
            }
            case 5: {
                char spec_buff[256];
                bool new_cond = true;
                while (new_cond) {
                    cout << "Введите специальность доктора\n"
                            "специальность - цифра 1, 2 или 3\n"
                            "1 - терапевт\n"
                            "2 - кардиолог\n"
                            "3 - стоматолог\n";
                    cin >> spec_buff;
                    long spec = check_int(spec_buff);
                    if (spec == -1) {
                        cout << "Специальность - целое число!\n\n";
                        continue;
                    } else if (spec < 1 || spec > 3) {
                        cout << "Нет такой специальности\n\n";
                        continue;
                    }
                    DoctorList founded = doctor_list.find_spec(spec);
                    founded.print_doctors();
                    cout << endl;
                    new_cond = false;
                }
                break;
            }
            case 6: {
                char qual_buff[256];
                bool new_cond = true;
                while (new_cond) {
                    cout << "Введите квалификацию доктора\n"
                            "квалификация - цифра 0, 1 или 2\n"
                            "0 - высшая\n"
                            "1 - первая\n"
                            "2 - вторая\n";
                    cin >> qual_buff;
                    long qual = check_int(qual_buff);
                    if (qual == -1) {
                        cout << "Квалификация - целое число!\n\n";
                        continue;
                    } else if (qual < 0 || qual > 2) {
                        cout << "Нет такой квалификации\n\n";
                        continue;
                    }
                    DoctorList founded = doctor_list.find_qual(qual);
                    founded.print_doctors();
                    cout << endl;
                    new_cond = false;
                }
                break;
            }
            case 7: {
                reception reception_to_add;
                cin >> reception_to_add;
                reception_list.add_reception(reception_to_add);
                cout << endl;
                break;
            }
            case 8:
                reception_list.print_receptions();
                cout << endl;
                break;
            case 9:
                reception_list.bubbleSort();
                cout << "Данные отсортированы\n\n";
                break;
            case 10: {
                fio initials;
                cin >> initials;
                reception *founded_rec = reception_list.find_by_fio(initials);
                if (!founded_rec) {
                    cout << "Прием не найден\n\n";
                } else {
                    cout << "Прием найден:\n\n";
                    cout << founded_rec->get_fam() << " " << founded_rec->get_name() << ", число пациентов: "
                         << founded_rec->get_patients() << ", дата: " << founded_rec->get_date() << endl
                         << endl;
                }
                break;
            }
            case 11: {
                date date_to_find;
                cin >> date_to_find;
                ReceptionList founded = reception_list.find_by_date(date_to_find);
                founded.print_receptions();
                cout << endl;
                break;
            }
            case 12:
                condition = false;
                doctor_list.save(file_name1);
                reception_list.save(file_name2);
                break;
            default:
                cout << "Нет такой команды, введите команду от 1 до 7\n\n";
                break;
        }
    }

    return 0;
}