#include<bits/stdc++.h>
#include<vector>
#include<string>
#include<stack>
#include<map>
#include<queue>
#define ub upper_bound
#define lb lower_bound
#define pb push_back
//#define for(i,n) for(ll i=0;i<n;i++)
#define ll long long
using namespace std;

class Compare
{
             public:
             bool operator() (pair<int,int> p1, pair<int,int> p2)
             {
                if(p1.first<p2.first) return true;
                else if(p1.first>p2.first) return false;
                else if(p1.first==p2.first)
                {
                    if(p1.second>p2.second) return true;
                    else return false;
                }
             }
 };

 int main()
 {
     vector<int> tt;
     tt.push_back(2);
     tt.push_back(2);
     tt.push_back(2);
     tt.push_back(2);
     cout<<tt.size()<<endl;
     tt.pop_back();
     cout<<tt.size()<<endl;
 }
           