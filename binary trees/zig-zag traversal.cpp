//zig zag traversal
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
vector<vector<int> > res;
class Binarytree{
	public:
		int data;
		Binarytree* left,*right;
		Binarytree(int data)
		{
			this->data=data;
			left=NULL;
			right=NULL;
		}
};
Binarytree* takeinput()
{
	int data;cin>>data;
	if(data==-1)
	{
		return NULL;
	}
	Binarytree* root= new Binarytree(data);
	Binarytree* leftchild=takeinput();
	Binarytree* rightchild=takeinput();
	root->left=leftchild;
	root->right=rightchild;
	
	return root;
}
void zigzag_level(Binarytree* root)
{
	queue<Binarytree* > q;
	q.push(root);
	bool left_right=true;
	
	while(!q.empty())
	{
		int n = q.size();
		vector<int> level(n);
		for(int i=0;i<n;i++)
		{
			Binarytree* node=q.front();
			q.pop();
			
			int j;
			if(left_right)
			{
				j=i;
			}
			else
			{
				j=n-1-i;
			}
			level[j]=node->data;
			
			if(node->left)
			{
				q.push(node->left);
			}
			if(node->right)
			{
				q.push(node->right);
			}
		}
		left_right = !left_right;
		res.push_back(level);
	}
}
int main()
{
	Binarytree* root=takeinput();
	zigzag_level(root);
	
	for (int i = 0; i < res.size(); i++) 
	{
        for (int j = 0; j < res[i].size(); j++)
        {
        	cout << res[i][j] << " ";	
		}
    }
}
