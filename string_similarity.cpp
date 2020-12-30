#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
 
#define ll long long
#define ld long double
ll const N=1e5+5;
ll const INF=8223372036854775807;
 
#define pb push_back
#define popb pop_back()
#define pf push_front
#define popf pop_front()
#define si size()
#define be begin()
#define en end()
#define all(v) v.be, v.en
#define len length()
#define mp make_pair
#define mt make_tuple
#define umap unordered_map
#define uset unordered_set
#define acc(v) accumulate(all(v), 0)
#define F first
#define S second

typedef pair<ll,ll> pll;
 
#define forz(i, n) for (ll i = 0; i < n; i++)
#define fore(i, m, n) for (ll i = m; i <= n; i++)
#define rforz(i, n) for (ll i = n - 1; i >= 0; i--)
#define rfore(i, m, n) for (ll i = n; i >= m; i--)
#define deci(n) fixed << setprecision(n)
#define high(n) __builtin_popcount(n)
#define highll(n) __builtin_popcountll(n)
#define parity(n) __builtin_parity(n)
#define ctz(n) __builtin_ctz(n)
#define lb lower_bound
#define ub upper_bound
#define er equal_range
#define maxe *max_element
#define mine *min_element
#define mod 1000000007
#define mod2 998244353
#define PI 3.1415926535
#define gcd __gcd
#define prag ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
 
#define endl "\n"
#define p0(a) cout << a << " "
#define p1(a) cout << a << endl
#define p2(a, b) cout << a << " " << b << endl
#define p3(a, b, c) cout << a << " " << b << " " << c << endl
#define p4(a, b, c, d) cout << a << " " << b << " " << c << " " << d << endl


//nCr= n-1Cr-1+ n-1Cr


 
// this gives us depth of each node, size of each subtree
// vector<ll> adj[N];

// long long depth[N],sizz[N],size1[N];
// bool visited[N]={false};
// long long clr[N];
 
// void bfs(ll s,ll p){
//     sizz[s]=1;
//     visited[s]=true;
//     for(auto x:adj[s]){
//         if(x==p){
//             continue;
//         }
//             depth[x]=depth[s]+1;
//             if(visited[x]==false) bfs(x,s);
//             sizz[s]=sizz[s]+sizz[x];
        
//     }
// }



bool issub(string p,string q)
    {   ll it=0;
        forz(i,p.len)
        {
            if(p[i]==q[it])
            it++;

            if(it==q.len) return true;
        }

        return false;
    }



void solve(ll* arr,ll sii,ll ei,ll op)
{
    if(sii>ei) return;

    ll siz=(ei-sii)+1;
    ll id=(ei+sii)/2;

    arr[id]=op;

    if(siz%2==1)
     {solve(arr,sii,id-1,op+1);
     solve(arr,id+1,ei,op+2);}
     else
     {
         solve(arr,id+1,ei,op+1);
         solve(arr,sii,id-1,op+2);
     }


}

bool grater(pair<ll,ll> p1,pair<ll,ll> p2)
{
    if(p2.S-p2.F<p1.S-p1.F) return true;
    else if(p2.S-p2.F==p1.S-p1.F)
    { 
        if(p1.F<p2.F)  return true;
        else return false;
    }
    else return false;
        
}

/// used for internal sorting in minpriority queue
template <class pll> struct greatter : binary_function <pll,pll,bool> {
  bool operator() (const pll& p1, const pll& p2) const 
  {
    if(p2.S-p2.F>p1.S-p1.F) return true;
    else if(p2.S-p2.F==p1.S-p1.F)
    { 
        if(p1.F>p2.F)  return true;
        else return false;
    }
    else return false;
  
  
  
  }
};





