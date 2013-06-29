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

	printf("retreiving values from hashmap size %d\n", ohm_size(table));
	printf("%s -> %d\n", "lolcats", *(int *) ohm_search(table, "lolcats", strlen("lolcats") + 1));
	printf("%s -> %d\n", "fircats", *(int *) ohm_search(table, "fircats", strlen("fircats") + 1));
	printf("%s -> %d\n", "man", *(int *) ohm_search(table, "man", strlen("man") + 1));

	printf("resizing hashmap\n");
	table = ohm_resize(table, 50);

	printf("retreiving values from hashmap size %d\n", ohm_size(table));
	printf("%s -> %d\n", "lolcats", *(int *) ohm_search(table, "lolcats", strlen("lolcats") + 1));
	printf("%s -> %d\n", "fircats", *(int *) ohm_search(table, "fircats", strlen("fircats") + 1));
	printf("%s -> %d\n", "man", *(int *) ohm_search(table, "man", strlen("man") + 1));

	printf("resizing hashmap\n");
	table = ohm_resize(table, 1);

	printf("retreiving values from hashmap size %d\n", ohm_size(table));
	printf("%s -> %d\n", "lolcats", *(int *) ohm_search(table, "lolcats", strlen("lolcats") + 1));
	printf("%s -> %d\n", "fircats", *(int *) ohm_search(table, "fircats", strlen("fircats") + 1));
	printf("%s -> %d\n", "man", *(int *) ohm_search(table, "man", strlen("man") + 1));

	ohm_t *new = ohm_init(2, NULL);

	a = 3;
	b = 4;
	c = 2;

	ohm_insert(table, "dsd", strlen("dsd") + 1, &a, sizeof(3));
	ohm_insert(table, "fircs", strlen("fircs") + 1, &b, sizeof(4));
	ohm_insert(table, "man", strlen("man") + 1, &c, sizeof(2));

	printf("merging new hashmap with old\n");
	ohm_merge(table, new);

	printf("retreiving values from hashmap size %d\n", ohm_size(table));
	printf("%s -> %d\n", "lolcats", *(int *) ohm_search(table, "lolcats", strlen("lolcats") + 1));
	printf("%s -> %d\n", "fircats", *(int *) ohm_search(table, "fircats", strlen("fircats") + 1));
	printf("%s -> %d\n", "man", *(int *) ohm_search(table, "man", strlen("man") + 1));
	printf("%s -> %d\n", "fircs", *(int *) ohm_search(table, "fircs", strlen("fircs") + 1));
	printf("%s -> %d\n", "dsd", *(int *) ohm_search(table, "dsd", strlen("dsd") + 1));

	printf("duplicating merged hashmap\n");
	ohm_t *dup = ohm_dup(table);

	printf("retreiving values from hashmap size %d\n", ohm_size(dup));
	printf("%s -> %d\n", "lolcats", *(int *) ohm_search(dup, "lolcats", strlen("lolcats") + 1));
	printf("%s -> %d\n", "fircats", *(int *) ohm_search(dup, "fircats", strlen("fircats") + 1));
	printf("%s -> %d\n", "man", *(int *) ohm_search(dup, "man", strlen("man") + 1));
	printf("%s -> %d\n", "fircs", *(int *) ohm_search(dup, "fircs", strlen("fircs") + 1));
	printf("%s -> %d\n", "dsd", *(int *) ohm_search(dup, "dsd", strlen("dsd") + 1));

	printf("making temporary hashmap\n");
	ohm_t *to = ohm_init(2, NULL);
	ohm_insert(to, "dsd", strlen("dsd") + 1, &a, sizeof(3));
	ohm_insert(to, "fircs", strlen("fircs") + 1, &b, sizeof(4));
	ohm_insert(to, "man", strlen("man") + 1, &c, sizeof(2));

	printf("retreiving values from hashmap size %d\n", ohm_size(to));
	printf("%s -> %d\n", "man", *(int *) ohm_search(to, "man", strlen("man") + 1));
	printf("%s -> %d\n", "fircs", *(int *) ohm_search(to, "fircs", strlen("fircs") + 1));
	printf("%s -> %d\n", "dsd", *(int *) ohm_search(to, "dsd", strlen("dsd") + 1));

	printf("copying to temporary hashmap\n");
	ohm_cpy(to, table);

	printf("retreiving values from hashmap size %d\n", ohm_size(to));
	printf("%s -> %d\n", "lolcats", *(int *) ohm_search(to, "lolcats", strlen("lolcats") + 1));
	printf("%s -> %d\n", "fircats", *(int *) ohm_search(to, "fircats", strlen("fircats") + 1));
	printf("%s -> %d\n", "man", *(int *) ohm_search(to, "man", strlen("man") + 1));

	printf("freeing hashmap\n");
	ohm_free(table);
	ohm_free(new);
	ohm_free(dup);
	ohm_free(to);
	return 0;
} /* main() */
