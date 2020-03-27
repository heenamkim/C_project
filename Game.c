#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define DICE_SIMULATION 1
#define GAME_SHOW       2
#define HIGH_LOW_GAME   3
#define WORD_GAME       4
#define ABOUT           5
#define EXIT            0
#define NUM_OF_SIMULATION 10000

int displayMainMenu();
void diceSimulation();
void gameShow();
void highLowGame();
void wordGame();
void about();

int main()
{
    int menu=1;
    while(menu!=0) {

        menu = displayMainMenu();
        switch(menu) {
            case DICE_SIMULATION:
                diceSimulation();
                break;
            case GAME_SHOW:
                gameShow();
                break;
            case HIGH_LOW_GAME:
                highLowGame();
                break;
            case WORD_GAME:
                wordGame();
                break;
            case ABOUT:
                about();
                break;
            case EXIT:
                break;
            default:
                printf("올바르지 않은 입력입니다\n");
        } // switch
    } //wile
} // main

int displayMainMenu()
{
    int menu;

    printf("===================\n");
    printf("GAME MENU\n");
    printf("___________________\n");
    printf("1.Dice Simulation\n");
    printf("2.Game show\n");
    printf("3.High Low Game\n");
    printf("4.Word Game\n");
    printf("5.About\n");
    printf("___________________\n");
    printf("0.Exit\n");
    printf("===================\n");
    printf("Game Menu Number>>");
    scanf("%d",&menu);
    printf("===================\n");

    return menu;
}

void diceSimulation() {

    int total=0;
    int count=0;
    int num;

    srand(time(0));
    for (int i = 0; i < NUM_OF_SIMULATION; i++){
        total = 0;
        while (total < 100) {
            num = (rand() % 6)+1;
            total += num;
            count++;
        }
    }
    printf("avg = %.2lf\n", (double)count/NUM_OF_SIMULATION);
}

void gameShow() {
    int total=0;
    int count=0;
    int my_door, prize_door, another_door, new_door;

    srand(time(0));
    for (int i = 0; i < NUM_OF_SIMULATION; i++){
        prize_door = rand() % 3;
        my_door = rand() % 3;
        if (prize_door == my_door)
            count++;
    }
    printf("%.2lf%%\n",(double)count/NUM_OF_SIMULATION*100);
    count = 0;
    for (int i = 0; i < NUM_OF_SIMULATION; i++){
        prize_door = rand() % 3;
        my_door = rand() % 3;
        while (1) {
            another_door = rand() % 3;
            new_door = rand() % 3;
            if (prize_door != another_door && my_door != another_door){
                if (my_door != new_door && another_door != new_door)
                    break;
            }
        }
        if (prize_door == new_door)
            count++;
    }
    printf("%.2lf%%\n", (double)count/NUM_OF_SIMULATION*100);
}

void highLowGame() {
    int ran,num;
    srand(time(0));
    ran = rand() % 100;
    printf("High Low Game Start!\n");
    printf("___________________\n");
        while (1){
            printf("Num >>");
            scanf("%d",&num);
            if (ran > num)
                printf("High!\n");
            else if (ran < num)
                printf("Low..\n");
            else if (ran == num){
                printf("That's Right!\n");
                break;
            }
        }
}

void wordGame() {
    printf("4.Word Game\n");
}

void about() {
    printf("Sujong university\n");
    printf("somputher Engineering\n");
    printf("Created by heenam.k on 2020\n");
    printf("copyright(c) 2020y heenam.k\n");
}
