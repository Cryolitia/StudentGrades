cmake_minimum_required(VERSION 3.20)
project(StudentGrades C)

set(CMAKE_C_STANDARD 11)

add_executable(StudentGrades main.c main.h config.c config.h menu/SystemSetting.c menu/SystemSetting.h MACRO.h menu/Student.c menu/Student.h menu/Course.c menu/Course.h menu/Grade.c menu/Grade.h)
