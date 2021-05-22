# Interface Double Linked List for C
This is an interface to work with double list in C. It's tested on Linux operating systems, specifically, Arch linux. 
The interface is generic, so the nodes can have any type data.
## Functions of the interface
```C
createDoubleList() /*Create an intance of double list*/

insertOrderedDN(nodeD *q, doubleList *ls, int (*fn)(void *a, void *b)) 
  /*Insert node q at the location specified by fn (this function must define it the user)*/

newNodeD() /*Reserve memory for the one nodeD (Double node)*/

pushDN(nodeD *q, doubleList *ls) /*Insert the node q at the last position*/

unshiftDN(nodeD *q, doubleList *ls) /*Insert the node q at the first position*/

shiftDN(doubleList *ls) /*Delete the first node the list*/

popDN(doubleList *ls) /*Delete the last node of list*/

*getNextNodeD(nodeD *p) /*Get next node of the p and return it*/

*getPreviousNodeD(nodeD *p) /*Get previous node of the p and return it*/

deleteALL(doubleList *ls) /*Delete all nodes of the list and free memory*/

travelListNatural(doubleList *dl, void (*fn)(void *e))
  /*Travel natural: travel from the first node. You must define the funcion fn to display the datas*/

travelListUnnatural(doubleList *dl, void (*fn)(void *e))
  /*Travel unnatural: travel from the last node. You must define the funcion fn to display the datas*/
```
