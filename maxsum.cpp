#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
 
#define ll long long
#define ld long double
ll const N=1e6+5;
ll const INF=8223372036854775807;
ll const M=200000;
 
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
#define gcd __gcd
#define prag ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
 
#define endl "\n"
#define p0(a) cout << a << " "
#define p1(a) cout << a << endl
#define p2(a, b) cout << a << " " << b << endl
#define p3(a, b, c) cout << a << " " << b << " " << c << endl
#define p4(a, b, c, d) cout << a << " " << b << " " << c << " " << d << endl
const int P=2e5+7;
    
vector<ll> adj[P];
ll depth[P]={0},sizz[P]={0},size1[P]={0};


bool co(ll a,ll b)
{
    return a>b;
}



void bfs(ll s,ll p){
    sizz[s]=1; 
    depth[s]=depth[p]+1;
    for(auto x:adj[s]){
        if(x==p){
            continue;
        }
            depth[x]=depth[s]+1;
            bfs(x,s);
            sizz[s]=sizz[s]+sizz[x];
        
    }
}

ll solve(vector<ll> arr1,vector<ll> arr2,ll val)
{
    ll big_i=lb(arr2.begin(),arr2.end(),val)-arr2.begin();
    ll small_i=lb(arr1.begin(),arr1.end(),val)-arr1.begin();
    if(arr1[small_i]>val && small_i>0) small_i--;

    return pow(arr2[big_i]-val,2)+pow(arr1[small_i]-val,2)+pow(arr2[big_i]-arr1[small_i],2);

}

int main() {
	prag;
	ll q;
    cin>>q;
    while(q--)
    {
        ll r,g,b;
        vector<ll> red,green,blue;
        cin>>r>>g>>b;
        forz(i,r)
        {
            ll p; cin>>p; red.pb(p);
        }
        forz(i,g)
        {
            ll p; cin>>p; green.pb(p);
        }
        forz(i,b)
        {
            ll p; cin>>p; blue.pb(p);
        }

        sort(red.begin(),red.end());
        sort(green.begin(),green.end());
        sort(blue.begin(),blue.end());


        ll ans=LLONG_MAX;

        forz(i,green.si)
       {  ans=min(ans,solve(red,blue,green[i]));
          ans=min(ans,solve(blue,red,green[i]));
       } 

        forz(i,blue.si)
       {  ans=min(ans,solve(green,red,blue[i]));
          ans=min(ans,solve(red,green,blue[i]));
       } 

        forz(i,red.si)
       {  ans=min(ans,solve(green,blue,red[i]));
          ans=min(ans,solve(blue,green,red[i]));
       }    

          cout<<ans<<endl;

        }

       
    
    
       
       


    }

           
            
     return 0;

    }

            
            
            
          
            
        
        
       
     
      
     
       

       
   
