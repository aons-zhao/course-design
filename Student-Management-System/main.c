#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct student {
    int id; //ѧ��
    char name[20]; //����
    int literature;  //���ĳɼ�
    int math;  // ��ѧ�ɼ�
    int eng;    //Ӣ��ɼ�
    int sum;  //�ܳɼ�
} stu[200], n;  //����n���˵���Ϣ

// ¼��ѧ����Ϣ
void InputStudentInfo();

// �鿴ѧ����Ϣ
void ViewStudentInfo();

//�ܳɼ�����
void Grade_ranking();

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

//���ļ����洢��Ϣ
void save_data(int num);

//��ȡ�ļ���Ϣ
int get_Info();

int main() {
    Loop();

    return 0;
}

// menu��ʾ�˵�
void menu() {
    printf("\n\n\n");
    printf("    **********************************************\n");
    printf("    *          ��ӭʹ��ѧ���������ϵͳ               *\n");
    printf("    **********************************************\n");
    printf("    *             ��ѡ�����б�                    *\n");
    printf("    **********************************************\n");
    printf("    *          [1] ¼��ѧ����Ϣ                    *\n");
    printf("    *          [2] �鿴ѧ����Ϣ                    *\n");
    printf("    *          [3] ���ܳɼ�����                    *\n");
    printf("    *          [4] ����ѧ����Ϣ                    *\n");
    printf("    *          [5] �޸�ѧ����Ϣ                    *\n");
    printf("    *          [6] ɾ��ѧ����Ϣ                    *\n");
    printf("    *          [0] �˳�ϵͳ                       *\n");
    printf("    **********************************************\n");
}

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
                Grade_ranking();
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
                        break;
                    case 2:
                        SearchStudentInfo_name();
                        break;
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
                        break;
                    case 2:
                        DeleteStudentInfo_name();
                        break;
                    case 3:
                        break;
                }
                break;
            case 9:
                get_Info();
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

