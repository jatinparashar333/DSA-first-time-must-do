//height of binary tree
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
	Binarytree* root = new Binarytree(data);
	if(data==-1)
	{
		return NULL;
	}
	//Binarytree* leftchild = takeinput();
	//Binarytree* rightchild = takeinput();
	root->left=takeinput();
	root->right=takeinput();
	
	return root;
}
int height_tree(Binarytree* root)
{
	if(root==NULL)
	{
		return 0;
	}
	int left_height=height_tree(root->left);
	int right_height=height_tree(root->right);
	
	return max(left_height,right_height)+1;
}
int main()
{
	Binarytree* root = takeinput();
	cout<<height_tree(root);
}
