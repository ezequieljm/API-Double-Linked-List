#include "dll.h"
#include <stdio.h>
#include <stdlib.h>

nodeC *newNodeC() {
    nodeC *q = (nodeC *)malloc(sizeof(nodeC));
    if (!q) error();
    q->next = NULL;
    q->prev = NULL;
    return q;
}

void insertNodeC(nodeC *q, doubleCircularList *cl, int first) {
    if (cl->first == NULL) {
        cl->first = q;
        q->next = q;
        q->prev = q;
    } else {
        cl->first->prev->next = q;
        q->prev = cl->first->prev;
        q->next = cl->first;
        cl->first->prev = q;
        if (first == 1) 
            cl->first = q;
    }
    cl->elements++;
}

int naturalTravel(doubleCircularList *cl, void(*fn)(void *)) {
    nodeC *p = NULL;

    if (cl->first == NULL) {
        printf("Empty list\n");
        return -1;
    } else {
        p = cl->first;
        while(p->next != cl->first) {
            fn(p->data);
            p = p->next;
        }
        fn(p->data);
        return 0;
    }

}

int unnaturalTravel(doubleCircularList *cl, void(*fn)(void *)) {
    nodeC *p = NULL;

    if (cl->first == NULL) {
        printf("Empty list\n");
        return -1;
    } else {
        p = cl->first;
        while(p->prev != cl->first) {
            fn(p->data);
            p = p->prev;
        }
        fn(p->data);
        return 0;
    }

}

void deleteAllDCL(doubleCircularList *cl) {
    nodeC *p = NULL, *m = NULL;

    if (cl->first == NULL) {
        printf("Empty list\n");
    } else {
        m = cl->first;
        cl->first = cl->first->next;
        while (cl->first->next != m) {
            p = cl->first;
            cl->first = cl->first->next;
            free(p->data);
            free(p);
            cl->elements--;
        }

        free(cl->first->data);
        free(cl->first);
        cl->first = NULL;
        cl->elements--;

        free(m->data);
        free(m);
        cl->elements--;

        printf("%p\n", cl->first);
        printf("%d\n", cl->elements);
    }

}

void *reserv(void *x, void *(*fn)(), int (*fn2)(void *, void *)) {
    void *ptrX = fn();
    fn2(ptrX, x);
    return (void *)ptrX;
}

void insertOrdered(nodeC *q, doubleCircularList *cl, int (*fn)(void *a, void *b)) {
    /*Insert node q at the location specified by fn (this function must define it the user)*/
    nodeC *p = NULL;

    if (cl->first == NULL) {
        cl->first = q;
        q->next = q;
        q->prev = q;
    } else {
        p = cl->first;
        while (p->next != cl->first && (fn(q->data, p->data) != 1)) {
            p = p->next;
        }

        if (p->next == cl->first) {
            if(fn(q->data, p->data) == -1) {
                //insert in front of p
                q->prev = p;
                q->next = p->next;
                p->next->prev = q;
                p->next = q;
            } else {
                //insert back of p
                q->next = p;
                q->prev = p->prev;
                p->prev->next = q;
                p->prev = q;
            }
        } else {
            //insert back of p
            q->next = p;
            q->prev = p->prev;
            p->prev->next = q;
            p->prev = q;
            if (p == cl->first) {
                if(fn(q->data, p->data) == 1) {
                    cl->first = q;

                }

            }

        }

    }

    cl->elements++;
}

doubleCircularList createDCL() {
    doubleCircularList cl;
    cl.first = NULL;
    cl.elements = 0;
    cl.deleteAllDCL = &deleteAllDCL;
    cl.insert = &insertNodeC;
    cl.insertOrdered = &insertOrdered;
    cl.naturalTravel = &naturalTravel;
    cl.unnaturalTravel = &unnaturalTravel;
    cl.reserv = &reserv;
    return cl;
}
