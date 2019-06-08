#include "hash.h"

int main () {

    int M = 7;

    Hash *H = create_hash (M);

    insert_chained (H, "Marina");
    insert_chained (H, "Pedro");
    insert_chained (H, "Joana");
    insert_chained (H, "Thais");
    insert_chained (H, "Fabio");
    insert_chained (H, "Jonas");
    insert_chained (H, "Joaquim");
    insert_chained (H, "Mauricio");
    insert_chained (H, "Jorge");
    insert_chained (H, "Ana");
    insert_chained (H, "Patricia");
    insert_chained (H, "Henrique");


    print_hash (H);

    free_hash (H);

    return 0;
}
