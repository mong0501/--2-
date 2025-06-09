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
void interact() {
    int choice, dice;
    printf("� ��ȣ�ۿ��� �Ͻðڽ��ϱ�?\n");
    if (toy_mouse) printf("2. �峭�� ��� ���\n");
    printf("0. �ƹ��͵� ���� ����\n1. �ܾ� �ֱ�\n");
    if (laser) printf("3. ������ �����ͷ� ���\n");

    do {
        printf(">> ");
        scanf_s("%d", &choice);
    } while (choice < 0 || choice > 3);

    dice = roll_dice();

    if (choice == 0) {
        if (mood > 0) mood--;
        if (dice <= 5 && intimacy > 0) intimacy--;
    }
    else if (choice == 1) {
        if (dice >= 5 && intimacy < 4) intimacy++;
    }
    else if (choice == 2 && toy_mouse) {
        if (mood < 3) mood++;
        if (dice >= 4 && intimacy < 4) intimacy++;
    }
    else if (choice == 3 && laser) {
        mood += 2;
        if (mood > 3) mood = 3;
        if (dice >= 2 && intimacy < 4) intimacy++;
    }
}

void produce_cp() {
    int gain = (mood > 0 ? mood - 1 : 0) + intimacy;
    cp += gain;
    printf("CP %d ����Ǿ����ϴ�. �� CP: %d\n", gain, cp);
}

void shop() {
    int choice;
    while (1) {
        printf("����:\n0. �ƹ��͵� �� ��\n");
        if (!toy_mouse) printf("1. �峭�� �� (1 CP)\n");
        if (!laser) printf("2. ������ ������ (2 CP)\n");
        if (!scratcher) printf("3. ��ũ��ó (4 CP)\n");
        if (!cattower) printf("4. Ĺ Ÿ�� (6 CP)\n");

        scanf_s("%d", &choice);

        if (choice == 0) break;
        else if (choice == 1 && !toy_mouse && cp >= 1) {
            toy_mouse = 1; cp -= 1; break;
        }
        else if (choice == 2 && !laser && cp >= 2) {
            laser = 1; cp -= 2; break;
        }
        else if (choice == 3 && !scratcher && cp >= 4) {
            scratcher = 1; cp -= 4; break;
        }
        else if (choice == 4 && !cattower && cp >= 6) {
            cattower = 1; cp -= 6; break;
        }
        else {
            printf("CP ���� �Ǵ� �̹� ������. �ٽ� �����ϼ���.\n");
        }
    }
}

void quest() {
    int q;
    printf("[���� ����Ʈ �߻�!] ���� �غ���?\n1. ����\n2. ����\n3. ���� ���\n>> ");
    scanf_s("%d", &q);
    if (q == 2 && intimacy < 4) {
        intimacy++;
        printf("�˶� ���� ����! ģ�е� +1\n");
    }
    else {
        if (mood > 0) mood--;
        printf("�˶� �Ǹ�... ��� -1\n");
    }
}

