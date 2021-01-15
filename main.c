//һ��ѧ����Ϣ����ϵͳ���ܹ���ѧ����ѧ�š������͸��Ƴɼ�����ͳ�ơ�����͸���
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//ѧ���ṹ��
typedef struct _Student {
    int id; // ѧ��
    char name[20];   // ����
    int math; // ��ѧ�ɼ�
    int eng;  // Ӣ��ɼ�
    int C;    // C���Գɼ�
    int sum;  // �ܳɼ�
} Student;

//��������
typedef struct _Node {
    Student stu;        // ѧ����Ϣ
    struct _Node *next; // ��һ���ڵ�ָ��
} Node;

//ͷ���
Node *g_pHead = NULL;


//�ļ�
FILE *fp;
char filename[120];

// ��ӭ����
void menu();

//����ͷ���
void CreatListOfHead();

//¼��ѧ����Ϣ
void InputStudentInfo();

//�鿴ѧ����Ϣ
void ViewStudentInfo();

//����ѧ����Ϣ
void AddStudentInfo();

//�ܳɼ�����
void GradesRanking();

//����ѧ����Ϣ(id)
void SearchStudentInfo_id();

//����ѧ����Ϣ(name)
void SearchStudentInfo_name();

//�޸�ѧ����Ϣ
void ModifyStudentInfo();

//ɾ��ѧ����Ϣ(id)
void DeleteStudentInfo_id();

//ɾ��ѧ����Ϣ(name)
void DeleteStudentInfo_name();

//ѭ����
int Loop();

int main() {
    menu();
    Loop();

    return 0;
}


// menu��ʾ�˵�
void menu() {
    printf("\n\n\n");
    printf("    *******************************************\n");
    printf("    *          ��ӭʹ�óɼ�����ϵͳ               *\n");
    printf("    *******************************************\n");
    printf("    *             ��ѡ�����б�                 *\n");
    printf("    *******************************************\n");
    printf("    *          [1] ¼��ѧ����Ϣ                 *\n");
    printf("    *          [2] �鿴ѧ����Ϣ                 *\n");
    printf("    *          [3] ����ѧ����Ϣ                 *\n");
    printf("    *          [4] ���ܳɼ�����                 *\n");
    printf("    *          [5] ����ѧ����Ϣ                 *\n");
    printf("    *          [6] �޸�ѧ����Ϣ                 *\n");
    printf("    *          [7] ɾ��ѧ����Ϣ                 *\n");
    printf("    *          [0] �˳�ϵͳ                    *\n");
    printf("    *******************************************\n");
}

//����ͷ���
void CreatListOfHead() {
    Node *g_pHead = (Node *) malloc(sizeof(Node));
    g_pHead->next = NULL;
}

void InputStudentInfo() {
    //�����ڴ棬���ٽڵ�
    Node *p = (Node *) malloc(sizeof(Node));
    p->next = NULL;
    printf("������ѧ����Ϣ:\n");
    printf("ѧ��:");
    scanf("%d", &p->stu.id);
    printf("����:");
    scanf("%s", p->stu.name);
    printf("��ѧ�ɼ�:");
    scanf("%d", &p->stu.math);
    printf("Ӣ��ɼ�:");
    scanf("%d", &p->stu.eng);
    printf("C���Գɼ�:");
    scanf("%d", &p->stu.C);
    p->stu.sum = p->stu.math + p->stu.eng + p->stu.C;

    //���ڵ���ӵ�������
    if (g_pHead == NULL) {
        g_pHead = p;
    } else {
        //ͷ�巨
        p->next = g_pHead;
        g_pHead = p;
    }
    printf("��Ϣ¼��ɹ���\n");
}

void ViewStudentInfo() {

    //��������
    Node *p = g_pHead;
    while (p != NULL) {
        printf("%d %s %d %d %d %d\n", p->stu.id, p->stu.name, p->stu.math, p->stu.eng,
               p->stu.C, p->stu.sum);
        p = p->next;
    }
    if (g_pHead == NULL) {
        printf("|û�д洢ѧ����Ϣ!\n");
    }
}

void AddStudentInfo() {

}

void GradesRanking() {

}

void SearchStudentInfo_id() {

}

void SearchStudentInfo_name() {

}

void ModifyStudentInfo() {

}

void DeleteStudentInfo_id() {

}

void DeleteStudentInfo_name() {

}

int Loop() {
    while (1) {
        int ch, sea, mo;
        printf("��ѡ��");
        scanf("%d", &ch);
        switch (ch) {
            case 1:
                InputStudentInfo();
                break;
            case 2:
                ViewStudentInfo();
                break;
            case 3:
                AddStudentInfo();
                break;
            case 4:
                GradesRanking();
                break;
            case 5:
                printf("\n");
                printf("[1] ����ѧ��������\n");
                printf("[2] ��������������\n");
                printf("[3] �����ء�\n");
                printf("->��ѡ��:");
                scanf("%d", &sea);
                switch (sea) {
                    case 1:
                        SearchStudentInfo_id();
                    case 2:
                        SearchStudentInfo_name();
                    case 3:
                        break;
                }
                break;
            case 6:
                ModifyStudentInfo();
                break;
            case 7:
                printf("\n");
                printf("[1] ����ѧ��ɾ����\n");
                printf("[2] ��������ɾ����\n");
                printf("[3] �����ء�\n");
                printf("->��ѡ��:");
                scanf("%d", &mo);
                switch (mo) {
                    case 1:
                        DeleteStudentInfo_id();
                    case 2:
                        DeleteStudentInfo_name();
                    case 3:
                        break;
                }
                break;
            case 0:
                //�˳�ϵͳ
                exit(0);
            default:
                break;
        }
    }
}