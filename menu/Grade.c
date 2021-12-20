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
                    printf("没有学生，请先添加学生！");
                    sleep(3);
                    break;
                }
                if (config->courseHEAD==NULL) {
                    printf("没有课程，请先添加课程！");
                    sleep(3);
                    break;
                }
                char courseID[USER_MAX_LENGTH], studentID[USER_MAX_LENGTH];
                inputCourseID:
                printf("请输入课程ID: ");
                scanf_s("%s",courseID,USER_MAX_LENGTH);
                Course* course = config->courseHEAD;
                while(course!=NULL&&strcmp(course->id,courseID)!=0) {
                    course = course->nextCourse;
                }
                if (course==NULL) {
                    printf("课程未找到!\n");
                    goto inputCourseID;
                } else {
                    printf("ID：%s\t名称：%s\t教师: %s\n",course->id,course->name,course->teacher);
                }
                inputStudentID:
                printf("请输入学生ID: ");
                scanf_s("%s",studentID,USER_MAX_LENGTH);
                Student *student= config->studentHEAD;
                while(student!=NULL&&strcmp(student->studentNumber,studentID)!=0) {
                    student = student->nextStudent;
                }
                if (student==NULL) {
                    printf("学生未找到!\n");
                    goto inputStudentID;
                } else {
                    printf("ID：%s\t姓名：%s\t性别: %s\t班级:%s\n",student->studentNumber,student->name,student->sex?"女":"男",student->class);
                }
                float f;
                printf("请输入学生成绩: ");
                scanf("%f",&f);
                if (config->gradeHEAD!=NULL) {
                    Grade* g = config->gradeHEAD;
                    while(g->nextGrade!=NULL) {
                        if (g->student==student&&g->course==course) {
                            printf("成绩已存在: %.2f",g->grade);
                            sleep(3);
                            goto endAdd;
                        }
                        g = g->nextGrade;
                    }
                }
                InsertGrade(config,student,course,f);
                printf("添加成功！\n");
                sleep(3);
                endAdd:
                break;
            }
            case '2': {
                if (config->gradeHEAD==NULL) {
                    printf("没有成绩！");
                    sleep(3);
                    break;
                }
                if (config->studentHEAD==NULL) {
                    printf("没有学生，请先添加学生！");
                    sleep(3);
                    break;
                }
                if (config->courseHEAD==NULL) {
                    printf("没有课程，请先添加课程！");
                    sleep(3);
                    break;
                }
                char courseID[USER_MAX_LENGTH], studentID[USER_MAX_LENGTH];
                inputCourseID2:
                printf("请输入课程ID: ");
                scanf_s("%s",courseID,USER_MAX_LENGTH);
                Course* course = config->courseHEAD;
                while(course!=NULL&&strcmp(course->id,courseID)!=0) {
                    course = course->nextCourse;
                }
                if (course==NULL) {
                    printf("课程未找到!\n");
                    goto inputCourseID2;
                } else {
                    printf("ID：%s\t名称：%s\t教师: %s\n",course->id,course->name,course->teacher);
                }
                inputStudentID2:
                printf("请输入学生ID: ");
                scanf_s("%s",studentID,USER_MAX_LENGTH);
                Student *student= config->studentHEAD;
                while(student!=NULL&&strcmp(student->studentNumber,studentID)!=0) {
                    student = student->nextStudent;
                }
                if (student==NULL) {
                    printf("学生未找到!\n");
                    goto inputStudentID2;
                } else {
                    printf("ID：%s\t姓名：%s\t性别: %s\t班级:%s\n",student->studentNumber,student->name,student->sex?"女":"男",student->class);
                }
                Grade* grade = config->gradeHEAD;
                while(grade!=NULL) {
                    if (grade->student==student&&grade->course==course) {
                        break;
                    }
                    grade = grade->nextGrade;
                }
                if (grade==NULL) {
                    printf("未找到对应成绩信息！");
                    sleep(3);
                    break;
                }
                printf("成绩：%.2f\n",grade->grade);
                printf("请输入新的成绩：");
                float f;
                scanf("%.2f",&f);
                printf("修改成功！");
                sleep(3);
                break;
            }
            case '3': {
                if (config->gradeHEAD==NULL) {
                    printf("没有成绩！");
                    sleep(3);
                    break;
                }
                if (config->studentHEAD==NULL) {
                    printf("没有学生，请先添加学生！");
                    sleep(3);
                    break;
                }
                if (config->courseHEAD==NULL) {
                    printf("没有课程，请先添加课程！");
                    sleep(3);
                    break;
                }
                char courseID[USER_MAX_LENGTH], studentID[USER_MAX_LENGTH];
                inputCourseID3:
                printf("请输入课程ID: ");
                scanf_s("%s",courseID,USER_MAX_LENGTH);
                Course* course = config->courseHEAD;
                while(course!=NULL&&strcmp(course->id,courseID)!=0) {
                    course = course->nextCourse;
                }
                if (course==NULL) {
                    printf("课程未找到!\n");
                    goto inputCourseID3;
                } else {
                    printf("ID：%s\t名称：%s\t教师: %s\n",course->id,course->name,course->teacher);
                }
                inputStudentID3:
                printf("请输入学生ID: ");
                scanf_s("%s",studentID,USER_MAX_LENGTH);
                Student *student= config->studentHEAD;
                while(student!=NULL&&strcmp(student->studentNumber,studentID)!=0) {
                    student = student->nextStudent;
                }
                if (student==NULL) {
                    printf("学生未找到!\n");
                    goto inputStudentID3;
                } else {
                    printf("ID：%s\t姓名：%s\t性别: %s\t班级:%s\n",student->studentNumber,student->name,student->sex?"女":"男",student->class);
                }
                Grade* grade = config->gradeHEAD;
                if (grade->student==student&&grade->course==course) {
                    config->gradeHEAD = grade->nextGrade;
                    printf("删除成功！");
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
                    printf("记录未找到！");
                    sleep(3);
                    break;
                }
                Grade* g = grade->nextGrade;
                grade->nextGrade = grade->nextGrade->nextGrade;
                free(g);
                printf("删除成功！");
                sleep(3);
                break;
            }
            case '4': {
                if (config->gradeHEAD==NULL) {
                    printf("没有成绩！");
                    sleep(3);
                    break;
                }
                if (config->courseHEAD==NULL) {
                    printf("没有课程，请先添加课程！");
                    sleep(3);
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
                printf("ID：%s\t名称：%s\t教师: %s\n",course->id,course->name,course->teacher);
                printf("ID\t\t姓名\t\t性别\t\t班级\t\t成绩\n\n");
                Grade* grade = config->gradeHEAD;
                while(grade!=NULL) {
                    if (grade->course==course) {
                        printf("%s\t\t%s\t\t%s\t\t%s\t\t%.2f\n",grade->student->studentNumber,grade->student->name,grade->student->sex?"女":"男",grade->student->class,grade->grade);
                    }
                    grade = grade->nextGrade;
                }
                system("pause");
                break1:
                break;
            }
            case '5': {
                if (config->gradeHEAD==NULL) {
                    printf("没有成绩！");
                    sleep(3);
                    break;
                }
                if (config->studentHEAD==NULL) {
                    printf("没有学生，请先添加学生！");
                    sleep(3);
                    break;
                }
                char id[USER_MAX_LENGTH] = {0};
                printf("请输入学生ID：");
                scanf_s("%s", id, USER_MAX_LENGTH);
                Student* student = config->studentHEAD;
                while(strcmp(student->studentNumber,id)!=0) {
                    if (student->nextStudent==NULL) {
                        printf("学生未找到！\n");
                        system("pause");
                        goto break2;
                    }
                    student = student->nextStudent;
                }
                printf("ID：%s\t姓名：%s\t性别: %s\t班级:%s\n",student->studentNumber,student->name,student->sex?"女":"男",student->class);
                printf("ID\t\t名称\t\t教师\t\t成绩\n");
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
                    printf("没有成绩！");
                    sleep(3);
                    break;
                }
                if (config->studentHEAD==NULL) {
                    printf("没有学生，请先添加学生！");
                    sleep(3);
                    break;
                }
                if (config->courseHEAD==NULL) {
                    printf("没有课程，请先添加课程！");
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
                    printf("没有成绩！");
                    sleep(3);
                    break;
                }
                if (config->studentHEAD==NULL) {
                    printf("没有学生，请先添加学生！");
                    sleep(3);
                    break;
                }
                if (config->courseHEAD==NULL) {
                    printf("没有课程，请先添加课程！");
                    sleep(3);
                    break;
                }
                FILE *file;
                if ((file=fopen("Grade.csv","w"))==NULL) {
                    printf("打开文件失败！");
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
                printf("导出成功！\n");
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
    printf("1. 成绩录入\n");
    printf("2. 成绩修改\n");
    printf("3. 成绩删除\n");
    printf("4. 按课程查看成绩\n");
    printf("5. 按学生查看成绩\n");
    printf("6. 查看成绩总表\n");
    printf("7. 导出CSV\n");
    printf("0. 返回\n");
    printf("=========\n");
    printf("请输入您的选择：");
    return getche();
}