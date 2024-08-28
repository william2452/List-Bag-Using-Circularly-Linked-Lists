#include "listbag.h"
#include <assert.h>
#include <stdlib.h>
#include <stdio.h>

/*Turn on for debugging messages*/
int debug = 0;

/*
	initlist: initialize the list - create the head and initialize pointers
	param: lst is the list
	pre: lst is not null
	post: memory has been dynamically allocated for the head
	post: head next is initialized to NULL
*/
void initList (struct List *lst) {
	assert(lst != NULL);
	lst->head = malloc(sizeof(struct Link));
	lst->head->next = NULL;
}

/*
	addFrontList: add a value to the front of the list
	param: head is the head of the list
	param: e is the value to add to the list
	pre: head is not null
	post: memory has been dynamically allocated for a new link
	post: new link is added to the front of the list
*/
void addFrontList (struct Link *head, TYPE e) {
	if(debug)printf("Inserting %d at head of list\n", e);
	/* FIX ME*/
    assert(head != NULL);

    struct Link *newNode = malloc(sizeof(struct Link));
    newNode -> value = e;

    if(head -> next == NULL) {
        newNode -> next = NULL;
    } else {
        newNode -> next = head -> next;
    }
    head -> next = newNode;
}

/*
	addBackList: add a value to the back of the list
	param: head is the front of the list
	param: e is the value to add to the list
	pre: head is not null
	post: memory has been dynamically allocated for a new link
	post: new link is added to the back of the list
*/
void addBackList(struct Link *head, TYPE e) {
	if(debug) printf("Inserting %d at back of list\n", e);
	/* FIX ME*/
    assert(head != NULL);

    struct Link *newNode = malloc(sizeof(struct Link));
    newNode -> value = e;
    newNode -> next = NULL;

    if(head -> next == NULL) {
        head -> next = newNode;
    } else {
        struct Link *curr = head -> next;
        while(curr -> next != NULL) {
            curr = curr -> next;
        }
        curr -> next = newNode;
    }
}

/*
	displayList: print the contents of the list
	param: head is the front of the list
	pre: head is not null
	pre: list is not empty
	post: list contents are displayed - separated by spaces
	post: no changes to the list
*/
void displayList (struct Link *head) {
    printf("List Contents: ");
	/* FIX ME*/
    assert(head != NULL);

    struct Link *curr = head -> next;
    while(curr != NULL) {
        printf("%i ", curr -> value);
        curr = curr -> next;
    }
    printf("\n");
}

/*
	frontList: return the element at the head of the list
	param: head is the front of the list
	return: return value at front of the list
	pre: head is not null
	pre: list is not empty
	post: no changes to the list
*/
TYPE frontList (struct Link *head) {
	/* FIX ME*/
    assert(head != NULL);

    struct Link *curr = head -> next;
	return curr -> value;
}

/*
	backList: return the element at the back of the  list
	param: head is the front of the list
    return: return value at back of the list
	pre: head is not null
	pre: list is not empty
	post: no changes to the list
*/
TYPE backList(struct Link *head) {
	/* FIX ME*/
	assert(head != NULL);

    struct Link *curr = head -> next;
    while(curr -> next != NULL) {
        curr = curr -> next;
    }
    return curr -> value;
}


/*
	removeFrontList: remove element from front of list
	param: head is the front of the list
	pre: head is not null
	pre: list is not empty
	post: head points to head->next
	post: old head has been freed
*/
void removeFrontList(struct Link *head) {
	if(debug) printf("remove front of list: \n");
	/* FIX ME*/
    assert(head != NULL);
    assert(head->next != NULL);

    struct Link *delNode = head -> next;
    head -> next = head -> next -> next;
    free(delNode);
    delNode = 0;
}

/*
	removeBackList:	remove element from back of list
	param: head is the front of the list
	pre: head is not null
	pre: list is not empty
	post: link before the end points to NULL
	post: old head has been freed
*/
void removeBackList (struct Link *head) {
	if(debug) printf("remove back of list: \n");
	/* FIX ME*/
    assert(head != NULL);
    assert(head->next != NULL);

    struct Link *curr = head -> next;
    struct Link *delNode = head -> next;
    while(delNode -> next != NULL) {
        curr = delNode;
        delNode = delNode -> next;
    }
    curr -> next = NULL;
    free(delNode);
    delNode = 0;
}

/*
	listRemove: remove the first occurrence of the value from the list
	param: head is the front of the list
	param: e is the value to remove
	pre: head is not null
	pre: list is not empty
	post: link containing  first occurrence of value e has been freed
	post: pointer before link containing  first occurrence of value has been updated
*/
void listRemove (struct Link *head, TYPE e) {
	if(debug) printf("remove %d from list: \n", e);
	/* FIX ME*/
    assert(head != NULL);
    assert(head->next != NULL);

    struct Link *curr = head -> next;
    struct Link *delNode = head -> next;
    while(delNode -> next != NULL) {
        if(delNode -> value == e) {
            curr -> next = delNode -> next;
            free(delNode);
            delNode = 0;
            break;
        } else {
            curr = delNode;
            delNode = delNode -> next;
        }
    }
}

/*
	isEmptyList: checks whether the list is empty or not
	param: head is the front of the list
    return: Return 1 if empty, 0 if not
	pre: head is not null
	post: no changes to the list
*/
int isEmptyList(struct Link *head) {
	assert(head != NULL);
	if(head->next == NULL) {
		return 1;
	}
	return 0;
}

