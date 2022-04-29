//vertical order traversal
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
class Node{
	public:
		int data;
		Node* left,*right;
		Node(int data)
		{
			this->data=data;
			left=NULL;
			right=NULL;
		}
};
Node* takeinput()
{
	int data;cin>>data;
	Node* root=new Node(data);
	if(data==-1)
	{
		return NULL;
	}
	Node* leftchild=takeinput();
	Node* rightchild=takeinput();
	root->left=leftchild;
	root->right=rightchild;
	return root;
}
void vertical_order_traversal(Node* root)
{
	map<int,map<int,multiset<int> > > nodes;
	queue<pair<Node*,pair<int,int> > > q;
	q.push({root,{0,0}});
	while(!q.empty())
	{
		auto p = q.front();
		q.pop();
		Node* node=p.first;
		int x=p.second.first;
		int y=p.second.second;
		nodes[x][y].insert(node->data);
		if(node->left)
		{
			q.push({node->left,{x-1,y+1}});
		}
		if(node->right)
		{
			q.push({node->right,{x+1,y+1}});
		}
	}
	vector<vector<int>> v;
	for(auto p: nodes)
	{
		vector<int> col;
		for(auto q: p.second)
		{
			col.insert(col.end(),q.second.begin(),q.second.end());
			
		}
		v.push_back(col);
	}
	for(int i=0;i<v.size();i++)
	{
		for(int j=0;j<v[i].size();j++)
		{
			cout<<v[i][j]<<" ";
		}
		cout<<endl;
	}
}
int main()
{
	Node* root=takeinput();
	vertical_order_traversal(root);
	
}
