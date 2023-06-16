#include <stdio.h>
#include <stdlib.h>

typedef struct component
{
    int exp;
    int coeff;
} component;

typedef struct poly
{
    int id;
    struct poly *next;
    component arr[100];
    int size;
} poly;
int exppp(int base, int exp)
{
    int a = 1;
    for (int i = 0; i < exp; i++)
    {
        a = a * base;
    }
    return a;
}
component makeComponent(int cof, int exp)
{
    component newa;
    newa.coeff = cof;
    newa.exp = exp;
    return newa;
}
poly *start, *last;

int isEmpty()
{
    return start == NULL;
}

poly *checkPolyId(int id)
{
    if (isEmpty())
        return NULL;
    poly *cur = start;
    while (cur != NULL)
    {
        if (cur->id == id)
            return cur;
        cur = cur->next;
    }
    return NULL;
}
poly *makePoly(int id)
{
    poly *newPo = (poly *)malloc(sizeof(poly));
    newPo->id = id;
    newPo->size = 0;
    return newPo;
}
poly *create(int id)
{
    if (checkPolyId(id) == NULL)
    {
        if (isEmpty())
        {
            last = start = makePoly(id);
        }
        else
        {
            poly *newPo = makePoly(id);
            last->next = newPo;
            last = newPo;
        }
        return last;
    }
}
int addTerm(int id, int val, int exp)
{
    poly *a = checkPolyId(id);
    if (a == NULL)
    {
        a = create(id);
        a->arr[a->size] = makeComponent(val, exp);
        a->size = a->size + 1;
    }
    else
    {
        for (int i = 0; i < a->size; i++)
        {
            if (a->arr[i].exp == exp)
            {
                a->arr[i].coeff += val;
                return 0;
            }
        }
        a->arr[a->size] = makeComponent(val, exp);
        a->size = a->size + 1;
    }
}
void printPoly(int id)
{
    poly *a = checkPolyId(id);
    if (a != NULL)
    {
        for (int i = 0; i < a->size; i++)
        {
            printf("%d %d ", a->arr[i].coeff, a->arr[i].exp);
        }
    }
}
void evaluatePoly(int id, int vari)
{
    poly *a = checkPolyId(id);
    int sum = 0;
    if (a != NULL)
    {

        for (int i = 0; i < a->size; i++)
        {

            sum += a->arr[i].coeff * exppp(vari, a->arr[i].exp);
        }
    }
    printf("%d", sum);
}

node* addPoly(int id1 , int id2 , int id3){
    node *poly1 = checkPolyId(id1);
}

int main()
{
    start = last = NULL;
    addTerm(1, 2, 3);
    evaluatePoly(1, 2);
    // addTerm(2,2,3);
    // addTerm(1,22,3);
    // addTerm(1,22,2);
    // printPoly(1);
}