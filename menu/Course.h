//
// Created by Neuron on 2021/12/7.
//

#ifndef STUDENTGRADES_COURSE_H
#define STUDENTGRADES_COURSE_H

#include <stdint.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>

#include "../MACRO.h"

void CourseSetting(Config*);
void InsertCourse(Config*,Course*);
void InsertCourseString(Config*,char*,char*,char*);

#endif //STUDENTGRADES_COURSE_H
