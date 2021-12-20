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
            printf("�������µ��û�����");
            scanf_s("%s",config->name,USER_MAX_LENGTH);
            printf("�������µ����룺");
            scanf_s("%s",config->password,USER_MAX_LENGTH);
            SaveConfig(*config, DEFAULT_CONFIG);
            printf("�޸ĳɹ���");
            sleep(3);
            break;
        }
        case '2':{
            fflush(stdin);
            printf("����ʹ�õ���ɫ���£�\n");
            printf("0\t��ɫ\n1\t��ɫ\n2\t��ɫ\n3\tǳ��ɫ\n4\t��ɫ\n5\t��ɫ\n6\t��ɫ\n7\t��ɫ\n8\t��ɫ\n9\t����ɫ\nA\t����ɫ\nB\t��ǳ��ɫ\nC\t����ɫ\nD\t����ɫ\nE\t����ɫ\nF\t����ɫ\n");
            printf("�����뱳��ɫ��");
            char back = getchar();
            fflush(stdin);
            printf("������ǰ��ɫ��");
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
    printf("1. �޸��û���������\n");
    printf("2. �޸���ɫ\n");
    printf("0. ����\n");
    printf("=========\n");
    printf("����������ѡ��");
    return getche();
}