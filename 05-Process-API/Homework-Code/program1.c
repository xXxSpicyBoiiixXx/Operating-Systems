/*
 * 1. Write a program that calls fork(). Before calling fork(), have
 * the main process access a variable (e.g., x) and set its value to
 * something (e.g., 100). What value is the variable in the child 
 * process? What happens to the variable when both the child and 
 * parent change the value of x? 
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char *argv[]) {
	int x = 100;
	
	int rc = fork();

	if(rc < 0){
		fprintf(stderr, "Fork Failed\n");
		exit(1);
	}

	// Child (new process) 
	else if(rc == 0) {
		printf("This is a child process!\n");
		x = 101;
		printf("x = %d\n", x);
	}
	// Parent goes down this path (main)
	else{
		printf("This is a parent process!\n");
		x = 102;
		printf("x = %d\n", x);
	}
	
	printf("Finally x = %d\n", x);

	return 0;
}
