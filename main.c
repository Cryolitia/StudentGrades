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

    /*printf("��ӭʹ��ѧ���ɼ�����ϵͳ��������¼\n\n");
    while(!Login(&config)) {
        printf("��½ʧ�ܣ������µ�½��\n");
    }
    printf("��½�ɹ�!\n");
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
    printf("�������û�����");
    char* name = calloc(USER_MAX_LENGTH, sizeof(char));
    scanf("%s",name,USER_MAX_LENGTH);
    printf("���������룺");
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
    printf("1. ϵͳ����\n");
    printf("2. ѧ������\n");
    printf("3. �γ̹���\n");
    printf("4. �ɼ�����\n");
    printf("0. �˳�ϵͳ\n");
    printf("=========\n");
    printf("����������ѡ��");
    return getch();
}

void InitData(Config* config) {
    InsertStudentString(config,"1","����",0,"2101");
    InsertStudentString(config,"2","����",1,"2101");
    InsertStudentString(config,"3","����",0,"2102");
    InsertStudentString(config,"4","����",1,"2102");
    InsertStudentString(config,"5","����",1,"2103");
    InsertStudentString(config,"6","Ǯ��",0,"2103");
    InsertStudentString(config,"7","���",1,"2104");
    InsertStudentString(config,"8","Ben",0,"2104");
    InsertStudentString(config,"9","Amy",1,"2104");
    InsertCourseString(config,"1","����","����");
    InsertCourseString(config,"2","��ѧ","����");
    InsertCourseString(config,"3","Ӣ��","С��");
    InsertCourseString(config,"4","����","����");
    InsertCourseString(config,"5","��ѧ","����");
    InsertCourseString(config,"6","����","����");
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