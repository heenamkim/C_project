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
    int subject;
    char word[20];
    char subjects[5][10] = {"FRUIT", "VEGETABLE", "FISH", "HOUSE", "ANIMAL"};
    char subject_words[5][20][20] = {{"apple", "pear", "cherry", "melon", "banana",
                        "peach", "grape", "orange", "mango","pineapple",
                        "plum", "coconut", "strawberry", "kiwi", "lemon",
                        "watermelon", "papaya", "lime", "durian", "papaya"},
                        {"aloe", "broccoli", "carrot", "celery", "corn",
                        "eggplant", "garlic", "ginger", "onion", "potato",
                        "avocado", "tomato", "pea", "pumpkin", "cucumber",
                        "cabbage", "pimento", "bean", "leek", "lettuce"},
                        {"crayfish", "mackerel", "oyster", "cod", "bream",
                        "anchovy", "octopus", "swellfish", "shark", "shrimp",
                        "salmon", "squid", "abalone", "clam", "herring",
                        "mussel", "flatfish", "eel", "angler", "carp"},
                        {"mirror", "lamp", "microwave", "table", "refrigerator",
                        "telephone", "computer", "television", "iron", "dest",
                        "printer", "calender", "chair", "bed", "clock",
                        "closet", "sofa", "carpet", "window", "book"},
                        {"dog", "cat", "crow", "frog", "spider",
                        "turtle", "goose", "whale", "gorilla", "hedgehog",
                        "bear", "cricket", "magpie", "giraffe", "butterfly",
                        "camel", "racoon", "wolf", "snail", "donkey"}};
    char words[10][20];
    int flag = 1;
    int count = 1;

    printf("  Game Start!!\n\n");
    printf("  SUBJECT : 1.FRUIT, 2.VEGETABLE, 3.FISH, 4.HOUSE, 5.ANIMAL\n");
    printf("  SUBJECT NUMBER >> ");
    scanf("%d", &subject);
    subject--;


    while(flag) {
        for (int j = 1; j <= 11; j++) {
            if (j % 2 == 1) {
                printf("  \nPlayer1");
            }
            else {
                printf("  \nPlayer2");
            }
            printf("\n  When you go to the %s~\n", subjects[subject]);
            for (int i = 0; i < j; i++) {
                if (i < j-1) {
                    printf("  INPUT%d/%d >> ", j-1, i+1);
                    scanf("%s", word);
                    if (strcmp(word, words[i]) == 0){
                        continue;
                    }
                    else {
                        printf("You Lose~\n");
                        flag = 0;
                        break;
                    }
                }
                else {
                    printf("  NEWINPUT >> ");
                    scanf("%s", word);
                    count = 1;
                    for (int k = 0; k < 20; k++) {
                        if (strcmp(word, subject_words[subject][k]) == 0) {
                            strcpy(words[j-1], word);
                            count = 0;
                        }
                    }
                    if (count == 1) {
                        printf("  Please re-enter.\n");
                        i--;
                    }
                }
            }
            if (!flag) {
                break;
            }
            if (j == 11) {
                printf("Draw~\n");
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
    int many , count = 1, flag = 1;

    for (int i = 0; i < 31; i++){
        number[i] = i+1;
    }
    printf("  \nBaskin Rabbins ThirtyOne~\n\n");
    while(flag) {

        for(int i = 0; i < player_num; i++) {

            printf("  \nplayer%d How many nambers? >> ", i+1);
            scanf("%d", &many);

            if (many > 3) {
                printf("\n  Too much\n");
                i--;
                continue;
            }
            else {
                printf("  ");
                for (int j = 0; j < many; j++) {
                    if (count >= 32) {
                        printf("\n  player%d Lose~~\n\n", i+1);
                        flag = 0;
                        break;
                    }
                    printf("%d ", count);
                    count++;
                } // for
                printf("\n");
            }
            if (!flag) {
                break;
            }
        } // for
    } // while
}

void FoolGugudanGame()
{
    int a, b;
    int total, num;
    int check;

    printf("  Game Start!!\n\n");

    printf("  1) Player1 Input Two Numbers >> ");
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
            printf("\n  %d) Player1 Answer >> ", i+2);
            scanf("%d", &check);
        }
        else {
            printf("\n  %d) Player2 Answer >> ", i+2);
            scanf("%d", &check);
        }
            if(total != check){
                printf("  You Lose~\n\n");
                break;
            }
            printf("        Input Two Numbers >> ");
            scanf("%d %d", &a, &b);
    }
}
