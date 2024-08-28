#include "listbag.h"
#include <malloc.h>
#include <stdio.h>
#include <stdlib.h>


void assertTrue(int predicate, char *message) {
	printf("%s: ", message);
	if (predicate)
		printf("Pass \n");
	else
		printf("Fail \n");
}


int main() {


	struct List *lst = malloc(sizeof(struct List));
	initList(lst);
	printf("Initialized List \n");

    printf("---------testing addFrontList---------- \n");

    addFrontList(lst->head, 3);
    addFrontList(lst->head, 2);
    addFrontList(lst->head, 1);

    printf("List should contain [1, 2, 3]\n");
    displayList(lst->head);

    assertTrue(frontList(lst->head) == 1, "Testing head == 1 ");

    printf("---------testing addBackList---------- \n");

    addBackList(lst->head, 4);
    addBackList(lst->head, 5);

    printf("List should contain [1, 2, 3, 4, 5]\n");
    displayList(lst->head);

    assertTrue(frontList(lst->head) == 1, "Testing head == 1 ");
    assertTrue(backList(lst->head) == 5, "Testing tail == 5 ");

    printf("---------testing removeFrontList---------- \n");

    removeFrontList(lst->head);
    printf("List should contain [2, 3, 4, 5]\n");
    displayList(lst->head);

    assertTrue(frontList(lst->head) == 2, "Testing head == 2 ");
    assertTrue(backList(lst->head) == 5, "Testing tail == 5 ");

    printf("---------testing removeBackList---------- \n");

    removeBackList(lst->head);
    printf("List should contain [2, 3, 4]\n");
    displayList(lst->head);

    assertTrue(frontList(lst->head) == 2, "Testing head == 2 ");
    assertTrue(backList(lst->head) == 4, "Testing tail == 4 ");

    printf("---------testing listRemove---------- \n");

    printf("listRemove(lst->head, 3)\n");
    listRemove(lst->head, 3);

    assertTrue(frontList(lst->head) == 2, "Testing head == 2 ");
    assertTrue(backList(lst->head) == 4, "Testing tail == 4 ");

    printf("List should contain [2, 4]\n");
    displayList(lst->head);

    free(lst->head);

    printf("----------------- ******** testing listBag ******** ----------------- \n");

    struct bag *b = malloc(sizeof(struct bag));
	initBag(b);

	printf("---------testing addToBag---------- \n");
	addToBag(b, 1);
	addToBag(b, 2);
	addToBag(b, 3);
	addToBag(b, 7);
	addToBag(b, 11);
	addToBag(b, 8);
	addToBag(b, 3);
	addToBag(b, 9);

    printf("Bag should contain [9, 3, 8, 11, 7, 3, 2, 1]\n");
    displayList(b->lst->head);

    printf("\n\nMy Tests:\n");
    printf("---------testing bagSearch---------- \n");
	printf("The search for 8 in the bag took (%i) comparisons. (-1 if not present).\n", bagSearch(b, 8));
	printf("The search for 2 in the bag took (%i) comparisons. (-1 if not present).\n", bagSearch(b, 2));
	printf("The search for 0 in the bag took (%i) comparisons. (-1 if not present).\n", bagSearch(b, 0));
	printf("End My Tests.\n\n");

    printf("---------testing bag contents using dynamic array functions---------- \n");
    assertTrue(frontList(b->lst->head) == 9, "Testing head == 9 ");
    assertTrue(backList(b->lst->head) == 1, "Testing tail == 1 ");

    printf("---------testing bagContains---------- \n");
	assertTrue(bagContains(b, 3), "Testing bagContains(b, 3)");
	assertTrue(bagContains(b, 1), "Testing bagContains(b, 1)");
	assertTrue(!bagContains(b, 4), "Testing bagContains(b, 4)");

    printf("---------testing removeFromBag---------- \n");
	removeFromBag(b, 2);

	assertTrue(!bagContains(b, 2), "Testing bagContains(b, 2)");
	assertTrue(bagContains(b, 3), "Testing bagContains(b, 3)");


    printf("---------testing isEmptyBag---------- \n");
	assertTrue(isEmptyBag(b), "Testing isEmpty ");

	freeBag(b);

	return 0;
}
