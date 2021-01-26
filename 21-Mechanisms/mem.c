#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <sys/time.h>

// Simple routine to return absolute time in seconds 
double Time_GetSeconds() {
	struct timeval t;
	int rc = gettimeofday(&t, NULL);
	assert(rc == 0);
	return(double)((double)t.tv_sec +(double)t.tv_usec/1e6);
}

// Program that allocates an array of ints of a certain size and
// then proceeds to update each int in a loop, forever. 
int main(int argc, char *argv[]) {
	for(int i = 1; i < 9; i++){
		long long int size = (long long int) i;
		long long int size_in_bytes = size * 1024 * 1024 * 1024;

		printf("allocating %lld bytes (%.2f MB)\n", size_in_bytes, size_in_bytes / (1024 * 1024.0));

		// The big memory allocation happens here 
		int *x = malloc(size_in_bytes);
		if(x == NULL){
			fprintf(stderr, "memory allocation failed\n");
			exit(1);
		}

		long long int num_ints = size_in_bytes / sizeof(int)
		printf(" number of integers in array: %lld\n", num_ints);

		// This loop will go through each time, touch each 
		// integer and increment its value by 1.
		int k = 0;
		double time_since_last_print = 2.0;
		double t = Time_GetSeconds();
		int loop_count = 0;
		double bandwidthSum = 0;
		while(1){
			x[k++] += 1;

		if(k == num_ints){
		double delta_time = Time_GetSeconds() - t;
		time_since_last_print += delta_time;
		double bandwidth = size_in_bytes / (1024.0*1024.0*delta_time);
		bandwidthSum += bandwidth;

		// Only print every 0.2 seconds 
		if(time_since_last_print >= 0.2){
		printf("loop %d in %.2f ms (bandwidth: %.2f MB/s)\n", loop_count, 1000* delta_time, bandwidth);
		time_since_last_print = 0;
		}
	if(loop_count >9){
	break;
	}

	else {
	k = 0;
	t = Time_GetSeconds();
	loop_count++;
	}
		}
		}
	free(x);
	printf("Average bandwidth: %.2f\n\n", bandwidthSum / loop_count);
	}
return 0;
}

