#ifndef DSA3_BDD_SCRIPT_H
#define DSA3_BDD_SCRIPT_H

typedef struct BF{
    char *foo;                    // string representation of boolean vector
    unsigned int bool_var_count;  // number of boolean variables for function (value only stored in root BF)
}BF;

typedef struct BDD{
    BF* bool;
    //int depth;                  // depth for knowing which bool variable this node describes
    struct BDD *false;
    struct BDD *true;
    int depth;
}BDD;

BF *BF_create(char *bf);
BDD *BDD_create_node(char *bf, int depth);
void BDD_recursive_create(BDD* node, int depth);
BDD *BDD_create(BF *bfunkcia);

char BDD_use_recursive(BDD *bdd, char *vstupy, unsigned int index, unsigned int vars);
char BDD_use(BDD *bdd, char *vstupy);

int reduce_leaf_nodes(BDD *bdd, BDD *false_node, BDD *true_node);
int remove_child(BDD *bdd, BDD *false_node, BDD *true_node);
int reduce_no_value_nodes(BDD *bdd,  BDD *false_node, BDD *true_node);
int find_and_free_nodes(BDD *bdd, BDD *main_node,  BDD *false_node, BDD *true_node);
int remove_equal_nodes(BDD *bdd,  BDD *false_node, BDD *true_node, BDD *root);
int BDD_reduce(BDD *bdd);

void print_tree_recursive(BDD *root, int spaces);
void print_tree(BDD *root);

void free_BDD(BDD *bdd);
#endif //DSA3_BDD_SCRIPT_H
