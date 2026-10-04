#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Debt
{
    int id;
    char creditor[30];
    float amount;
    float balance;
};

struct Node
{
    struct Debt data;
    struct Node *next;
};

struct Tree
{
    struct Debt data;
    struct Tree *left;
    struct Tree *right;
};

struct Payment
{
    int id;
    float amount;
    float oldBalance;
    struct Payment *next;
};

struct Node *head = NULL;
struct Tree *root = NULL;
struct Payment *top = NULL;

void addDebt()
{
    struct Node *newNode;
    newNode = (struct Node *)malloc(sizeof(struct Node));

    printf("\nEnter Debt ID: ");
    scanf("%d", &newNode->data.id);

    printf("Enter Creditor Name: ");
    scanf("%s", newNode->data.creditor);

    printf("Enter Debt Amount: ");
    scanf("%f", &newNode->data.amount);

    newNode->data.balance = newNode->data.amount;
    newNode->next = NULL;

    if (head == NULL)
    {
        head = newNode;
    }
    else
    {
        struct Node *temp = head;

        while (temp->next != NULL)
            temp = temp->next;

        temp->next = newNode;
    }

    printf("\nDebt added successfully!\n");
}

void displayDebts()
{
    struct Node *temp = head;

    if (head == NULL)
    {
        printf("\nNo debts available.\n");
        return;
    }

    printf("\n========== ALL DEBTS ==========\n");

    while (temp != NULL)
    {
        printf("\nID       : %d", temp->data.id);
        printf("\nCreditor : %s", temp->data.creditor);
        printf("\nAmount   : %.2f", temp->data.amount);
        printf("\nBalance  : %.2f\n", temp->data.balance);

        temp = temp->next;
    }
}

struct Tree *insertBST(struct Tree *root, struct Debt d)
{
    if (root == NULL)
    {
        struct Tree *newNode;
        newNode = (struct Tree *)malloc(sizeof(struct Tree));

        newNode->data = d;
        newNode->left = NULL;
        newNode->right = NULL;

        return newNode;
    }

    if (d.id < root->data.id)
        root->left = insertBST(root->left, d);
    else if (d.id > root->data.id)
        root->right = insertBST(root->right, d);

    return root;
}

struct Tree *searchBST(struct Tree *root, int id)
{
    if (root == NULL)
        return NULL;

    if (root->data.id == id)
        return root;

    if (id < root->data.id)
        return searchBST(root->left, id);

    return searchBST(root->right, id);
}

void createBST()
{
    struct Node *temp = head;

    root = NULL;

    while (temp != NULL)
    {
        root = insertBST(root, temp->data);
        temp = temp->next;
    }
}

void searchDebt()
{
    int id;
    struct Tree *result;

    printf("\nEnter Debt ID to search: ");
    scanf("%d", &id);

    result = searchBST(root, id);

    if (result == NULL)
    {
        printf("\nDebt not found!\n");
    }
    else
    {
        printf("\nDebt Found!\n");
        printf("ID       : %d\n", result->data.id);
        printf("Creditor : %s\n", result->data.creditor);
        printf("Amount   : %.2f\n", result->data.amount);
        printf("Balance  : %.2f\n", result->data.balance);
    }
}

void makePayment()
{
    int id;
    float amount;
    struct Node *temp = head;

    printf("\nEnter Debt ID: ");
    scanf("%d", &id);

    while (temp != NULL && temp->data.id != id)
        temp = temp->next;

    if (temp == NULL)
    {
        printf("\nDebt not found!\n");
        return;
    }

    printf("Current Balance: %.2f\n", temp->data.balance);

    printf("Enter Payment Amount: ");
    scanf("%f", &amount);

    if (amount > temp->data.balance)
    {
        printf("\nPayment is greater than balance!\n");
        return;
    }

    struct Payment *p;
    p = (struct Payment *)malloc(sizeof(struct Payment));

    p->id = id;
    p->amount = amount;
    p->oldBalance = temp->data.balance;
    p->next = top;
    top = p;

    temp->data.balance -= amount;

    printf("\nPayment successful!\n");
    printf("Remaining Balance: %.2f\n", temp->data.balance);
}

void undoPayment()
{
    struct Payment *p;
    struct Node *temp;

    if (top == NULL)
    {
        printf("\nNo payment to undo!\n");
        return;
    }

    p = top;
    temp = head;

    while (temp != NULL && temp->data.id != p->id)
        temp = temp->next;

    if (temp != NULL)
    {
        temp->data.balance = p->oldBalance;

        printf("\nLast payment undone!\n");
        printf("Restored Balance: %.2f\n", temp->data.balance);
    }

    top = top->next;
    free(p);
}

int main()
{
    int choice;

    while (1)
    {
        printf("\n\n================================");
        printf("\n        DEBT DESTROYER");
        printf("\n================================");
        printf("\n1. Add Debt");
        printf("\n2. Display Debts");
        printf("\n3. Search Debt");
        printf("\n4. Make Payment");
        printf("\n5. Undo Payment");
        printf("\n0. Exit");

        printf("\n\nEnter choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                addDebt();
                createBST();
                break;

            case 2:
                displayDebts();
                break;

            case 3:
                searchDebt();
                break;

            case 4:
                makePayment();
                createBST();
                break;

            case 5:
                undoPayment();
                createBST();
                break;

            case 0:
                printf("\nThank you for using Debt Destroyer!\n");
                return 0;

            default:
                printf("\nInvalid choice!\n");
        }
    }

    return 0;
}
