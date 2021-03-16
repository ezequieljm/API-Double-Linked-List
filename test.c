#include "test2.h"
#include <stdlib.h>
#include <stdio.h>
#include <time.h>


void displayDates(void *e) {
    int *x = (int *)((nodeD *)e)->data;
    printf("Node data: %d\n", *x);
}

int *randPoint(int max) {
    int *ptrX = NULL;
    ptrX = (int *)malloc(sizeof(int));
    *ptrX = rand() % max;
    return ptrX;
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

int main (int argc, char *argv[]) {
    nodeD *q = NULL;
    int x, *ptrX = NULL;
    srand(time(NULL));

    doubleList myDl = createDoubleList();

    for (x = 0; x < 100; x++) {
        q = newNodeD();
        q->data = (void *)randPoint(100);
        /*myDl.push(q, &myDl);*/
        /*myDl.unshift(q, &myDl);*/
        myDl.insertOrdered(q, &myDl, comparator);
    }

    myDl.travelListNatural(&myDl, displayDates);
    printf("\nUnnatural travel\n");
    myDl.travelListUnnatural(&myDl, displayDates);

    ptrX = (int *)malloc(sizeof(int)); 
    x = rand() % 100;
    ptrX = &x;
    ptrX = (int *)myDl.search(ptrX, &myDl, comparator);
    if (ptrX == NULL)
        printf("Not exist node\n");
    else 
        printf("Data: %d\n", *ptrX);

    x = rand() % 100;
    ptrX = &x;

    x = myDl.deleteNodeD(ptrX, &myDl, comparator);

    if (x == 1) {
        printf("Node deltede\n");
    } else {
        printf("Not exists node\n");
    }

    myDl.deleteAll(&myDl);

    return 0;
}
