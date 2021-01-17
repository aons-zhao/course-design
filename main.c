//һ��ѧ����Ϣ����ϵͳ���ܹ���ѧ����ѧ�š������͸��Ƴɼ�����ͳ�ơ�����͸���
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int stu_count = 0;

//ѧ���ṹ��
typedef struct Student {
    int id; // ѧ��
    char name[20];   // ����
    int math; // ��ѧ�ɼ�
    int eng;  // Ӣ��ɼ�
    int C;    // C���Գɼ�
    int sum;  // �ܳɼ�
} Student;

//����������
typedef struct Node {
    Student stu;    // ѧ����Ϣ
    struct Node *next; // ��һ���ڵ�ָ��,(����ṹ��ָ�����)
} Node;

//ͷ���
Node *firstHead = NULL;

//�ļ�
void openfile();

// ��ӭ����
void menu();

//����ͷ���
void CreatHead();

//¼��ѧ����Ϣ
void InputStudentInfo();

//�鿴ѧ����Ϣ
void ViewStudentInfo();

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

//����ѭ����
int Loop();

int main() {
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
    printf("    *          [3] ���ܳɼ�����                 *\n");
    printf("    *          [4] ����ѧ����Ϣ                 *\n");
    printf("    *          [5] �޸�ѧ����Ϣ                 *\n");
    printf("    *          [6] ɾ��ѧ����Ϣ                 *\n");
    printf("    *          [0] �˳�ϵͳ                    *\n");
    printf("    *******************************************\n");
}

// ���ļ�������Ϣ����
void save_date() {
    char value;
    printf("�Ƿ���Ϣ���ļ���:\n");
    printf("��Y��\n");
    printf("��N��\n");
    scanf("%c", &value);
    if (value == 'Y') {
        Node *p = firstHead;
        FILE *fp = NULL;
        fp = fopen(".\\date.txt", "r+");
        if ((fp = fopen(".\\date.txt", "r+")) == NULL) {
            printf("���ݱ���ʧ��!\n");
            system("pause");
            return;
        }
        while (p != NULL) {
            fprintf(fp, "%d %s %d %d %d %d\n", p->stu.id, p->stu.name, p->stu.math, p->stu.eng, p->stu.C,
                    p->stu.sum);
            p = p->next;
        }
        printf("���ݱ���ɹ�!");
        fclose(fp);
        system("pause");
        return;
    }
    if (value == 'N') {
        return;
    }
}

//����ͷ���
void CreatHead() {
    Node *firstHead = (Node *) malloc(sizeof(Node));
    firstHead->next = NULL;
}

// ¼��ѧ����Ϣ����
void InputStudentInfo() {
    int val;
    char value;
    //�����ڴ棬���ٽڵ�
    Node *p = (Node *) malloc(sizeof(Node));
    p->next = NULL;
    printf("������Ҫ¼���ѧ������:");
    scanf("%d", &val);
    for (int i = 0; i < val; i++) {
        printf("�������%dѧ����Ϣ:\n", i + 1);
        printf("-->ѧ��:");
        scanf("%d", &p->stu.id);
        printf("-->����:");
        scanf("%s", p->stu.name);
        printf("-->��ѧ�ɼ�:");
        scanf("%d", &p->stu.math);
        printf("-->Ӣ��ɼ�:");
        scanf("%d", &p->stu.eng);
        printf("-->C���Գɼ�:");
        scanf("%d", &p->stu.C);
        p->stu.sum = p->stu.math + p->stu.eng + p->stu.C;
        stu_count++;

        //���ڵ���ӵ�������
        if (firstHead == NULL) {
            firstHead = p;
        } else {
            //ͷ�巨
            p->next = firstHead;
            firstHead = p;
        }
    }
    save_date();
    system("pause");
}

// �鿴ѧ����Ϣ����
void ViewStudentInfo() {
    //��������
    Node *p = firstHead;
    while (p != NULL) {
        printf("%d %s %d %d %d %d\n", p->stu.id, p->stu.name, p->stu.math, p->stu.eng, p->stu.C, p->stu.sum);
        p = p->next;
        p = p->next;
    }
    if (firstHead == NULL) {
        printf("û�д洢�κ�ѧ����Ϣ!\n");
    }
    system("pause");
}

// ���ܳɼ��Ӹߵ�����������
void GradesRanking() {
    int val;
    Node *p = firstHead;
    while (p != NULL) {
        if (p->stu.sum < p->next->stu.sum) {
            val = p->stu.sum;
            p->stu.sum = p->next->stu.sum;
            p->next->stu.sum = val;
        }
        p = p->next;
    }
    printf("*****���ܳɼ�������*****\n");
    while (p != NULL) {
        printf("%d %s %d %d %d %d\n", p->stu.id, p->stu.name, p->stu.math, p->stu.eng, p->stu.C, p->stu.sum);
        p = p->next;
    }
    system("pause");
}

