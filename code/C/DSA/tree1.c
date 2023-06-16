#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>
typedef struct Node
{
    int id;
    struct Node *left;
    struct Node *right;
}Node;

Node *root;

int printTree(Node *r){
    if(r==NULL) return 0;
    printf("%d",r->id);
    if(r->left==NULL) printf("-1");
    else{printf("%d",r->left->id);}
    if(r->right==NULL) printf("-1");
    else{printf("%d",r->right->id);};
    printf("\n");
    printTree(r->left);
    printTree(r->right);
}

Node* makeNode(int id){
    Node *p = (Node*)malloc(sizeof(Node));
    p->id = id ;
    p->left = NULL;
    p->right =NULL;
    return p;
}

Node *find(Node *ro , int id ){
    if(ro == NULL) return NULL;
    if(ro->id == id ) return ro;
    Node *p = find(ro->left,id);
    if(p!=NULL) return p;
    return find(ro->right,id);
}

int addLeftChild(int u, int left){
    Node *pu = find(root,u);
    if(pu == NULL){
       return 0;
    }else{
        if(pu->left==NULL){
            Node *newNode = makeNode(left);
            pu->left= newNode;
        }
    }
}

int addRightChild(int u, int right){
    Node *pu = find(root,u);
    if(pu == NULL){
        return 0;
    }else{
        if(pu->right==NULL){
            Node *newNode = makeNode(right);
            pu->right= newNode;
        }
    }
}

int countNode(Node *ro){
    if(ro==NULL) return 0;
    return 1 + countNode(ro->left) + countNode(ro->right);
}
int max(int a, int b){
    return a>b ? a:b ;
}
int height(Node *ro){
    if(ro==NULL){
        return -1;
    }
    return max(height(ro->left),height(ro->right))+1;
}
int balence(Node *ro){
    int leftH = height(ro->left);
    int rightH = height(ro->right);
    if(leftH-rightH > 1 || leftH -rightH < -1) return 0;
    return 1;
}
int banceLeft(Node *ro){
    if(balence(ro)==0) return 0;
    if(ro->left ==NULL) return 1;
    return banceLeft(ro->left);
}
int banceRight(Node *ro){
    if(balence(ro)==0) return 0;
    if(ro->right ==NULL) return 1;
    return banceRight(ro->right);
}

int main(){
    char cmd[100];
    do{
         scanf("%s",cmd);
         if(!strcmp(cmd,"MakeRoot")){
            int a;
            scanf("%d",&a);
            root = makeNode(a);
         }else if(!strcmp(cmd,"AddLeft")){
            int u,v;
            scanf("%d%d",&u,&v);
            addLeftChild(v,u);
         }else if(!strcmp(cmd,"AddRight")){
            int u,v;
            scanf("%d%d",&u,&v);
            addRightChild(v,u);
         }
    }while(strcmp(cmd,"*"));

    if(banceLeft(root) == banceLeft(root) && banceLeft(root) ==1 ){
        printf("1 ");
    }else{
        printf("0 ");
    }
    // root = makeNode(1);
    // addLeftChild(1,2);
    // addRightChild(1,3);
    // addLeftChild(3,4);
    // printf("%d",height(root)+1);
    printf("%d",countNode(root));
    
}