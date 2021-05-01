#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

void Jobisdone() {
	printf("Job is done\n");
}

int main (void) {
	char name[50];

	for(int i = 0; i < 4; i++) {
		int a = fork();

		if(a == 0) {
			printf("Please enter your name : ");
			scanf("%s", name);
			printf("Your name is %s\n", name);
			exit (0);
		}
		else {
			wait(NULL);
		}
	}
	Jobisdone();
	return (0);
}
