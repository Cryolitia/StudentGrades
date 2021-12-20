//
// Created by Administrator on 2021/12/14.
//

#include "Grade.h"

int PrintGradeMenu();

void GradeSetting(Config* config) {
    while (true) {
        system("cls");
        switch (PrintGradeMenu()) {
            case '1': {
                if (config->studentHEAD==NULL) {
                    printf("û��ѧ�����������ѧ����");
                    sleep(3);
                    break;
                }
                if (config->courseHEAD==NULL) {
                    printf("û�пγ̣�������ӿγ̣�");
                    sleep(3);
                    break;
                }
                char courseID[USER_MAX_LENGTH], studentID[USER_MAX_LENGTH];
                inputCourseID:
                printf("������γ�ID: ");
                scanf_s("%s",courseID,USER_MAX_LENGTH);
                Course* course = config->courseHEAD;
                while(course!=NULL&&strcmp(course->id,courseID)!=0) {
                    course = course->nextCourse;
                }
                if (course==NULL) {
                    printf("�γ�δ�ҵ�!\n");
                    goto inputCourseID;
                } else {
                    printf("ID��%s\t���ƣ�%s\t��ʦ: %s\n",course->id,course->name,course->teacher);
                }
                inputStudentID:
                printf("������ѧ��ID: ");
                scanf_s("%s",studentID,USER_MAX_LENGTH);
                Student *student= config->studentHEAD;
                while(student!=NULL&&strcmp(student->studentNumber,studentID)!=0) {
                    student = student->nextStudent;
                }
                if (student==NULL) {
                    printf("ѧ��δ�ҵ�!\n");
                    goto inputStudentID;
                } else {
                    printf("ID��%s\t������%s\t�Ա�: %s\t�༶:%s\n",student->studentNumber,student->name,student->sex?"Ů":"��",student->class);
                }
                float f;
                printf("������ѧ���ɼ�: ");
                scanf("%f",&f);
                if (config->gradeHEAD!=NULL) {
                    Grade* g = config->gradeHEAD;
                    while(g->nextGrade!=NULL) {
                        if (g->student==student&&g->course==course) {
                            printf("�ɼ��Ѵ���: %.2f",g->grade);
                            sleep(3);
                            goto endAdd;
                        }
                        g = g->nextGrade;
                    }
                }
                InsertGrade(config,student,course,f);
                printf("��ӳɹ���\n");
                sleep(3);
                endAdd:
                break;
            }
            case '2': {
                if (config->gradeHEAD==NULL) {
                    printf("û�гɼ���");
                    sleep(3);
                    break;
                }
                if (config->studentHEAD==NULL) {
                    printf("û��ѧ�����������ѧ����");
                    sleep(3);
                    break;
                }
                if (config->courseHEAD==NULL) {
                    printf("û�пγ̣�������ӿγ̣�");
                    sleep(3);
                    break;
                }
                char courseID[USER_MAX_LENGTH], studentID[USER_MAX_LENGTH];
                inputCourseID2:
                printf("������γ�ID: ");
                scanf_s("%s",courseID,USER_MAX_LENGTH);
                Course* course = config->courseHEAD;
                while(course!=NULL&&strcmp(course->id,courseID)!=0) {
                    course = course->nextCourse;
                }
                if (course==NULL) {
                    printf("�γ�δ�ҵ�!\n");
                    goto inputCourseID2;
                } else {
                    printf("ID��%s\t���ƣ�%s\t��ʦ: %s\n",course->id,course->name,course->teacher);
                }
                inputStudentID2:
                printf("������ѧ��ID: ");
                scanf_s("%s",studentID,USER_MAX_LENGTH);
                Student *student= config->studentHEAD;
                while(student!=NULL&&strcmp(student->studentNumber,studentID)!=0) {
                    student = student->nextStudent;
                }
                if (student==NULL) {
                    printf("ѧ��δ�ҵ�!\n");
                    goto inputStudentID2;
                } else {
                    printf("ID��%s\t������%s\t�Ա�: %s\t�༶:%s\n",student->studentNumber,student->name,student->sex?"Ů":"��",student->class);
                }
                Grade* grade = config->gradeHEAD;
                while(grade!=NULL) {
                    if (grade->student==student&&grade->course==course) {
                        break;
                    }
                    grade = grade->nextGrade;
                }
                if (grade==NULL) {
                    printf("δ�ҵ���Ӧ�ɼ���Ϣ��");
                    sleep(3);
                    break;
                }
                printf("�ɼ���%.2f\n",grade->grade);
                printf("�������µĳɼ���");
                float f;
                scanf("%.2f",&f);
                printf("�޸ĳɹ���");
                sleep(3);
                break;
            }
            case '3': {
                if (config->gradeHEAD==NULL) {
                    printf("û�гɼ���");
                    sleep(3);
                    break;
                }
                if (config->studentHEAD==NULL) {
                    printf("û��ѧ�����������ѧ����");
                    sleep(3);
                    break;
                }
                if (config->courseHEAD==NULL) {
                    printf("û�пγ̣�������ӿγ̣�");
                    sleep(3);
                    break;
                }
                char courseID[USER_MAX_LENGTH], studentID[USER_MAX_LENGTH];
                inputCourseID3:
                printf("������γ�ID: ");
                scanf_s("%s",courseID,USER_MAX_LENGTH);
                Course* course = config->courseHEAD;
                while(course!=NULL&&strcmp(course->id,courseID)!=0) {
                    course = course->nextCourse;
                }
                if (course==NULL) {
                    printf("�γ�δ�ҵ�!\n");
                    goto inputCourseID3;
                } else {
                    printf("ID��%s\t���ƣ�%s\t��ʦ: %s\n",course->id,course->name,course->teacher);
                }
                inputStudentID3:
                printf("������ѧ��ID: ");
                scanf_s("%s",studentID,USER_MAX_LENGTH);
                Student *student= config->studentHEAD;
                while(student!=NULL&&strcmp(student->studentNumber,studentID)!=0) {
                    student = student->nextStudent;
                }
                if (student==NULL) {
                    printf("ѧ��δ�ҵ�!\n");
                    goto inputStudentID3;
                } else {
                    printf("ID��%s\t������%s\t�Ա�: %s\t�༶:%s\n",student->studentNumber,student->name,student->sex?"Ů":"��",student->class);
                }
                Grade* grade = config->gradeHEAD;
                if (grade->student==student&&grade->course==course) {
                    config->gradeHEAD = grade->nextGrade;
                    printf("ɾ���ɹ���");
                    sleep(3);
                    break;
                }
                while (grade->nextGrade!=NULL) {
                    if (grade->nextGrade->student==student&&grade->nextGrade->course==course) {
                        break;
                    }
                    grade = grade->nextGrade;
                }
                if (grade->nextGrade==NULL) {
                    printf("��¼δ�ҵ���");
                    sleep(3);
                    break;
                }
                Grade* g = grade->nextGrade;
                grade->nextGrade = grade->nextGrade->nextGrade;
                free(g);
                printf("ɾ���ɹ���");
                sleep(3);
                break;
            }
            case '4': {
                if (config->gradeHEAD==NULL) {
                    printf("û�гɼ���");
                    sleep(3);
                    break;
                }
                if (config->courseHEAD==NULL) {
                    printf("û�пγ̣�������ӿγ̣�");
                    sleep(3);
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
                printf("ID��%s\t���ƣ�%s\t��ʦ: %s\n",course->id,course->name,course->teacher);
                printf("ID\t\t����\t\t�Ա�\t\t�༶\t\t�ɼ�\n\n");
                Grade* grade = config->gradeHEAD;
                while(grade!=NULL) {
                    if (grade->course==course) {
                        printf("%s\t\t%s\t\t%s\t\t%s\t\t%.2f\n",grade->student->studentNumber,grade->student->name,grade->student->sex?"Ů":"��",grade->student->class,grade->grade);
                    }
                    grade = grade->nextGrade;
                }
                system("pause");
                break1:
                break;
            }
            case '5': {
                if (config->gradeHEAD==NULL) {
                    printf("û�гɼ���");
                    sleep(3);
                    break;
                }
                if (config->studentHEAD==NULL) {
                    printf("û��ѧ�����������ѧ����");
                    sleep(3);
                    break;
                }
                char id[USER_MAX_LENGTH] = {0};
                printf("������ѧ��ID��");
                scanf_s("%s", id, USER_MAX_LENGTH);
                Student* student = config->studentHEAD;
                while(strcmp(student->studentNumber,id)!=0) {
                    if (student->nextStudent==NULL) {
                        printf("ѧ��δ�ҵ���\n");
                        system("pause");
                        goto break2;
                    }
                    student = student->nextStudent;
                }
                printf("ID��%s\t������%s\t�Ա�: %s\t�༶:%s\n",student->studentNumber,student->name,student->sex?"Ů":"��",student->class);
                printf("ID\t\t����\t\t��ʦ\t\t�ɼ�\n");
                Grade* grade = config->gradeHEAD;
                while(grade!=NULL) {
                    if (grade->student==student) {
                        printf("%s\t\t%s\t\t%s\t\t%.2f\n",grade->course->id,grade->course->name,grade->course->teacher,grade->grade);
                    }
                    grade = grade->nextGrade;
                }
                system("pause");
                break2:
                break;
            }
            case '6': {
                if (config->gradeHEAD==NULL) {
                    printf("û�гɼ���");
                    sleep(3);
                    break;
                }
                if (config->studentHEAD==NULL) {
                    printf("û��ѧ�����������ѧ����");
                    sleep(3);
                    break;
                }
                if (config->courseHEAD==NULL) {
                    printf("û�пγ̣�������ӿγ̣�");
                    sleep(3);
                    break;
                }
                system("cls");
                {
                    Course* course = config->courseHEAD;
                    printf("\t\t");
                    while (course!=NULL) {
                        printf("[%s]%s\t",course->id,course->name);
                        course = course->nextCourse;
                    }
                    printf("\n\n");
                }
                {
                    Student* student = config->studentHEAD;
                    while (student!=NULL) {
                        printf("[%s]%s\t\t",student->studentNumber,student->name);
                        Course *course = config->courseHEAD;
                        while (course!=NULL) {
                            Grade *grade = config->gradeHEAD;
                            while(grade!=NULL) {
                                if (grade->student==student&&grade->course==course) {
                                    break;
                                }
                                grade = grade->nextGrade;
                            }
                            if (grade!=NULL) {
                                printf("%.2f\t",grade->grade);
                            } else {
                                printf("\t");
                            }
                            course = course->nextCourse;
                        }
                        printf("\n");
                        student = student->nextStudent;
                    }
                }
                system("pause");
                break;
            }
            case '7': {
                if (config->gradeHEAD==NULL) {
                    printf("û�гɼ���");
                    sleep(3);
                    break;
                }
                if (config->studentHEAD==NULL) {
                    printf("û��ѧ�����������ѧ����");
                    sleep(3);
                    break;
                }
                if (config->courseHEAD==NULL) {
                    printf("û�пγ̣�������ӿγ̣�");
                    sleep(3);
                    break;
                }
                FILE *file;
                if ((file=fopen("Grade.csv","w"))==NULL) {
                    printf("���ļ�ʧ�ܣ�");
                    sleep(3);
                    break;
                }
                {
                    Course* course = config->courseHEAD;
                    fprintf(file,",,");
                    while (course!=NULL) {
                        fprintf(file,"[%s]%s,",course->id,course->name);
                        course = course->nextCourse;
                    }
                    fprintf(file,"\n");
                }
                {
                    Student* student = config->studentHEAD;
                    while (student!=NULL) {
                        fprintf(file,"%s,%s,",student->studentNumber,student->name);
                        Course *course = config->courseHEAD;
                        while (course!=NULL) {
                            Grade *grade = config->gradeHEAD;
                            while(grade!=NULL) {
                                if (grade->student==student&&grade->course==course) {
                                    break;
                                }
                                grade = grade->nextGrade;
                            }
                            if (grade!=NULL) {
                                fprintf(file,"%.2f,",grade->grade);
                            } else {
                                fprintf(file,",");
                            }
                            course = course->nextCourse;
                        }
                        fprintf(file,"\n");
                        student = student->nextStudent;
                    }
                }
                fclose(file);
                printf("�����ɹ���\n");
                system("pause");
                break;
            }
            case '0': {
                return;
            }
        }
    }
}

void InsertGrade(Config* config,Student* student,Course* course,float f) {
    Grade *grade = calloc(1, sizeof(Grade));
    grade->student = student;
    grade->course = course;
    grade->grade = f;
    if (config->gradeHEAD==NULL) {
        config->gradeHEAD=grade;
    } else {
        Grade* g = config->gradeHEAD;
        while(g->nextGrade!=NULL) {
            g = g->nextGrade;
        }
        g->nextGrade=grade;
    }
}

int PrintGradeMenu() {
    fflush(stdin);
    printf("=========\n");
    printf("1. �ɼ�¼��\n");
    printf("2. �ɼ��޸�\n");
    printf("3. �ɼ�ɾ��\n");
    printf("4. ���γ̲鿴�ɼ�\n");
    printf("5. ��ѧ���鿴�ɼ�\n");
    printf("6. �鿴�ɼ��ܱ�\n");
    printf("7. ����CSV\n");
    printf("0. ����\n");
    printf("=========\n");
    printf("����������ѡ��");
    return getche();
}