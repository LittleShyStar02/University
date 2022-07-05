#include <item.h>

typedef struct node *Btree;

Btree newTree(void);
int emptyTree(Btree tree);
int contains(Btree tree,Item val);
void insertTree(Btree *tree,Item elem);
struct node* deleteTree(struct node* root,Item key);