#include <bits/stdc++.h>
#include <fcntl.h>
#include <string.h>
#include <unistd.h>
#include <string>
using namespace std;
#define fori(n) for (ll i = 0; i < n; ++i)
#define forj(n) for (ll j = 0; j < n; ++j)
#define forixy(x, y) for (ll i = x; i < y; ++i)
#define ll long long int
#define MOD 1000000007
#define Pi 3.14159265358979323846
bool compare(string s1,string s2)
{
    int l1=s1.length();
    int l2=s2.length();
    int i;
    int e=min(l1,l2);
    for(i=0;i<e;i++)
    {
        if(s1[i]==s2[i])
        i++;
        else //if(s1[i]>s2[i])
        return s1>s2;
       /* else if(s1[i]<s2[i])
        return s1<s2;*/
    }

    if(l1==l2 && i==l1)
     return s1<s2;
    
   
    char c='5';
    if(l1<l2)
    { 
        if(s2[l1]>=c)
        return false;//s2>s1;
        else
        return true;//s1>s2;
    }
    else if(l1>l2)
    {
        if(s1[l2]>=c)
        return true;//s2<s1;
        else
        return false;//s1<s2;
        
    }

  //  return s1<s2;
   
}   

bool com(string s1,string s2)
{
    string a,b;
    a=s1+s2;
    b=s2+s1;
    return a>b;
}


 string largestNumber(vector<int> A) {
    vector<string> d;
    string ans="";
    for(int i=0;i<A.size();i++)
    {   
        string q=to_string(A[i]);
        d.push_back(q);
    
    }
    
    sort(d.begin(),d.end(),com);
    
    
    for(int i=0;i<d.size();i++)
    { ans+=d[i];
      ans+=" ";
      if(d[0]=="0")
       break;
    }
    
    
    
    
   /* int num[10];
    for(int i=0;i<10;i++)
     num[i]=0;
    priority_queue<int> pq; 
    for(int i=0;i<A.size();i++)
    {   int a=A[i];
        if(a/10==0)
         num[a]++;
        else
        pq.push(a);
    }
    
    string ans="";
    for(int i=9;i>=0;i--)
    {
      string sc=to_string(i);
    
       
      while(!pq.empty())
      {
          int t=pq.top();
          string p=to_string(t);
          string s_f,s_b;
          s_f=p.substr(0,1); s_b=p.substr(p.length()-1,1);
          int i_f,i_b;
          i_f=stoi(s_f); i_b=stoi(s_b);
          
          if(p.substr(0,1)!=sc)
             break;
             
           else if(i_b>i_f )
           {  
               ans=ans+p;
               pq.pop();
           }
           
           else if(i_b<=i_f)
           {
                  while(num[i]>0)
                      {ans=ans+sc;
                       num[i]--;}
                       
                  ans=ans+p;
                  pq.pop();
               
           }
           
      }
      
      while(num[i]>0)
            {ans=ans+sc;
                num[i]--;}
        
    }*/
    
    // if(ans[0]=='0')
    // ans='0';
    
    return ans;
    
}

// int isPalindrome(int A) {
//     string s=to_string(A);
    
//     if(s==reverse(s.begin(),s.end()))
//     return 1;
//     else
//     return 0;
    
// }



int fact(int n)
{
    if(n==0 || n==1)
    return 1;

   
    return  ((n%MOD)*(fact(n-1)%MOD))%MOD;
}

ll poww(ll x,ll y)
{  ll ans=1;
   while(y)
   {
      if(y%2==1)
      ans=ans%MOD*x%MOD;
   
      x=x%MOD*x%MOD;
      y/=2;
   }
    
    return ans%MOD;
}



int main()
{ 
 ll t;
 cin>>t;
 while(t--)
 { 
     ll x,k;
     vector<ll> v;
     cin>>x>>k;
     fori(x)
     {
         ll num;
         cin>>num;
         v.push_back(num);
         
     }
     
     ll ptr1=0,ptr2=x-1,ma=LLONG_MIN,max_e=LLONG_MIN,min_e=LLONG_MAX,ma_e=0;
     
     unordered_map<ll,ll> m1;
     
     
     while(ptr1<ptr2)
     {
         ll sum=v[ptr1]+v[ptr2];
         if(sum<min_e) min_e=sum;
         if(sum>max_e) max_e=sum;
         
         m1[sum]++;
         
         if(m1[sum]>ma)
         {ma=m1[sum]; ma_e=sum;}
         
         ptr1++; ptr2--;
         
     }
     
     if(ma_e-min_e<=k)
     cout<<(x/2)-ma<<endl;
     else
     cout<<(x/2)<<endl;
     
     
 }
return 0;
}
