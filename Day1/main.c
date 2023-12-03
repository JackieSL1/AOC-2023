/* Advent of Code 2023: Day 1
 * - Combine first and last digit in multiline file
 * - Combine each of these values to get answer
 */
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>

#define LINE_SIZE 100

int main(int argc, char* argv[]) {

	if (argc != 2) {
		perror("Please enter the test filename");
		exit(1);
	}

	FILE *f;
	if ((f = fopen(argv[1], "r")) == NULL) {
		perror("fopen: failed to open file");
		exit(1);
	}

	int first = -1, last, total = 0;

	char c;

	while((c = fgetc(f)) != EOF) {
		printf("%c", c);
		if (c == '\n') {
			printf("First: %d\n", first);
			printf("Last: %d\n", last);
			printf("Adding: %d\n", (10 * first) + last);
			total += (10 * first) + last;
			first = -1;
			last = first;
			puts("");

		}
		if (isdigit(c)) {
			if (first == -1) first = c - '0';
			last = c - '0';
		}
	}

	printf("Total: %i\n", total);


	return 0;
}

