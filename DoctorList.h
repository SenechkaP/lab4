#define _CRT_SECURE_NO_WARNINGS

#include "doctor.h"
#include <fstream>
#include <sstream>

class DoctorList {
private:
    doctor *all_doctors;
    int total_doctors;
    int capacity;
public:
    DoctorList();

    DoctorList(int);

    ~DoctorList();

    DoctorList &operator=(DoctorList &);

    int get_total_doctors();

    int get_capacity();

    doctor *get_array();

    void add_doctor(doctor &);

    void print_doctors();

    void bubbleSort();

    doctor *find_doctor(fio &);

    DoctorList *find_spec(int);

    DoctorList *find_qual(int);

    void processFile(char *);

    void save(char *);
};