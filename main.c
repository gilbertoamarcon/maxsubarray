#include <stdio.h>

int enumerate(int n, int array[]){

	int max = 0;
	int aux = 0;

	for(int i = 0; i < n; i++)
		for(int j = i; j < n; j++){

			// Sum for sub-array array[i:j]
			aux = 0;
			for(int k = i; k <= j; k++)
				aux += array[k];

			// Updating max value
			if(aux > max) max = aux;
		}

	return max;
}

int better_enumerate(int n, int array[]){

	int max = 0;
	int aux = 0;

	for(int i = 0; i < n; i++){
		aux = 0;
		for(int j = i; j < n; j++){

			aux += array[j];

			// Updating max value
			if(aux > max) max = aux;
		}
	}

	return max;
}

int max_xffix(int n, int array[], int pre){

	int max = 0;
	int aux = 0;

	for(int i = 0; i < n; i++){

		if(pre)
			aux += array[i];
		else
			aux += array[n-i-1];

		// Updating max value
		if(aux > max) max = aux;
	}

	return max;
}

int divide_and_conquer(int n, int array[]){

	if(n == 1)
		return array[0];

	int max = 0;
	int aux = 0;
	int h = (float)n/2;

	// First half
	aux = divide_and_conquer(h,array);
	if(aux > max) max = aux;

	// Second half
	aux = divide_and_conquer(n-h,array+h);
	if(aux > max) max = aux;

	// Middle
	aux = max_xffix(h,array,0) + max_xffix(n-h,array+h,1);
	if(aux > max) max = aux;

	return max;
}

int linear(int n, int array[]){

	int max_suffix		= 0;
	int max_subarray	= 0;
	int aux = 0;

	for(int i = 0; i < n; i++){

		// Max suffix i
		aux = max_suffix + array[i];
		if(aux > 0)
			max_suffix = aux;
		else
			max_suffix = 0;

		// Max sub-array i
		if(max_suffix > max_subarray)
			max_subarray = max_suffix;

	}

	return max_subarray;
}

int main(int argc, char **argv){

	/*
	Expected results:
	34
	30
	50
	187
	7
	210
	6
	*/

	int array1[] = {1,4,-9,8,1,3,3,1,-1,-4,-6,2,8,19,-10,-11};
	int array2[] = {2,9,8,6,5,-11,9,-11,7,5,-1,-8,-3,7,-2};
	int array3[] = {10,-11,-1,-9,33,-45,23,24,-1,-7,-8,19};
	int array4[] = {31,-41,59,26,-53,58,97,-93,-23,84};
	int array5[] = {3,2,1,1,-8,1,1,2,3};
	int array6[] = {12,99,99,-99,-27,0,0,0,-3,10};
	int array7[] = {-2,1,-3,4,-1,2,1,-5,4};

	printf("%d\n",linear(16,array1));
	printf("%d\n",linear(15,array2));
	printf("%d\n",linear(12,array3));
	printf("%d\n",linear(10,array4));
	printf("%d\n",linear( 9,array5));
	printf("%d\n",linear(10,array6));
	printf("%d\n",linear( 9,array7));

	return 0;
}
