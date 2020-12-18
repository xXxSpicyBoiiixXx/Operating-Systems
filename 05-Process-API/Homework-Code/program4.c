/*
 * 4. Write a program that calls fork() and then calls someform of exec() to run the program /bin/ls. See if you can try all of the variants of exec(), including (on Linux) execl(), execle(), execlp(), execv(), execvp(), and execvpe(). Why do you think there are so many variants of the same basic call?
 */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

int main(int argc, char* argv[]){
	printf("Parent process!\n");
	int rc = fork();

	if(rc < 0) {
		fprintf(stderr, "Fork Failed");
		exit(1);
	}

	else if(rc == 0){
		printf("Child Process!\n");
		//execl("/bin/ls", "ls", "-l", (char*)NULL);
		//char *args[] = {"ls", "-l", NULL};
		//execv("/bin/ls", args);
		//execlp("ls", "ls", "-l", (char*)NULL);
		
		char *args[] = {"ls", "-l", NULL};
		execvp("ls", args);
	} else{
		wait(NULL);
	}
	return 0;
}
