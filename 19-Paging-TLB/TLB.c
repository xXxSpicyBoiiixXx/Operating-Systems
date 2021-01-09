#ifdef Linux 
	#define _GNU_SOURCE
	#include <sched.h> 
#endif 

#include <errno.h>
#include <pthread.h> // pthread_self
#include <stdio.h> // printf, fprintf 
#include <stdlib.h> // exit, malloc, free 
#include <sys/time.h> // times 
#include <unistd.h> // sysconf 

#define handle_error_en(en, msg) 
	do {
		errno = en;
		perror(msg); 
		exit(EXIT_FAILURE);
	} while(0)

int main(int argc, char *argv[]) {
	if(argc < 3) 
	{
		fprintf(stderr, "Need the number of pages and the number of trials\n");
		exit(EXIT_FAILURE);
	}

	if(argc == 3) 
	{
		cpu_set_t cpuset; 
		pthread_t thread = pthread_self(); 
		CPU_ZERO(&cpuset); 
		CPU_SET(0, &cpuset); 
		int s; 

		s = pthread_setaffinity_np(thread, sizeof(cpu_set_t), &cpuset);
		if(s != 0)
		{
			handle_error_en(s, "pthread_setaffinity_np");
		}
	}


