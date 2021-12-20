//
// Created by Neuron on 2021/12/7.
//

#ifndef STUDENTGRADES_MAIN_H
#define STUDENTGRADES_MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <stdint.h>
#include <inttypes.h>
#include <conio.h>

#include "MACRO.h"
#include "config.h"
#include "menu/SystemSetting.h"
#include "menu/Student.h"
#include "menu/Course.h"
#include "menu/Grade.h"

//处理系统登陆相关事件
bool Login();

/*
 * 打印菜单
 * @Return 选择的菜单项
 */
int PrintMenu();
void InitData();

#endif //STUDENTGRADES_MAIN_H
