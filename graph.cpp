#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
 
#define ll long long
#define ld long double
ll const N=1e6+5;
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
#define gcd __gcd
#define prag ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
 
#define endl "\n"
#define p0(a) cout << a << " "
#define p1(a) cout << a << endl
#define p2(a, b) cout << a << " " << b << endl
#define p3(a, b, c) cout << a << " " << b << " " << c << endl
#define p4(a, b, c, d) cout << a << " " << b << " " << c << " " << d << endl


 
// this gives us depth of each node, size of each subtree
vector<ll> adj[N];

long long depth[N],sizz[N],parent[N];
bool visited[N]={false};
long long clr[N];
 
void bfs(ll s,ll p){
    sizz[s]=1;
    visited[s]=true;
    parent[s]=p;
    for(auto x:adj[s]){
        if(x==p){
            continue;
        }
            depth[x]=depth[s]+1;
            if(visited[x]==false) bfs(x,s);
            sizz[s]=sizz[s]+sizz[x];
        
    }
}

int main()
{
ll T;
T=1;
while(T--)
{

    ll v,n,x,y,r,c;
    vector<ll> vec;
    char p;
    cin>>r>>c;

    char arr[r][c];

    forz(i,r) forz(j,c) cin>>arr[i][j];
    bool flag=false,awc=false,awr=false;




   
    ll counter=1,tc=0,wc=0,cnt=0;
    forz(i,r) 
     {
      forz(j,c)
        { 
          if(arr[i][j]=='#')
          {   
              cnt++;
              vec.pb(counter);
              if(i+1<r && arr[i+1][j]=='#')
              {
                  adj[counter].pb(counter+c); 
                  adj[counter+c].pb(counter);

              }

              if(j+1<c && arr[i][j+1]=='#')
              {
                  adj[counter].pb(counter+1); 
                  adj[counter+1].pb(counter);

              }
          }
          else
          {
              if(tc==0 && cnt>0) tc++;
              else if(tc==1 && cnt>0) flag=true;
              cnt=0;
              wc++;
          }
          

           counter++;
        }

        if(tc==1 && cnt>0) flag=true;

        // if(flag) p1("True");
        // else p1("False");

        if(wc==c) awc=true;
        if(flag) break;
               cnt=0;
               tc=0;
               wc=0;

    }
     
     cnt=0,wc=0,tc=0;
     forz(j,c)
      {  forz(i,r) 
          {
              if(arr[i][j]=='#') cnt++;
              else
              {
                  if(tc==0 && cnt>0) tc++;
                  else if(tc==1 && cnt>0) flag=true;
                  cnt=0;
                  wc++;
              }

              
              
        }
               if(tc==1 && cnt>0) flag=true;
               if(wc==r) awr=true;
                // if(flag) p1("True");
                //  else p1("False");

            if(flag) break;
               cnt=0;
               tc=0;
               wc=0;


     }

    //  p3(flag,awc,awr);
      if(flag || (awr&&!awc) || (!awr&&awc)) {p1(-1); continue;}

    //  forz(i,N)
    //  {     
    //        if(adj[i].si>0) cout<<i<<":";
    //        forz(j,adj[i].si) p0(adj[i][j]);
    //        if(adj[i].si>0) cout<<endl;

    //  }

    //    forz(i,vec.si) p0(vec[i]);
    //    if(vec.si>0) cout<<endl;


       ll cntt=0;
       forz(i,vec.si)
       {  
          if(visited[vec[i]]==false) {bfs(vec[i],0); cntt++;}
       }

       p1(cntt);


    
}

}