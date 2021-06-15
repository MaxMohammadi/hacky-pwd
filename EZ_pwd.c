#define _BSD_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void usage() {
	(void)fprintf(stderr, "usage: pwd [-L | -P]\n");
	exit(1);
}

int main(int argc, char *argv[]) {
	char buffer[500];
	FILE *output;
	char *pwd;

	if (argc != 1)
		usage();

	output = popen("/bin/pwd", "r");
	pwd = fgets(buffer, sizeof(buffer), output);

	pwd = strtok(pwd, "\n");

	printf("/%s\n", pwd);

	return 0;
}