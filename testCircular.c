#include "dll.h"
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

void showDates(void *e) {
    int val = *(int *)e;
    printf("Node value: %d\n", val);
}

void *reservMemForData() {
    int *ptrX = (int *)malloc(sizeof(int));
    if (!ptrX) error();

    return (void *)ptrX;
}

int castConv(void *a, void *b) {
    int *x = NULL, *y = NULL;
    x = (int *)a;
    y = (int *)b;
    *x = *y;
    return 0;
}

int comparator(void *e, void *z) {
    int x = *((int *)e);
    int y = *((int *)z);

    if (x == y) 
        return 0;
    else if (x < y)
        return 1;
    else
        return -1;
}

int main(int argc, char *argv[]) {
    doubleCircularList cl = createDCL();
    nodeC *q = NULL;
    int *pInt = NULL, val = 0;
    srand(time(NULL));

    for (int x = 0; x < 10000; x++) {
        q = newNodeC();
        val = rand() % 1000;
        q->data = reserv(&val, reservMemForData, castConv);
        /*insertNodeC(q, &cl, 1);*/
        insertOrdered(q, &cl, comparator);
    }

    printf("Nodes %d\n", cl.elements);
    naturalTravel(&cl, showDates);
    deleteAllDCL(&cl);

    return 0;
}
