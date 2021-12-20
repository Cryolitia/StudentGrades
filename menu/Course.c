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
                printf("������γ�ID��");
                scanf_s("%s", course->id, USER_MAX_LENGTH);
                Course *c = config->courseHEAD;
                do {
                    if (course != c && strcmp(course->id, c->id) == 0) {
                        printf("�γ�ID�ظ������������룡\n");
                        goto inputID;
                    }
                    c = c->nextCourse;
                } while(c!=NULL);
                printf("������γ����ƣ�");
                scanf_s("%s", course->name, USER_MAX_LENGTH);
                printf("������γ̽�ʦ��");
                scanf_s("%s", course->teacher, USER_MAX_LENGTH);
                course->nextCourse = NULL;
                printf("��ӳɹ�");
                sleep(3);
                break;
            }
            case '2': {
                fflush(stdin);
                if (config->courseHEAD==NULL) {
                    printf("û�пγ̼�¼! \n");
                    system("pause");
                    break;
                }
                char id[USER_MAX_LENGTH] = {0};
                printf("������γ�ID��");
                scanf_s("%s", id, USER_MAX_LENGTH);
                Course *course = config->courseHEAD;
                while(strcmp(course->id,id)!=0) {
                    if (course->nextCourse==NULL) {
                        printf("�γ�δ�ҵ���\n");
                        system("pause");
                        goto break1;
                    }
                    course = course->nextCourse;
                }
                printf("��ǰ��Ϣ��\nID\t\t����\t\t��ʦ\n");
                printf("%s\t\t%s\t\t%s\n", course->id, course->name, course->teacher);
                printf("������γ����ƣ�");
                scanf_s("%s", course->name, USER_MAX_LENGTH);
                printf("������γ̽�ʦ��");
                scanf_s("%s", course->teacher, USER_MAX_LENGTH);
                printf("�޸ĳɹ�");
                sleep(3);
                break1:
                break;
            }
            case '3': {
                fflush(stdin);
                if (config->courseHEAD==NULL) {
                    printf("û�пγ̼�¼! \n");
                    system("pause");
                    break;
                }
                char id[USER_MAX_LENGTH] = {0};
                printf("������γ�ID��");
                scanf_s("%s", id, USER_MAX_LENGTH);
                Course *course = config->courseHEAD;
                if (strcmp(course->id,id)==0) {
                    printf("��ǰ��Ϣ��\nID\t\t����\t\t��ʦ\n");
                    printf("%s\t\t%s\t\t%s\n", course->id, course->name, course->teacher);
                    printf("ȷ��ɾ����[y/N]");
                    if (getche()=='y') {
                        Course  *c = course->nextCourse;
                        free(config->courseHEAD);
                        config->courseHEAD=c;
                        printf("ɾ���ɹ���\n");
                        goto break2;
                    }
                } else if (course->nextCourse==NULL) {
                    printf("�γ�δ�ҵ���\n");
                    goto break2;
                }
                while(strcmp(course->nextCourse->id,id)!=0) {
                    if (course->nextCourse->nextCourse==NULL) {
                        printf("�γ�δ�ҵ���\n");
                        system("pause");
                        goto break2;
                    }
                    course = course->nextCourse;
                }
                printf("��ǰ��Ϣ��\nID\t\t����\t\t��ʦ\n");
                printf("%s\t\t%s\t\t%s\n", course->nextCourse->id, course->nextCourse->name, course->nextCourse->teacher);
                printf("ȷ��ɾ����[y/N]");
                if (getche()=='y') {
                    Course *c = course->nextCourse->nextCourse;
                    free(course->nextCourse);
                    course->nextCourse = c;
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
                if (config->courseHEAD == NULL) {
                    printf("�ռ�¼��\n\n");
                    system("pause");
                    break;
                }
                Course *course = config->courseHEAD;
                printf("ID\t\t����\t\t��ʦ\n");
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
                    printf("���ļ�ʧ�ܣ�\n");
                    system("pause");
                    break;
                }
                Course *course = config->courseHEAD;
                while (course!=NULL) {
                    fprintf(file,"%s,%s,%s\n",course->id,course->name,course->teacher);
                    course = course->nextCourse;
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
    printf("1. ��ӿγ�\n");
    printf("2. �޸Ŀγ�\n");
    printf("3. ɾ���γ�\n");
    printf("4. �鿴�γ�\n");
    printf("5. ����CSV\n");
    printf("0. ����\n");
    printf("=========\n");
    printf("����������ѡ��");
    return getche();
}