#include "test2.h"
#include <stdlib.h>
#include <stdio.h>

void displayDates(void *e) {
    int *x = (int *)((nodeD *)e)->data;
    printf("Node data: %d\n", *x);
}

int main (int argc, char *argv[]) {
    nodeD *q = NULL;
    doubleList myDl = createDoubleList();
    int x, *ptrX = NULL;

    for (x = 0; x < 100000; x++) {
        ptrX = (int *)malloc(sizeof(int));
        *ptrX = x;
        q = newNodeD();
        q->data = (void *)ptrX;
        myDl.push(q, &myDl);
    }

    myDl.travelListNatural(&myDl, displayDates);
    printf("\nUnnatural travel\n");
    myDl.travelListUnnatural(&myDl, displayDates);
    myDl.deleteAll(&myDl);

    return 0;
}
