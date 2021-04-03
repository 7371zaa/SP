#include <cstdio>

extern "C" {
int min(int *a, int size, int *num_index, int *min);
}

int main(void) {	

	int arr[] = {127, 27, 43, 123, -54, 12}; 
	
	int size = sizeof(arr) / sizeof(int);
	int num_index = 0;
	int num_min = 0;

	min(arr, size, &num_index, &num_min);

	printf("%d\n%d\n", num_min, num_index);

	return 0;
}
