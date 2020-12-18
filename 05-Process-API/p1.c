#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
	printf("Hello World (pid:%d)\n", (int) getpid());
	int rc = fork();
	if (rc < 0) {
		// Fork failed 
		fprintf(stderr, "fork failed\n");
		exit(1);
	} else if (rc == 0){
		// Child (new process)
		printf("Hello, I am child (pid:%d)\n", (int) getpid());
	} else {
		// Parent goes down this path (main)
		printf("Hello, I am parent of %d (pid:%d)\n", rc, (int) getpid());
	}
	return 0;
}
