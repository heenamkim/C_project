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
    Bread *new = (Bread *)malloc(sizeof(Bread));

    printf("빵 이름: ");
    scanf("%s", name);
    printf("가격: ");
    scanf("%d", &pri);
    printf("유통기한: ");
    scanf("%d", &exp);
    printf("수량: ");
    scanf("%d", &q);
    strcpy(new->name, name);
    new->price = pri;
    new->expiration_date = exp;
    new->quantity = q;

    new->next = phead;
    phead = new;
    // free(new);
}

void Delete()
{
    printf("delete");
}
void Update()
{
    Bread *p = phead;
    char name[20];

    int num;
    char new_name[20];
    int new_price, new_quan, new_exp;

    printf("Bread name : ");
    scanf("%s", name);

    while (p != NULL){

        if (strcmp(name, p->name) == 0) {
            break;
        }
        else {
            p = p->next;
        }
    }

    if (p == NULL) {
        printf("찾는 이름이 없습니다.\n");
    } else {

        printf("변경할 변수를 고르세요.\n");
        printf("1. name\n");
        printf("2. price\n");
        printf("3. quantity\n");
        printf("4. expiration_date\n");
        scanf("%d", &num);
        if (num == 1) {
            printf("변경할 이름을 입력하세요.\n");
            scanf("%s", new_name);
            strcpy(p->name, new_name);
        }
        else if (num == 2) {
            printf("변경할 가격을 입력하세요.\n");
            scanf("%d", &new_price);
            p->price = new_price;
        }
        else if (num == 3) {
            printf("변경할 수량을 입력하세요.\n");
            scanf("%d", &new_quan);
            p->quantity = new_quan;
        }
        else {
            printf("변경할 유통기한을 입력하세요.\n");
            scanf("%d", &new_exp);
            p->expiration_date = new_exp;
        }
    }
}
void Retrieve()
{
    Bread *p = phead;
    char found_name[20];

    printf("찾으시는 빵이름을 입력해 주세요: ");
    scanf("%s", found_name);

    while (p != NULL) {

        if (strcmp(found_name, p->name) == 0) {
            printf("name: %s| price: %d| expiration_date: %d: quantity:%d\n", p->name, p->price, p->expiration_date, p->quantity);
            break;
        } else {
            p = p -> next;
        }
    }
    if (p == NULL) {
        printf("찾으시는 빵이 없습니다.\n");
    }
}
void Print()
{
    Bread *p = phead;
    int i = 1;

    printf("  Name   Price   Amount   exp\n");
    printf("______________________________________\n");

    while(p != NULL){

        printf("%d   %s   %d   %d   %d\n", i, p->name, p->price, p->quantity, p->expiration_date);
        i++;
        p = p->next;

    }
    printf("total = %d\n", i-1);
}
