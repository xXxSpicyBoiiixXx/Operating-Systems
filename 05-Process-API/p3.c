#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

int main(int argc, char *argv[]) {
	printf("Hello World (pid:%d)\n", (int) getpid());
	int rc = fork();

	// Fork Failed exiting with exit code 1
	if(rc < 0) {
		fprintf(stderr, "Fork Failed\n");
		exit(1);
	}

	// Child (new process)
	else if(rc == 0) {
		printf("Hello, I am child (pid:%d)\n", (int) getpid());
		char *myargs[3];
		myargs[0] = strdup("wc"); // program "wc" (word count)
		myargs[1] = strdup("p3.c"); // argument: file to count 
		myargs[2] = NULL; // marks end of array
		execvp(myargs[0], myargs); // runs word count
		printf("This shoudn't print out");
	}

	// Parent goes down this path (main)
	else{
		int rc_wait = wait(NULL);
		printf("Hello, I am parent of %d (rc_wait:%d) (pid:%d)\n", rc, rc_wait, (int) getpid());
	}
	return 0;
}
