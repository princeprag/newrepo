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
#define mod 1000000007
#define Pi 3.14159265358979323846

// a%b is neg if a or b is neg

ll getMinDiff(vector<ll>  arr) 
{ 
     
    ll n=arr.size();
    ll freq[101] = { 0 }; 
  
    for (ll i = 0; i < n; i++)  
    {
     freq[arr[i]]++; 
     if(freq[arr[i]]>1) return 0;
    }
    
  
    ll mn = LLONG_MAX; 
  
   
    for (int i = 0; i < 101; i++) { 
        if (freq[i] > 0) { 
            i++; 
            ll cnt = 1; 
            while ((freq[i] == 0) && (i != 100)) { 
                cnt++; 
                i++; 
            } 
            mn = min(cnt, mn); 
            i--; 
        } 
    } 
  
    
    return mn; 
} 


bool checkPrime(ll x)
{
    if (x == 1)
    {
        return false;
    }
    if (x <= 3)
    {
        return true;
    }
    ll t = 2;
    if (x % 2 == 0)
    {
        return false;
    }
    t = 3;
    for (t; t <= sqrt(x); t += 2)
    {
        if (x % t == 0)
        {
            return false;
        }
    }
    return true;
}

unsigned int reverse(unsigned int A) {
    unsigned int B = 0; //B will hold the reversed number
    for(int i=0;i<32;i++){  //Iterating on all bit positions
        int k = A & 1;      //Extracting the rightmost bit from A (the ith bit in original number)
        B <<= 1;            //Shifting B to left (rightmost bit becomes 0)
        B |= k;             //Adding the extracted bit
        A >>= 1;            //Now the (i+1)st bit shifts to the rightmost position in A
    }
    return B;
}
 

  

ll fact(ll n) 
{ 
    ll res = 1; 
    for (ll i = 2; i <= n; i++) 
        res = res * i; 
    return res; 
} 

  
ll nCr(ll n, ll r) 
{ 
    return fact(n) / (fact(r) * fact(n - r)); 
} 
  

void allSumadj(int arr[], int n,vector<ll>* v,int* it)
{ if(n==0)
  {
   return;
  }


   allSumadj(arr+1,n-1,v,it);
  ll size=v->size();
  v->push_back(arr[0]);
  for(ll k=(*it);k<size;k++)
  {
    v->push_back(v->at(k)+arr[0]);
    
  }

  *it=size;

}




bool checkPow(ll x,ll k)
{   
    while(abs(x)>1)           // does not work if both x nd k are negative,, but is fastest
    {
        if(x%k!=0)
         return false;

        x=x/k; 
    }
    /*
    ll val=1;
    int count=0;
    while(abs(val)<abs(x))   // to check for negative like ispow(-9,-3)
    {
        val=val*k;
        count++;
    }
    if(val==x)
     return true;
     else
     {
         return false;
     }*/

   

     return true;
     
}




string gives(string s,int i)
{  if(i==s.length())
         return reversee(s);


         string dum,ss="";
         dum=reversee(s.substr(0,i));
         dum=dum+s.substr(i);

         string fs=gives(dum.substr(1),i);
         return dum.substr(0,1)+fs;
}


int no_of_common_ones_inxor(int x,int y)
{   int count=0;
    for(int i=31;i>=0;i--)
    { bool b1= x&(1<<i);
      bool b2= y&(1<<i);
      int num=(b1&b2)?0:(b1|b2);
      if(num==1)
      count++;
}

    return count;
}



void givesubstrings(string s,vector<string>* v)
{
    ll l=s.length();
    for(ll sl=1;sl<=l;sl++)
       for(ll i=0;i<=l-sl;i++)
           v->push_back(s.substr(i,sl));
}

void givesubsequence(string s,vector<string>* v)
{
    if(s.length()==1)
    {
        v->push_back(s);
        return;}

    
    givesubsequence(s.substr(1),v);

    ll a=v->size();

    for(ll i=0;i<a;i++)
    {
        string p= s[0]+v->at(i);
        v->push_back(p);
    }

    v->push_back(s.substr(0,1));

}

ll power(ll x, ll y, ll p) 
{ 
    ll res = 1;      
    x = x % p;  
  
    while (y > 0) 
    { 
       
        if (y & 1) 
            res = (res*x) % p; 
  
        
        y = y>>1; 
        x = (x*x) % p; 
    } 
    return res; 
}

ll modInverse(ll n, ll p) 
{ 
    return power(n, p-2, p); 
} 

ll nCrModPFermat(ll n, ll r, ll p) 
{ 
   // Base case 
   if (r==0) 
      return 1; 
  
    
    ll fac[n+1]; 
    fac[0] = 1; 
    for (ll i=1 ; i<=n; i++) 
        fac[i] = fac[i-1]*i%p; 
  
    return (fac[n] % p* modInverse(fac[r], p) % p * modInverse(fac[n-r], p) % p) % p; 
}




  

int main()
{  
  ios_base::sync_with_stdio(false);
  cin.tie(0);cout.tie(0);
  ll t;
  
  
  t=1;
  while(t--)
  {  
      ll a,b;
      cin>>a>>b;
      cout<<no_of_common_ones_inxor(a,b);
     
     
  }

  return 0;
 
 
}



/*
 ll x,y;
      cin>>x>>y;
      if(x==2)
      {cout<<"bb"<<endl;
      continue;}
      
      
      ll a=x-2,b=2;
      
      ll p_b1=x-2,p_b2=x-1;
      
      
      
      for(int i=2;i<=y;i++)
      {
        if(p_b2-p_b1==1) {p_b1--;p_b2=x-1;}
        else
        p_b2--;
       
      }
      
      string ans;
      for(int i=0;i<x;i++)
      {
          if(i==p_b1 || i==p_b2) ans+='b';
          else ans+='a';
          
      }
      
      cout<<ans<<endl;
    
  }*/