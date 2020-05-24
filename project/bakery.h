#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define INSERT   1
#define DELETE   2
#define UPDATE   3
#define RETRIEVE 4
#define PRINT    5
#define EXIT     0

typedef struct bread {
    char name[20]; // 이름
    int price; //가격
    int quantity; // 수량
    int expiration_date;// 유통기한
    struct bread *next; // 자기참조 구조체 (리스트형태를 사용할때 필요)
}Bread;

Bread *phead;

int displayMainMenu();
void Insert();
void Delete();
void Update();
void Retrieve();
void Print();
