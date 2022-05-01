//delete a node in BST
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

Node* deletenode(Node* root,int key)
{
	if(!root)
	{
		return NULL;
	}
	if(root->data==key)
	{
		return helper(root);
	}
	Node* temp=root;
	while(!root)
	{
		if(root->data > key)
		{
			if(root->left && root->left->data==key)
			{
				root->left =helper(root->left);
			}
			else {
				root=root->left;
			}
		}
		else
		{
			if(root->right && root->right->data=key)
			{
				root->right=helper(root->right);
			}
			else{
				root=root->right;
			}
		}
	}
}

Node* helper(Node* root)
{
	if(root->left==NULL)
	{
		return root->right;
	}
	else if(root->right==NULL)
	{
		return root->left;
	}
	Node* rightchild=root->right;
	Node* rightmost = findrightmost(root->left);
	rightmost->right=rightchild;
	return root->left;
}
Node* findrightmost(Node* root)
{
	if(root->right==NULL)
	{
		return root;
	}
	return findrightmost(root->right);
}
