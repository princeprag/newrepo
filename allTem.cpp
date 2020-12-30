
// GRAPHS

// vector<ll> adj[N];
// vector<ll> till;
// ll value[N],parent[N];
// bool visited[N];
// bool rec[N];
// ll ans[N];
// bool isCycle=false;
// ll clr[N];


/*
ll dfs(ll s,ll p)
{ 
    sizz[s]=1;
    visited[s]=true;
    for(auto x:adj[s])
    {
        if(x==p || x==s)
        {
            continue;
        }

        if(!visited[x])
        { 
        depth[x]=depth[s]+1;
        dfs(x,s,n);
        sizz[s]+=sizz[x];
        }
           
        
    }

}


void initGraph(ll NOdes,ll n)
{
   ll a,b;
   for(int i=1;i<=NOdes;i++)
   {
       adj[i].clear();
       visited[i]=false;
       //sizz[i]=depth[i]=0;
   }

    for(int i=0;i<n;i++)
    {
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
}

void bfs(ll start,ll N)
{

      bool vis[N];
      ll  dis[N];
      for(int i=1;i<=N;i++) {vis[i]=false; dis[i]=0;}
      queue<pair<ll,ll>> qq;
      qq.push(make_pair(start,0));
      dis[start]=0;
      visited[start]=true;

      while(!qq.empty())
      {
            int sz=qq.size();
            for(int i=0;i<sz;i++)
            { 
        
            pair<ll,ll> fr=qq.front();
            qq.pop();

            ll nd=fr.first;
            if(visited[nd]) continue;

            for(auto x:adj[nd])
            {
                if(!visited[x])
                { 
                dis[x]=fr.second+1; // distance of x
                visited[x]=true;
                qq.push(make_pair(x,fr.second+1));
                }

            }

            }
      }

      for(ll i=1;i<=tNOde;i++)
      cout<<dis[i]<<" ";

}*/
/*

void dfs_Directed(ll s,ll p)
{
    sizz[s]=1;
    visited[s]=true;
    rec[s]=true;
   
    for(auto x:adj[s]){
       
            if(visited[x]==false)
            {
        
            depth[x]=depth[s]+1;
            dfs(x,s);
            sizz[s]=sizz[s]+sizz[x];

            }
            else if(rec[x]) isCycle=true;
           
        
    }
    rec[s]=false;
}
*/

/*

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



/// used for internal sorting in minpriority queue
template <class pll> struct greatter : binary_function <pll,pll,bool> {
  bool operator() (const pll& p1, const pll& p2) const 
  {
    if(p2.S-p2.F>p1.S-p1.F) return true;
    else if(p2.S-p2.F==p1.S-p1.F)
    { 
        if(p1.F>p2.F)  return true;
        else return false;
    }
    else return false;
  }
};


ll power(ll x, ll y, ll p) 
{ 
    ll res = 1;      
    x = x % p;  
  
    while (y > 0) 
    { 
       
        if (y & 1) 
            res = (res*x) % p; 
  
        
        y = y/2; 
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
  
    return (fac[n]*modInverse(fac[r], p) % p * modInverse(fac[n-r], p)  % p); 
}




// ll dp[3605][8005];
// ll countsubsets(vector<ll> arr,ll ss, ll i,ll remsum)
// {
//    if(i==ss) 
//    {
//        if(remsum==0) return 1;
//        else return 0;
//    }

//    if(dp[i][remsum]!=-1) return dp[i][remsum];
//    else
//    {
//        dp[i][remsum]=countsubsets(arr,ss,i+1,remsum)+countsubsets(arr,ss,i+1,remsum-arr[i]);
//        return  dp[i][remsum];
//    }
   

// }

bool comp1(string ss1,string ss2)
{
    if(ss1+ss2 <= ss2+ss1) return true;
    else return false;
}

vector<int> findmaxright_index(vector<int>&arr, int n)
{
    stack<pair<int,int>> st;
    vector<int> ans(n,0);
    for(int i=0;i<n;i++)
    {
        if(st.empty()) st.push(make_pair(arr[i],i));
        else
        {
            while(!st.empty() && st.top().first<arr[i])
            {
              ans[st.top().second]=i;
              st.pop();

            }
            st.push(make_pair(arr[i],i));
        }
        
    }

    while(!st.empty())
    {
              ans[st.top().second]=n;
              st.pop();   
    }
    return ans;
}


vector<int> findmaxleft_index(vector<int>&arr, int n)
{
    stack<pair<int,int>> st;
    vector<int> ans(n,0);
    for(int i=n-1;i>=0;i--)
    {
        if(st.empty()) st.push(make_pair(arr[i],i));
        else
        {
            while(!st.empty() && st.top().first<arr[i])
            {
              ans[st.top().second]=i;
              st.pop();

            }
            st.push(make_pair(arr[i],i));
        }
        
    }

    while(!st.empty())
    {
              ans[st.top().second]=-1;
              st.pop();   
    }

    return ans;
}



/*
void permute(vector<ll> vec, int l, int r)  
{  
    // Base case  
    if (l == r)  
        {
            int sans=0;
            for(int i=0;i<vec.si;i++)
            sans=sans*10+vec[i];
            
            fans+=sans;


        }  
    else
    {  
        // Permutations made  
        for (int i = l; i <= r; i++)  
        {  
  
            // Swapping done  
            swap(vec[l], vec[i]);  
  
            // Recursion called  
            permute(vec, l+1, r);  
  
            //backtrack  
            swap(vec[l], vec[i]);   
        }  
    }  
}
0*/ 

