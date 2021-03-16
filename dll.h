/*doubleList.h
 * */
#if !defined _DOUBLE_LIST_H
#define _DOUBLE_LIST_H

typedef struct d {
    void *data;
    struct d *next;
    struct d *prev;
} nodeD;

typedef struct dl{
    nodeD *first;
    nodeD *last;
    int elements;

    void (*pop)(struct dl *ls);

    void (*push)(nodeD *q, struct dl *ls);

    void (*unshift)(nodeD *q, struct dl *ls);

    void (*shift)(struct dl *ls);

    void (*insertOrdered)(nodeD *q, 
            struct dl *ls, 
            int(*comparator)(void *, void *)
        );

    nodeD *(*getNextNode)(nodeD *q);

    nodeD *(*getPreviousNode)(nodeD *q);

    void *(*search)(void *e, struct dl *ls, int(*fn)(void *, void *));   

    int (*deleteNodeD)(void *e, struct dl *ls, int(*fn)(void *, void *));

    void (*deleteAll)(struct dl *ls);

    void (*travelListNatural)(struct dl *ls,
            void (*displayDates)(void *)
        );

    void (*travelListUnnatural)(struct dl *ls,
            void (*displayDates)(void *)
        );

} doubleList;

void error();

void fflishIn();

nodeD *newNodeD();

void pushDN(nodeD *q, doubleList *ls);

void popDN(doubleList *ls); 

void unshiftDN(nodeD *q, doubleList *ls);

void insertOrderedDN(nodeD *q, doubleList *ls, int (*fn)(void *a, void *b));

void shiftDN(doubleList *ls);

nodeD *getNextNodeD(nodeD *p);

nodeD *getPreviousNodeD(nodeD *p);

void *searchNodeD(void *e, struct dl *ls, int(*fn)(void *, void *));

int deleteNodeD(void *e, struct dl *ls, int(*fn)(void *, void *));

void deleteALL(doubleList *ls);

void travelListNatural(doubleList *dl, void (*fn)(void *e));

void travelListUnnatural(doubleList *dl, void (*fn)(void *e));

doubleList createDoubleList();

#endif //_DOUBLE_LIST_H
