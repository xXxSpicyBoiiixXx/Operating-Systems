/*
 * 3. Write another program using fork(). The child process should
 * print "hello"; the parent proces should print "goodbye". You 
 * should try to ensure that the child process always prints first;
 * can you do this wihtout calling wait() in the parent?
 */

// You can't do this wihtout wait.

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

int main(int argc, char* argv[]){
	
	int rc = fork();
	int status;

	if(rc < 0){
		fprintf(stderr, "Forking Failed");
		exit(1);
	}
	
	// Child process
	else if(rc == 0){
		printf("Hello!\n");
	}

	// Parents process
	else{
		while(waitpid (rc, &status, WNOHANG) == 0) {
			sleep(1);
		}

	printf("Goodbye!\n");
	}
	return 0;
}
