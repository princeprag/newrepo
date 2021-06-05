#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
 
#define ll long long
#define ld long double
//ll const N=1e5+9;
ll const MAX=200009;
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

#define mod3 998244353
/*
ll fcnt=0;
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

void GraphAlgo(vector<vector<ll>> vec, ll M, ll N)
{
    bool visited[M][N];
    forz(i,M) 
    {
      forz(j,N) 
      {
         visited[i][j]=false;
         cout<<vec[i][j]<<" ";
      }
      cout<<endl;
     

     }

    ll total=0;
        

    forz(i,M)
    {
        forz(j,N)
        {
             if(visited[i][j]) continue;

             total++;

             queue<pair<ll,ll>> pq;
             pq.push(mp(i,j));
             while(!pq.empty())
             {
                 pair<ll,ll> cc=pq.front();
                 pq.pop();
                 ll X=cc.F,Y=cc.S;
                 visited[X][Y]=true;

                 if(X+1<M && vec[X+1][Y]<=vec[X][Y] && !visited[X+1][Y])  pq.push(mp(X+1,Y));
                 if(Y+1<N && vec[X][Y+1]<=vec[X][Y] && !visited[X][Y+1])  pq.push(mp(X,Y+1));
                 if(X-1>=0 && vec[X-1][Y]<=vec[X][Y] && !visited[X-1][Y])  pq.push(mp(X-1,Y));
                 if(Y-1>=0 && vec[X][Y-1]<=vec[X][Y] && !visited[X][Y-1])  pq.push(mp(X,Y-1));


             }

            
           
        }
    }

   // cout<<total<<" ";

    fcnt+=total;
   
}



void func(vector<vector<ll>> vec, int M, int N, int i, int j,int K)
{      
      if(i==M)
      {
          GraphAlgo(vec,M,N);
          return;
      }   

       for(ll y=1;y<=K;y++)
       {
            vec[i][j]=y;
            ll ni=i,nj=j+1;
            if(nj==N)
            {
                nj=0;
                ni++;
            }
            func(vec,M,N,ni,nj,K);

       }
}


*/


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

bool contains(ll p,ll d)
{
    while(p)
    {
        ll j=p%10;
        if(j==d) return true;

        p/=10;
    }

    return false;
}

ll LCSubStr(string X, string Y, ll m, ll n)
{
    
    ll LCSuff[m + 1][n + 1];
    ll result = 0;
 
    for (int i = 0; i <= m; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            
            if (i == 0 || j == 0)
                LCSuff[i][j] = 0;
 
            else if (X[i - 1] == Y[j - 1]) 
            {
                LCSuff[i][j] = LCSuff[i - 1][j - 1] + 1;
                result = max(result, LCSuff[i][j]);
            }
            else
                LCSuff[i][j] = 0;
        }
    }
    return result;
}


int main()
{

   prag;
   
   ll T;
   cin>>T;
   while(T--)
   {

    ll n;
    cin>>n;
    bool b[n],c[n];
    ll arr[n],mx[n],mn[n];

    forz(i,n)
    {
        cin>>arr[i];
        mx[i]=-1;
        mn[i]=-1;
        b[i]=false;
        c[i]=false;
    }

    forz(i,n)
    {
        if(i==0) {mx[i]=arr[i]; mn[i]=arr[i]; b[arr[i]-1]=true; c[arr[i]-1]=true;}
        else
        {
             if(arr[i]!=arr[i-1])
             {
                 mx[i]=arr[i];
                 mn[i]=arr[i];
                 b[arr[i]-1]=true;
                 c[arr[i]-1]=true;

             } 
        }
    }

    ll num=1;
    forz(i,n)
    {
        while(b[num-1]==true) num++;

        if(mn[i]==-1)
        {
            mn[i]=num;
            b[num-1]=true;
            
        }
          
    }

    set<ll> se;
    forz(i,n)  if(!c[i]) se.insert(i+1);

    forz(i,n)
    {
        if(mx[i]==-1)
        {
            ll mnum=arr[i];
            cout<<mnum<<" ";
            auto it = se.lower_bound(mnum);

            
          
          
            if(it!=se.begin()) {it--;}

            
           
           
            mx[i]= *it;
            se.erase(*it);



        }

    }
    

    

    forz(i,n) p0(mn[i]); 
    cout<<endl;
    forz(i,n) p0(mx[i]); 
    cout<<endl;


     
    


   }


}
