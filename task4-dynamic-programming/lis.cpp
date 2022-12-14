/* Dynamic Programming C/C++ implementation of LIS problem */
#include <iostream>
using namespace std;

/* lis() returns the length of the longest increasing
subsequence in arr[] of size n */
int lis(int arr[], int n)
{
	int *lis, i, j, max = 0;
	lis = (int*)malloc(sizeof(int) * n);

	/* Initialize LIS values for all indexes */
	for (i = 0; i < n; i++)
		lis[i] = 1;

	/* Compute optimized LIS values in bottom up manner */
	for (i = 1; i < n; i++)
		for (j = 0; j < i; j++)
			if (arr[i] > arr[j] && lis[i] < lis[j] + 1)
				lis[i] = lis[j] + 1;

	/* Pick maximum of all LIS values */
	for (i = 0; i < n; i++)
		if (max < lis[i])
			max = lis[i];

	/* Free memory to avoid memory leak */
	free(lis);

	return max;
}

/* Driver program to test above function */

//input:
//line 1: a positive integer (n) represents the length of the sequence
//line 2: n numbers, "the sequence to be examined"
//output: a single number, the longest increasing subsequence
int main(int argc, char** argv)
{
    int n;
    cin >> n;

    //int* arr = new int(n);
	int arr[n];
    for (int i = 0; i < n; i++){
    cin >> arr[i];
    }

	cout << lis(arr, n);
	return 0;
}