// ���ļ�������Ϣ����,numΪ�������
void save_data(int num) {
    char value[5];
    printf("�Ƿ񱣴���Ϣ:\n");
    printf("��Y�� / ��N��\n");
    printf("-->");
    scanf("%s", value);
    if (strcmp(value, "Y") == 0) {
        FILE *fp = NULL;
        fp = fopen("../data.txt", "w+");
        for (int i = 0; i < num; ++i) {
            fprintf(fp, "%d\t%s\t%d\t%d\t%d\t%d\n", stu[i].id, stu[i].name, stu[i].literature, stu[i].math, stu[i].eng,
                    stu[i].sum);
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

// ¼��ѧ����Ϣ
void InputStudentInfo() {
    int val, num = get_Info();
    printf("������Ҫ¼���ѧ������:");
    scanf("%d", &val);
    for (int i = num; i < num + val; ++i) {
        printf("->������� %d λѧ����Ϣ:\n", i + 1);
        printf("-->ѧ��:");
        scanf("%d", &stu[i].id);
        printf("-->����:");
        scanf("%s", stu[i].name);
        printf("-->���ĳɼ�:");
        scanf("%d", &stu[i].literature);
        printf("-->��ѧ�ɼ�:");
        scanf("%d", &stu[i].math);
        printf("-->Ӣ��ɼ�:");
        scanf("%d", &stu[i].eng);
        stu[i].sum = stu[i].literature + stu[i].math + stu[i].eng;
    }
    save_data(num + val);
}

// �鿴ѧ����Ϣ
void ViewStudentInfo() {
    char ch;
    FILE *fp;
    fp = fopen("../data.txt", "a+");
    ch = fgetc(fp);
    if (ch == EOF) {
        printf("δ�洢�κ�ѧ����Ϣ�����ȴ�����Ϣ�������\n");
        system("pause");
        return;
    }
    printf("****����ѧ����Ϣ****\n");
    printf("ѧ��\t����\t����\t��ѧ\tӢ��\t�ܷ�\n");
    putchar(ch);
    while ((ch = fgetc(fp)) != EOF) {
        putchar(ch);
    }
    fclose(fp);
    system("pause");
}

//�ܳɼ�����
void Grade_ranking() {
    int num = get_Info();
    if (num == 0) {
        return;
    }
    int i, j;
    for (i = 0; i < num; i++) { // ʹ��ð������
        for (j = i + 1; j < num; j++) {
            if (stu[i].sum < stu[j].sum) {
                n = stu[i];
                stu[i] = stu[j];
                stu[j] = n;
            }
        }
    }
    printf("****�ܳɼ�����****\n");
    printf("ѧ��\t����\t����\t��ѧ\tӢ��\t�ܷ�\n");
    for (int k = 0; k < num; ++k) {
        printf("%d\t%s\t%d\t%d\t%d\t%d\n", stu[k].id, stu[k].name, stu[k].literature, stu[k].math, stu[k].eng,
               stu[k].sum);
    }
    system("pause");
}

//����ѧ����Ϣ(id)
void SearchStudentInfo_id() {
    int num = get_Info();
    if (num == 0) {
        return;
    }
    int value, count = 0;
    printf("--->������ѧ��:");
    scanf("%d", &value);
    for (int i = 0; i < num; ++i) {
        if (value == stu[i].id) {
            printf("ѧ��\t����\t����\t��ѧ\tӢ��\t�ܷ�\n");
            printf("%d\t%s\t%d\t%d\t%d\t%d\n", stu[i].id, stu[i].name, stu[i].literature, stu[i].math, stu[i].eng,
                   stu[i].sum);
            ++count;
            break;
        }
    }
    if (count == 0) {
        printf("����ѧ����Ϣʧ��!\n");
    }
    system("pause");
}

//����ѧ����Ϣ(name)
void SearchStudentInfo_name() {
    int num = get_Info(), count = 0;
    if (num == 0) {
        return;
    }
    char find_name[20];
    printf("--->����������:");
    scanf("%s", find_name);
    for (int i = 0; i < num; ++i) {
        if (strcmp(stu[i].name, find_name) == 0) {
            printf("ѧ��\t����\t����\t��ѧ\tӢ��\t�ܷ�\n");
            printf("%d\t%s\t%d\t%d\t%d\t%d\n", stu[i].id, stu[i].name, stu[i].literature, stu[i].math, stu[i].eng,
                   stu[i].sum);
            ++count;
            break;
        }
    }
    if (count == 0) {
        printf("����ѧ����Ϣʧ��!\n");
    }
    system("pause");
}

//�޸�ѧ����Ϣ
void ModifyStudentInfo() {
    int num = get_Info(), count = 0;  // �Ȼ�ȡ��ѧ������
    if (num == 0) {
        return;
    }
    int val;
    printf("������ѧ��:");
    scanf("%d", &val);
    for (int i = 0; i < num; ++i) {
        if (stu[i].id == val) {
            printf("�������޸ĺ��ѧ��:");
            scanf("%d", &stu[i].id);
            printf("�������޸ĺ������:");
            scanf("%s", stu[i].name);
            printf("�������޸ĺ�����ĳɼ�:");
            scanf("%d", &stu[i].literature);
            printf("�������޸ĺ����ѧ�ɼ�:");
            scanf("%d", &stu[i].math);
            printf("�������޸ĺ��Ӣ��ɼ�:");
            scanf("%d", &stu[i].eng);
            stu[i].sum = stu[i].literature + stu[i].math + stu[i].eng;
            ++count;
            break;
        }
    }
    if (count == 0) {
        printf("δ���ҵ���ѧ��!\n");
    }
    system("pause");
    save_data(num); // �������ݺ���
}

//ɾ��ѧ����Ϣ(id)
void DeleteStudentInfo_id() {
    int num = get_Info(), count = 0, val;
    if (num == 0) {
        return;
    }
    printf("--->������ѧ��:");
    scanf("%d", &val);
    for (int i = 0; i < num; ++i) {
        if (stu[i].id == val) {
            for (int j = i; j < num; ++j) {
                stu[j] = stu[j + 1];
            }
            ++count;
            printf("ɾ����Ϣ�ɹ�!\n");
            save_data(num - 1);
            break;
        }
    }
    if (count == 0) {
        printf("ɾ����Ϣʧ��!\n");
    }
    system("pause");
}

//ɾ��ѧ����Ϣ(name)
void DeleteStudentInfo_name() {
    int num = get_Info(), count = 0;
    if (num == 0) {
        return;
    }
    char del_name[20];
    printf("--->����������:");
    scanf("%s", del_name);
    for (int i = 0; i < num; ++i) {
        if (strcmp(stu[i].name, del_name) == 0) {
            for (int k = i; k < num; ++k) {
                stu[k] = stu[k + 1];
            }
            ++count;
            printf("ɾ����Ϣ�ɹ�!\n");
            save_data(num - 1);
            break;
        }
    }
    if (count == 0) {
        printf("ɾ����Ϣʧ��!\n");
    }
    system("pause");
}

// ��ȡ�ļ���Ϣ
int get_Info() {
    int num = 0, i = 0;
    char ch, val;
    FILE *fp;
    fp = fopen("../data.txt", "a+");
    ch = fgetc(fp);
    if (ch == EOF) {
        printf("δ�洢�κ�ѧ����Ϣ�����ȴ�����Ϣ�������\n");
        system("pause");
        return 0;
    } else {
        fp = fopen("../data.txt", "a+");
        while ((feof(fp) == 0)) {
            fscanf(fp, "%d", &stu[i].id);
            fgetc(fp);
            fscanf(fp, "%s", stu[i].name);
            fgetc(fp);
            fscanf(fp, "%d", &stu[i].literature);
            fgetc(fp);
            fscanf(fp, "%d", &stu[i].math);
            fgetc(fp);
            fscanf(fp, "%d", &stu[i].eng);
            fgetc(fp);
            fscanf(fp, "%d", &stu[i].sum);
            fgetc(fp);
            ++i;
            ++num;
        }
        --num;
    }
    return num;
}