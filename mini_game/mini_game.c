#include <stdio.h>
#include <stdlib.h>

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
    printf("       MiNI GAME\n");
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
        printf("  MemoryGame()\n");
    }

    void ThirtyOneGame()
    {
        printf("  ThirtyOneGame\n");
    }
    void FoolGugudanGame()
    {
        printf("  FoolGugudanGame\n");
    }