ll func(string s1,string s2)
{
  ll i=0;
  while(i<s1.len && i<s2.len && s1[i]==s2[i]) 
  i++;

  return i;

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



// ll nCrModPFermat(ll n, ll r, ll p) 
// { 
//    // Base case 
//    if (r==0) 
//       return 1; 
  
    
//     ll fac[n+1]; 
//     fac[0] = 1; 
//     for (ll i=1 ; i<=n; i++) 
//         fac[i] = fac[i-1]*i%p; 
  
//     return (fac[n] % p * modInverse(fac[r], p) % p* modInverse(fac[n-r], p) % p) % p; 
// }

vector<int> prefArr(string s)
{
   int n=s.length();
   vector<int> ans(n);
   ans[0]=0;
   
   for(int i=1;i<n;i++)
   {  
     
       ll j=ans[i-1];

       while(j>0 && s[i]!=s[j])
       j=ans[j-1];

       if(s[i]==s[j])
       j++;
       ans[i]=j;
   }

   return ans;
}

vector<int> Zarray(string s)
{
    int le = s.size();
    vector<int> z(le);
   
    z[0]=le;
    
    
    int left = 0, right = 0;
    for (int i = 1; i < le; i++) {
      if (i > right) {
        left = right = i;
        while (right < le and (s[right] == s[right - left]))
          right++;
        z[i] = right - left;
        right--;
      } else {
        int k = i - left; // do a mistake here.
        if (z[k] < (right - i + 1)) {
          cout<<k<<" ";
          z[i] = z[k];
        } else {
          left = i;
          while (right < le and (s[right] == s[right - left]))
            right++;
          z[i] = right - left;
          right--;
        }
      }

       //cout<<i<<" "<<left<<" "<<right<<" "<<z[i]<<" "<<s.substr(left,right-left+1)<<endl;
}

return z;

}



int main()
{
  int t;
  cin >> t;
  string s;
  while (t--)
   {
    cin >> s;
    vector<int> ans1,ans2;
    ans1=Zarray(s);
    ans2=prefArr(s);

    forz(i,ans1.size()) p0(ans1[i]); cout<<endl;
    forz(i,ans2.size()) p0(ans2[i]); cout<<endl;
    
       
     

   
  }
}
   
                       
 
 ////////////////
 #include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
 
#define ll long long
#define ld long double
ll const N=1e5+9;
ll const INF=8223372036854775807;
ll const INFF=2147483647;
 
#define pb push_back
#define popb pop_back()
#define pf push_front
#define popf pop_front()
#define si size()
#define be begin()
#define en end()
#define all(v) v.be, v.en
#define len length()
#define mp make_pair
#define mt make_tuple
#define umap unordered_map
#define uset unordered_set
#define acc(v) accumulate(all(v), 0)
#define F first
#define S second

typedef vector<int> vi;
typedef vector<ll> vl;
typedef pair<ll,ll> pll;
typedef pair<ll,pll> plll;


 
#define forz(i, n) for (ll i = 0; i < n; i++)
#define fore(i, m, n) for (ll i = m; i <= n; i++)
#define rforz(i, n) for (ll i = n - 1; i >= 0; i--)
#define rfore(i, m, n) for (ll i = m; i >= n; i--)
#define deci(n) fixed << setprecision(n)
#define high(n) __builtin_popcount(n)
#define highll(n) __builtin_popcountll(n)
#define parity(n) __builtin_parity(n)
#define ctz(n) __builtin_ctz(n)
#define lb lower_bound
#define ub upper_bound
#define er equal_range
#define maxe *max_element
#define mine *min_element
#define mod 1000000007
#define mod2 998244353
#define PI 3.1415926535

#define gcd __gcd
#define prag ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
 
#define endl "\n"
#define p0(a) cout << a << " "
#define p1(a) cout << a << endl
#define p2(a, b) cout << a << " " << b << endl
#define p3(a, b, c) cout << a << " " << b << " " << c << endl
#define p4(a, b, c, d) cout << a << " " << b << " " << c << " " << d << endl







// GRAPHS

vector<ll> adj[N];

ll sizz[N],people[N],parent[N];
bool visited[N];
//rec[N],depth[N];
bool isCycle=false;
// ll clr[N];


 
void dfs(ll s,ll p){
    sizz[s]=people[s];
    parent[s]=p;
    visited[s]=true;
   
    for(auto x:adj[s]){
        if(x==p){
            continue;
        }
            
           
            
            if(visited[x]==false)
            {
        
           // depth[x]=depth[s]+1;
            dfs(x,s);
            sizz[s]=sizz[s]+sizz[x];

            }
           
        
    }
}
/*
void dfs2(ll s,ll p){
    sizz[s]=1;
    visited[s]=true;
    rec[s]=true;
   
    for(auto x:adj[s]){
       
            if(visited[x]==false)
            {
        
            depth[x]=depth[s]+1;
            dfs(x,s);
            sizz[s]=sizz[s]+sizz[x];

            }
            else if(rec[x]) isCycle=true;
           
        
    }
    rec[s]=false;
}
*/



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



/// used for internal sorting in minpriority queue
template <class pll> struct greatter : binary_function <pll,pll,bool> {
  bool operator() (const pll& p1, const pll& p2) const 
  {
    if(p2.S-p2.F>p1.S-p1.F) return true;
    else if(p2.S-p2.F==p1.S-p1.F)
    { 
        if(p1.F>p2.F)  return true;
        else return false;
    }
    else return false;
  }
};

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
   
   if (r==0) 
      return 1; 
  
    
    ll fac[n+1]; 
    fac[0] = 1; 
    for (ll i=1 ; i<=n; i++) 
        fac[i] = fac[i-1]*i%p; 
  
    return (fac[n] % p * modInverse(fac[r], p) % p* modInverse(fac[n-r], p) % p) % p; 
}




