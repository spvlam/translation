#include<stdio.h>
#include<stdlib.h>
#include<string.h>
// use array to perform stack
int arr[100]; int n;
int exc[100];
// int initilizeStack(){
//   scanf("%d",&n);
//   for (int i=0;i<n;i++){
//     scanf("%c",&arr[i]);
//   }
  
// }
void push(int s){
    arr[n]=s;
    n=n+1;
}
int pop(){
    n=n-1;
    return arr[n];
}
int isEmpty(){
    // return 1 if the statement is true
    return n==0;
}
int top(){
    if(isEmpty()){
        return 0;
    }else{
        return arr[n-1];
    }
}

int check(char s){
    if((top()=='(' && s==')')|| (top()=='[' && s==']') || (top()=='{' && s=='}')) return 1;
    return 0;
}
int printStack(){
    for(int i=n-1;i>=0;i--){
        printf("%d",arr[i]);
    }
}
int main(){
    // matching parenthesis problem
    // char s[100];
    // scanf("%s",s);
    // int i=0;
    // n=0;
    // initilizeStack();
    // while (i!=strlen(s))
    // {
    //     printf("%c",s[i]);
    //     if(check(s[i])){
    //         pop();
    //     }else{
    //      push(s[i]);
    //     }
    //     i++;
    // }
    // if(isEmpty()){
    //     printf("correct");
    // }else{
    //     printf("incorrect");
    // }

    // exchange coeeficient problem
   int n=0;
   int m=3553;
   int b=8;
   while (m!=0)
   {
     push(m%b);
     m=m/b;
   }
   printStack();
   
    
}