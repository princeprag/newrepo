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


int isPalindrome(int A) {
    string s=to_string(A);
    string copy=s;
    reverse(s.begin(),s.end());
    if(s==copy)
    return 1;
    else
    return 0;
    
}

ll fact(ll n,ll MOD)
{
    if(n==0 || n==1)
    return 1;
    return  ((n%MOD)*(fact(n-1,MOD)%MOD))%MOD;
}

ll poww(ll x,ll y,ll MOD)
{  ll ans=1;
   while(y)
   {
      if(y%2==1)  ans=(ans%MOD*x%MOD)%MOD;
     
      x=(x%MOD*x%MOD)%MOD;

      y/=2;
   }
    
    return ans%MOD;
}

ll modi(ll a,ll MOD){
    return poww(a,MOD-2,MOD);
}

// ll gcd(ll a,ll b)
// {   
//     if(a==0)
//     return b;
//     if(a>b) return gcd(a%b,b);
//     else  return gcd(b%a,a);
// }

ll lcm(ll a,ll b){ 
    return (a*b)/(gcd(a, b));
}
 
ll max(ll a,ll b){
    if(a>b){
        return a;
    }else{
        return b;
    }
}
 
ll min(ll a,ll b){
    if(a<b){
        return a;
    }else{
        return b;
    }
}

ll nCr(ll n,ll k){ 
    ll C[n + 1][k + 1]; 
    ll i, j; 
    for(i=0;i<=n;i++){ 
        for(j=0;j<=min(i,k);j++){
            if(j==0||j==i){
                C[i][j]=1;  
            }else{
                C[i][j]=C[i-1][j-1]+C[i-1][j]; 
            }
        } 
    }
    return C[n][k]; 
}

int giveno(vector<int> v)
{
    int ans=0;
    for(int i=0;i<v.size();i++)
    ans = ans*10+v[i];

    return ans;

}

ll solve(ll r,ll m,ll b)
{      ll an= r/m;
       ll cor= min(r,an*m+b-1)-(an*m)+1;
       ll tot=((r/m)-1)*b+cor+b-1;

       return tot;

}

bool cc(string A,string B)
  {return A.length()>B.length();}

ll solve(ll** arr,bool** visited,ll dcount,ll i,ll j,ll m,ll n)
{    

     dcount++;
     visited[i][j]=true;
     if(i<m-1)
     {
         if(arr[i+1][j]== -1) {arr[i+1][j]=dcount; }
     }
     
     if(i>0)
     {
         if(arr[i-1][j]== -1) {arr[i-1][j]=dcount; }
     }

     if(j<n-1)
     {
         if(arr[i][j+1]==-1) {arr[i][j+1]=dcount;}
     }

     if(j>0)
     {
         if(arr[i][j-1]==-1) {arr[i][j-1]=dcount;}
     }

}

vector<ll> res;
///generates a no of 18 digits or less having not more than 3 non zero digits
void gen(int pos, int cnt, long long cur){
    if (pos == 18){
        res.push_back(cur);
        return;
    }
    
    gen(pos + 1, cnt, cur * 10);
    
    if (cnt < 3)
        for (int i = 1; i <= 9; ++i)
            gen(pos + 1, cnt + 1, cur * 10 + i);
}

bool func(pair<ll,ll>a,pair<ll,ll> b)
{
    return (a.S-a.F)>(b.S-b.F);
}


int main()
{ prag;
  ll t;
  t=1;
  while(t--)
  {
      ll a,b,c,d;
      cin>>a>>b;

      
      vector<pair<ll,ll>> lm[a+1];
      
      forz(i,b)
      {
          ll a,b;
          cin>>a>>b;
          if(a>b) swap(a,b);
          ll j=b-a+1;
          lm[j].pb(mp(a,b)); 
         
      }

      umap<ll,bool> map1;
      ll cnt=0;
     
      rforz(i,a+1)
      {
         forz(j,lm[i].si)
         {
             pair<ll,ll> p=lm[i][j];
             
            

             if(map1.count(p.F)==0 && map1.count(p.S)==0)
             {  
                 cnt++;
                 for(ll i=p.F;i<=p.S;i++) map1[i]=true;
             }
             else if(map1.count(p.F)==0 && map1.count(p.S)!=0)
             {   ll i;
                 for(i=p.S;i>=p.F;i--)  if(map1.count(i)==0) break;

                 if(i>=p.F) lm[i-p.F+1].pb(mp(p.F,i));
             }
             else if(map1.count(p.F)!=0 && map1.count(p.S)==0)
             {   ll i;
                 for(i=p.F;i<=p.S;i++)  if(map1.count(i)==0) break;

                 if(i<=p.S) lm[p.S-i+1].pb(mp(i,p.S));
             }
            else if(map1.count(p.F)!=0 && map1.count(p.S)!=0)   
            {
                 ll i;
                 for(i=p.F;i<=p.S;i++)  if(map1.count(i)==0) break;
                 
                 ll j;
                 for(j=p.S;j>=p.F;j--)  if(map1.count(j)==0) break;

                 if(i<=j) lm[j-i+1].pb(mp(i,j));


                
                 
            }  

            if(cnt==b-2) break;     

         }

         lm[i].clear();

         if(cnt==b-2) break; 


      }

     // forz(i,lm[1].si) p0(lm[1][i].F);

      cout<<map1.si<<endl;

     for(auto it=map1.begin();it!=map1.end();it++) p0(it->first);
      


     
      
  }
      
      
    
  return 0;
}
