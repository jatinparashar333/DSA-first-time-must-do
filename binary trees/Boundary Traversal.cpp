//Boundary Traversal anti-clock wise
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

vector<int> v;
stack<int> s;
class BinaryNode{
	public:
		int data;
		BinaryNode *left,*right;
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
	if(data==-1)
	{
		return NULL;
	}
	BinaryNode* root=new BinaryNode(data);
	BinaryNode* leftchild=takeinput();
	BinaryNode* rightchild=takeinput();
	root->left=leftchild;
	root->right=rightchild;
	
	return root;
}
void traverse_left(BinaryNode* temp)
{
	BinaryNode* curr=temp->left;
	while(curr->left || curr->right)
	{
		if(curr->left)
		{
			v.push_back(curr->data);
			curr=curr->left;
		}
		else if(curr->right)
		{
			v.push_back(curr->data);
			curr=curr->right;
		}
	}
}
void leaf_node(BinaryNode* temp1)
{
	if(temp1==NULL)
	{
		return;
	}
	leaf_node(temp1->left);
	if(temp1->left==NULL && temp1->right==NULL)
	{
		v.push_back(temp1->data);
	}
	leaf_node(temp1->right);
}
void traverse_right(BinaryNode* temp2)
{
	BinaryNode* curr=temp2->right;
	while(curr->left || curr->right)
	{
		if(curr->right)
		{
			s.push(curr->data);
			curr=curr->right;
		}
		else if(curr->left)
		{
			s.push(curr->data);
			curr=curr->left;
		}
	}
}
void boundary_traversal(BinaryNode* root)
{
	BinaryNode* temp=root,*temp1=root,*temp2=root;
	
	traverse_left(temp);
	leaf_node(temp1);
	traverse_right(temp2);
	while(!s.empty())
	{
		v.push_back(s.top());
		s.pop();
	}
}
int main()
{
	BinaryNode* root=takeinput();
	v.push_back(root->data);
	boundary_traversal(root);
	vector<int> :: iterator it;
	for(it=v.begin();it!=v.end();it++)
	{
		cout<<(*it)<<" ";
	}
	return 0;	
}

