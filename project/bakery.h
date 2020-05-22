#include <stdio.h>
#include <string.h>

#define INSERT   1
#define DELETE   2
#define UPDATE   3
#define RETRIEVE 4
#define PRINT    5
#define EXIT     0

struct Bread{
    char name[20]; // 이름
    int price; //가격
    int quantity; // 수량
    int expiation_date;// 유통기한
};


void sizeExpansion(struct bread)
{
    plen *= 2; // 배열 길이를 2배로 늘려라
    p = (int *)malloc(p, sizeof(struct Bread)*plen); // p에 늘린값 저장
}

void sizeReduction(struct bread)
{
    plen /= 2; // 배열 길이를 반으로 줄여라
    p = (int *)malloc(p, sizeof(struct Bread)*plen); // p에 줄인값 저장
}

int main()
{
    int plen=10; //초기 배열 길이
    int idx = 0; // 배열 인덱스
    struct Bread *p
    p = (int *)malloc(sizeof(struct Bread)*plen); // struct Bread를 plen길이 만큼 할당

    while(1)
    {
        scanf("%d", &plen[idx]);
        if (p[idx]==-1)
        break;

        if (plen == inx+1){ // 배열의 길이를 초과하면 sizeExpansion() 함수 호출
            sizeExpansion();
        }
        if (plen < (inx/3)){ // 배열의 길이가 1/3이하면 sizeReduction() 함수 호출
            sizeReduction();
        }
        idx++;
    }
    free(p); // p가 가르키는 메모리 공간 해제
    return 0;
}

int displayMainMenu();
void Insert();
void Delete();
void Update();
void Retrieve();
void Print();
