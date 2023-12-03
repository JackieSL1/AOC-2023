/* Advent of Code 2023: Day 1, Part 2
 * - Combine first and last digit in multiline file
 * - Combine each of these values to get answer
 */
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define LINE_SIZE 100

char *words[9] = {
	"one",
	"two",
	"three",
	"four",
	"five",
	"six",
	"seven",
	"eight",
	"nine",
};

int check_word(char line[], int i) {

	for (int j = 0; j < 9; j++) {
		int wordlen = strlen(words[j]);
		if (strlen(line) - i - wordlen - 1 < 0) return 0;


		int valid = 1;

		for (int k = 0; k < wordlen; k++) {
			if (line[i + k] != words[j][k]) {
				valid = 0;
				break;
			};
		}
		if (valid) return j + 1;
	}

	return 0;
}

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

	char line[256];

	while(fgets(line, sizeof(line), f)) {
		for (int i = 0; i < strlen(line); i++) {
			c = line[i];
			// printf("%c", c);

			if (isdigit(c)) {
				if (first == -1) first = c - '0';
				last = c - '0';
			} else {
				int num;
				if((num = check_word(line, i))) {
					//printf("checkword(%s, %d) = %d\n", line, i, num);
					if (first == -1) first = num;
					last = num;
				}
			}
		}

		//printf("First: %d\n", first);
		//printf("Last: %d\n", last);
		//printf("Adding: %d\n", (10 * first) + last);
		total += (10 * first) + last;
		first = -1;
		last = first;
		puts("");
	}

	//printf("Total: %i\n", total);


	return 0;
}

