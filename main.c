#include "main.h"
#include "menu/Course.h"

int main(void) {
    system("chcp 936");
    Config config = ReadConfig(DEFAULT_CONFIG);
    char cmd[9] = "COLOR";
    cmd[5] = ' ';
    cmd[6] = config.color[0];
    cmd[7] = config.color[1];
    cmd[8] = 0;
    system(cmd);

    InitData(&config);

    /*printf("欢迎使用学生成绩管理系统，请您登录\n\n");
    while(!Login(&config)) {
        printf("登陆失败，请重新登陆！\n");
    }
    printf("登陆成功!\n");
    sleep(3);*/

    while (true) {
        system("cls");
        switch(PrintMenu()) {
            case '1': {
                SystemSetting(&config);
                break;
            }
            case '2': {
                StudentSetting(&config);
                break;
            }
            case '3': {
                CourseSetting(&config);
                break;
            }
            case '4': {
                GradeSetting(&config);
                break;
            }
            case '0': {
                system("cls");
                return 0;
            }
        }
    }
}

bool Login(const Config *config) {
    fflush(stdin);
    printf("请输入用户名：");
    char* name = calloc(USER_MAX_LENGTH, sizeof(char));
    scanf("%s",name,USER_MAX_LENGTH);
    printf("请输入密码：");
    char* password = calloc(USER_MAX_LENGTH, sizeof(char));
    scanf("%s",password,USER_MAX_LENGTH);
    bool result = strcmp(name,config->name) == 0 && strcmp(password,config->password)==0;
    free(name);
    name=NULL;
    free(password);
    password=NULL;
    return result;
}

int PrintMenu() {
    fflush(stdin);
    printf("=========\n");
    printf("1. 系统设置\n");
    printf("2. 学生管理\n");
    printf("3. 课程管理\n");
    printf("4. 成绩管理\n");
    printf("0. 退出系统\n");
    printf("=========\n");
    printf("请输入您的选择：");
    return getch();
}

void InitData(Config* config) {
    InsertStudentString(config,"1","张三",0,"2101");
    InsertStudentString(config,"2","李四",1,"2101");
    InsertStudentString(config,"3","王五",0,"2102");
    InsertStudentString(config,"4","刘六",1,"2102");
    InsertStudentString(config,"5","孙七",1,"2103");
    InsertStudentString(config,"6","钱八",0,"2103");
    InsertStudentString(config,"7","吴九",1,"2104");
    InsertStudentString(config,"8","Ben",0,"2104");
    InsertStudentString(config,"9","Amy",1,"2104");
    InsertCourseString(config,"1","语文","老刘");
    InsertCourseString(config,"2","数学","老王");
    InsertCourseString(config,"3","英语","小张");
    InsertCourseString(config,"4","物理","老任");
    InsertCourseString(config,"5","化学","老杨");
    InsertCourseString(config,"6","生物","老林");
    Student* student = config->studentHEAD;
    while(student!=NULL) {
        Course *course = config->courseHEAD;
        while (course!=NULL) {
            if (rand()%2) {
                InsertGrade(config,student,course,rand()*10000/RAND_MAX/100.0);
            }
            course = course->nextCourse;
        }
        student = student->nextStudent;
    }
}