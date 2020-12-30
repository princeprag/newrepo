vector<ll> adj[N];
ll depth[N],sizz[N];
bool visited[N],rec[N];
bool isCycle=false;
// ll clr[N];


// Dfs and finding cycle in undirected graph
// Time Complex O(V+E)
void dfs(ll s,ll p){
    sizz[s]=1;
    visited[s]=true;
   
    for(auto x:adj[s]){
        if(x==p){
            continue;
        }
            
            if(visited[x]==true) isCycle=true;
            
            if(visited[x]==false)
            {
        
            depth[x]=depth[s]+1;
            dfs(x,s);
            sizz[s]=sizz[s]+sizz[x];

            }
           
        
    }
}

void dfs_Directed(ll s,ll p){
    sizz[s]=1;
    visited[s]=true;
    rec[s]=true;
   
    for(auto x:adj[s]){

        if(x==p){
            continue;
        }
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
// tc of BFS/Dfs O(V+E)
//tc of prims = O((V+E)logV) == O(ElogV), wrost case !! using priority queue since its basically a bfs with priority queue,, using adj. matrix its O(V^2)
// tc of kruskals = O(ElogV+ElogE)== O(ElogV+ElogV^2)== O(ElogV) !!using good parent finding algo

bool marked[MAX];
vector <PII> adj[MAX];
//Prims
long long prims(int x)
{
    priority_queue<PII, vector<PII>, greater<PII> > Q;
    int y;
    long long minimumCost = 0;
    PII p;
    Q.push(make_pair(0, x));
    while(!Q.empty())
    {
        // Select the edge with minimum weight
        p = Q.top();
        Q.pop();
        x = p.second;
        // Checking for cycle
        if(marked[x] == true)
            continue;

        minimumCost += p.first;
        marked[x] = true;
        for(int i = 0;i < adj[x].size();++i)
        {
            y = adj[x][i].second;
            if(marked[y] == false)
                Q.push(adj[x][i]);
        }
    }
    return minimumCost;
}

int main()
{
    int nodes, edges, x, y;
    long long weight, minimumCost;
    cin >> nodes >> edges;
    for(int i = 0;i < edges;++i)
    {
        cin >> x >> y >> weight;
        adj[x].push_back(make_pair(weight, y));
        adj[y].push_back(make_pair(weight, x));
    }
    // Selecting 1 as the starting node
    minimumCost = prim(1);
    cout << minimumCost << endl;
    return 0;
}

/***************************************************
 Kruskals
 int id[MAX], nodes, edges;
pair <long long, pair<int, int> > p[MAX];

void initialize()
{
    for(int i = 0;i < MAX;++i)
        id[i] = i;
}

int root(int x)
{
    while(id[x] != x)
    {
        id[x] = id[id[x]];
        x = id[x];
    }
    return x;
}

void union1(int x, int y)
{
    int p = root(x);
    int q = root(y);
    id[p] = id[q];
}

long long kruskal(pair<long long, pair<int, int> > p[])
{
    int x, y;
    long long cost, minimumCost = 0;
    for(int i = 0;i < edges;++i)
    {
        // Selecting edges one by one in increasing order from the beginning
        x = p[i].second.first;
        y = p[i].second.second;
        cost = p[i].first;
        // Check if the selected edge is creating a cycle or not
        if(root(x) != root(y))
        {
            minimumCost += cost;
            union1(x, y);
        }    
    }
    return minimumCost;
}

int main()
{
    int x, y;
    long long weight, cost, minimumCost;
    initialize();
    cin >> nodes >> edges;
    for(int i = 0;i < edges;++i)
    {
        cin >> x >> y >> weight;
        p[i] = make_pair(weight, make_pair(x, y));
    }
    // Sort the edges in the ascending order
    sort(p, p + edges);
    minimumCost = kruskal(p);
    cout << minimumCost << endl;
    return 0;
}

*////////////////////////
//Djkastra Algorithm- fails for negative weighted Edges!!
// N is total number of Nodes:)

void dijkstra(int s)
{
    double cost[N+1];
    for(int i=1;i<=N;i++) cost[i]=INT_MAX;
    cost[s] = 0;
    for(int i=1; i<=N; i++)
    {
        double d=DOUBLE_MAX;
        int u=0;
        // submodule to find the vertex with minimum distance
        for(int j=1; j<=N; j++)
            if(!flag[j] && cost[j]< d)
            {
                d=cost[j]; u=j;
            }

        flag[u] = 1;
        for(int j=1; j<=N; j++)
            if(!flag[j] && adj[u][j] && cost[u]!=INT_MAX)
                cost[j]=min(cost[j], cost[u]+adj[u][j]);
    }
}






//Next Greater Element
void printNGE(int arr[], int n) { 

  stack <pair<int,int>> s; 
  int rdx[n];
  memset(rdx,0,sizeof(rdx));
  
  /* push the first element to stack */
  s.push(arr[0],0); 
  
  // iterate for rest of the elements 
  for (int i = 1; i < n; i++) { 
  
    if (s.empty()) { 
      s.push(arr[i],i); 
      continue; 
    } 
  
    while (s.empty() == false && s.top().first < arr[i]) 
    {   
        rdx[s.top().second]=i;       
        //cout << s.top() << " --> " << arr[i] << endl; 
        s.pop(); 
    } 
  
   
    s.push(arr[i],i); 
  } 
  
  /* After iterating over the loop, the remaining 
  elements in stack do not have the next greater 
  element, so print -1 for them */
  while (s.empty() == false) { 
     rdx[s.top().second]=-1;  
    //cout << s.top() << " --> " << -1 << endl; 
    s.pop(); 
  } 
} 













// COIN CHANGE LIMITED//
#include <bits/stdc++.h>
#define ll long long int
#define MOD 1000000007
#define fastIO ios_base::sync_with_stdio(false); cin.tie(NULL);
using namespace std;
using namespace std::chrono;

 
int main() {
    fastIO;
    int t; cin >> t;
    for(int qq = 0; qq < t; qq++) {
        long int n, k;
        cin >> n >> k;
        // k is total types of coins
        // d is quantity(limit) of each coin
        // l is value of each coin
        long long int l[k+1], d[k+1];
        for(long int i = 1; i <= k; i++)
            cin >> l[i];
        for(long int i = 1; i <= k; i++)
            cin >> d[i];

        ll dp[k+1][n+1];
        memset(dp, 0, sizeof(dp));
        dp[0][0] = 1; // if you need to get 0 logs out of 0 types of bundles, only way is to DO NOTHING
        for(ll i = 1; i <= k; i++) {
            for(ll j = 0; j <= n; j++) {
                ll rem = min(d[i], j/l[i]);
                
                for(ll f = 0; f <= rem; f++)
                    dp[i][j] = (dp[i][j]%MOD + dp[i-1][j-l[i]*f]%MOD) %MOD;
            }
        }
        cout << dp[k][n]%MOD << endl;
    }

} 
