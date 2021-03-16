#include "test2.h"
#include <stdio.h>
#include <stdlib.h>

void error() {
/*Print a message if has not been possible reserv memory*/
    printf("Error. Inssuficient memory\n");
    exit(1);
}

void fflishIn() {
    /*Clear the buff input (stdin)*/
    int d;
    while ((d = getchar() != '\n') && d != EOF);
}

nodeD *newNodeD() {
    /*Reserv memory for the one nodeD (Double node)*/
    nodeD *q = (nodeD *)malloc(sizeof(nodeD));
    if (!q) error();
    q->next = NULL;
    q->prev = NULL;
    return q;
}

void pushDN(nodeD *q, doubleList *ls) {
    /*Insert the node q at the last position*/
    if (ls->first == NULL && ls->last == NULL) {
        ls->first = q;
        ls->last = q;
    } else {
        q->prev = ls->last;
        q->prev->next = q;
        ls->last = q;
    }
    
    ls->elements++;
}

void popDN(doubleList *ls) {
    /*Delete the last node of list*/
    if (ls->first == NULL) {
        printf("Empty list\n");
    } else {
        nodeD *den = ls->last;
        if (ls->last == ls->first) {
            ls->first = NULL;
            ls->last = NULL;
        } else {
            if (ls->last) {
                ls->last = ls->last->prev;
                ls->last->next = NULL;
            }
        }
        free(den->data);
        free(den);
        ls->elements--;
    }
}

void unshiftDN(nodeD *q, doubleList *ls) {
    /*Insert the node q at the first position*/
    if (ls->first == NULL && ls->last == NULL) {
        ls->first = q;
        ls->last = q;
    } else {
        q->next = ls->first;
        q->next->prev = q;
        ls->first = q;
    }
    ls->elements++;
}

void insertOrderedDN(nodeD *q, doubleList *ls, int (*fn)(void *a, void *b)) {
    /*Insert node q at the location specified by fn (this function must define it the user)*/
    doubleList dl = *ls;
    nodeD *p = NULL;

    if (dl.first == NULL && dl.last == NULL) {
        dl.first = q;
        dl.last = q;
    } else {
        p = dl.first;
        while (p != NULL && (fn(q->data, p->data) != 1)) {
            p = p->next;
        }
        if (p == dl.first) {
            unshiftDN(q, &dl);
        } else if (p == NULL) {
            pushDN(q, &dl);
        } else {
            q->next = p;
            q->prev = p->prev;
            q->next->prev = q;
            q->prev->next = q;
            dl.elements++;
        }
    }
    *ls = dl;
}

void shiftDN(doubleList *ls) {
/*Delete the first node the list*/
    if (ls->first == NULL) {
        printf("Empty list\n");
    } else {
        nodeD *den = ls->first;
        if (ls->first == ls->last) {
            ls->first = NULL;
            ls->last = NULL;
        } else {
            ls->first = ls->first->next;
            ls->first->prev = NULL;
        }
        free(den);
        ls->elements--;
    }
}

nodeD *getNextNodeD(nodeD *p) {
    /*Get next node of the p and return it*/
    p = p->next;
    return p;
}

nodeD *getPreviousNodeD(nodeD *p) {
    /*Get previous node of the p and return it*/
    p = p->prev;
    return p;
}

void *searchNodeD(void *e, doubleList *ls, int (*fn)(void *, void *)) {
    nodeD *p = NULL;

    if(ls->first == NULL) {
        printf("Empty list\n");
        return NULL;
    } else {
        p = ls->first;
        while (p != NULL && (fn(e, p->data) != 0)) {
            p = p->next;
        }
        if (p == NULL) {
            printf("No exist the value.\n");
            return NULL;
        } else {
            return p->data;
        }
    }
}

int deleteNodeD(void *e, doubleList *ls, int (*fn)(void *, void *)) {
    nodeD *p = NULL;

    if(ls->first == NULL) {
        printf("Empty list\n");
        return -1;
    } else {
        p = ls->first;
        while (p != NULL && (fn(e, p->data) != 0)) {
            p = p->next;
        }
        if (p == NULL) {
            printf("No exist the value.\n");
            return -1;
        } else {
            if (p == ls->first) {
                shiftDN(ls);
            } else {
                if (p == ls->last) {
                    popDN(ls);
                } else {
                    p->prev->next = p->next;
                    p->next->prev = p->prev;
                    free(p->data);
                    free(p);
                }
            }
        }
        return 1;
    }
}

void deleteALL(doubleList *ls){
    /*Delete all nodes of the list and free memory*/
    nodeD *p = ls->first;
    
    while (ls->first != NULL) {
        p = ls->first;
        ls->first = ls->first->next;
        free(p->data);
        free(p);
        ls->elements--;
    }
    
    ls->first = NULL;
    ls->last = NULL;
    ls->elements = 0;
}

void travelListNatural(doubleList *dl, void (*fn)(void *e)) {
    /*Travel natrual: travel from the first node
      You must define the funcion fn to display the dates */
    
    nodeD *p = dl->first;
    while (p != NULL) {
        fn(p);
        p = getNextNodeD(p);
    }
}

void travelListUnnatural(doubleList *dl, void (*fn)(void *e)) {
    /*Travel unnatural: travel from the last node
      You must define the funcion fn to display the dates */
    
    nodeD *p = dl->last;
    while (p != NULL) {
        fn(p);
        p = getPreviousNodeD(p);
    }
}

doubleList createDoubleList() {
    /*Create an intance of double list*/
    doubleList dl;

    //attributes
    dl.first = NULL; 
    dl.last = NULL;
    dl.elements = 1;

    //methods
    dl.pop = &popDN;
    dl.push = &pushDN;
    dl.unshift = &unshiftDN;
    dl.shift = &shiftDN;
    dl.insertOrdered = &insertOrderedDN;
    dl.search = &searchNodeD;
    dl.deleteNodeD = &deleteNodeD;
    dl.deleteAll = &deleteALL;
    dl.getNextNode = &getNextNodeD;
    dl.getPreviousNode = &getPreviousNodeD;
    dl.travelListNatural = &travelListNatural;
    dl.travelListUnnatural = &travelListUnnatural;

    return dl;
}
