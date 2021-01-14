//һ��ѧ����Ϣ����ϵͳ���ܹ���ѧ����ѧ�š������͸��Ƴɼ�����ͳ�ơ�����͸���
#include<stdio.h>
#include <string.h>

struct student {
    char name[20]; // ����
    int id; // ѧ��
    int math; // ��ѧ�ɼ�
    int eng;  // Ӣ��ɼ�
    int C;    // C���Գɼ�
    int sum;  // �ܳɼ�
    double av;  // ƽ���ɼ�
} student[200], n;  // ����n���˵���Ϣ


void menu() // menu��ʾ�˵�
{
    printf("��ӭʹ��ѧ����Ϣ����ϵͳ\n");
    printf("[1] ¼������ѧ����Ϣ\n");
    printf("[2] �������ѧ����Ϣ\n");
    printf("[3] ����ѧ����Ϣ\n");
    printf("[4] ��ѧ�Ų���ĳ��ѧ����Ϣ\n");
    printf("[5] ����������ĳ��ѧ����Ϣ\n");
    printf("[6] ���ܳɼ���ѧ������\n");
    printf("[7] ��ѧ���޸�ĳ��ѧ����Ϣ\n");
    printf("[8] �������޸�ĳ��ѧ����Ϣ\n");
    printf("[9] ��ѧ��ɾ��ĳ��ѧ����Ϣ\n");
    printf("[10] ������ɾ��ĳ��ѧ����Ϣ\n");
    printf("[0] �˳�ϵͳ\n");
}


int main() {

    int num = 0, ch = 11; // ѧ������
    int input1(); // ��������
    void output2(int num);
    int output3(int num);
    void output4(int num);
    void output5(int num);
    void output6(int num);
    void output7(int num);
    void output8(int num);
    void output9(int num);
    void output10(int num);
    void pause();   // ��ͣ����
    while (1) {
        menu();
        printf("���������ѡ��(0~10)��");
        scanf("%d", &ch);
        if (ch == 1) {
            num = input1();
            pause();
        } else if (ch == 2) {
            output2(num);
            pause();
        } else if (ch == 3) {
            num = output3(num);
            pause();
        } else if (ch == 4) {
            output4(num);
            pause();
        } else if (ch == 5) {
            output5(num);
            pause();
        } else if (ch == 6) {
            output6(num);
            pause();
        } else if (ch == 7) {
            output7(num);
            pause();
        } else if (ch == 8) {
            output8(num);
            pause();
        } else if (ch == 9) {
            output9(num);
            pause();
        } else if (ch == 10) {
            output10(num);
            pause();
        } else if (ch == 0) {
            break;
        }
    }
    return 0;
}

int input1() {
    int val;
    printf("������Ҫ¼����Ϣ��ѧ������:");
    scanf("%d", &val);
    for (int i = 0; i < val; i++) {   // ¼��n��ѧ������Ϣ
        printf("�������%d��ѧ�������� ѧ�ţ���ѧ�ɼ���Ӣ��ɼ���C���Գɼ�(�ÿո����)\n", i + 1);
        scanf("%s %d %d %d %d", student[i].name, &student[i].id, &student[i].math, &student[i].eng,
              &student[i].C);
        student[i].sum = student[i].math + student[i].eng + student[i].C;
        student[i].av = 1.0 * student[i].sum / 3;
    }
    return val;
}

void output2(int num) {
    printf("����Ϊ����ѧ����Ϣ:\n");
    for (int j = 0; j < num; j++) {
        printf("����:%s, ѧ��:%d, ��ѧ:%d, Ӣ��:%d, C����:%d, �ܳɼ�:%d\n", student[j].name, student[j].id,
               student[j].math, student[j].eng, student[j].C, student[j].sum);
    }
}

int output3(int num) {
    int q;
    printf("������Ҫ���ӵ�ѧ������:");
    scanf("%d", &q);
    for (int i = num; i < num + q; i++) {
        printf("����������������ѧ�ţ���ѧ�ɼ���Ӣ��ɼ���C���Գɼ�(�ÿո����)\n");
        scanf("%s %d %d %d %d", student[i].name, &student[i].id, &student[i].math, &student[i].eng,
              &student[i].C);
        student[i].sum = student[i].math + student[i].eng + student[i].C;
        student[i].av = 1.0 * student[i].sum / 3;
    }
    return num + q;
}

void output4(int num) {
    int s;
    printf("������ѧ��:");
    scanf("%d", &s);
    for (int i = 0; i < num; i++) {
        if (student[i].id == s) {
            printf("����:%s, ѧ��:%d, ��ѧ:%d, Ӣ��:%d, C����:%d, �ܳɼ�:%d\n", student[i].name, student[i].id,
                   student[i].math, student[i].eng, student[i].C, student[i].sum);
            break;
        }
    }
}

void output5(int num) {
    char s[20];
    printf("����������:");
    scanf("%s", s);
    for (int i = 0; i < num; i++) {
        if (strcmp(student[i].name, s) == 0) {
            printf("����:%s, ѧ��:%d, ��ѧ:%d, Ӣ��:%d, C����:%d, �ܳɼ�:%d\n", student[i].name, student[i].id,
                   student[i].math, student[i].eng, student[i].C, student[i].sum);
            break;
        }
    }
}

void output6(int num) {
    int i, j;
    for (i = 0; i < num; i++) { // ���ֵܷݼ�����
        for (j = i + 1; j < num; j++) {
            if (student[j].sum > student[i].sum) {
                n = student[i];
                student[i] = student[j];
                student[j] = n;
            }
        }
    }
    for (int k = 0; k < num; k++) {
        printf("����:%s, ѧ��:%d, ��ѧ:%d, Ӣ��:%d, C����:%d, �ܳɼ�:%d\n", student[k].name, student[k].id,
               student[k].math, student[k].eng, student[k].C, student[k].sum);
    }
}

void output7(int num) {
    int ID1;
    printf("������ѧ��:\n");
    scanf("%d", &ID1);
    for (int i = 0; i < num; i++) {
        if (student[i].id == ID1) {
            printf("�������µ���Ϣ:\n");
            scanf("%s %d %d %d %d", student[i].name, &student[i].id, &student[i].math, &student[i].eng,
                  &student[i].C);
            student[i].sum = student[i].math + student[i].eng + student[i].C;
            student[i].av = 1.0 * student[i].sum / 3;
            break;
        }
    }
}

void output8(int num) {
    char title[20];
    printf("����������:");
    scanf("%s", title);
    for (int i = 0; i < num; i++) {
        if (strcmp(student[i].name, title) == 0) {
            printf("�������µ���Ϣ:\n");
            scanf("%s %d %d %d %d", student[i].name, &student[i].id, &student[i].math, &student[i].eng,
                  &student[i].C);
            student[i].sum = student[i].math + student[i].eng + student[i].C;
            student[i].av = 1.0 * student[i].sum / 3;
            break;
        }
    }
}

void output9(int num) {
    int ID2;
    printf("������ѧ��:");
    scanf("%d", &ID2);
    for (int i = 0; i < num; i++) {
        if (student[i].id == ID2) {
            
        }
    }
}

void output10(int num) {
    char title;
    printf("����������:");
    scanf("%c", &title);
    for (int i = 0; i < num; i++) {
        if (strcmp(student[i].name, &title) == 0) {

        }
    }
}

void pause() {
    getchar();
    printf("�밴�س�����...");
    getchar();
}