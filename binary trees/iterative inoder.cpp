//iterative inorder
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
	Binarytree* root=new Binarytree(data);
	if(data==-1)
	{
		return NULL;
	}
	Binarytree* leftchild=takeinput();
	Binarytree* rightchild=takeinput();
	root->left=leftchild;
	root->right=rightchild;
	
	return root;
}

void inorder(Binarytree* root)
{
	stack<Binarytree* >s;
	Binarytree* temp=root;
	while(true)
	{
		if(temp!=NULL)
		{
			s.push(temp);
			temp=temp->left;
		}
		else
		{
			if(s.empty())
			{
				return;
			}
			temp=s.top();
			s.pop();
			v.push_back(temp->data);
			temp=temp->right;
		}
	}
}
int main()
{
	Binarytree* root=takeinput();
	 inorder(root);
	 vector<int> :: iterator it;
	 for(it=v.begin();it!=v.end();it++)
	 {
	 	cout<<(*it)<<" ";
	 }
}
