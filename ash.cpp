#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll quick(int* arr,int n)
{   if(n==1 || n==0)
     return 0;
    else if(n==2)
    {
      int m=max(arr[0],arr[1]);
      int mi=min(arr[0],arr[1]);
      arr[0]=mi;arr[1]=m;
      return 1;
    }

   
    
    int me=(n-1)/2;
    int m_i;

    int ss[]={arr[0],arr[me],arr[n-1]};
    sort(ss,ss+3);


    
   // int p=(n+1)/2;

   
   if(arr[0]==ss[1])
     m_i=0;
   else if(arr[me]==ss[1])
      m_i=me;
    else if(arr[n-1]==ss[1])
      m_i=n-1;
  
  
 
// changing index of pivot to 0
        // int temp1=arr[m_i];
        // arr[m_i]=arr[0];
        // arr[0]=temp1;

    int temp1=arr[n-1];
        arr[n-1]=arr[0];
        arr[0]=temp1;
    int pivot=arr[0];
   // cout<<"pivot is"<<pivot<<endl;

   /*int p1=0,p2=j+1;
    while(p1<j && p2<n)
    {  if(arr[p1]<pivot)
       p1++;

       else if(arr[p2]>pivot)
       p2++;

       else
       {
         int temp=arr[p1];
         arr[p1]=arr[p2];
          arr[p2]=temp;

          p1++;p2++;
         
       }
       
 }*/
    
    
    int i=1;
    for(int j=1;j<n;j++)
    { 

      if(arr[j]<=pivot)
      {
        int temp=arr[j];
        arr[j]=arr[i];
        arr[i]=temp;
        i++;
        
      }

    }

         int temp=arr[0];
         arr[0]=arr[i-1];
         arr[i-1]=temp;

   

    ll a= quick(arr,i-1);
    ll b= quick(arr+i,n-i);

    // ll a_c= (i-1)==0?0:(i-2);
    // ll b_c= (n-i)==0?0:(n-i-1);

    return a+b+n-1;



}


   

    
    

int main()
{   
 int n;
    n=10000;
    ifstream infile;
    int* arr=new int[n];

infile.open("QuickSort.txt");
  if(!infile)
  {
    cout<<"Unable to open file";
    exit(1);
  }

  for(int i=0;i<n;i++)
  { infile>>arr[i];}

// for(int i=0;i<n;i++)
// {
//     cin>>arr[i];
// }

ll as=quick(arr,n);

for(int i=0;i<n;i++)
cout<<arr[i]<<" ";

cout<<endl;

cout<<as<<endl;

  return 0;
   
}