#ifndef __LIST_H
#define __LIST_H

# ifndef TYPE
# define TYPE int
# define TYPE_SIZE sizeof(int)
# endif

/*Structure for a link in the List*/
struct Link{
	TYPE value; /*Value of the link*/
	struct Link* next; /*Ptr to next link*/
};

/*Structure for the list - contains a sentinel Link to the head of the List*/
struct List{
	struct Link* head;
};

/*Structure for the bag - just a wrapper - so that you can pass a bag pointer to the bag functions*/
struct bag{
	struct List *lst;/*List that implements the bag*/
	int size;
};

/*Linked list*/
void initList(struct List *lst);
void addFrontList(struct Link *head, TYPE val);
void addBackList(struct Link *head, TYPE val);
TYPE frontList(struct Link *head);
TYPE backList(struct Link *head);
void removeFrontList(struct Link *head);
void removeBackList(struct Link *head);
void displayList(struct Link *head);
void listRemove(struct Link *head, TYPE e);
int isEmptyList(struct Link *head);
void freeList(struct List *lst);

/*Bag interface*/
void initBag(struct bag* b);
void addToBag(struct bag* b, TYPE val);
void removeFromBag(struct bag* b, TYPE val);
int bagContains(struct bag* b, TYPE val);
int isEmptyBag(struct bag* b);
void freeBag(struct bag *b);
int bagSearch(struct bag* b, TYPE val);

#endif
