// CPP program to find median of 
// an array 

#include "bits/stdc++.h" 
using namespace std; 

void swap(int* a, int* b) 
{ 
	int temp = *a; 
	*a = *b; 
	*b = temp; 
} 

int Partition(int arr[], int l, int r) 
{ 
	int lst = arr[r], i = l, j = l; 
	while (j < r) 
    { 
		if (arr[j] < lst) 
        { 
			swap(&arr[i], &arr[j]); 
			i++; 
		} 
		j++; 
	} 
	swap(&arr[i], &arr[r]); 
	return i; 
} 

int randomPartition(int arr[], int l, 
					int r) 
{ 
	int n = r - l + 1; 
	int pivot = rand() % n; 
	swap(&arr[l + pivot], &arr[r]); 
	return Partition(arr, l, r); 
} 

void MedianUtil(int arr[], int l, int r, 
				int k, int& a, int& b) 
{ 
	if (l <= r) 
    { 

		
		int partitionIndex = randomPartition(arr, l, r); 

		if (partitionIndex == k) { 
			b = arr[partitionIndex]; 
            cout<<"b set ";
			if (a != -1) 
				return; 
		} 

		else if (partitionIndex == k - 1) { 
			a = arr[partitionIndex]; 
            cout<<"a set ";
			if (b != -1) 
				return; 
		} 

		if (partitionIndex >= k) 
			return MedianUtil(arr, l, partitionIndex - 1, k, a, b); 

		// If partitionIndex <= k then 
		// find the index in second half 
		// of the arr[] 
		else
			return MedianUtil(arr,partitionIndex + 1, r, k, a, b); 
	} 

	return; 
} 

// Function to find Median 
void findMedian(int arr[], int n) 
{ 
	int ans, a = -1, b = -1; 

	// If n is odd 
	if (n % 2 == 1) 
    { 
		MedianUtil(arr, 0, n - 1,n / 2, a, b); 
        cout<<a<<" "<<b<<" ";
		ans = b; 
	} 

	// If n is even 
	else 
    { 
		MedianUtil(arr, 0, n - 1,n / 2, a, b); 
        cout<<a<<" "<<b<<" ";
		ans = (a + b) / 2; 
	} 

	// Print the Median of arr[] 
	cout << "Median = " << ans; 
} 

// Driver program to test above methods 
int main() 
{ 
	int arr[] = { 1,2,4,4,5,6 }; 
	int n = sizeof(arr) / sizeof(arr[0]); 
	findMedian(arr, n); 
	return 0; 
} 