// ll dp[3605][8005];
// ll countsubsets(vector<ll> arr,ll ss, ll i,ll remsum)
// {
//    if(i==ss) 
//    {
//        if(remsum==0) return 1;
//        else return 0;
//    }

//    if(dp[i][remsum]!=-1) return dp[i][remsum];
//    else
//    {
//        dp[i][remsum]=countsubsets(arr,ss,i+1,remsum)+countsubsets(arr,ss,i+1,remsum-arr[i]);
//        return  dp[i][remsum];
//    }
   

// }

bool comp1(string ss1,string ss2)
{
    if(ss1+ss2 <= ss2+ss1) return true;
    else return false;
}



/*
void permute(vector<ll> vec, int l, int r)  
{  
    // Base case  
    if (l == r)  
        {
            int sans=0;
            for(int i=0;i<vec.si;i++)
            sans=sans*10+vec[i];
            
            fans+=sans;


        }  
    else
    {  
        // Permutations made  
        for (int i = l; i <= r; i++)  
        {  
  
            // Swapping done  
            swap(vec[l], vec[i]);  
  
            // Recursion called  
            permute(vec, l+1, r);  
  
            //backtrack  
            swap(vec[l], vec[i]);   
        }  
    }  
}
0*/ 

/*

void mkstring(string s,ll lth,ll idx)
{

    
        ll a=0;
        for(ll i=0;i<=lth-6;i++)
        {
                 if(s.substr(i,7)=="abacaba") a++;

        }

        if(a==1) {found=true; ans=s; return;}

        
       if(idx==lth) return;
   
    
    if(s[idx]=='?') 
    {
        for(char p='a';p<='c';p++)
        {
            s[idx]=p;
            mkstring(s,lth,idx+1);


            if(found) return;

        }
    }
    else
    {
         mkstring(s,lth,idx+1);
    }
    

     return;
 

}
*/
int binarys(vector<int> &A,int sii,int li,int val,int idx)
{
    if(sii>li) return idx;
    int mid=(sii+li)/2;
    
   
    if(A[mid]<=val)
    {  
       
        if(A[mid]==val) idx=mid;
        return binarys(A,mid+1,li,val,idx);
    }
    else if(A[mid]>val)
    {
     
        
        return binarys(A,sii,mid-1,val,idx);
    }
}

int findOverlappingPair(string str1, string str2, string &str) 
{ 
    // max will store maximum overlap i.e maximum 
    // length of the matching prefix and suffix 
    int max = INT_MIN; 
    int len1 = str1.length(); 
    int len2 = str2.length(); 
  
    // check suffix of str1 matches with prefix of str2 
    for (int i = 1; i <= min(len1, len2); i++) 
    { 
        // compare last i characters in str1 with first i 
        // characters in str2 
        if (str1.compare(len1-i, i, str2, 0, i) == 0) 
        { 
            if (max < i) 
            { 
                //update max and str 
                max = i; 
                str = str1 + str2.substr(i); 
            } 
        } 
    } 
  
    // check prefix of str1 matches with suffix of str2 
    for (int i = 1; i <= min(len1, len2); i++) 
    { 
        // compare first i characters in str1 with last i 
        // characters in str2 
        if (str1.compare(0, i, str2, len2-i, i) == 0) 
        { 
            if (max < i) 
            { 
                //update max and str 
                max = i; 
                str = str2 + str1.substr(i); 
            } 
        } 
    } 


    if(len1<len2)
    {
        for (int i = 0; i <= len2-len1; i++) 
        if(str2.substr(i,len1)==str1)
        {
            if (max < len2) 
            { 
                //update max and str 
                max = len2; 
                str = str2; 
            } 
        }
    }
    else
    {
        for (int i = 0; i <= len1-len2; i++) 
        if(str1.substr(i,len2)==str2)
        {
            if (max < len1) 
            { 
                //update max and str 
                max = len1; 
                str = str1; 
            } 
        }
    }
    
  
    return max; 
} 




int main()
{
        prag;
        ll T=1;
        cin>>T;
        while(T--)
        {
            
           ll n,k,p;
           cin>>n;

           ll arr[n][n];
           ll vec[n];

           forz(i,n) cin>>vec[i];

           memset(arr,0,sizeof(arr));

           for(ll i=0;i<n;i++)
           {
               for(ll j=i+1;j<n;j++)
               {
                   arr[i][j]=vec[i]+vec[j];
               }
           }

          umap<ll,ll> mp1;
          for(ll i=0;i<n;i++)
          {
              
              for(ll j=i+1;j<n;j++)
              {
                  
              }
          }

          ll ans=0,mx=INT_MIN;

          for(auto it=mp1.begin();it!=mp1.end();it++)
          {
              if(it->S > mx && it->F > 0)
              {
                  mx=it->S;
                  
              }
          }

          p1(mx);


          }


           
return 0;

}
