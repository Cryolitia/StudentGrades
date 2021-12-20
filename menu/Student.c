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
                printf("请输入学生ID：");
                scanf_s("%s", student->studentNumber, USER_MAX_LENGTH);
                if(config->studentHEAD!=NULL) {
                    Student *s = config->studentHEAD;
                    do {
                        if (student != s && strcmp(student->studentNumber, s->studentNumber) == 0) {
                            printf("学生ID重复，请重新输入！\n");
                            goto inputID;
                        }
                        s = s->nextStudent;
                    } while (s != NULL);
                }
                printf("请输入学生姓名：");
                scanf_s("%s", student->name, USER_MAX_LENGTH);
                while (true) {
                    fflush(stdin);
                    printf("请输入学生性别[M/F]：");
                    char s = (char) getchar();
                    if (s == 'M') {
                        student->sex = 0;
                        break;
                    } else if (s == 'F') {
                        student->sex = 1;
                        break;
                    }
                }
                printf("请输入学生班级：");
                scanf_s("%s", student->class, USER_MAX_LENGTH);
                student->nextStudent = NULL;
                InsertStudent(config,student);
                printf("添加成功");
                sleep(3);
                break;
            }
            case '2': {
                fflush(stdin);
                if (config->studentHEAD==NULL) {
                    printf("没有学生记录! \n");
                    system("pause");
                    break;
                }
                char id[USER_MAX_LENGTH] = {0};
                printf("请输入学生ID：");
                scanf_s("%s", id, USER_MAX_LENGTH);
                Student *student = config->studentHEAD;
                while(strcmp(student->studentNumber,id)!=0) {
                    if (student->nextStudent==NULL) {
                        printf("学生未找到！\n");
                        system("pause");
                        goto break1;
                    }
                    student = student->nextStudent;
                }
                printf("当前信息：\nID\t\t姓名\t\t性别\t\t班级\n");
                char *sex = student->sex == 0 ? "男" : "女";
                printf("%s\t\t%s\t\t%s\t\t%s\n", student->studentNumber, student->name, sex, student->class);
                printf("请输入学生姓名：");
                scanf_s("%s", student->name, USER_MAX_LENGTH);
                while (true) {
                    fflush(stdin);
                    printf("请输入学生性别[M/F]：");
                    char s = (char) getchar();
                    if (s == 'M') {
                        student->sex = 0;
                        break;
                    } else if (s == 'F') {
                        student->sex = 1;
                        break;
                    }
                }
                printf("请输入学生班级：");
                scanf_s("%s", student->class, USER_MAX_LENGTH);
                printf("修改成功");
                sleep(3);
                break1:
                break;
            }
            case '3': {
                fflush(stdin);
                if (config->studentHEAD==NULL) {
                    printf("没有学生记录! \n");
                    system("pause");
                    break;
                }
                char id[USER_MAX_LENGTH] = {0};
                printf("请输入学生ID：");
                scanf_s("%s", id, USER_MAX_LENGTH);
                Student *student = config->studentHEAD;
                if (strcmp(student->studentNumber,id)==0) {
                    printf("当前信息：\nID\t\t姓名\t\t性别\t\t班级\n");
                    char *sex = student->sex == 0 ? "男" : "女";
                    printf("%s\t\t%s\t\t%s\t\t%s\n", student->studentNumber, student->name, sex, student->class);
                    printf("确认删除？[y/N]");
                    if (getche()=='y') {
                        Student *s = student->nextStudent;
                        free(config->studentHEAD);
                        config->studentHEAD=s;
                        printf("删除成功！\n");
                        goto break2;
                    }
                } else if (student->nextStudent==NULL) {
                    printf("学生未找到！\n");
                    goto break2;
                }
                while(strcmp(student->nextStudent->studentNumber,id)!=0) {
                    if (student->nextStudent->nextStudent==NULL) {
                        printf("学生未找到！\n");
                        system("pause");
                        goto break2;
                    }
                    student = student->nextStudent;
                }
                printf("当前信息：\nID\t\t姓名\t\t性别\t\t班级\n");
                char *sex = student->nextStudent->sex == 0 ? "男" : "女";
                printf("%s\t\t%s\t\t%s\t\t%s\n", student->nextStudent->studentNumber, student->nextStudent->name, sex, student->nextStudent->class);
                printf("确认删除？[y/N]");
                if (getche()=='y') {
                    Student *s = student->nextStudent->nextStudent;
                    free(student->nextStudent);
                    student->nextStudent = s;
                    printf("删除成功！\n");
                } else {
                    printf("取消删除!\n");
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
                    printf("空记录！\n\n");
                    system("pause");
                    break;
                }
                Student *student = config->studentHEAD;
                printf("ID\t\t姓名\t\t性别\t\t班级\n\n");
                while (student!=NULL) {
                    char *sex = student->sex == 0 ? "男" : "女";
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
                    printf("打开文件失败！\n");
                    system("pause");
                    break;
                }
                Student *student = config->studentHEAD;
                while (student!=NULL) {
                    fprintf(file,"%s,%s,%c,%s\n",student->studentNumber,student->name,student->sex?'M':'F',student->class);
                    student = student->nextStudent;
                }
                fclose(file);
                printf("保存成功！\n");
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
    printf("1. 添加学生\n");
    printf("2. 修改学生\n");
    printf("3. 删除学生\n");
    printf("4. 查看学生\n");
    printf("5. 导出CSV\n");
    printf("0. 返回\n");
    printf("=========\n");
    printf("请输入您的选择：");
    return getche();
}