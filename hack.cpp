#include<bits/stdc++.h>
#include<vector>
#include<string>
#include<stack>
#include<map>
#include<queue>
#define ub upper_bound
#define lb lower_bound
#define pb push_back
#define forz(i,n) for(ll i=0;i<n;i++)
#define ll long long

#define endl "\n"
#define p0(a) cout << a << " "
#define p1(a) cout << a << endl
#define p2(a, b) cout << a << " " << b << endl
#define p3(a, b, c) cout << a << " " << b << " " << c << endl
#define p4(a, b, c, d) cout << a << " " << b << " " << c << " " << d << endl

using namespace std;

void initia(vector<vector<ll>> &A,  ll n, ll m)
{
      for(ll i=0;i<n;i++)
      {
         vector<ll> temp;
         for(ll j=0;j<m;j++)
         {
            temp.pb(rand()%10);
         }

         A.pb(temp);

      }


}


vector<vector<ll>> matrixMult(vector<vector<ll>> &A,vector<vector<ll>> &B,ll n1, ll m1, ll n2, ll m2)
{
     vector<vector<ll>> C;
     if(m1!=n2)
     {
        cout<<"The sizes do not match!!"<<endl;
        return C;
     }
     
     for(ll i=0;i<n1;i++)
     {   vector<ll> temp;
         for(ll j=0;j<m2;j++)
         {
            ll ans=0;
            for(ll k=0;k<m1;k++)
            {
                 ans+=(A[i][k]*B[k][j]);
            }

            temp.pb(ans);

         }

         C.pb(temp);
     }

     return C;

}
void displayM(vector<vector<ll>> &A, ll n, ll m)
{
     for(ll i=0;i<n;i++)
      {
        
         for(ll j=0;j<m;j++)
         {
               cout<<A[i][j]<<" ";
         }
         cout<<endl;
      }
}


int solvexxx(vector<int> &A, int B) {
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
           
           
            bool prime[100005];
            for(int i=0;i<100005;i++) prime[i]=true;

            for(int i=2;i*i<100005;i++)
            {
                if(prime[i])
                {
                    for(int p=i*i;p<100005;p=p+i)
                    {
                        prime[p]=false;
                    }
                }
            }
            
    map<int,int> se;
    vector<int> cnt;

    for(int i=0;i<A.size();i++)
    {
        int val=A[i];
      //   if(val==1)
      //   {
      //      cnt.push_back(0);
      //      continue;
      //   }



        if(se.find(val)==se.end())
        {
            int c=0;
            int dm=val;
            for(int i=2;i<100005;i++)
            {
                if(se.find(val)!=se.end())
                {
                    c+=se[val];
                    break;
                }

                if(!prime[i]) continue;
                
                if(val%i==0)
                {   
                    c++;
                    while(val%i==0) 
                    {
                        val/=i;

                    }
                
                }
                
                if(val==1) break;
                
            }
            
            se[dm]=c;
            cnt.push_back(c);
        }
        else
        {
            cnt.push_back(se[val]);
        }
    }

   //  for(int i=0;i<A.size();i++)
   //  {
   //     cout<<cnt[i]<<" ";
   //  }
    
   //  cout<<endl;
    map<pair<int,int>,int> mp1;
    priority_queue<pair<int,int>,vector<pair<int,int>>,Compare> pq;
    int times=0,fans=0,mod=1000000007;
    
    while(times<B) 
    {
        pq.push(make_pair(cnt[times],times));
        mp1[make_pair(cnt[times],times)]++;
        times++;
    }
    
    //cout<<A[pq.top().second]<<" ";
    fans=(fans%mod+ A[pq.top().second] %mod)%mod;
    
    while(times<cnt.size())
    {
        mp1[make_pair(cnt[times-B],times-B)]--;
        mp1[make_pair(cnt[times],times)]++;

        //cout<<cnt[times]<<" "<<A[times]<<endl;
        pq.push(make_pair(cnt[times],times));
        
        while(mp1[pq.top()]<=0)
        {
            pq.pop();
        }
        
        //cout<<A[pq.top().second]<<" ";
        fans=(fans%mod+A[pq.top().second]%mod)%mod;
        times++;
         
        
        
    }
    
    return fans;
    
    
}


int solvee(vector<int> arr, int sz, int sum)
{
    int count[sum+1][sz+1];
    bool found[sum+1][sz+1];
    
    
    for(int i=0;i<=sz;i++)
    {
        found[0][i]=true;
        count[0][i]=0;
    }
    
    for(int i=1;i<=sum;i++)
    {
        found[i][0]=false;
        count[i][0]= -1;
    }
    
    for(int i=1;i<=sum;i++)
    {
         for(int j=1;j<=sz;j++)
         {
             found[i][j]=found[i][j-1];
             count[i][j]=count[i][j-1];
             
             if(i>=arr[j-1])
             {
                 found[i][j]= found[i][j] || found[i-arr[j-1]][j-1];
                 
                 if(found[i][j])
                 {
                     count[i][j]= max(count[i][j], count[i-arr[j-1]][j-1]+1);
                 }
             }
         }
    }
    
    return count[sum][sz];
    
    
}

vector<int> solve(vector<vector<int> > &A) {
    
    vector<int> tt,fans;
    for(int i=0;i<A.size();i++)
    {
        int a=A[i][0],b=A[i][1];
        if(a==1)
        {
            tt.push_back(b);
        }
        else if(a==2)
        {
            tt.pop_back();
        }
        else
        {
            forz(l,tt.size())
            {
                p0(tt[l]);

            }

            cout<<endl;

            int sans=solvee(tt,tt.size(),b);
            fans.push_back(sans);
        }
    }
    
    return fans;
}



int main()
{
 
  ll T=1;
  //cin>>T;

  while(T--)
  {
     
     ll n;
     cin>>n;
     n*=2;
     ll cnt=0;
     for(int k=1;k*k<=n;k++)
     {
         if(n%k==0)
         {
             ll terms=k;
             ll d=n/terms;
             d-=terms;
             d++;
             if(d%2==0) cnt++;

             if(n/k!=k)
             { 
             terms=n/k;
             d=n/terms;
             d-=terms;
             d++;
             if(d%2==0) cnt++;
             }


         }
     }

     cout<<cnt<<endl;

    

     

      
    

  }


  
}

