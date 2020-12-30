#include<bits/stdc++.h> 
#define ll long long
#define N 200005
using namespace std; 


int power(ll x, ll y, ll p) 
{ 
	ll res = 1;	

	x = x % p; 

	while (y > 0) 
	{ 
	
		if (y & 1) 
			res = (res*x) % p; 

		
		y = y>>1; // y = y/2 
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

	return (fac[n]* modInverse(fac[r], p) % p * 
			modInverse(fac[n-r], p) % p) % p; 
} 

ll fact[N],inversefac[N];
void solve(ll n, ll p)
{
	
	fact[0]=1;
	for (ll i=1 ; i<=n; i++) 
	fact[i] = (fact[i-1]%p * i%p)%p; 

	inversefac[n]=modInverse(fact[n],p)%p;
	for(ll i=n-1;i>=1;i--)
	inversefac[i]=(inversefac[i+1]%p * (i+1)%p)%p;


}

ll nCr(ll n, ll r,ll p)
{
	//cout<<endl<<fact[n]<<" "<<inversefac[r]<<" "<<inversefac[n-r]<<endl;
	return (fact[n] % p  * (inversefac[r] % p * inversefac[n-r] % p) % p)%p; 
}

int main() 
{ 
	// p must be a prime greater than n. 
	int n, r, p = 1000000007; 
	cin>>n>>r;
	solve(n,p);
	cout << "Value of nCr % p is "
		<< nCrModPFermat(n, r, p) <<" "<<nCr(n,r,p); 
	return 0; 
} 
