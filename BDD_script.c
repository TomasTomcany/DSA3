#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>



typedef struct BF{
    char *foo;                    // string representation of boolean vector
    unsigned int bool_var_count;  // number of boolean variables for function
}BF;

typedef struct BDD{
    BF* bool;
    struct BDD *false;
    struct BDD *true;
    int depth;                   // depth for knowing which bool variable this node describes
}BDD;

BF *BF_create(char *bf){
    BF* bool = (BF*)malloc(sizeof(BF));
    bool->foo = (char*)malloc(strlen(bf)*sizeof(char));
    bool->foo = bf;
    bool->bool_var_count = (unsigned int) log2((double) strlen(bool->foo));
    return bool;
}

BDD *BDD_create_node(char *bf, int depth){
    BDD* node = (BDD*) malloc(sizeof(BDD));
    node->bool = BF_create(bf);
    node->false = NULL;
    node->true = NULL;
    node->depth = depth;        // depth will not matter for leaf nodes, important for BDD_reduce
    return node;
}

void BDD_recursive_create(BDD* node, int depth){
    char* bfoo = node->bool->foo;

    // in case node is leaf, end recursion
    if (strlen(bfoo) == 1){
        return;
    }

    // splitting string for children
    unsigned int len = strlen(bfoo);
    unsigned int len_half = len/2;
    char *fst = (char*)malloc(len_half*sizeof (char));
    char *snd = (char*)malloc(len_half*sizeof (char));
    memcpy(fst, bfoo, len_half);
    memcpy(snd, bfoo+len_half, len_half);
    fst[len_half]='\0';
    snd[len_half]='\0';

    // creating and assigning new children nodes to parent
    node->false = BDD_create_node(fst, depth);
    node->true = BDD_create_node(snd, depth);

    // recursive call for children
    BDD_recursive_create(node->false, depth+1);
    BDD_recursive_create(node->true, depth+1);


}

BDD *BDD_create(BF *bfunkcia){
    BDD *root = BDD_create_node(bfunkcia->foo, 0);              // creating root

    // recursively create rest of tree
    BDD_recursive_create(root, 1);

    return root;
}



char BDD_use_recursive(BDD *bdd, char *vstupy, unsigned int vars, unsigned int root_count){
    char* foo = bdd->bool->foo;

    // check if root is leaf
    if (strlen(foo) == 1){
        return foo[0];
    }

    unsigned int index = root_count - bdd->false->bool->bool_var_count -1;

    // next index calculated from all variable count - variable count of child
    if (vstupy[index] == '0'){
        BDD_use_recursive(bdd->false, vstupy, vars, root_count);
    }
    else {
        BDD_use_recursive(bdd->true, vstupy, vars, root_count);
    }


}

char BDD_use(BDD *bdd, char *vstupy){
    // check if there is correct amount of boolean variables from input according to BDD
    unsigned int input_len = strlen(vstupy);
    if (input_len != bdd->bool->bool_var_count){
        return -1;
    }

    // for knowing how many bool variables there are throughout recursion
    unsigned int vars = bdd->bool->bool_var_count;

    char* foo = bdd->bool->foo;
    // check if root is leaf
    if (strlen(foo) == 1){
        return foo[0];
    }

    unsigned int root_count = bdd->bool->bool_var_count;
    unsigned int index = root_count - bdd->false->bool->bool_var_count -1;

    // else recursively move to false or true child based on boolean value of first variable
    if (vstupy[index] == '0'){
        BDD_use_recursive(bdd->false, vstupy, vars, root_count);
    }
    else {
        BDD_use_recursive(bdd->true, vstupy, vars, root_count);
    }
}



int reduce_leaf_nodes(BDD *bdd, BDD *false_node, BDD *true_node){
    if (strlen(bdd->false->bool->foo) == 1){        // if children are leaves
        // free children and point to unified leaves
        if ((char) bdd->false->bool->foo[0] == '0'){
            free(bdd->false);
            bdd->false = false_node;
        }
        else{
            free(bdd->false);
            bdd->false = true_node;
        }

        if ((char) bdd->true->bool->foo[0] == '0'){
            free(bdd->true);
            bdd->true = false_node;
        }
        else{
            free(bdd->true);
            bdd->true = true_node;
        }
        return 2;
    }

    // recursively move
    return reduce_leaf_nodes(bdd->false, false_node, true_node) +
           reduce_leaf_nodes(bdd->true, false_node, true_node);
}



int find_and_free_nodes(BDD *bdd, BDD *main_node,  BDD *false_node, BDD *true_node){
    // if node is leaf, return
    if (bdd == false_node || bdd == true_node){
        return 0;
    }

    // if we get to depth before the depth of a node we are trying to find and remove equal nodes,
    // check children and remove them and link to main_node if necessary
    if (bdd->depth == main_node->depth-1){
        int sum = 0;
        // if false child has the same value and is not main_node
        if (strcmp(bdd->false->bool->foo, main_node->bool->foo) == 0 && bdd->false != main_node){

            free(bdd->false->bool);
            free(bdd->false);
            bdd->false = main_node;
            sum++;
        }
        // if true child has the same value and is not main_node
        if (strcmp(bdd->true->bool->foo, main_node->bool->foo) == 0 && bdd->true != main_node){

            free(bdd->true->bool);
            free(bdd->true);
            bdd->true = main_node;
            sum++;
        }

        return sum;
    }

    return find_and_free_nodes(bdd->false, main_node, false_node, true_node)+
           find_and_free_nodes(bdd->true, main_node, false_node, true_node);
}

int remove_equal_nodes(BDD *bdd,  BDD *false_node, BDD *true_node, BDD *root){
    if (bdd == false_node || bdd == true_node){
        return 0;
    }

    // recursively move to bottom of tree first, then find and remove equal nodes
    return remove_equal_nodes(bdd->false, false_node, true_node, root) +
           remove_equal_nodes(bdd->true, false_node, true_node, root) +
           find_and_free_nodes(root, bdd, false_node, true_node);
}


int BDD_reduce(BDD *bdd){
    // joining leaf nodes
    BDD * false_node = BDD_create_node("0", -1);
    BDD * true_node = BDD_create_node("1", -1);
    int leaves = reduce_leaf_nodes(bdd, false_node, true_node) - 2;

    // removing nodes with equal values in same depth
    int equals = remove_equal_nodes(bdd, false_node, true_node, bdd);

    return leaves + equals;
}


void print_tree_recursive(BDD *root, int spaces)
{
    // base case
    if (root == NULL)
        return;

    spaces += 10;                                           // distance between depths

    print_tree_recursive(root->true, spaces);

    // printing current node
    for (int i = 10; i < spaces; i++)
        printf(" ");
    printf("%s\n", root->bool->foo);

    print_tree_recursive(root->false, spaces);
}

void print_tree(BDD *root)
{
    print_tree_recursive(root, 0);
}
