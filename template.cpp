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

void allSum(ll arr[], ll n,vector<ll>* v)
{ if(n==0)
  {
   return;
  }
   allSum(arr+1,n-1,v);
  ll size=v->size();
  for(ll k=0;k<size;k++)
  {
      v->push_back(v->at(k)+arr[0]);
      
  }

  v->push_back(arr[0]);


}

bool checkPow(ll x,ll k)
{   
   /* while(abs(x)>1)
    {
        if(x%k!=0)
         return false;

        x=x/k; 
    }*/
    ll val=1;
    int count=0;
    while(abs(val)<abs(x))
    {
        val=val*k;
        count++;
    }
    if(val==x)
     return true;
     else
     {
         return false;
     }
     
}

string reversee(string s)
     {
         if(s.length()==0)
         return "";

         string ans= reversee(s.substr(1))+s.substr(0,1);
         return ans;

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
    

int main()
{   

  

//cout<<checkPow(9,-3);

  /*  cin>>n>>k;


 vector<ll> v;
 int* arr = new int[n];
    // cout<<v.size();
     fori(n) cin>>arr[i];
      int x=0;
     allSumadj(arr,n,&v,&x);

     delete[] arr;

    // //cout<<v.size()<<endl;
    // for(int i=0;i<v.size();i++)
    // cout<<v.at(i)<<" ";

    // cout<<endl;

   /* unordered_map<ll,ll> m;
    unordered_map<ll,ll> ::iterator it;
    for(int i=0;i<v.size();i++)
    {
        m[v.at(i)]++;
    }
    ll sum=0;
    for(it=m.begin();it!=m.end();++it)
    {
        // cout<<it->first<<" "<<it->second<<endl;
        if(it->first==1 || checkPow(it->first,k))
        sum=sum+it->second;
    }

    cout<<sum;
    //cout<<checkPow(2,2);
    cout<<v.size();
    ll sum=0;
    for(int i=0;i<v.size();i++)
    {    //cout<<v.at(i)<<" ";
        if(v.at(i)==1 || checkPow(v.at(i),k))
        sum++;
    }
    cout<<sum;
    stack<char> q;
    vector<int> index,small;
    string s;
    int op=0,sml=0;
    bool b= true;
    cin>>s;
    ll l=s.size();
    int arr[l];
    fori(l)
    arr[i]=0;

    fori(l)
    {
        if(s[i]==')')
        {   
            if(q.size()!=0 && q.top()=='(')
            { 
              if(b==true || index.size()==0)
              op++;

              q.pop();
              b=false;
              index.push_back(i);
              index.push_back(i+1);

              sml=+2;
            }
            else
            {   if(sml!=0)
                small.push_back(sml);
               
                q.push(s[i]);
                b=false;
                sml=0;
              
            }
            

        }
        else
        {   if(sml!=0)
            small.push_back(sml);

            b=true;
            q.push(s[i]);
            sml=0;
        }
        


    }

    cout<<op<<endl;

   for(int i=0;i<small.size();i++)
    cout<<small[i]<<" ";

    if(small.size())
    cout<<endl;

    for(int i=0;i<index.size();i++)
    cout<<index[i]<<" ";

   ll n,m,p;
   bool x=false;
   cin>>n>>m>>p;
   ll arr[n],arr1[m],prod[n][m];
   vector<int> id1,id2;
   for(ll i=n-1;i>=0;i--)
   {
       cin>>arr[i];
       if(arr[i]%p==0)
       id1.push_back(i);
   }

   for(ll i=m-1;i>=0;i--)
   {
       cin>>arr1[i];
       if(arr1[i]%p==0)
       id2.push_back(i);
   }

   for(ll i=n-1;i>=0;i--)
    {   for(ll j=m-1;j>=0;j--)
     {
         ll prod[i+j]=arr[i]*arr1[j];
         
     }*/

     ll t;
     cin>>t;
     while(t--)
     {

     

    string s;
    int rr=0;
    cin>>s;
    int l=s.length();
    for(int a=0;a<l;a++)
    {
        prev+prev;
    }
    for(int i=1;i<=l;i++)
    {
        string ans=gives(s,i);
     //   cout<<ans<<endl;
        if(prev.compare(ans)>0)
        {prev=ans; rr=i;}
    }

    cout<<prev<<endl;
   cout<<rr<<endl;
       
     }
    return 0;
    
}