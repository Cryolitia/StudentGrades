//
// Created by Neuron on 2021/12/7.
//

#include "Student.h"

int PrintStudentMenu();

void StudentSetting(Config* config) {
    while(true) {
        system("cls");
        switch (PrintStudentMenu()) {
            case '1': {
                fflush(stdin);
                Student* student = calloc(1, sizeof(Student));
                inputID:
                printf("������ѧ��ID��");
                scanf_s("%s", student->studentNumber, USER_MAX_LENGTH);
                if(config->studentHEAD!=NULL) {
                    Student *s = config->studentHEAD;
                    do {
                        if (student != s && strcmp(student->studentNumber, s->studentNumber) == 0) {
                            printf("ѧ��ID�ظ������������룡\n");
                            goto inputID;
                        }
                        s = s->nextStudent;
                    } while (s != NULL);
                }
                printf("������ѧ��������");
                scanf_s("%s", student->name, USER_MAX_LENGTH);
                while (true) {
                    fflush(stdin);
                    printf("������ѧ���Ա�[M/F]��");
                    char s = (char) getchar();
                    if (s == 'M') {
                        student->sex = 0;
                        break;
                    } else if (s == 'F') {
                        student->sex = 1;
                        break;
                    }
                }
                printf("������ѧ���༶��");
                scanf_s("%s", student->class, USER_MAX_LENGTH);
                student->nextStudent = NULL;
                InsertStudent(config,student);
                printf("��ӳɹ�");
                sleep(3);
                break;
            }
            case '2': {
                fflush(stdin);
                if (config->studentHEAD==NULL) {
                    printf("û��ѧ����¼! \n");
                    system("pause");
                    break;
                }
                char id[USER_MAX_LENGTH] = {0};
                printf("������ѧ��ID��");
                scanf_s("%s", id, USER_MAX_LENGTH);
                Student *student = config->studentHEAD;
                while(strcmp(student->studentNumber,id)!=0) {
                    if (student->nextStudent==NULL) {
                        printf("ѧ��δ�ҵ���\n");
                        system("pause");
                        goto break1;
                    }
                    student = student->nextStudent;
                }
                printf("��ǰ��Ϣ��\nID\t\t����\t\t�Ա�\t\t�༶\n");
                char *sex = student->sex == 0 ? "��" : "Ů";
                printf("%s\t\t%s\t\t%s\t\t%s\n", student->studentNumber, student->name, sex, student->class);
                printf("������ѧ��������");
                scanf_s("%s", student->name, USER_MAX_LENGTH);
                while (true) {
                    fflush(stdin);
                    printf("������ѧ���Ա�[M/F]��");
                    char s = (char) getchar();
                    if (s == 'M') {
                        student->sex = 0;
                        break;
                    } else if (s == 'F') {
                        student->sex = 1;
                        break;
                    }
                }
                printf("������ѧ���༶��");
                scanf_s("%s", student->class, USER_MAX_LENGTH);
                printf("�޸ĳɹ�");
                sleep(3);
                break1:
                break;
            }
            case '3': {
                fflush(stdin);
                if (config->studentHEAD==NULL) {
                    printf("û��ѧ����¼! \n");
                    system("pause");
                    break;
                }
                char id[USER_MAX_LENGTH] = {0};
                printf("������ѧ��ID��");
                scanf_s("%s", id, USER_MAX_LENGTH);
                Student *student = config->studentHEAD;
                if (strcmp(student->studentNumber,id)==0) {
                    printf("��ǰ��Ϣ��\nID\t\t����\t\t�Ա�\t\t�༶\n");
                    char *sex = student->sex == 0 ? "��" : "Ů";
                    printf("%s\t\t%s\t\t%s\t\t%s\n", student->studentNumber, student->name, sex, student->class);
                    printf("ȷ��ɾ����[y/N]");
                    if (getche()=='y') {
                        Student *s = student->nextStudent;
                        free(config->studentHEAD);
                        config->studentHEAD=s;
                        printf("ɾ���ɹ���\n");
                        goto break2;
                    }
                } else if (student->nextStudent==NULL) {
                    printf("ѧ��δ�ҵ���\n");
                    goto break2;
                }
                while(strcmp(student->nextStudent->studentNumber,id)!=0) {
                    if (student->nextStudent->nextStudent==NULL) {
                        printf("ѧ��δ�ҵ���\n");
                        system("pause");
                        goto break2;
                    }
                    student = student->nextStudent;
                }
                printf("��ǰ��Ϣ��\nID\t\t����\t\t�Ա�\t\t�༶\n");
                char *sex = student->nextStudent->sex == 0 ? "��" : "Ů";
                printf("%s\t\t%s\t\t%s\t\t%s\n", student->nextStudent->studentNumber, student->nextStudent->name, sex, student->nextStudent->class);
                printf("ȷ��ɾ����[y/N]");
                if (getche()=='y') {
                    Student *s = student->nextStudent->nextStudent;
                    free(student->nextStudent);
                    student->nextStudent = s;
                    printf("ɾ���ɹ���\n");
                } else {
                    printf("ȡ��ɾ��!\n");
                    system("pause");
                    break;
                }
                break2:
                system("pause");
                break;
            }
            case '4': {
                system("cls");
                if (config->studentHEAD == NULL) {
                    printf("�ռ�¼��\n\n");
                    system("pause");
                    break;
                }
                Student *student = config->studentHEAD;
                printf("ID\t\t����\t\t�Ա�\t\t�༶\n\n");
                while (student!=NULL) {
                    char *sex = student->sex == 0 ? "��" : "Ů";
                    printf("%s\t\t%s\t\t%s\t\t%s\n", student->studentNumber, student->name, sex, student->class);
                    student = student->nextStudent;
                }
                printf("\n\n");
                system("pause");
                break;
            }
            case '5': {
                FILE *file;
                if ((file = fopen("./Student.csv","w"))==NULL) {
                    printf("���ļ�ʧ�ܣ�\n");
                    system("pause");
                    break;
                }
                Student *student = config->studentHEAD;
                while (student!=NULL) {
                    fprintf(file,"%s,%s,%c,%s\n",student->studentNumber,student->name,student->sex?'M':'F',student->class);
                    student = student->nextStudent;
                }
                fclose(file);
                printf("����ɹ���\n");
                system("pause");
                break;
            }
            case '0': {
                return;
            }
        }
    }
}

void InsertStudent(Config* config,Student* s) {
    Student *student = config->studentHEAD;
    if (student != NULL) {
        while (student->nextStudent != NULL) {
            student = student->nextStudent;
        }
        student->nextStudent = s;
    } else {
        config->studentHEAD = s;
    }
}

void InsertStudentString(Config* config,char* id,char* name,bool sex,char* class){
    Student* student = calloc(1,sizeof(Student));
    strcpy(student->studentNumber,id);
    strcpy(student->name,name);
    student->sex = sex;
    strcpy(student->class,class);
    InsertStudent(config,student);
}

int PrintStudentMenu() {
    fflush(stdin);
    printf("=========\n");
    printf("1. ���ѧ��\n");
    printf("2. �޸�ѧ��\n");
    printf("3. ɾ��ѧ��\n");
    printf("4. �鿴ѧ��\n");
    printf("5. ����CSV\n");
    printf("0. ����\n");
    printf("=========\n");
    printf("����������ѡ��");
    return getche();
}