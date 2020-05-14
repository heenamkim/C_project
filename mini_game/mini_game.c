#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define MEMORY_GAME       1
#define THIRTYONE_GAME    2
#define FOOL_GUGUDAN_GAME 3
#define EXIT              0

int MainMenu();
void MemoryGame();
void ThirtyOneGame();
void FoolGugudanGame();

int main()
{
    int menu=1;
    while(menu!=0) {

        menu = MainMenu();
        switch(menu) {
            case MEMORY_GAME:
                MemoryGame();
                break;
            case THIRTYONE_GAME:
                ThirtyOneGame();
                break;
            case FOOL_GUGUDAN_GAME:
                FoolGugudanGame();
                break;
            case EXIT:
                break;
            default:
                printf("  Please re-enter.\n");
        }
    }
}

int MainMenu()
{
    int menu;

    printf("  ======================\n");
    printf("       MINI GAME\n");
    printf("  ______________________\n");
    printf("  1. MEMORY_GAME\n");
    printf("  2. THIRTYONE_GAME\n");
    printf("  3. FOOL_GUGUDAN_GAME\n");
    printf("  0. EXIT\n");
    printf("  ______________________\n");
    printf("");
    printf("  INPUT >> ");
    scanf("%d", &menu);
    printf("  ======================\n");
    printf("");

    return menu;
}

    void MemoryGame()
    {
        char subject[20];
        char word[10];
        char words[20][10];
        int count = 0;

        printf("  Game Start!!\n\n");
        printf("  SUBJECT : FRUIT, VEGETABLE, FISH, HOUSE, ANIMAL\n");
        printf("  SUBJECT >> ");
        scanf("%s", subject);

        while(1){
            for (int j = 1; j < 20; j++){
                if (j % 2 == 1){
                    printf("  \nPlayer1");
                }
                else {
                    printf("  \nPlayer2");
                }
                printf("\n  When you go to the %s~\n", subject);
                for (int i = 0; i < j; i++){
                    printf("  INPUT%d/%d >> ", j, i+1);
                    scanf("%s", word);
                    strcpy(words[j-1], word);
                    if (j > 1){
                        if (strcmp(word, words[i]) != 0){
                            printf("  You Lose~\n");
                            count = 1;
                            break;
                        }
                    }
                }
            }
        }
    }

    void ThirtyOneGame()
    {
        int player_num;
        printf("  Game Start!!\n\n");
        printf("  How many people?? ");
        scanf("%d", &player_num);
        int player[player_num];
        int number[31];
        int many , count = 1, count2 = 0;

        for (int i = 0; i < 31; i++){
            number[i] = i+1;
        }
        printf("  \nBaskin Rabbins ThirtyOne~\n\n");
        while(1){

            for(int i = 0; i < player_num; i++){

                printf("  \nplayer%d How many nambers? >> ", i+1);
                scanf("%d", &many);

                if (many > 3) {
                    printf("\n  Too much\n");
                    i--;
                }

                else {
                    printf("  ");
                    for (int j = 0; j < many; j++){
                        if (count >= 32){
                            printf("\n  player%d Lose~~\n\n", i+1);
                            count2 = 1;
                            break;
                        }
                        printf("%d ", count);
                        count++;
                    }
                    printf("\n");
                }
            }
            if (count2 == 1){
                break;
            }
        }
    }
    void FoolGugudanGame()
    {
        int a, b;
        int total, num;
        int check;

        printf("  Game Start!!\n\n");

        printf("  Player1 Input Number >> ");
        scanf("%d %d", &a, &b);
        for (int i = 0; i <= 20; i++){
            if (i == 20){
                printf("  Draw~\n");
                break;
            }
            total = 0;

            num = a * b;
            if (num >= 10){
                total += num / 10;
                total += (num % 10) * 10;
            }
            else{
                total = num;
            }

            if (i % 2 == 1) {
                printf("\n  Player1 Answer >> ");
                scanf("%d", &check);
            }
            else {
                printf("\n  Player2 Answer >> ");
                scanf("%d", &check);
            }
                if(total != check){
                    printf("  You Lose~\n\n");
                    break;
                }
                printf("        Input Number >> ");
                scanf("%d %d", &a, &b);
        }
    }
