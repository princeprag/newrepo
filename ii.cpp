#include <bits/stdc++.h>
using namespace std;
//IDEA-if a[n]=1,4,2,3,1,1,2,3,4,2,3->count all similar no..1,2,3,4,....n,1,2,3...n-1,....
int main()
{
int n;
cin>>n;
int a[n];
for(int i=0;i<n;i++)cin>>a[i];
sort(a,a+n);int t=1;
vector<int>v;
for(int i=0;i<n-1;i++){
    if(a[i+1]==a[i]){
        t++;
    }
    else  {
        v.push_back(t);
        t=1;
    }
}
v.push_back(t);
sort(v.begin(),v.end());
//cout<<v[0]<<v[1]<<v.size();
int x;

x=v[0]*(v.size()-2)+1;
//if(v.size()>1)//28th line ka if statement htane se 30  line k karn n=4, a[n]=7,7,7,7 dene pe segmented fault kyu de rha hai
long long cnt=0;

for(int i=1;i<v.size()-2;i++){
    cnt++;
    cout<<cnt<<" ";
    x+=(v[i]-v[i-1])*(v.size()-2-i);
    
}

cout<<cnt<<endl;
if(n==1)cout<<"YES";
 else if(v.size()==1)cout<<"NO";
else if(x>=v[v.size()-1]-v[v.size()-2])cout<<"YES";
else cout<<"NO";
return 0;
}