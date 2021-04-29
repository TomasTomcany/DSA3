#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#include "BDD_script.h"

void debug_tester(){
    BDD *root = BDD_create(BF_create("01010111"));
    print_tree(root);

    int a = BDD_reduce(root);
    if (a != 8){
        printf("Incorrectly reduced tree, removed %d nodes, it should be 8.\n", a);
    }

    if (BDD_use(root, "000") == '1')
        printf("error, for A=0, B=0, C=0 it should be 0.\n");
    if (BDD_use(root, "001") == '0')
        printf("error, for A=0, B=0, C=1 it should be 1.\n");
    if (BDD_use(root, "010") == '1')
        printf("error, for A=0, B=1, C=0 it should be 0.\n");
    if (BDD_use(root, "011") == '0')
        printf("error, for A=0, B=1, C=1 it should be 1.\n");
    if (BDD_use(root, "100") == '1')
        printf("error, for A=1, B=0, C=0 it should be 0.\n");
    if (BDD_use(root, "101") == '0')
        printf("error, for A=1, B=0, C=1 it should be 1.\n");
    if (BDD_use(root, "110") == '0')
        printf("error, for A=1, B=1, C=0 it should be 0.\n");
    if (BDD_use(root, "111") == '0')
        printf("error, for A=1, B=1, C=1 it should be 0.\n");

}

void generate_all_uses(int vars_num, char use[], int i, BDD *root, int *index){
    if (i == vars_num){
        use[vars_num] = '\0';
        *index = *index + 1;
        if ( BDD_use(root, use) != root->bool->foo[*index - 1]){
            printf("Wrong use, for %s it should be %c.\n", use, root->bool->foo[*index - 1]);
        }
        return;
    }

    use[i] = '0';
    generate_all_uses(vars_num, use, i+1, root, index);

    use[i] = '1';
    generate_all_uses(vars_num, use, i+1, root, index);
}

int main_tester(int vars_num, int num_of_bdd){
    double sum = 0;
    double create_sum = 0;
    double reduce_sum = 0;
    double uses_sum = 0;

    for (int i = 0; i < num_of_bdd; i++) {
        srand(time(NULL));
        unsigned int vectors_num = (unsigned int) pow(2, vars_num);
        char vector[vectors_num];
        char chars[] = "01";

        // generating vector of vars_num variables
        for (int i = 0; i < vectors_num; i++) {
            int c = (rand() % 2);
            vector[i] = chars[c];
        }
        vector[vectors_num] = '\0';

        // timing create
        clock_t create = clock();
        BF *bf = BF_create(vector);
        BDD *root = BDD_create(bf);
        clock_t create_end = clock();

        // timing reduce
        clock_t reduce = clock();
        unsigned int reduced_nodes = BDD_reduce(root);
        clock_t reduce_end = clock();

        // calculating num of nodes
        unsigned int original_nodes = 0;
        for (int i = 0; i <= vars_num; i++) {
            original_nodes += (unsigned int) pow(2, i);
        }

        // calculating number of nodes reduced in BDD in percentage
        double reduction = ((double) reduced_nodes / (double) original_nodes) * 100;

        // testing all uses
        char use[vars_num];
        int index = 0;

        // timing all uses
        clock_t uses = clock();
        generate_all_uses(vars_num, use, 0, root, &index);
        clock_t uses_end = clock();


        sum += reduction;
        create_sum += (double)(create_end - create) * 1000.0 / CLOCKS_PER_SEC;
        reduce_sum += (double)(reduce_end - reduce) * 1000.0 / CLOCKS_PER_SEC;
        uses_sum += (double)(uses_end - uses) * 1000.0 / CLOCKS_PER_SEC;

    }

    double average_reduction = sum / num_of_bdd;
    double average_create = create_sum / num_of_bdd;
    double average_reduce = reduce_sum / num_of_bdd;
    double average_uses = uses_sum / num_of_bdd;

    printf("%d BDDs of %d variables:\n", num_of_bdd, vars_num);
    printf("Average time to create BDDs: %2.lf ms.\n", average_create);
    printf("Average time to reduce BDDs: %2.lf ms.\n", average_reduce);
    printf("BDDs were reduced on average by %2.lf%%.\n",average_reduction);
    printf("Average time to test all cases of use function: %2.lf ms.\n", average_uses);
}


int main() {
    //debug_tester();

    main_tester(15, 1);
    return 0;
}
