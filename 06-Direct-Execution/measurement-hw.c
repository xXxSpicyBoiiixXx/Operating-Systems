/*
 * A system call is expected to be significantly more expensive 
 * than a procedure call (provided that both perform very little 
 * actual computation). A system call involves the following actions, which do not occur during a simple procedure call which makes hgih overhead:
 *
 * A context switch
 * A trap to a specific location in the interrupt vecotr 
 * Control passes to a service routine, which runs in 'monitor' mode
 * The monitor determines what system call has occured 
 * Monitor verfies that the parameters passed are correct and legal
 */

#include <sys/time.h>
#include <unistd.h>
#include <assert.h>
#include <stdio.h>

int foo(){
	return(10);
}

// Calculates nanoseconds in a timevalu structure
long nanosec(struct timeval t){
	return((t.tv_sec*1000000+t.tv_usec)*1000);
}

int main(){
	int i;
	int j;
	int res;
	long N_iterations = 1000000;
	float avgTimeSysCall;
	float avgTimeFuncCall;
	struct timeval t1;
	struct timeval t2;

	// Find average time for system call 
	res = gettimeofday(&t1, NULL);	assert(res == 0);
	for(i = 0; i < N_iterations; i++){
		j = getpid();
	}

	res = gettimeofday(&t2, NULL);	assert(res == 0);
	avgTimeSysCall = (nanosec(t2) - nanosec(t1))/(N_iterations*1.0);

	// Find average time for Function call 
	res = gettimeofday(&t1, NULL);	assert(res == 0);
	for(i = 0; i < N_iterations; i++){
		j = foo();
	}

	res = gettimeofday(&t2, NULL);	assert(res == 0);
	avgTimeFuncCall = (nanosec(t2) - nanosec(t1))/(N_iterations*1.0);

	printf("Average time for System call getpid : %f\n", avgTimeSysCall);
	printf("Average time for Function call : %f\n", avgTimeFuncCall);

	return 0;
}
