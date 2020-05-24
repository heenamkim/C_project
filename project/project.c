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
    printf("update");
}
void Retrieve()
{
    printf("retrieve");
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
