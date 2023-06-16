#include<stdio.h>
#include<stdlib.h>
void swap(int *p, int *a){
    int *ex;
    ex = (int *)malloc(sizeof(int));
    ex=p;
    p=a;
    a=ex;
}
int partition(int a[], int p, int r){
    // can choose random p and r
    int x = a[r];
    int i=p-1;
    for(int j=p;j<r;j++){
        swap(&a[i],&a[j]);
        i++;
    }
    swap(&a[r],&a[i+1]);
    return i+1;

}
void quickSort(int a[],int p,int r){
    if (p<r){
        int q = partition(a,p,r);
        quickSort(a,q,p-1);
        quickSort(a,q+1,r); 
    }
}
int main(){
    int a[8]={2,8,7,1,3,5,6,4};
    // choose randomly r = 7
    int b=3,c=5;
    swap(&b,&c);
    printf("%d-%d",b,c);

}