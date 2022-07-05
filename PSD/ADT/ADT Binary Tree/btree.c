#include <stdio.h>
#include <stdlib.h>

#include <item.h>
#include <btree.h>

struct node
{
    Item value;
    struct node *left;
    struct node *right;
};

Item getItem(struct node *Node);
void setItem(struct node *Node,Item elem);

Item getItem(struct node *Node)
{
    return Node->value;
}

void setItem(struct node *Node,Item elem)
{
    Node->value = elem;
}

Btree newTree(void)
{
    return NULL;
}

int emptyTree(Btree tree)
{
    return (tree==NULL);
}

int contains(Btree tree,Item val)
{
    if(tree == NULL) return 0;
    if(items_equals(getItem(tree),val)) return 1;
    if(val < getItem(tree)) return contains(figlioSX(tree),val);
    else return contains(figlioDX(tree),val);
}

Btree creaFoglia(Item elem)
{
    struct node *Node;
    Node = malloc(sizeof(struct node));
    if(Node == NULL) return NULL;
    setItem(Node,elem);
    Node->left = NULL;
    Node->right = NULL;
    return Node;
}

void insertTree(Btree *tree,Item elem)
{
    if(*tree == NULL) *tree=creaFoglia(elem);
    else
    {
        if(elem < getItem(*tree)) insert(&((*tree)->left),elem);
        else insert(&((*tree)->right),elem);
    }
}

struct node* minValue(struct node* node)
{
    struct node* current = node;
    while(current->left != NULL)
    {
        current = current->left;
    }
    return current;
}

struct node* deleteTree(struct node* root,Item key)
{
    if(root == NULL) return root;
    
    if (key < root->value)
    {
        root->left = deleteTree(root->left,key);
    }
    else if(key > root->value)
    {
        root->right = deleteTree(root->right,key);
    }
    else
    {
        if(root->left == NULL)
        {
            struct node *temp = root->right;
            free(root);
            return temp;
        }
        else if(root->right == NULL)
        {
            struct node *temp = root->left;
            free(root);
            return temp;
        }
        struct node* temp = minValue(root->right);
        root->value = temp->value;
        root->right = deleteTree(root->right,temp->value);
    }
    return root;
    
}