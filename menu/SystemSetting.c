//
// Created by Neuron on 2021/12/7.
//

#include "SystemSetting.h"

int PrintSystemSettingMenu();

void SystemSetting(Config *config) {
    system("cls");
    switch (PrintSystemSettingMenu()) {
        case '1':{
            fflush(stdin);
            printf("请输入新的用户名：");
            scanf_s("%s",config->name,USER_MAX_LENGTH);
            printf("请输入新的密码：");
            scanf_s("%s",config->password,USER_MAX_LENGTH);
            SaveConfig(*config, DEFAULT_CONFIG);
            printf("修改成功！");
            sleep(3);
            break;
        }
        case '2':{
            fflush(stdin);
            printf("可以使用的颜色如下：\n");
            printf("0\t黑色\n1\t蓝色\n2\t绿色\n3\t浅绿色\n4\t红色\n5\t紫色\n6\t黄色\n7\t白色\n8\t灰色\n9\t淡蓝色\nA\t淡绿色\nB\t淡浅绿色\nC\t淡红色\nD\t淡紫色\nE\t淡黄色\nF\t亮白色\n");
            printf("请输入背景色：");
            char back = getchar();
            fflush(stdin);
            printf("请输入前景色：");
            char fore = getchar();
            config->color[0]=back;
            config->color[1]=fore;
            config->color[2]=0;
            char cmd[9] = "COLOR";
            cmd[5] = ' ';
            cmd[6] = back;
            cmd[7] = fore;
            cmd[8] = 0;
            system(cmd);
            SaveConfig(*config,DEFAULT_CONFIG);
        }
        case '0':{
            return;
        }
    }
}

int PrintSystemSettingMenu() {
    fflush(stdin);
    printf("=========\n");
    printf("1. 修改用户名和密码\n");
    printf("2. 修改颜色\n");
    printf("0. 返回\n");
    printf("=========\n");
    printf("请输入您的选择：");
    return getche();
}