/*

void mkstring(string s,ll lth,ll idx)
{

    
        ll a=0;
        for(ll i=0;i<=lth-6;i++)
        {
                 if(s.substr(i,7)=="abacaba") a++;

        }

        if(a==1) {found=true; ans=s; return;}

        
       if(idx==lth) return;
   
    
    if(s[idx]=='?') 
    {
        for(char p='a';p<='c';p++)
        {
            s[idx]=p;
            mkstring(s,lth,idx+1);


            if(found) return;

        }
    }
    else
    {
         mkstring(s,lth,idx+1);
    }
    

     return;
 

}

int binarys(vector<int> &A,int sii,int li,int val,int idx)
{
    if(sii>li) return idx;
    int mid=(sii+li)/2;
    
   
    if(A[mid]<=val)
    {  
       
        if(A[mid]==val) idx=mid;
        return binarys(A,mid+1,li,val,idx);
    }
    else if(A[mid]>val)
    {
     
        
        return binarys(A,sii,mid-1,val,idx);
    }
}

int findOverlappingPair(string str1, string str2, string &str) 
{ 
    // max will store maximum overlap i.e maximum 
    // length of the matching prefix and suffix 
    int max = INT_MIN; 
    int len1 = str1.length(); 
    int len2 = str2.length(); 
  
    // check suffix of str1 matches with prefix of str2 
    for (int i = 1; i <= min(len1, len2); i++) 
    { 
        // compare last i characters in str1 with first i 
        // characters in str2 
        if (str1.compare(len1-i, i, str2, 0, i) == 0) 
        { 
            if (max < i) 
            { 
                //update max and str 
                max = i; 
                str = str1 + str2.substr(i); 
            } 
        } 
    } 
  
    // check prefix of str1 matches with suffix of str2 
    for (int i = 1; i <= min(len1, len2); i++) 
    { 
        // compare first i characters in str1 with last i 
        // characters in str2 
        if (str1.compare(0, i, str2, len2-i, i) == 0) 
        { 
            if (max < i) 
            { 
                //update max and str 
                max = i; 
                str = str2 + str1.substr(i); 
            } 
        } 
    } 


    if(len1<len2)
    {
        for (int i = 0; i <= len2-len1; i++) 
        if(str2.substr(i,len1)==str1)
        {
            if (max < len2) 
            { 
                //update max and str 
                max = len2; 
                str = str2; 
            } 
        }
    }
    else
    {
        for (int i = 0; i <= len1-len2; i++) 
        if(str1.substr(i,len2)==str2)
        {
            if (max < len1) 
            { 
                //update max and str 
                max = len1; 
                str = str1; 
            } 
        }
    }
    
  
    return max; 
} 

ll findpairs(vector<ll> &vec, ll s)
{
    int ptr1=0,ptr2=vec.si-1;
    int ans=0;
    while(ptr1<ptr2)
    {
        if(vec[ptr1]+vec[ptr2]==s) {ans++; ptr1++; ptr2--;}
        else if(vec[ptr1]+vec[ptr2]<s) ptr1++;
        else ptr2--;
    }

    return ans;
}


int func(string a,string b)
{
    int i=0,cnt=0;
    int n=b.size();
    for(int i=0;i<n;i++) if(a[i]!=b[i]) cnt++;

    return cnt;
}

bool isT()
{
    cout<<"Trueeeeeeeee";
    return true;
}

bool isF()
{
    cout<<"Falseeeee";
    return true;
}

long lsteps(long n)
{
    long bit,ans=0;
    long res=0;
    for(long i=63;i>=0;i--)
    {
       bit=((n>>i)&1);
       ans=(bit+ans)%2;
       res=res<<1;
       res+=ans;
     
    }

    return res;
}

/*
bool visited[100][100];
map<pair<int,int>,int> mp1;
set<pair<int,int>> se;

void bfs(int i,int j,int n,int m)
{
   queue<pair<int,pair<int,int>>> qq;
   pair<int,pair<int,int>> tt;
   tt.first=0; tt.second.first=i; tt.second.second=j; 
   qq.push(tt);
   visited[i][j]=true;
   while(!qq.empty())
   {
     pair<int,pair<int,int>> tt;
     tt=qq.front();
     qq.pop();

     int i1=tt.second.first,j1=tt.second.second;
     int dis=tt.first;
     if(se.find(make_pair(i1,j1))!=se.end())
     {
         mp1[make_pair(i1,j1)]=dis;
         cout<<"Distance to "<<i1<<" "<<j1<<"is :"<<dis<<endl;
     }


     

     if(i1>0 && !visited[i1-1][j1])
     {
          pair<int,pair<int,int>> d;
          visited[i1-1][j1]=true;
          d.first=dis+1; d.second.first=i1-1; d.second.second=j1; 
          qq.push(d);
     }
     if(i1<n-1 && !visited[i1+1][j1])
     {
          pair<int,pair<int,int>> d;
          visited[i1+1][j1]=true;
          d.first=dis+1; d.second.first=i1+1; d.second.second=j1; 
          qq.push(d);
     }
     if(j1>0 && !visited[i1][j1-1])
     {
          pair<int,pair<int,int>> d;
          visited[i1][j1-1]=true;
          d.first=dis+1; d.second.first=i1; d.second.second=j1-1;
          qq.push(d); 
     }
     if(j1<m-1 && !visited[i1][j1+1])
     {
          pair<int,pair<int,int>> d;
          visited[i1][j1+1]=true;
          d.first=dis+1; d.second.first=i1; d.second.second=j1+1; 
          qq.push(d);
     }
     


   }

   return;


}

// rotated sorted array
int maxBitonic(vector<int> arr,int low,int high)
{
    if (high < low) 
        return -1; 
    if (high == low) 
        return low; 
  
    int mid = (low + high) / 2; 

    if (mid < high && arr[mid] < arr[mid + 1]) 
        return maxBitonic(arr,mid+1,high); 
    else if (mid > low && arr[mid] < arr[mid - 1]) 
         return maxBitonic(arr,low,mid-1); 
    else return mid;
}

int minBitonic(vector<int> arr,int low,int high)
{
    if (high < low) 
        return -1; 
    if (high == low) 
        return low; 
  
    int mid = (low + high) / 2; 

    if (mid < high && arr[mid] > arr[mid + 1]) 
        return minBitonic(arr,mid+1,high); 
    else if (mid > low && arr[mid] > arr[mid - 1]) 
         return minBitonic(arr,low,mid-1); 
    else return mid;
}

int findPivot(vector<int> arr,int low,int high)
{
    if (high < low) 
        return -1; 
    if (high == low) 
        return low; 
  
    int mid = (low + high) / 2; 
    if (mid < high && arr[mid] > arr[mid + 1]) 
        return mid; 
  
    if (mid > low && arr[mid] < arr[mid - 1]) 
        return (mid - 1); 
  
    if (arr[low] >= arr[mid]) 
        return findPivot(arr, low, mid - 1); 
  
    return findPivot(arr, mid + 1, high);
}

double fans;
void dfss(int s,int e,bool visited[26],double mat[26][26],double ans)
{

    if(s==e) {fans=ans; return;}

    for(int i=0;i<26;i++)
    {
        if(mat[s][i]!=-1 && !visited[i])
        {
            visited[i]=true;
            dfss(i,e,visited,mat,ans*mat[s][i]);
        }
    }

    return;


}


double dijkstra(int start,int end,double mat[26][26])
{
    double cost[26];
    bool flag[26];

    for(int i=0;i<26;i++) {cost[i]=DBL_MAX; flag[i]=false;}
    cost[start] = 1.0;
    for(int i=0; i<26; i++)
    {
        double d=DBL_MAX;
        int u=0;
        // submodule to find the vertex with minimum distance
        for(int j=0; j<26; j++)
            if(!flag[j] && cost[j]< d)
            {
                d=cost[j]; u=j;
            }

        flag[u] = 1;
        for(int j=0; j<26; j++)
            if(!flag[j] && mat[u][j]!=-1.0 && cost[u]!=DBL_MAX)
                cost[j]=min(cost[j], cost[u]*mat[u][j]);
    }

    return cost[end];
}


bool comp(vector<ll> B1, vector<ll> B2)
{
  
  if(B1[2]<B2[2]) return true;
  else return false;
    
}
void initialize()
{
    for(ll i = 0;i < MAX;++i)
        id[i] = i;
}

ll root(ll x)
{
    while(id[x] != x)
    {
        id[x] = id[id[x]];
        x = id[x];
    }
    return x;
}

void union1(ll x, ll y)
{
    ll p = root(x);
    ll q = root(y);
    id[p] = id[q];
}

ll kruskal(vector<vector<ll>> vec)
{
    
    ll x, y,edges;
    ll cost, minimumCost = 0;
    edges=vec.size();
    for(int i = 0;i < edges;++i)
    {
        // Selecting edges one by one in increasing order from the beginning
        x = vec[i][0];
        y = vec[i][1];
        cost = vec[i][2];
        // Check if the selected edge is creating a cycle or NOt
        if(root(x) != root(y))
        {
            minimumCost += cost;
            union1(x, y);
        } 
        // Check if the selected edge is creating a cycle or NOt
        if(root(x) != root(y))
        {
            minimumCost += cost;
            union1(x, y);
        }    
    }
    
    return minimumCost;
}

*/

/*
int knapSack(int W, int wt[], int val[], int n) 
{ 
	int i, w; 
	int K[n + 1][W + 1]; 

	0-1 knapsack with max value/profit and weight is exactly** W
	for (i = 0; i <= n; i++) { 
		for (w = 0; w <= W; w++) 
        { 
			if (i == 0) 
				K[i][w] = -1; // if the is NO element NO +ve value W is possible 
            else if( w == 0)
                K[i][w] = 0;
			else if (wt[i - 1] <= w &&  K[i][w - wt[i - 1]]!=-1) 
				K[i][w] = max(val[i - 1] + K[i][w - wt[i - 1]],K[i - 1][w]); 
			else
				K[i][w] = K[i - 1][w]; 
		} 
	} 

	return K[n][W]; 
}
    
    range is [low,high]
    int even_count = high / 2 - (low - 1) / 2;  
    int odd_count = (high + 1) / 2 - low / 2;  

//
int a[N] // This is the input
int products[N];

// Get the products below the current index
p=1;
for(int i=0;i<N;++i)
 {
  products[i]=p;
  p*=a[i];
}

// Get the products above the curent index
p=1;
for(int i=N-1;i>=0;--i)
{
  products[i]*=p;
  p*=a[i];
}
*/