#define _CRT_SECURE_NO_WARNINGS

#include "reception.h"
#include <fstream>
#include <sstream>

class ReceptionList {
private:
    reception *all_receptions;
    int total_receptions;
    int capacity;
public:
    ReceptionList();

    ReceptionList(int);

    ~ReceptionList();

    ReceptionList &operator=(ReceptionList &);

    int get_total_receptions();

    int get_capacity();

    reception *get_array();

    void add_reception(reception &);

    void print_receptions();

    void bubbleSort();

    reception *find_by_fio(fio &);

    ReceptionList *find_by_date(date &);

    void processFile(char *);

    void save(char *);
};