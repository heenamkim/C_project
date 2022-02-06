#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define BULL_SAND_COWS 1
#define BASKIN_ROBBIN_SGAME 2
#define HIGH_LOW_GAME 3
#define CARD_GAME 4

int bullsAndCows();
int baskinRobbinsGame();
int highLowGame();
int cardGame();

int main() {

    while (1) {
        int number;

        printf("  =============================\n");
        printf("           GAME MENU           \n");
        printf("  _____________________________\n");
        printf("      1. Bulls And Cows        \n");
        printf("      2. Baskin Robbins Game   \n");
        printf("      3. High Low Game         \n");
        printf("      4. Card Game             \n");
        printf("      5. About                 \n");
        printf("  _____________________________\n");
        printf("      0. EXIT                  \n");
        printf("  =============================\n");
        printf("  >>> ");
        scanf("%d", &number);
        printf("\n\n");

        switch(number) {
            case 0: {
                printf("다음에 또 이용해주세요:0\n\n");
                break;
            }
            case BULL_SAND_COWS: {
                bullsAndCows();
                break;
            }
            case BASKIN_ROBBIN_SGAME: {
                baskinRobbinsGame();
                break;
            }
            case HIGH_LOW_GAME: {
                highLowGame();
                break;
            }
            case CARD_GAME: {
                cardGame();
                break;
            }
            case 5: {
                printf("  =============================\n");
                printf("        H University\n");
                printf("     Computer Engineering\n");
                printf("  Created by Heenam.K on 2021\n");
                printf("  Copyright (c) 2021Y Heenam.K\n");
                break;
            }
        }
        if (number == 0) {
            break;
        }
    }

    return 0;
}
    int bullsAndCows() {
        srand(time(NULL));
        printf("  =============================\n");
        printf("           Bulls And Cows         \n");
        printf("  -----------------------------\n");
        printf("  정답으로 예상되는 숫자 3개를 입력합니다.\n");
        printf("  숫자만 맞으면 b 숫자와 위치까지 맞으면 s로 힌트 표시가 됩니다.\n");
        printf("  총 기회는 10번 입니다.\n");
        printf("  =============================\n\n");
        printf("  Game Start!!\n\n");

        int numbers[3] = {}, input_arr[3] = {};
        int number_list[10] = {0};
        int input;
        int i = 0;


        while(i < 3) {
            numbers[i] = (rand() % 9) +1;
            if (number_list[numbers[i]] == 0){
                number_list[numbers[i]] = numbers[i];
                i++;
            }
        }
        for (int j = 0; j <= 9; j++) {
            int b = 0, s = 0;
            if (j == 9) {
                printf("  땡! 틀렸습니다. 정답은 %d %d %d입니다.\n\n",numbers[0], numbers[1], numbers[2]);
                break;
            }
            printf("  (%d이닝)정답을 입력해 주세요:", j+1);
            scanf("%d", &input);
            for (int k = 0; k < 3; k++) {
                input_arr[2-k] = input % 10;
                input /= 10;
            }
            for (int i = 0; i < 3; i++) {
                for (int j = 0; j < 3; j++) {
                    if (numbers[i] == input_arr[j]) {
                        b++;
                        if (numbers[i] == input_arr[i]){
                            s++;
                            b--;
                        }

                    }
                }
            }
            if (s == 3) {
                printf("\n  정답입니다. 축하합니다!\n\n");
                break;
            }
            printf("  %ds %db 입니다.\n", s, b);
        }

    }
    int baskinRobbinsGame() {
        printf("  =============================\n");
        printf("           BaskinRobbinsGame         \n");
        printf("  -----------------------------\n");
        printf("  computer와 돌아가며 숫자를 차례대로 입력합니다.\n");
        printf("  최대 3번까지 입력 가능하며 31을 입력하는 사람이 지는 게임입니다.\n");
        printf("  =============================\n\n");
        printf("  Game Start!!\n\n");

        int input = 0, computer = 0, computer_random;
        int last_num = 0;
        int i, j;

        while (input <= 31 && computer <= 31) {
            printf("  숫자를 입력해 주세요.\n  ");
            for (i = 0; i <= 3; i++) {
                scanf("%d", &input);

                if(input == 0) {
                    break;
                }
                if (last_num < input) {
                    last_num = input;
                }
            }

            if (last_num == 31) {
                printf("  computer가 이겼습니다.\n\n");
                break;
            }

            printf("  computer의 입력값은 ");
            if (last_num == 30) {
                printf(" 31입니다. user가 이겼습니다. 축하합니다.\n\n");
                break;
            }
            else if (last_num == 29) {
                printf("%d", last_num + 1);
            }
            else if (last_num == 28) {
                printf("%d %d", last_num +1, last_num + 2);
            }
            else {
                computer_random = (rand() % 3) + 1;
                for (j = 0; j < computer_random; j++) {
                    last_num++;
                    printf(" %d", last_num);
                }
            }
            printf(" 입니다. \n");
        }

        return 0;
    }
    int highLowGame() {
        srand(time(NULL));
        printf("  =============================\n");
        printf("           HighLowGame         \n");
        printf("  -----------------------------\n");
        printf("  1~100중 랜덤으로 골라진 숫자 하나를 맞추는 게임입니다.\n");
        printf("  총 10번의 기회가 주어집니다.\n");
        printf("  =============================\n");

        int input, random_num;
        random_num = (rand() % 100) + 1;

        for (int i = 0; i <= 10; i++) {
            if (i == 10) {
                printf("\n  아쉽지만 탈락! 정답은 %d 입니다.\n\n", random_num);
                break;
            }
            printf("  (%d번 남음)정답을 입력해 주세요.:", 10-i);
            scanf("%d", &input);
            if (random_num == input){
                printf("\n  축하합니다. 정답입니다!!\n\n");
                break;
            }
            else if (random_num > input)
                printf("  숫자가 낮아요. 좀 더 올려보세요.\n");
            else
                printf("  숫자가 높아요. 좀 더 낮춰보세요.\n");
        }
        return 0;
    }
    int cardGame() {
        srand(time(NULL));
        printf("  =============================\n");
        printf("           CardGame        \n");
        printf("  -----------------------------\n");
        printf("  1~13 카드중 랜덤으로 6개의 카드를 지급합니다.\n  그 중 3개를 골라 합이 21에 가까운 사람이 승리하게 됩니다.\n");
        printf("  단 합 21이 넘어가면 탈락하게 됩니다.\n");
        printf("  =============================\n");

        int i, j, result = 0;
        int card[12], computer_card[6], user_card[6], numbers[15] = {0};
        int computer, computer_max = 0, computer_result, user;
        int input1, input2, input3;
        int num = 0;

        while(result < 12) {
            num = (rand() % 13) +1;
            if (numbers[num] == 0){
                card[result] = num;
                numbers[num] = num;
                result++;
            }
        }

        for (i = 0; i < 12; i++) {
            if (i < 6) {
                computer_card[i] = card[i];
            }
            else {
                user_card[i-6] = card[i];
            }
        }
        printf("  user님의 카드는 %d %d %d %d %d %d 입니다. \n", user_card[0], user_card[1], user_card[2], user_card[3], user_card[4], user_card[5]);
        printf("  computer님의 카드는 %d %d %d %d %d %d 입니다. \n", computer_card[0], computer_card[1], computer_card[2], computer_card[3], computer_card[4], computer_card[5]);
        printf("  카드를 선택해 주세요. >>");
        scanf("  %d %d %d", &input1, &input2, &input3);

        user = input1 + input2 + input3;
        for (i = 0; i < 4; i++) {
            computer_result = 0;
            for (j = 0; j < 3; j++) {
                computer_result += computer_card[i+j];
            }
            if (computer_result <= 21) {
                computer = computer_result;

                if (computer < computer_max) {
                    computer = computer_max;

                }
                if(computer_max < computer) {
                    computer_max = computer;
                }
            }

        }
        if (computer > 21) {
            printf("computer 탈락입니다.\n");
        }
        else if (user > 21) {
            printf("user 탈락입니다.\n");
        }

        printf("  결과는 computer: %d, user: %d 입니다. ", computer, user);
        if (computer <= 21 && computer > user) {
            printf("computer가 이겼습니다.\n\n");
        }
        else if (user <= 21 && computer < user) {
            printf("user가 이겼습니다. 축하합니다.\n\n");
        }
        else if (computer == user) {
            printf("비겼습니다.\n\n");
        }

        return 0;
        }
