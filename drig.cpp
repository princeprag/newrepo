#include <bits/stdc++.h> 
using namespace std; 
  
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
#define rep(i,n) for(int i=0;i<n;i++)
#define rep1(i,n) for(int i=1;i<n;i++)
#define repl(i,n) for(ll i=0;i<n;i++)
#define repl1(i,n) for(ll i=1;i<n;i++)
#define rev(i,n) for(int i=n-1;i>=0;i--)
#define revl(i,n) for(ll i=n-1;i>=0;i--)
#define repn(i,n) for(int i=0;i<=n;i++)
#define repln(i,n) for(ll i=0;i<=n;i++)
#define lb lower_bound
#define up upper_bound
#define pb push_back
#define Mod 1000000007

#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);

void solve(){
	
	int n;
	cin>>n;
	vector<ll> v(n);
	vector<ll> vec(n);
	// vec.push_back(INT_MAX);
	rep(i,n){
		cin>>v[i];
	}
	sort(v.begin(),v.end());
	ll temp=INT_MAX;
	rep(i,n-1){
		vec[i]=v[i+1]-v[i];
		vec[i]=min(vec[i],temp);
		temp=vec[i];
	}
	
// 	rep(i,n){
// 		vec[i+1]=min(vec[i],v[i]);
// 	}
	int ans=0;
	for(int i=n-1;i>0;i--)
    {
		if(v[i]<=vec[i-1]){
			ans=i;
			break;
		}
	}
	cout<<ans+1;
	
	return ;
}
int main(){
    fastio;
    int tc;
    // tc=1;
    cin>>tc;
    while(tc--){
    	solve();
    	if(tc) cout<<"\n";
    }
    
    return 0;
}