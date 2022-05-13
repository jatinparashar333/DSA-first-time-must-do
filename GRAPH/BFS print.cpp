//BFS print
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ft first
#define sc second
#define pb push_back
#define ins insert
#define all(v) v.begin(), v.end()
#define Sort(v) sort(all(v))
#define s(a, n) sort(a, a + n)
#define f1(i,a,b) for(ll i=a;i<b;i++)
#define f2(i,a,b,c) for(ll i=a;i<b;i+=c)
#define f3(i,a,b) for(ll i=a;i>=b;i--)
#define f4(i,a,b,c) for(ll i=a;i>=b;i-=c)
#define jatin(t) int t; cin >> t; while(t--)
const int N = 1e5+2, MOD = 1e9+7;
vector<int> adj[N];

int main()
{
	int n,m;cin>>n>>m; //no.of nodes & edges
	for(int i=0;i<m;i++)
	{
		int x,y;cin>>x>>y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	bool vis[n];
	for(int i=1;i<=n;i++)
	{
		vis[i]=0;
	}
	queue<int> q;
	q.push(1);       //suppose starting with 1
	vis[1]=true;
	while(!q.empty())
	{
		int n=q.front();
		q.pop();
		cout<<n<<" ";
		vector<int> :: iterator it;
		for(it=adj[n].begin();it!=adj[n].end();it++)
		{
			if(!vis[*it])
			{
				q.push(*it);
				vis[*it]=true;
			}
		}
	}
}
