//
// Created by Administrator on 2021/12/14.
//

#ifndef STUDENTGRADES_GRADE_H
#define STUDENTGRADES_GRADE_H

#include <stdint.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>

#include "../MACRO.h"

void GradeSetting(Config*);

void InsertGrade(Config*,Student*,Course*,float);

#endif //STUDENTGRADES_GRADE_H
