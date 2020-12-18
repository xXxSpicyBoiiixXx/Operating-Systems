#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char *argv[]) {
	printf("Hello World (pid:%d)\n", (int) getpid());
	int rc = fork();

	// If the fork failed, then exit with error code 1
	if(rc < 0) {
		fprintf(stderr, "Fork Failed\n");
		exit(1);
	} 
	
	// Child (new process)
	else if(rc == 0){
		printf("Hello, I am child (pid:%d)\n", (int) getpid());
	}

	// Parent goes down this path (main)
	else{
		int rc_wait = wait(NULL);
		printf("Hello, I am parent of %d (rc_wait:%d) (pid:%d)\n", rc, rc_wait, (int) getpid());
	}
	return 0;
}
