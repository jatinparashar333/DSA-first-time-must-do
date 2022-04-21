//
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


// preorder 
void preorder(BinaryNode* root1)
{
	if(root1==NULL)
	{
		return;
	}
	cout<<root1->data<<" ";
	preorder(root1->left);
	preorder(root1->right);
}

// inorder
void inorder(BinaryNode* root2)
{
	if(root2==NULL)
	{
		return;
	}
	inorder(root2->left);
	cout<<root2->data<<" ";
	inorder(root2->right);
}

// postorder
void postorder(BinaryNode* root3)
{
	if(root3==NULL)
	{
		return;
	}
	postorder(root3->left);
	postorder(root3->right);
	cout<<root3->data<<" ";
}

int main()
{
	BinaryNode* root = takeinput();
	BinaryNode* root1=root;
	BinaryNode* root2=root;
	BinaryNode* root3=root;
	preorder(root1);
	cout<<endl;
	inorder(root2);
	cout<<endl;
	postorder(root3);
}
