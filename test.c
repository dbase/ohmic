/* This is the most rudimentary test file in existence.
 * Do whatever you want with it.
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "ohmic.h"

int main(void) {
	printf("initialising hashmap\n");
	ohm_t *table = ohm_init(2, NULL);

	int a = 1, b = 7, c = 100;

	printf("inserting into hashmap\n");
	ohm_insert(table, "lolcats", strlen("lolcats") + 1, &a, sizeof(1));
	ohm_insert(table, "fircats", strlen("fircats") + 1, &b, sizeof(7));
	ohm_insert(table, "man", strlen("man") + 1, &c, sizeof(100));

	printf("retreiving values from hashmap size %d\n", table->size);
	printf("%s -> %d\n", "lolcats", *(int *) ohm_search(table, "lolcats", strlen("lolcats") + 1));
	printf("%s -> %d\n", "fircats", *(int *) ohm_search(table, "fircats", strlen("fircats") + 1));
	printf("%s -> %d\n", "man", *(int *) ohm_search(table, "man", strlen("man") + 1));

	printf("resizing hashmap\n");
	table = ohm_resize(table, 50);

	printf("retreiving values from hashmap size %d\n", table->size);
	printf("%s -> %d\n", "lolcats", *(int *) ohm_search(table, "lolcats", strlen("lolcats") + 1));
	printf("%s -> %d\n", "fircats", *(int *) ohm_search(table, "fircats", strlen("fircats") + 1));
	printf("%s -> %d\n", "man", *(int *) ohm_search(table, "man", strlen("man") + 1));

	printf("freeing hashmap\n");
	ohm_free(table);
	return 0;
} /* main() */
