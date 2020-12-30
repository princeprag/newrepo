// C++ implementation of the approach 
#include <bits/stdc++.h> 
using namespace std; 
#define MAX 10

// Function to return the minimum 
// absolute difference between any 
// two elements of the array 
int getMinDiff(int arr[], int n) 
{ 
	// To store the frequency of each element 
	int freq[MAX] = { 0 }; 

	for (int i = 0; i < n; i++) { 

		// Update the frequency of current element 
		freq[arr[i]]++; 

		// If current element appears more than once 
		// then the minimum absolute difference 
		// will be 0 i.e. |arr[i] - arr[i]| 
		if (freq[arr[i]] > 1) 
			return 0; 
	} 

	int mn = INT_MAX; 

	// Checking the distance between the nearest 
	// two elements in the frequency array 
	for (int i = 0; i < MAX; i++) { 
		if (freq[i] > 0) { 
			i++; 
			int cnt = 1; 
			while ((freq[i] == 0) && (i != MAX - 1)) { 
				cnt++; 
				i++; 
			} 
			mn = min(cnt, mn); 
			i--; 
		} 
	} 

	// Return the minimum absolute difference 
	return mn; 
} 

// Driver code 

int main() 
{ 
	


    map<vector<int>,int> s1;
	vector<int> vec;

	for(int i=0;i<11;i++)
	{
	vec.push_back(i);
	s1[vec]++;
	}
	
	

	return 0; 
} 
