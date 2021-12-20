//
// Created by Neuron on 2021/12/7.
//

#include "Course.h"

int PrintCourseMenu();

void CourseSetting(Config* config) {
    while(true) {
        system("cls");
        switch (PrintCourseMenu()) {
            case '1': {
                fflush(stdin);
                Course *course = calloc(1, sizeof(Course));
                inputID:
                printf("请输入课程ID：");
                scanf_s("%s", course->id, USER_MAX_LENGTH);
                Course *c = config->courseHEAD;
                do {
                    if (course != c && strcmp(course->id, c->id) == 0) {
                        printf("课程ID重复，请重新输入！\n");
                        goto inputID;
                    }
                    c = c->nextCourse;
                } while(c!=NULL);
                printf("请输入课程名称：");
                scanf_s("%s", course->name, USER_MAX_LENGTH);
                printf("请输入课程教师：");
                scanf_s("%s", course->teacher, USER_MAX_LENGTH);
                course->nextCourse = NULL;
                printf("添加成功");
                sleep(3);
                break;
            }
            case '2': {
                fflush(stdin);
                if (config->courseHEAD==NULL) {
                    printf("没有课程记录! \n");
                    system("pause");
                    break;
                }
                char id[USER_MAX_LENGTH] = {0};
                printf("请输入课程ID：");
                scanf_s("%s", id, USER_MAX_LENGTH);
                Course *course = config->courseHEAD;
                while(strcmp(course->id,id)!=0) {
                    if (course->nextCourse==NULL) {
                        printf("课程未找到！\n");
                        system("pause");
                        goto break1;
                    }
                    course = course->nextCourse;
                }
                printf("当前信息：\nID\t\t名称\t\t教师\n");
                printf("%s\t\t%s\t\t%s\n", course->id, course->name, course->teacher);
                printf("请输入课程名称：");
                scanf_s("%s", course->name, USER_MAX_LENGTH);
                printf("请输入课程教师：");
                scanf_s("%s", course->teacher, USER_MAX_LENGTH);
                printf("修改成功");
                sleep(3);
                break1:
                break;
            }
            case '3': {
                fflush(stdin);
                if (config->courseHEAD==NULL) {
                    printf("没有课程记录! \n");
                    system("pause");
                    break;
                }
                char id[USER_MAX_LENGTH] = {0};
                printf("请输入课程ID：");
                scanf_s("%s", id, USER_MAX_LENGTH);
                Course *course = config->courseHEAD;
                if (strcmp(course->id,id)==0) {
                    printf("当前信息：\nID\t\t名称\t\t教师\n");
                    printf("%s\t\t%s\t\t%s\n", course->id, course->name, course->teacher);
                    printf("确认删除？[y/N]");
                    if (getche()=='y') {
                        Course  *c = course->nextCourse;
                        free(config->courseHEAD);
                        config->courseHEAD=c;
                        printf("删除成功！\n");
                        goto break2;
                    }
                } else if (course->nextCourse==NULL) {
                    printf("课程未找到！\n");
                    goto break2;
                }
                while(strcmp(course->nextCourse->id,id)!=0) {
                    if (course->nextCourse->nextCourse==NULL) {
                        printf("课程未找到！\n");
                        system("pause");
                        goto break2;
                    }
                    course = course->nextCourse;
                }
                printf("当前信息：\nID\t\t名称\t\t教师\n");
                printf("%s\t\t%s\t\t%s\n", course->nextCourse->id, course->nextCourse->name, course->nextCourse->teacher);
                printf("确认删除？[y/N]");
                if (getche()=='y') {
                    Course *c = course->nextCourse->nextCourse;
                    free(course->nextCourse);
                    course->nextCourse = c;
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
                if (config->courseHEAD == NULL) {
                    printf("空记录！\n\n");
                    system("pause");
                    break;
                }
                Course *course = config->courseHEAD;
                printf("ID\t\t名称\t\t教师\n");
                while (course!=NULL) {
                    printf("%s\t\t%s\t\t%s\n", course->id, course->name, course->teacher);
                    course = course->nextCourse;
                }
                printf("\n\n");
                system("pause");
                break;
            }
            case '5': {
                FILE *file;
                if ((file = fopen("./Course.csv","w"))==NULL) {
                    printf("打开文件失败！\n");
                    system("pause");
                    break;
                }
                Course *course = config->courseHEAD;
                while (course!=NULL) {
                    fprintf(file,"%s,%s,%s\n",course->id,course->name,course->teacher);
                    course = course->nextCourse;
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

void InsertCourse(Config* config,Course* c) {
    Course *course = config->courseHEAD;
    if (course != NULL) {
        while (course->nextCourse != NULL) {
            course = course->nextCourse;
        }
        course->nextCourse = c;
    } else {
        config->courseHEAD = c;
    }
}

void InsertCourseString(Config* config,char* id,char* name,char* teacher) {
    Course *course= calloc(1, sizeof(Course));
    strcpy(course->id,id);
    strcpy(course->name,name);
    strcpy(course->teacher,teacher);
    InsertCourse(config,course);
}

int PrintCourseMenu() {
    fflush(stdin);
    printf("=========\n");
    printf("1. 添加课程\n");
    printf("2. 修改课程\n");
    printf("3. 删除课程\n");
    printf("4. 查看课程\n");
    printf("5. 导出CSV\n");
    printf("0. 返回\n");
    printf("=========\n");
    printf("请输入您的选择：");
    return getche();
}