// ��ѧ������ѧ����Ϣ����
void SearchStudentInfo_id() {
    Node *p = firstHead;
    int id, val = 0;
    printf("������Ҫ������ѧ��ѧ��:");
    scanf("%d", &id);
    while (p->next != NULL) {
        if (p->stu.id == id) {
            printf("%d %s %d %d %d %d\n", p->stu.id, p->stu.name, p->stu.math, p->stu.eng, p->stu.C,
                   p->stu.sum);
            p = p->next;
        } else {
            printf("δ��ѯ�������й���Ϣ!\n");
            system("pause");
            return;
        }
    }
}

// ����������ѧ����Ϣ����
void SearchStudentInfo_name() {
    Node *p = firstHead;
    char name[20];
    printf("������Ҫ������ѧ������:");
    scanf("%s", name);
    while (p && (strcmp(p->stu.name, name) != 0)) {
        p = p->next;
    }
    if (p) {
        printf("%d %s %d %d %d %d\n", p->stu.id, p->stu.name, p->stu.math, p->stu.eng, p->stu.C,
               p->stu.sum);
    } else {
        printf("δ��ѯ�������й���Ϣ!\n");
        system("pause");
        return;
    }
}

// �޸�ѧ����Ϣ����
void ModifyStudentInfo() {
    int id;
    printf("������Ҫ�޸ĵ�ѧ��ѧ��:");
    scanf("%d", &id);
    Node *p = firstHead;
    while (p && (p->stu.id != id)) {
        p = p->next;
    }
    if (p) {
        printf("�������µ���Ϣ:");
        printf("-->�������޸ĺ��ѧ��:");
        scanf("%d", &p->stu.id);
        printf("-->�������޸ĺ������:");
        scanf("%s", p->stu.name);
        printf("-->�������޸ĺ����ѧ�ɼ�:");
        scanf("%d", &p->stu.math);
        printf("-->�������޸ĺ�ĳɼ�:");
        scanf("%d", &p->stu.eng);
        printf("-->�������޸ĺ��C���Գɼ�:");
        scanf("%d", &p->stu.C);
        p->stu.sum = p->stu.math + p->stu.eng + p->stu.C;
        save_date();
        system("pause");
        return;
    } else {
        printf("δ��ѯ�������й���Ϣ!\n");
        system("pause");
        return;
    }
}

// ��ѧ��ɾ��ѧ����Ϣ����
void DeleteStudentInfo_id() {
    int id;
    printf("������Ҫɾ����ѧ��ѧ��:");
    scanf("%d", &id);
    Node *p = firstHead;
    while (1) {
        if (p->next && (p->next->stu.id == id)) {
            Node *useless = p->next;
            p->next = p->next->next;
            printf("�����й���Ϣ��ɾ��!");
            system("pause");
            free(useless);
            save_date();
            return;
        } else {
            if (p->next != NULL) {
                p = p->next;
            } else {
                printf("��Ϣɾ��ʧ��!");
                system("pause");
                return;
            }
        }
    }
}

// ������ɾ��ѧ����Ϣ����
void DeleteStudentInfo_name() {
    char name[20];
    printf("������Ҫɾ����ѧ������:");
    scanf("%s", name);
    Node *p = firstHead;
    while (1) {
        if (p->next && (strcmp(p->stu.name, name) == 0)) {
            Node *useless = p->next;
            p->next = p->next->next;
            printf("�����й���Ϣ��ɾ��!");
            system("pause");
            free(useless);
            save_date();
            return;
        } else {
            if (p->next != NULL) {
                p = p->next;
            } else {
                printf("��Ϣɾ��ʧ��!");
                system("pause");
                return;
            }
        }
    }
}

// ����ѭ���庯��
int Loop() {
    while (1) {
        int ch, sea, mo;
        menu();
        printf("->��ѡ��");
        scanf("%d", &ch);
        switch (ch) {
            case 1:
                InputStudentInfo();
                break;
            case 2:
                ViewStudentInfo();
                break;
            case 3:
                GradesRanking();
                break;
            case 4:
                printf("\n");
                printf("[1] ����ѧ��������\n");
                printf("[2] ��������������\n");
                printf("[3] �����ء�\n");
                printf("-->��ѡ��:");
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
            case 5:
                ModifyStudentInfo();
                break;
            case 6:
                printf("\n");
                printf("[1] ����ѧ��ɾ����\n");
                printf("[2] ��������ɾ����\n");
                printf("[3] �����ء�\n");
                printf("-->��ѡ��:");
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