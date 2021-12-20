//
// Created by Neuron on 2021/12/7.
//

#ifndef STUDENTGRADES_MACRO_H
#define STUDENTGRADES_MACRO_H

#include <stdbool.h>
#include <unistd.h>

//各类字符串的最大长度
#define USER_MAX_LENGTH 20

//默认配置存储位置
#define DEFAULT_CONFIG "./config.ini"

/*
 * 存储学生信息
 * studentNumber: 学生ID
 * name:          姓名
 * sex:           性别（0为男性，1为女性）
 * class:         班级
 * nextStudent    下一个
 */
typedef struct Student {
    char studentNumber[USER_MAX_LENGTH];
    char name[USER_MAX_LENGTH];
    bool sex;
    char class[USER_MAX_LENGTH];
    struct Student* nextStudent;
}Student;

typedef struct Course {
    char id[USER_MAX_LENGTH];
    char name[USER_MAX_LENGTH];
    char teacher[USER_MAX_LENGTH];
    struct Course* nextCourse;
}Course;

typedef struct Grade {
    float grade;
    struct Grade* nextGrade;
    struct Student* student;
    struct Course* course;
}Grade;

/*
 * 存储用户配置
 * name:     用户名
 * password：密码
 */
typedef struct Config{
    char name[USER_MAX_LENGTH];
    char password[USER_MAX_LENGTH];
    char color[3];
    Student* studentHEAD;
    Course* courseHEAD;
    Grade* gradeHEAD;
}Config;

#endif //STUDENTGRADES_MACRO_H
