#include <stdio.h>
#include <string.h>
#include <stdlib.h>


void sizeExpansion()
{
    p = (int *)realloc(p, (2*p)*sizeof(int)); // p에 늘린값 저장
}

void sizeReduction()
{
    p = (int *)realloc(p, (2/p)*sizeof(int)); // p에 줄인값 저장
}

int main()
{
    int plen = 10; //초기 배열 길이
    int i = 0;
    struct Bread *p;
    p = (int *)malloc(plen*sizeof(int)); // struct Bread를 plen길이 만큼 할당

    while(1)
    {
        scanf("%d", &p[i]);

        if (p[i] == plen){ // 배열의 길이를 초과하면 sizeExpansion() 함수 호출
            sizeExpansion();
        }
        if (p[i] < (plen/3)){ // 배열의 길이가 1/3이하면 sizeReduction() 함수 호출
            sizeReduction();
        }
        i++;
    }
    free(p); // p가 가르키는 메모리 공간 해제
    return 0;
}
