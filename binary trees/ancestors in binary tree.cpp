//ancestors in binary tree
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

vector<int> v;
    bool find_path(Node* root,int n)
    {
        if(root==NULL)
        {
            return false;
        }
        if(root->data==n)
        {
            return true;
        }
        if(find_path(root->left,n) || find_path(root->right,n))
        {
            v.push_back(root->data);
            return true;
        }
        return false;
    }
   int main()
   {
   	Node* root=takeinput();
   	int target;cin>>target;
   	find_path(root,target);
   	
   	vector<int> :: iterator it;
   	for(it=v.begin();it!=v.end();it++)
   	{
   		cout<<(*it)<<" ";
	}
   }
