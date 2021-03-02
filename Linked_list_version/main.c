//һ����ҵԱ����Ϣ����ϵͳ���ܹ�����ҵԱ���ĸ��ݹ��š����Ż�ְλ����ͳ�ơ�����͸��£����ҿ��Է�����ҵ�쵼��Ա���������������
#include<stdio.h>
#include<stdlib.h>
#include<string.h>


//Ա���ṹ��
typedef struct Worker {
    int id; // ����
    char name[20];   // ����
    int age; // ����
    char bra[20];  // ����
    char post[20];    // ְλ
    int pay;  // ����
} Worker;

//����������
typedef struct Node {
    Worker wor;    // Ա����Ϣ
    struct Node *next; // ��һ���ڵ�ָ��,(����ṹ��ָ�����)
} Node;

//ͷ���
Node *Head = NULL;

//���ļ�����
void openfile();

// ��¼��֤����
void Authentication();

// ��ӭ����
void menu();

//����ͷ���
void CreatHead();

//¼��Ա����Ϣ
void InputWorkerInfo();

//�鿴Ա����Ϣ
void ViewWorkerInfo();

//��������
void Salary_ranking();

//����Ա����Ϣ(id)
void SearchWorkerInfo_id();

//����Ա����Ϣ(name)
void SearchWorkerInfo_name();

//�޸�Ա����Ϣ
void ModifyWorkerInfo();

//ɾ��Ա����Ϣ(id)
void DeleteWorkerInfo_id();

//ɾ��Ա����Ϣ(name)
void DeleteWorkerInfo_name();

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
    printf("    *          ��ӭʹ����ҵ����ϵͳ               *\n");
    printf("    *******************************************\n");
    printf("    *             ��ѡ�����б�                 *\n");
    printf("    *******************************************\n");
    printf("    *          [1] ¼��Ա����Ϣ                 *\n");
    printf("    *          [2] �鿴Ա����Ϣ                 *\n");
    printf("    *          [3] ����������                   *\n");
    printf("    *          [4] ����Ա����Ϣ                 *\n");
    printf("    *          [5] �޸�Ա����Ϣ                 *\n");
    printf("    *          [6] ɾ��Ա����Ϣ                 *\n");
    printf("    *          [0] �˳�ϵͳ                    *\n");
    printf("    *******************************************\n");
}

// ���ļ�������Ϣ����
void save_date() {
    char value[5];
    printf("�Ƿ���Ϣ���ļ���:\n");
    printf("��Y�� / ��N��\n");
    printf("-->");
    scanf("%s", value);
    if (strcmp(value, "Y") == 0) {
        Node *p = Head;
        FILE *fp = NULL;
        fp = fopen("../data.txt", "a+");
        while (p != NULL) {
            fprintf(fp, "%d\t%s\t%d\t%s\t%s\t%d\n", p->wor.id, p->wor.name, p->wor.age, p->wor.post, p->wor.bra,
                    p->wor.pay);
            p = p->next;
        }
        printf("���ݱ���ɹ�!\n");
        fclose(fp);
        system("pause");
        return;
    }
    if (strcmp(value, "N") == 0) {
        printf("��ע��,����δ����,���ȱ�������,���ⶪʧ����!\n");
        system("pause");
        return;
    }
}

//����ͷ���
void CreatHead() {
    Node *Head = (Node *) malloc(sizeof(Node));
    Head->next = NULL;
}

// ¼��Ա����Ϣ����
void InputWorkerInfo() {
    int val;
    printf("������Ҫ¼���Ա������:");
    scanf("%d", &val);
    for (int i = 0; i < val; ++i) {
        //�����ڴ棬���ٽڵ�
        Node *p = (Node *) malloc(sizeof(Node));
        p->next = NULL;
        printf("->������� %d λԱ����Ϣ:\n", i + 1);
        printf("-->����:");
        scanf("%d", &p->wor.id);
        printf("-->����:");
        scanf("%s", p->wor.name);
        printf("-->����:");
        scanf("%d", &p->wor.age);
        printf("-->����:");
        scanf("%s", p->wor.bra);
        printf("-->ְλ:");
        scanf("%s", p->wor.post);
        printf("-->����:");
        scanf("%d", &p->wor.pay);

        //���ڵ���ӵ�������
        if (Head == NULL) {
            Head = p;
        } else {
            //ͷ�巨
            p->next = Head;
            Head = p;
        }
    }
    save_date();
}

// �鿴Ա����Ϣ����
void ViewWorkerInfo() {
    char ch;
    FILE *fp = NULL;
    fp = fopen("../data.txt", "r");
    ch = fgetc(fp);
    if (ch == EOF) {
        printf("û�д洢�κ�Ա����Ϣ!\n");
        system("pause");
        return;
    }
    printf("����\t����\t����\t����\tְλ\t����\n");
    putchar(ch);
    while ((ch = fgetc(fp)) != EOF) {
        putchar(ch);
    }
    fclose(fp);
    system("pause");
    return;
}

