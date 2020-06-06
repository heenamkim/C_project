#include "bakery.h"

int main()
{
    int menu = 1;
    phead = NULL;
    while(menu != 0){

        menu = displayMainMenu();
        switch (menu) {
            case INSERT:
                Insert();
                break;
            case DELETE:
                Delete();
                break;
            case UPDATE:
                Update();
                break;
            case RETRIEVE:
                Retrieve();
                break;
            case PRINT:
                Print();
                break;
            case EXIT:
                break;
            }
    }
    return 0;
}

int displayMainMenu()
{
    int menu;

    printf("\n  ==================\n");
    printf("  Management Profram\n");
    printf("  1. Insert\n");
    printf("  2. Delete\n");
    printf("  3. Update\n");
    printf("  4. Retrieve\n");
    printf("  5. Print\n");
    printf("  0. Exit\n");
    printf("  ___________________\n");
    printf("  INPUT >> ");
    scanf("%d", &menu);

    return menu;
}

void Insert()
{
    char name[20];
    int pri, exp, q;
    Bread *new = (Bread *)malloc(sizeof(Bread)); // bread구조체 new에 bread 크기만큼 할당

    printf("빵 이름: ");
    scanf("%s", name);
    printf("가격: ");
    scanf("%d", &pri);
    printf("유통기한: ");
    scanf("%d", &exp);
    printf("수량: ");
    scanf("%d", &q);
    strcpy(new->name, name); // new 가 가리키는 name에 name을 복사
    new->price = pri; // new가 가르키는 price pri
    new->expiration_date = exp; // new가 가르키는 expiration_date는 exp
    new->quantity = q; // new가 가르키는 quantity는 q

    new->next = phead; // new가 가르키는 next는 phead
    phead = new; // phead는 new
    // free(new);
}

void Delete()
{
    char del_name[20];
    Bread *p = phead;
    Bread *del = phead; // phead에 새로운 del 변수를 만듬

    printf("삭제할 빵 이름을 입력해 주세요 >> ");
    scanf("%s", del_name);

    while (p != NULL){

        if (strcmp(del_name, p->name) == 0) { // 입력 받은 값과  p가 가르키는 name 과 같으면
            break;
        }
        else { // 아니면
            del = p; //  del 은 p
            p = p->next; // p는 p가 가르키는 next
        }
    }
    if (p == NULL) {
        printf("삭제하려는 이름이 존재하지 않습니다.\n");
    }
    else {
        if (del == phead){ // 만약 del과 phead와 같으면
            phead = p->next; // phead는 p가 가르키는 next
        }
        else { // 다르면
            del->next = p->next; //del이 가르키는 next값에 p가 가르키는 next값을 넣음
        }
        printf("삭제되었습니다.\n");
        free(p);
    }
}
void Update()
{
    Bread *p = phead; //bread구조체 p는 phead
    char name[20];

    int num;
    char new_name[20];
    int new_price, new_quan, new_exp;

    printf("Bread name : ");
    scanf("%s", name);

    while (p != NULL){ // p가 null이 아닐때까지 반복

        if (strcmp(name, p->name) == 0) { // 입력받은 name과 p가 가리키는 name이 같으면
            break; // while문 빠져 나오기
        }
        else { //다르면
            p = p->next; // p는 p가 가르키는 next를 가르킴
        }
    }

    if (p == NULL) {
        printf("찾는 이름이 없습니다.\n");
    }
    else {

        printf("변경할 변수를 고르세요.\n");
        printf("1. name\n");
        printf("2. price\n");
        printf("3. quantity\n");
        printf("4. expiration_date\n");
        printf("number >> ");
        scanf("%d", &num);
        if (num == 1) {
            printf("변경할 이름을 입력하세요.>> ");
            scanf("%s", new_name);
            strcpy(p->name, new_name); // p가 가르키는 name에 입력받은 new_name을 복사
        }
        else if (num == 2) {
            printf("변경할 가격을 입력하세요.>> ");
            scanf("%d", &new_price);
            p->price = new_price; // p가 가르키는 price는 입력받은 new_price
        }
        else if (num == 3) {
            printf("변경할 수량을 입력하세요.>> ");
            scanf("%d", &new_quan);
            p->quantity = new_quan; // p가 가르키는 quantity는 입력받은 new_quan
        }
        else {
            printf("변경할 유통기한을 입력하세요.>> ");
            scanf("%d", &new_exp);
            p->expiration_date = new_exp; // p가 가르키는 expiration_date는 new_exp
        }
    }
}
void Retrieve()
{
    Bread *p = phead; //bread구조체 p는 phead
    char found_name[20];

    printf("찾으시는 빵이름을 입력해 주세요: ");
    scanf("%s", found_name);

    while (p != NULL) {

        if (strcmp(found_name, p->name) == 0) { // 입력받은 found_name과 p가 가르키는 name이 같으면
            printf("name: %s| price: %d| expiration_date: %d: quantity:%d\n", p->name, p->price, p->expiration_date, p->quantity);
            break;
        } else { // 다르면
            p = p -> next; // p는 p가 가르키는 next
        }
    }
    if (p == NULL) {
        printf("찾으시는 빵이 없습니다.\n");
    }
}
void Print()
{
    Bread *p = phead; // bread구조체 p는 phead
    int i = 1;

    printf("     Name   Price   Amount   exp\n");
    printf("__________________________________\n");

    while(p != NULL){

        printf("%d  %s    %d    %d     %d\n", i, p->name, p->price, p->quantity, p->expiration_date);
        i++;
        p = p->next;

    }
    printf("total = %d\n", i-1);
}
