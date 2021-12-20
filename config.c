//
// Created by Neuron on 2021/12/7.
//

#include "config.h"

Config ReadConfig(const char* locate){
    Config config;
    if (!GetPrivateProfileString(
            "User",
            "Name",
            "admin",
            config.name,
            USER_MAX_LENGTH,
            locate
            )){
        strcpy(config.name,"admin");
    }
    if (!GetPrivateProfileString(
            "User",
            "Password",
            "admin",
            config.password,
            USER_MAX_LENGTH,
            locate
            )){
        strcpy(config.password, "admin");
    }
    if (!GetPrivateProfileString(
            "Screen",
            "Color",
            "07",
            config.color,
            3,
            locate
    )){
        strcpy(config.password, "07");
    }
    config.studentHEAD = NULL;
    config.courseHEAD = NULL;
    config.gradeHEAD = NULL;
    return config;
}

void SaveConfig(Config config, const char* locate) {
    WritePrivateProfileString(
            "User",
            "Name",
            config.name,
            locate
            );
    WritePrivateProfileString(
            "User",
            "Password",
            config.password,
            locate
            );
    WritePrivateProfileString(
            "Screen",
            "Color",
            config.color,
            locate
            );
}