
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
    struct Bread *p;
    p = (int *)malloc(sizeof(struct Bread)*plen); // struct Bread를 plen길이 만큼 할당

    while(1)
    {
        scanf("%d", &p.price);

        if (plen == idx-1){ // 배열의 길이를 초과하면 sizeExpansion() 함수 호출
            sizeExpansion();
        }
        if (plen < (idx/3)){ // 배열의 길이가 1/3이하면 sizeReduction() 함수 호출
            sizeReduction();
        }
        idx++;
    }
    free(p); // p가 가르키는 메모리 공간 해제
    return 0;
}
