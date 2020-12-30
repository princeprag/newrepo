#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main()
{
int tt;
cin>>tt;
while(tt--){
    int n;
    cin>>n;
    ll x;
    cin>>x;
    vector <ll> v(n);
    for(int i=0;i<n;++i)cin>>v[i];
    
    //First step Sort the array.
    
    sort(v.begin(),v.end());
    
    int ans=0;
    int i=-1;
    int cnt=0;
    // cnt is the counter of number of countries already cured.
    while(i+1<n){
        //finding the right position for x i.e a[i] <= x < a[i+1].
        if(x>=v[i+1]){
            i++;
            continue;
        }
        // If v[i]*2>x we deliver to country i.
        if(i>=0&&(v[i]*2)>x){
            x=v[i]*2;
            cnt++;
            ans++;
            continue;
        }
        // If next element is the last one we keep on delivering it.
        if((i+1)==(n-1)){
            while(x<v[n-1]){
                x=x*2;
                ans++;
            }
            cnt++;
            ans++;
            break;
        }
        //To double x we deliver last element
        if((i+1)!=(n-1)&&x<=v[n-1]/2){
            x*=2;
            ans++;
            continue;
        }
        //We just take (remaining countries+1) days more in this condition.  
        if((i+1)!=(n-1)&&x>v[n-1]/2){
            ans++;
            break;
        }
    }
    ans+=(n-cnt);
    cout<<ans<<endl;
}
return 0;
} 