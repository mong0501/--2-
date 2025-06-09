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
    printf("%d-%d: 주사위 눈이 %d이하이면 그냥 기분이 나빠집니다.\n", 6, intimacy, threshold);
    printf("주사위를 굴립니다. 또르르...\n");
    printf("%d이(가) 나왔습니다.\n", dice);
    if (dice <= threshold && mood > 0) {
        printf("쫀떡의 기분이 나빠집니다: %d -> %d\n", mood, mood - 1);
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
        printf("쫀떡이 수프를 만들었습니다! 총 수프: %d개\n", soup);
    }
}   