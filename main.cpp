#define _CRT_SECURE_NO_WARNINGS

#include "main.h"

using namespace std;

int main() {
    setlocale(LC_ALL, "Russian");
    char file_name[256] = "doctors.txt";

    DoctorList main_list;
    main_list.processFile(file_name);

    bool condition = true;
    while (condition) {
        cout << "Добавить нового доктора................1\n"
                "Вывести информацию о всех докторах.....2\n"
                "Отсортировать докторов по фамилии......3\n"
                "Найти доктора по фамилии и имени.......4\n"
                "Найти доктора по специальности.........5\n"
                "Найти доктора по квалификации..........6\n"
                "Завершить программу....................7\n\n"
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
                main_list.add_doctor(doc_to_add);
                cout << endl;
                break;
            }
            case 2:
                main_list.print_doctors();
                cout << endl;
                break;
            case 3:
                main_list.bubbleSort();
                cout << "Данные отсортированы\n\n";
                break;
            case 4: {
                fio initials;
                cin >> initials;
                doctor *founded_doc = main_list.find_doctor(initials);
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
                    DoctorList founded = main_list.find_spec(spec);
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
                    DoctorList founded = main_list.find_qual(qual);
                    founded.print_doctors();
                    cout << endl;
                    new_cond = false;
                }
                break;
            }
            case 7:
                condition = false;
                main_list.save(file_name);
                break;
            default:
                cout << "Нет такой команды, введите команду от 1 до 7\n\n";
                break;
        }
    }

    return 0;
}
