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
    printf("==================== 현재 상태 =============\n");
    printf("현재까지 만든 수프: %d개\n", soup);
    printf("CP: %d 포인트\n", cp);
    printf("쫀떡이 기분(0~3): %d\n", mood);
    if (mood == 0) printf("기분이 매우 나쁩니다.\n");
    else if (mood == 1) printf("심심해합니다.\n");
    else if (mood == 2) printf("식빵을 굽습니다.\n");
    else printf("골골송을 부릅니다.\n");

    printf("집사와의 관계(0~4): %d\n", intimacy);
    if (intimacy == 0) printf("날마다 싸웁니다.\n");
    else if (intimacy == 1) printf("이상한 집사입니다.\n");
    else if (intimacy == 2) printf("그럭저럭 쓸만한 집사입니다.\n");
    else if (intimacy == 3) printf("믿을만한 집사입니다.\n");
    else printf("천생연분입니다.\n");
    printf("============================================\n");
}