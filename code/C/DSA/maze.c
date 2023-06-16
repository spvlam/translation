#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    int r, c;
    int step;
    struct node *parent;
    struct node *next;
} node;

node *start, *last;
node *finalNode;
node *listNode[100000];
int sizeofnode = 0;
int arr[1000][1000];
int row, col;
int stepNext[4] = {1, -1, 0, 0};
int stepNext2[4] = {0, 0, -1, 1};
int visitedArray[1000][1000]={0};

void input()
{
    start = (node *)malloc(sizeof(node));
    last = start;
    scanf("%d%d", &row, &col);
    scanf("%d%d", &start->r, &start->c);
    start->r = start->r-1 ;
    start->c = start->c-1;
    start->step = 1;
    for (int i = 0; i < row ; i++)
    {
        for (int j = 0; j < col ; j++)
        {
            scanf("%d", &arr[i][j]);
        }
    }
}

int target(node *cur)
{
    return cur->r == 0 || cur->r == row-1 || cur->c == 0 || cur->c == col-1;
}
int checkVisited(int r, int c)
{
    return visitedArray[r][c] == 0 && arr[r][c]==0; 
}

node *makenode(int co, int ro, int ste, node *cur)
{
    node *newnode = (node *)malloc(sizeof(node));
    newnode->c = co;
    newnode->r = ro;
    newnode->step = ste;
    newnode->parent = cur;
    newnode->next = NULL;
    return newnode;
}
void addToQueue(node *cur)
{
    for (int i = 0; i < 4; i++)
    {
        int newC = cur->c + stepNext[i];
        int newR = cur->r + stepNext2[i];
        int newStep = cur->step + 1;
        if (checkVisited(newR, newC))
        {
            node *newNode = makenode(newC, newR, newStep, cur);
            last->next = newNode;
            last = newNode;
        }
    }
}
int isEmpty()
{
    return start == NULL && last ==NULL;
}
node *pop()
{
    if (isEmpty())
    {
        return NULL;
    }
    node *getNode = start->next;
    if(getNode==NULL) last ==NULL;
    return getNode;
}

void finalize(){
    for(int i=0;i<sizeofnode;i++){
        free(listNode[i]);
    }
}

int main()
{
    //    initilize started node
    input();
    //  initilize queue
    while (start != NULL)
    {
        if (target(start))
        {
            finalNode = start;
            printf("%d", finalNode->step);
            break;
        }
        else
        {
            visitedArray[start->r][start->c] = 1;
            addToQueue(start);
            listNode[sizeofnode] = start;
            start = start->next;
            sizeofnode++;
        }
        // printf("\n%d",sizeofnode);
    }

      printf("%d",sizeofnode);
    finalize();

    if(finalNode==NULL){
        printf("-1");
    }
    return 0;
}