/*
	freeList: Free the list
	param: head is the front of the list
	pre: head is not null
	post: each link of the list has been freed
	post: lst has been freed
	post: lst points to nothing
*/
void freeList(struct List *lst) {
	/* FIX ME*/
    assert(lst -> head != NULL);


    struct Link *curr = lst -> head -> next;
    struct Link *freeLink = lst -> head -> next;
    while(curr != NULL) {
        freeLink = curr;
        curr = curr -> next;
        free(freeLink);
        freeLink = 0;
    }
}


/* -----------------------ListBag functions begin here---------------------- */


/*
	initBag: initialize bag
	param: b is the bag
	pre: b is not null
	post: memory for list is dynamically allocated
	post: lst is initialized using initList()
	post: size  is initialized to 0
*/
void initBag(struct bag* b) {
    assert( b != NULL);
	b->lst = (struct List*)malloc(sizeof(struct List));/*Allocate for the list part of the bag*/
	initList(b->lst);/*Initialize list*/
	b->size=0;
}

/*
	addToBag: add an element to the bag
	param: b is the bag
	param: val is the value added to the bag
	pre: b is not null
	post: val is added to the bag (list implementing the bag)
	post: size is incremented
	HINT: use linked list functions to manipulate the list
*/
void addToBag(struct bag* b, TYPE val) {
 	/* FIX ME*/
    assert(b != NULL);

    addFrontList(b -> lst -> head, val);
    b -> size++;
}

/*
	bagContains: test if an element exists in the bag
	param: b is the bag
	param: val is the value to search for
    return: return 1 if found, otherwise return 0
	pre: b is not null
	post: no changes to the bag
*/
int bagContains(struct bag* b, TYPE val) {
	/* FIX ME*/
    assert(b != NULL);

    struct Link *search = b -> lst -> head;
    while(search != NULL) {
        if(search -> value == val) {
            return 1;
        } else {
            search = search -> next;
        }
    }
    return 0;
}

/*
	removeFromBag: remove an element from the bag
	param: b is the bag
	param: val is the value to remove from the bag
	pre: b is not null
	pre: b contains val - use bagContains()
	post: link is removed from bag
	post: size is decremented
	HINT: use linked list functions to manipulate the list
*/
void removeFromBag(struct bag* b, TYPE val) {
	/*FIX ME*/
    assert(b != NULL);
    assert(bagContains(b, val));

    listRemove(b -> lst -> head, val);
    b -> size--;
}

/*
	isEmptyBag: test if the bag is empty
	param: b is the bag
	return: return 1 if found, otherwise return 0
	pre: b is not null
	post: no changes to the bag
*/
int isEmptyBag(struct bag* b) {
	/* FIX ME*/
    assert(b != NULL);

	if(b -> lst -> head != NULL) {
        return 1;
	} else {
        return 0;
	}
}

/*
	freeBag: deallocate bag memory
	param: b is the the bag
	pre: b is not null
	post: bag is freed
	post: list is freed
	HINT: use linked list functions to manipulate the list
*/
void freeBag(struct bag *b) {
	/* FIX ME*/
    assert(b != NULL);

    struct List *lst = b -> lst;
    free(b);
    b = 0;
    freeList(lst);
}

/*-------------------- Pt II - Algorithm Analysis --------------------------*/

/*

NONE ARE LOGn!!!!!!!!!


#0 - Write a function called bagSearch(struct bag* b, TYPE val) which returns the number of comparisons that it took to find the value
If the function does not find the value, then return -1 (6 Pts)
Call the bagSearch function for at least three values and display the number of comparisons the bagSearch() function carried out. (2 Pts)
*/
int bagSearch(struct bag* b, TYPE val){
    assert(b != NULL);

    int searchNum = 0;
    struct Link *search = b -> lst -> head;
    while(search != NULL) {
        if(search -> value == val) {
            return searchNum;
        } else {
            search = search -> next;
            searchNum++;
        }
    }
    return -1;
}
/*
Added test functions to main_bag.c as well as prototype to listbag.h, so there are no test cases shown on this document. The calls I used were:
    printf("The search for 8 in the bag took (%i) comparisons. (-1 if not present).\n", bagSearch(b, 8));    RETURNS: 3
	printf("The search for 2 in the bag took (%i) comparisons. (-1 if not present).\n", bagSearch(b, 2));    RETURNS: 7
	printf("The search for 0 in the bag took (%i) comparisons. (-1 if not present).\n", bagSearch(b, 0));    RETURNS: -1
*/

/*
#1 - What is the worst case performace of the bagSearch() operation expressed in terms of the size of the bag(n)? (1 Pt)    O(n)

#2 - What is the best case performance of the bagSearch() operation expressed in terms of the size of the bag(n)? (1 Pt)    O(1)

#3 - What is the average number of comparisons that bagSearch() performs expressed in terms of the size of the bag(n)? (1 Pt)   n/2

#4 - What is the worst case performance for the listRemove() operation? Describe the worst case in words. (2 Pts)
O(n) The function goes through the entire list until it reaches the last node before finding the correct value.

#5 - What is the best case performance for the listRemove() operation? Describe the best case in words. (2 Pts)
O(1) The function immediately finds the value it is looking to remove in the list.

#6 - Did you use addFrontList() or addBackList() to add elements to your bag? Why was this the best choice? (2 Pts)
I used addFrontList() because it does not need to search through the list to find the end before adding the new node. It just adds at the front.

#7 - Is a linked list or a dynamic array a better choice for adding elements to a bag? Explain your answer. (3 Pts)
I think a linked list is better for adding elements to a bag because it does not need to redefine its size, you can simply add new nodes.
For a dynamic array, if you fill the bag, you have to copy all the contents to a new bag and increase the size, which we have learned is costly.

*/
