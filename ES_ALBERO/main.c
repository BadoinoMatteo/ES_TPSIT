#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

struct albero{
    struct albero *left;
    struct albero *right;
    int key;
    int val;
};

void insert(struct albero **tree, struct albero *new);
void in_order_view(struct albero* tree);
struct albero * creaElemento(int key, int val);
struct albero* find_by_key(struct albero* albero, int key);

int main() {
    struct albero **albero ;
    int risp=0;
    int num=0;
    int key=0;
    int ricerca=0;
    do{
        printf("inserisci un numero\n");
        scanf("%d", &num );
        printf("inserisci la key\n");
        scanf("%d", &key);
        insert (albero , creaElemento(key, num) );
        printf("vuoi inserire un nuovo elemento?\n 1--> si 2--> no");
        scanf("%d", &risp);
    }while(risp==1);
    printf("inserisci la chiave da cercare\n");
    scanf("%d", &ricerca);
    if(find_by_key((struct albero *)albero,ricerca)==NULL)
        printf("elemento non trovato\n");
    else
        printf("elemento trovato\n");
    in_order_view((struct albero *) albero);
    return 0;
}

struct albero* creaElemento(int key, int val){
    struct albero* t;
    t=(struct albero *) malloc(sizeof(int) * val);
    t->key=key;
    t->val=val;
    t->right=t;
    t->left=NULL;
    return t;
}


void insert(struct albero **tree, struct albero *new) {
    if (*tree == NULL) {
        *tree = new;
        (*tree)->left = NULL;
        (*tree)->right = NULL;
    } else {
        if (new->key < (*tree)->key) {
            insert(&(*tree)->left, new);
        } else if (new->key > (*tree)->key)
            insert(&(*tree)->right, new);
        else
            printf("chiave duplicata\n");
    }
    return;
}

void in_order_view(struct albero* tree){
    if(tree!=NULL){
        in_order_view(tree->left);
        printf("key %d, value %d \n", tree->key, tree->val);
        in_order_view(tree->right);
    }
    return;
}

struct albero* find_by_key(struct albero* albero, int key){
    if(albero==NULL)
        return NULL;
    else{
        if(key<albero->key)
            return find_by_key(albero->left, key);
        else if (key>albero->key)
            return find_by_key(albero->right, key);
    }

    return albero;
}
