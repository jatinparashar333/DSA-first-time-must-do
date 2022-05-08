//graph representation using adjacency list (directed graph)
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
//int array[N];
//cout << (condition ? "YES\n" : "NO\n");
vector<int> adj[N];     // array of vectors
int main()
{
	int n,m;cin>>n>>m;                  // n->no.of nodes,m->no.of edges
	for(int i=0;i<m;i++)
	{
		int x,y;cin>>x>>y;
		
		adj[x].push_back(y);
	}
	
	// adjacency list of the above graph is given by -:
	for(int i=0;i<=n;i++)
	{
		cout<<i<<" -> ";
		vector<int> :: iterator it;
		for(it=adj[i].begin();it!=adj[i].end();it++)
		{
			cout<<*it<<" ";
		}
		cout<<endl;
	}
}
