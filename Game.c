#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define DICE_SIMULATION 1
#define GAME_SHOW       2
#define HIGH_LOW_GAME   3
#define WORD_GAME       4
#define ABOUT           5
#define EXIT            0
#define NUM_OF_SIMULATION 10000
//difine 이용해서 치환
int displayMainMenu();
void diceSimulation();
void gameShow();
void highLowGame();
void wordGame();
void about();
// 사용할 함수 만들어 주기
int main()
{
    int menu=1;
    while(menu!=0) {

        menu = displayMainMenu();
        switch(menu) { //switch문은  if문보다 빠름 if == 과 같은 의미
            case DICE_SIMULATION:
                diceSimulation();
                break; // switch case문을 쓸때는 break를 해줘야 함 아니면 입력받은 것 아래에 있는 것들도 실행
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
                printf("  올바르지 않은 입력입니다\n");
        } // switch
    } //wile
} // main

int displayMainMenu() //메인 함수
{
    int menu; //선택 할수 있는 메뉴를 보여줌

    printf("  ===================\n");
    printf("  GAME MENU\n");
    printf("  ___________________\n");
    printf("  1.Dice Simulation\n");
    printf("  2.Game show\n");
    printf("  3.High Low Game\n");
    printf("  4.Word Game\n");
    printf("  5.About\n");
    printf("  ___________________\n");
    printf("  0.Exit\n");
    printf("  ===================\n");
    printf("  Game Menu Number>>");
    scanf("  %d",&menu); //실행할 메뉴 선택
    printf("  ===================\n");

    return menu; //메뉴값 리턴 받기
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
    printf("  avg = %.2lf\n", (double)count/NUM_OF_SIMULATION);
}

void gameShow() { //확률을 보여주는 함수
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
    printf("  %.2lf%%\n",(double)count/NUM_OF_SIMULATION*100); //변수 하나만 실수로 바꿔 줘도 실수로 출력가능
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
    printf("  %.2lf%%\n", (double)count/NUM_OF_SIMULATION*100);
}

void highLowGame() {
    int ran,num;
    srand(time(0));
    ran = rand() % 100;
    printf("  High Low Game Start!\n");
    printf("  ___________________\n");
        while (1){
            printf("  Num >>");
            scanf("%d",&num);
            if (ran > num)
                printf("  High!\n");
            else if (ran < num)
                printf("  Low..\n");
            else if (ran == num){
                printf("  That's Right!\n");
                break;
            }
        }
}

void wordGame()
{
    char strWords[10][80] = { "university",
                                "school",
                                "mosquito",
                                "computer",
                                "rainbow",
                                "department",
                                "student",
                                "professor",
                                "blackboard",
                                "sunshine"
    };

    char strWordsmeans[10][80] = { "종합대학교",
                                   "학교",
                                   "모기",
                                   "컴퓨터",
                                   "무지개",
                                   "부서,학과",
                                   "학생",
                                   "교수",
                                   "칠판",
                                   "햇빛"
    };

    char alp[26];
    char word[80];
    int num;
    int length, count=0;
    char input;

    srand(time(0));
    num = rand() % 10;
    length = strlen(strWords[num]); // strlen함수(문자열 길이 구하는 함 )는 변수로 두고 사용하는게 좋음!
    for (int i = 0; i < length; i++){
        word[i] = '_';
    }
    word[length] = '\0';
    // word는 length의 길이만큼 _를 넣은 문자 배열 임
    // 따라서 문자열 배열로 만들어 주기 위해 length에 '\0'를 넣어 만들어줌

    for (int j = 0; j < 26; j++){
        alp[j] = 'a'+j;
    }
    while(1) {
        if (strcmp(strWords[num], word) == 0)
        // strcmp함수는 괄호 안에 있는 두 문자열배열을 비교해줌
            break;
            printf("\n     ");
        for (int i = 0; i < length; i++){
            printf("%c ", word[i]);
        }
        printf("\n\n   ");
        for (int j = 0; j < 26; j++){
            printf("%c ", alp[j]);
            if (j == 12)
                printf("\n     ");
        } //for j
        fflush(stdin);
        printf("\n\nalp input >> ");
        scanf("%c", &input);
        count++;

        for (int k = 0; k < length; k++){
            if (input == strWords[num][k])
            // input으로 받은 값과 strWords[랜덤으로 받은 단어][그 단어의 알파벳]이 같으면
                word[k] = input;
        }
        for (int k = 0; k < 26; k++){
            if (input == alp[k])
                alp[k] = '/';
        }

    } //while
    printf("count = %d\n\n",count);
    printf("word : %s, means : %s\n\n",strWords[num],strWordsmeans[num]);



}

void about() {
    printf("  Sujong university\n");
    printf("  somputher Engineering\n");
    printf("  Created by heenam.k on 2020\n");
    printf("  copyright(c) 2020y heenam.k\n");
}
