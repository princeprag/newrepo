#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
 
#define ll long long
#define ld long double
ll const N=1e5+9;
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

typedef vector<ll> vi;
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

ll func(ll a[], ll size)
{
   ll max_so_far = INT_MIN, max_ending_here = 0; 
   for (ll i = 0; i < size; i++) 
   { 
       max_ending_here = max_ending_here + a[i]; 
       max_so_far=max(max_so_far,max_ending_here);
   }
   return max_so_far; 
  


}

ll maxSubArraySum(ll a[], ll size) 
{ 
   ll max_so_far = 0, max_ending_here = 0; 
   for (ll i = 0; i < size; i++) 
   { 
       max_ending_here = max_ending_here + a[i]; 
       if (max_ending_here < 0) 
           max_ending_here = 0; 
  
       
       else if (max_so_far < max_ending_here) 
           max_so_far = max_ending_here; 
   } 
   return max_so_far; 
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




int main()
{

        prag;
        ll T=1;
        cin>>T;
       
        while(T--)
        {
           ll n,m;

           cin>>n;
           ll a[n];
           forz(i,n) cin>>a[i];

           cin>>m;

           ll b[m];
           forz(i,m) cin>>b[i];


           ll ans1=func(a,n);
           ll ans2=func(b,m);

           if(ans1<0) ans1=0;
           if(ans2<0) ans2=0;

           cout<<ans1+ans2<<endl;


       
           
                 
        }
        return 0;

 
}