// �����ʴӸߵ�����������
void Salary_ranking() {
    Worker temp;
    Node *p = Head;
    Node *q = NULL;
    Node *r = NULL;
    while (p->next != NULL) {
        p = p->next;
    }
    q = p;
    p = Head;
    r = p->next;
    while (p != q) {
        while (r != q->next) {
            if (p->wor.pay < r->wor.pay) {
                temp = p->wor;
                p->wor = r->wor;
                r->wor = temp;
            }
            if (r == q) {
                q = p;
                p = Head;
                r = p->next;
                break;
            }
            p = p->next;
            r = r->next;
        }
    }
    printf("*****������������*****\n");
    while (p != NULL) {
        printf("����\t����\t����\t����\tְλ\t����\n");
        printf("%d\t%s\t%d\t%s\t%s\t%d\n", p->wor.id, p->wor.name, p->wor.age, p->wor.bra, p->wor.post,
               p->wor.pay);
        p = p->next;
    }
    system("pause");
}

// ����������Ա����Ϣ����
void SearchWorkerInfo_id() {
    Node *p = Head;
    int id, val = 1;
    printf("������Ҫ������Ա������:");
    scanf("%d", &id);
    while (p->next != NULL) {
        if (p->wor.id == id) {
            printf("����\t����\t����\t����\tְλ\t����\n");
            printf("%d\t%s\t%d\t%s\t%s\t%d\n", p->wor.id, p->wor.name, p->wor.age, p->wor.bra, p->wor.post,
                   p->wor.pay);
            --val;
            system("pause");
        }
        p = p->next;
        if (val == 1) {
            printf("δ��ѯ����Ա���й���Ϣ!\n");
            system("pause");
            return;
        }
    }
}

// ����������Ա����Ϣ����
void SearchWorkerInfo_name() {
    Node *p = Head;
    char name[20];
    printf("������Ҫ������Ա������:");
    scanf("%s", name);
    while (p && (strcmp(p->wor.name, name) != 0)) {
        p = p->next;
    }
    if (p) {
        printf("����\t����\t����\t����\tְλ\t����\n");
        printf("%d\t%s\t%d\t%s\t%s\t%d\n", p->wor.id, p->wor.name, p->wor.age, p->wor.bra, p->wor.post,
               p->wor.pay);
        system("pause");
    } else {
        printf("δ��ѯ����Ա���й���Ϣ!\n");
        system("pause");
        return;
    }
}

// �޸�Ա����Ϣ����
void ModifyWorkerInfo() {
    int id;
    printf("������Ҫ�޸ĵ�Ա������:");
    scanf("%d", &id);
    Node *p = Head;
    while (p && (p->wor.id != id)) {
        p = p->next;
    }
    if (p) {
        printf("�������µ���Ϣ:\n");
        printf("-->�������޸ĺ�Ĺ���:");
        scanf("%d", &p->wor.id);
        printf("-->�������޸ĺ������:");
        scanf("%s", p->wor.name);
        printf("-->�������޸ĺ������:");
        scanf("%d", &p->wor.age);
        printf("-->�������޸ĺ�Ĳ���:");
        scanf("%s", p->wor.bra);
        printf("-->�������޸ĺ��ְλ:");
        scanf("%s", p->wor.post);
        printf("�������޸ĺ�Ĺ���:");
        scanf("%d", &p->wor.pay);
        save_date();
        system("pause");
        return;
    } else {
        printf("δ��ѯ����Ա���й���Ϣ!\n");
        system("pause");
        return;
    }
}

// ������ɾ��Ա����Ϣ����
void DeleteWorkerInfo_id() {
    int id;
    printf("������Ҫɾ����Ա������:");
    scanf("%d", &id);
    Node *p = Head;
    while (1) {
        if (p->next && (p->next->wor.id == id)) {
            Node *useless = p->next;
            p->next = useless->next;
            printf("��Ա���й���Ϣ��ɾ��!");
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

// ������ɾ��Ա����Ϣ����
void DeleteWorkerInfo_name() {
    char name[20];
    printf("������Ҫɾ����Ա������:");
    scanf("%s", name);
    Node *p = Head;
    while (1) {
        if (p->next && (strcmp(p->wor.name, name) == 0)) {
            Node *useless = p->next;
            p->next = p->next->next;
            printf("��Ա���й���Ϣ��ɾ��!\n");
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
                InputWorkerInfo();
                break;
            case 2:
                ViewWorkerInfo();
                break;
            case 3:
                Salary_ranking();
                break;
            case 4:
                printf("\n");
                printf("[1] ��������������\n");
                printf("[2] ��������������\n");
                printf("[3] �����ء�\n");
                printf("-->��ѡ��:");
                scanf("%d", &sea);
                switch (sea) {
                    case 1:
                        SearchWorkerInfo_id();
                        break;
                    case 2:
                        SearchWorkerInfo_name();
                        break;
                    case 3:
                        break;
                }
                break;
            case 5:
                ModifyWorkerInfo();
                break;
            case 6:
                printf("\n");
                printf("[1] ��������ɾ����\n");
                printf("[2] ��������ɾ����\n");
                printf("[3] �����ء�\n");
                printf("-->��ѡ��:");
                scanf("%d", &mo);
                switch (mo) {
                    case 1:
                        DeleteWorkerInfo_id();
                        break;
                    case 2:
                        DeleteWorkerInfo_name();
                        break;
                    case 3:
                        break;
                }
                break;
            case 0:
                //�˳�ϵͳ
                exit(0);
            default:
                printf("����������������룡\n\n");
                system("pause");
                break;
        }
    }
}

// ��¼��֤����
void Authentication() {
    char account[20];
    char password[20];
    printf("�˺�:");
    scanf("%s", account);
    printf("����:");
    scanf("%s", password);
}