//
// Created by Neuron on 2021/12/7.
//

#ifndef STUDENTGRADES_STUDENT_H
#define STUDENTGRADES_STUDENT_H

#include <stdint.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>

#include "../MACRO.h"

void StudentSetting(Config*);
void InsertStudent(Config*,Student*);
void InsertStudentString(Config*,char*,char*,bool,char*);
#endif //STUDENTGRADES_STUDENT_H
