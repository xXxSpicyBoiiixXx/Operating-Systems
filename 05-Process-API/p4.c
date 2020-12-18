#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <assert.h>
#include <sys/wait.h>

int main(int argc, char *argv[]){
	int rc =  fork();
	
	if(rc < 0) {
		// fork failed 
		fprintf(stderr, "fork failed\n");
		exit(1);
	} else if(rc == 0) {
		// child: redirect standard output to a file 
		close(STDOUT_FILENO);
		open("./p4.output", O_CREAT|O_WRONLY|O_TRUNC, S_IRWXU);
		// now exec "wc.."
		char *myargs[3];
		myargs[0] = strdup("wc"); // program: wc (word count) 
		myargs[1] = strdup("p4.c"); // arg: file to count
		myargs[2] = NULL; // mark ed of array

		execvp(myargs[0], myargs);
	} else {
		// parent goes down this path (main)
		int wc = wait(NULL);
		assert(wc >= 0);
	}
return 0;
}
