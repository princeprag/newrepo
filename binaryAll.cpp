
// code to find lowerbound of an element in sorted Array using BinarySearch
#include<bits/stdc++.h>
using namespace std;
int lowerbound(vector<int> vec,int n,int num)
{ 
        int l=0;
        int h=n-1;
        int cur=0;
        
        
        while(l<=h)
        {
            int m=(l+h)/2;
            
            if(num >= vec[m])
            {
                cur = m;
                l = m+1;
            }
            else
                h =m-1;
        }
        
        if(vec[cur]>=num) return cur;
        else if(vec[cur]<num) return (cur+1);

        // FOR HIGHER BOUND simply 
        //if(vec[cur]<=num) return cur+1;
        //else if(vec[cur]>num) return cur;
        
        
}

int main()
{
    int n,p,k;
    cin>>n;
    vector<int> vec;
    for(int i=0;i<n;i++)
    {
      
        vec.push_back(5*(i+1));
    }
           int cnt;
           cin>>cnt;


         for(int i=0;i<=cnt;i++)
         cout<<i<<" : "<<lowerbound(vec,n,i)<<endl;
    
    
    
    

}