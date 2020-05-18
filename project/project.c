#include "bakery.h"

int main()
{
    int menu = 1;

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
    printf("insert");
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
    printf("print");
}
