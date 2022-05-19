//Is graph(directed) tree or not 
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
vector<int> adj[N];
bool vis[N];
void DFS(int n){
	vis[n]=true;
	vector<int> :: iterator it;
	for(it=adj[n].begin();it!=adj[n].end();it++)
	{
		if(!vis[*it]){
			DFS(*it);
		}
	}
}
bool checkcycle(int src,vector<int> adj[],vector<bool> &vis,vector<bool> &stack){
        stack[src]=1;
       vis[src]=1;
            vector<int> :: iterator it;
            for(it=adj[src].begin();it!=adj[src].end();it++){
                if(!vis[*it] && checkcycle(*it,adj,vis,stack)){
                    return true;
                }
                if(stack[*it]){
                    return true;
                }
            }
            stack[src]=0;
            return false;
        
    }
    bool isCyclic(int V, vector<int> adj[]) {
        // code here
        vector<bool> stack(V,0);
        vector<bool> vis(V,0);
        for(int i=1;i<=V;i++){
            if(!vis[i] && checkcycle(i,adj,vis,stack)){
                return true;
            }
        }
        return false;
    }
int main(){
	int n,m;cin>>n>>m;
	for(int i=0;i<m;i++){
		int x,y;cin>>x>>y;
		adj[x].push_back(y);
	}
	for(int i=1;i<=n;i++){
		vis[i]=false;
	}
	DFS(1);
	bool key=true;
	for(int i=1;i<=n;i++){
		if(!vis[i]){
			key=false;
		}
	}
	if(key && !iscyclic(1)){
		cout<<"YES";
	}
	else{
		cout<<"NO";
	}
}
