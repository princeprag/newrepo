#include<bits/stdc++.h>
#define ll long long
using namespace std;

int count_ones(int num)
{
    int count=0;
    while(num & (num--))
    {count++;
   

    }

    return count;
}

// Program to find the parity of a given number 
#include <bits/stdc++.h> 

using namespace std; 

// Function to find the parity 
bool findParity(int y) 
{ 
	  
	y = y ^ (y >> 2); 
	y = y ^ (y >> 4); 
	y = y ^ (y >> 8); 
	y = y ^ (y >> 16);
    y = y ^ (y >> 1); 

	
	if (y & 1) 
		return 1; 
	return 0; 
} 




int main()
{ int a=6;
  cout<<count_ones(a);

}