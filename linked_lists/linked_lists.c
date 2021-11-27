// Implement a linked list structure of ordered integers.

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

void print_list(void);
void insert(int num);
void match(int num);
void order(void);
void delete_one(int num);
void delete_all(void);
int input(void);
void print_menu(void);

struct node
{
    int n;
    struct node *next;
};

struct node *head = NULL;
struct node *trv = NULL;

int main(void)
{
    while (1)
    {
        print_menu();
        int option;
        scanf("%d", &option);

        switch (option)
        {
            case 1: print_list();
                    break;
            case 2: match(input());
                    break;
            case 3: insert(input());
                    break;
            case 4: printf("NOT YET IMPLEMENTED!\n");
                    break;
            case 5: delete_one(input());
                    break;
            case 6: printf("NOT YET IMPLEMENTED!\n");
                    break;
            case 0: printf("Have a nice day!\n");
                    return 0;
            default: printf("Not a valid option.\n");
        }
    }

    return 0;
}

void print_list(void)
{
    trv = head;

    if (!trv)
    {
        printf("No list.\n");
    }

    while (trv)
    {
        printf("%d ", trv->n);
        trv = trv->next;
    }

    printf("\n");
}

void insert(int num)
{
    while (1)
    {
        if (num < 0) break;

        struct node *data = (struct node*) malloc(sizeof(struct node));

        data->n = num;
        data->next = head;
        head = data;

        num = input();
    }
}

void match(int num)
{
    trv = head;
    while (trv)
    {
        if (num < 0)
        {
            return;
        }
        else if (trv->n == num)
        {
            printf("%d is in the list.\n", num);
            return;
        }

        trv = trv->next;
    }

    printf("Could not find %d in linked list.\n", num);
}

void order(void)
{

}

void delete_one(int num)
{
    trv = head;
    while (trv)
    {
        if (trv->next->n == num)
        {
            struct node *tmp = trv->next;
            trv = trv->next = trv->next;
            free(tmp);
            break;
        }

        trv = trv->next;
    }
}

void delete_all(void)
{

}

int input(void)
{
    printf("Enter an integer (-1 to return to menu): ");

    int num;
    scanf("%d", &num);

    return num;
}

void print_menu(void)
{
    printf("\n");
    printf("-------MENU-------\n");
    printf("1 - Print\n");
    printf("2 - Match\n");
    printf("3 - Insert\n");
    printf("4 - Order\n");
    printf("5 - Delete One\n");
    printf("6 - Delete All\n");
    printf("7 - Repeat Options\n");
    printf("0 - Quit\n");
    printf("\n");
    printf("Enter an option: ");
}
