//binary tree input using recursion
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
//cout << (condition ? "YES\n" : "NO\n");
class BinaryNode{
	public:
		int data;
		BinaryNode* left,*right;
		BinaryNode(int data)
		{
			this->data=data;
			left=NULL;
			right=NULL;
		}
};
BinaryNode* takeinput()
{
	int data;
	cin>>data;
	BinaryNode* root=new BinaryNode(data);
	if(data==-1)
	{
		return NULL;
	}
	BinaryNode* leftchild=takeinput();
	BinaryNode* rightchild=takeinput();
	root->left=leftchild;
	root->right=rightchild;
	return root;
}
int main()
{
	BinaryNode* root = takeinput();
}
