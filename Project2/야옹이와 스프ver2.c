#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int soup = 0;
int cp = 0;
int mood = 3;
int intimacy = 2;
int turn = 0;

int toy_mouse = 0, laser = 0, scratcher = 0, cattower = 0;
char cat_pos = 'H';

int roll_dice() {
    return rand() % 6 + 1;
}

void print_status() {
    printf("==================== ���� ���� =============\n");
    printf("������� ���� ����: %d��\n", soup);
    printf("CP: %d ����Ʈ\n", cp);
    printf("�˶��� ���(0~3): %d\n", mood);
    if (mood == 0) printf("����� �ſ� ���޴ϴ�.\n");
    else if (mood == 1) printf("�ɽ����մϴ�.\n");
    else if (mood == 2) printf("�Ļ��� �����ϴ�.\n");
    else printf("������ �θ��ϴ�.\n");

    printf("������� ����(0~4): %d\n", intimacy);
    if (intimacy == 0) printf("������ �ο�ϴ�.\n");
    else if (intimacy == 1) printf("�̻��� �����Դϴ�.\n");
    else if (intimacy == 2) printf("�׷����� ������ �����Դϴ�.\n");
    else if (intimacy == 3) printf("�������� �����Դϴ�.\n");
    else printf("õ�������Դϴ�.\n");
    printf("============================================\n");
}