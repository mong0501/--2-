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
void print_room() {
    char line1[17] = "#H   ?    ?  B#";
    char line2[17] = "#             #";

    line1[5] = cattower ? 'T' : ' ';
    line1[10] = scratcher ? 'S' : ' ';

    for (int i = 0; i < 15; i++) {
        if (line1[i] == cat_pos) {
            line2[i] = 'C';
        }
    }

    printf("###############\n");
    printf("%s\n", line1);
    printf("%s\n", line2);
    printf("###############\n");
}

void decrease_mood() {
    int dice = roll_dice();
    int threshold = 6 - intimacy;
    printf("%d-%d: �ֻ��� ���� %d�����̸� �׳� ����� �������ϴ�.\n", 6, intimacy, threshold);
    printf("�ֻ����� �����ϴ�. �Ǹ���...\n");
    printf("%d��(��) ���Խ��ϴ�.\n", dice);
    if (dice <= threshold && mood > 0) {
        printf("�˶��� ����� �������ϴ�: %d -> %d\n", mood, mood - 1);
        mood--;
    }
}

void move_cat() {
    if (mood == 0) cat_pos = 'H';
    else if (mood == 1) {
        if (scratcher) cat_pos = 'S';
        else if (cattower) cat_pos = 'T';
    }
    else if (mood == 3) cat_pos = 'B';
}

void act_on_location() {
    if (cat_pos == 'H') {
        if (mood < 3) mood++;
    }
    else if (cat_pos == 'S' && scratcher) {
        if (mood < 3) mood++;
    }
    else if (cat_pos == 'T' && cattower) {
        mood += 2;
        if (mood > 3) mood = 3;
    }
    else if (cat_pos == 'B' && mood == 3) {
        soup++;
        printf("�˶��� ������ ��������ϴ�! �� ����: %d��\n", soup);
    }
}   