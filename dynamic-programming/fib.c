
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "fib.h"

int main(int argc, char * * argv)
{
	
	// test for fib3
	// int n = 47;
	// clock_t start = clock();
	// long int ans = fib3(n);
	// clock_t end = clock();
	// double ex_time = (double)(end - start) / (double)(CLOCKS_PER_SEC);
	// printf("Execution time: %.9f seconds\n", ex_time);
	// printf("%dth fibonacci number is: %ld\n", n, ans);

	// test for fib2
	int n = 100;
	clock_t start = clock();
	unsigned long long int ans = fib2(n);
	clock_t end = clock();
	double ex_time = (double)(end - start) / (double)(CLOCKS_PER_SEC);
	printf("Execution time: %.9f seconds\n", ex_time);
	printf("%dth fibonacci number is: %llu\n", n, ans);

	return 0;
}

// naive recursion and overall bad implementation
long int fib3(int n) {
	if (n <= 1) 
		return n;
	return fib3(n-1) + fib3(n-2);

}

// works lightning fast, only fails because of overflow of numbers 
// exceeding 64bits of unsinged long long int size
unsigned long long int fib2(int n) {
	unsigned long long int * array = malloc(sizeof(unsigned long long int) * n);
	array[0] = 0;
	array [1] = 1;
	for (int i=2; i<n+1; i++) {
		array[i] = array[i-1] + array[i-2];
	}
	unsigned long long int ans = array[n];
	free(array);
	return ans;
}

