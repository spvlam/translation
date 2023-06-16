#include<stdio.h>
#include<string.h>
int n;
char m[5];
int arr[20];
int len[5];
int dem=0;
int le;
int checkarr(int start){
    for(int i=0;i<le;i++){
        if(arr[i+start]!=len[i]) return 0;
    }
    return 1;
}
int check(){
    for(int i=0;i<n+1-le;i++){
        if(checkarr(i)==1) return 0;
    }
    return 1;
}
void gen(int k){
    for(int i=0;i<2;i++){
        arr[k]=i;
        if(k==n-1){
            if(check()==1){
                dem+=1;
            }
        }else{
            gen(k+1);
        }
    }
}

int main(){
   scanf("%d%s",&n,m);
   le = strlen(m);
   for(int i=0;i<le;i++){
    len[i]=(int) m[i];
    len[i]=len[i]-48;
   }
   gen(0);
   printf("%d",dem);
}