//
// Created by Neuron on 2021/12/7.
//

#ifndef STUDENTGRADES_CONFIG_H
#define STUDENTGRADES_CONFIG_H

#include <stdlib.h>
#include <windows.h>
#include <winbase.h>

#include "MACRO.h"

/*
 * 从文件中读取配置
 */
Config ReadConfig(const char*);
void SaveConfig(Config, const char*);

#endif //STUDENTGRADES_CONFIG_H
