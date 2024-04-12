cmake_minimum_required(VERSION 3.26)
project(lab4)

set(CMAKE_CXX_STANDARD 17)

add_executable(lab4 main.cpp
        fio.h
        fio.cpp
        funcs.h
        funcs.cpp
        doctor.h
        doctor.cpp
        reception.h
        date.h
        date.cpp
        reception.cpp
        main.h
        DoctorList.h
        DoctorList.cpp)
