#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int r, c;
    int step;
    struct node *parent;
    struct node *next;
} node;

node *head, *tail;
int row, col;
int arr[1000][1000];
node *listnode[100000];
int visited[1000][1000];
int sizeofnode = 0;
int d1[4] = {1, -1, 0, 0};
int d2[4] = {0, 0, 1, -1};

void input()
{
    scanf("%d%d%d%d", &row, &col, &head->r, &head->c);
    head->step = 0;
    for (int i = 1; i <= row; i++)
    {
        for (int j = 1; j <= col; j++)
        {
            scanf("%d", &arr[i][j]);
            visited[i][j] = 0;
        }
    }
}

int empty()
{
    return head == NULL && tail == NULL;
}

void push(node *cur)
{
    if (empty())
    {
        head = tail = cur;
    }
    else
    {
        tail->next = cur;
        tail = cur;
    }
}

node *pop()
{
    if (empty())
        return NULL;
    node *cur = head;
    head = head->next;
    if (head == NULL)
        tail = NULL;
    return cur;
}

int target(node *cur)
{
    return cur->c < 1 || cur->c > col || cur->r < 1 || cur->r > row;
}

int checkLegal(int ro, int co)
{
    return (visited[ro][co] == 0 && arr[ro][co] == 0);
}

node *makeNode(int r, int c, int ste, node *cur)
{
    node *a;
    a = (node *)malloc(sizeof(node));
    a->c = c;
    a->r = r;
    a->step = ste;
    a->parent = cur;
    a->next = NULL;
    return a;
}

void addToQueue(node *cur)
{
    for (int i = 0; i < 4; i++)
    {
        int newC = cur->c + d1[i];
        int newR = cur->r + d2[i];
        if (checkLegal(newR, newC))
        {
            node *newnode = makeNode(newR, newC, cur->step + 1, cur);
            push(newnode);
            visited[newR][newC] = 1;  // Mark as visited after pushing to the queue
        }
    }
}

void finalize()
{
    for (int i = 0; i < sizeofnode; i++)
    {
        free(listnode[i]);
    }
}

int main()
{
    head = (node *)malloc(sizeof(node));
    node *final = NULL;
    input();
    tail = head;
    while (head != NULL)
    {
        visited[head->r][head->c] = 1;
        if (target(head))
        {
            final = head;
            break;
        }
        else
        {
            addToQueue(head);
            listnode[sizeofnode] = head;
            sizeofnode++;
            head = head->next;
        }
    }
    printf("%d\n", sizeofnode);
    finalize();
    if (final != NULL)
    {
        printf("%d\n", final->step);
    }
    return 0;
}
