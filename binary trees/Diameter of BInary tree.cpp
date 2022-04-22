//Diameter of Binary tree
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
class Bt{
	public:
		int data;
		Bt* left;
		Bt* right;
		Bt(int data)
		{
			this->data=data;
			left=NULL;right=NULL;
		}
};
Bt* takeinput()
{
	int data;cin>>data;
	Bt* root=new Bt(data);
	if(data==-1)
	{
		return NULL;
	}
	root->left=takeinput();
	root->right=takeinput();
	return root;
}
int heightcalc(Bt* root)
{
	if(root==NULL)
	{
		return 0;
	}
	int LH=heightcalc(root->left);
	int RH=heightcalc(root->right);
	
	return max(LH,RH)+1;
}
int diameter(Bt* root)
{
	if(root==NULL)
	{
		return 0;
	}
	int curr_diameter = heightcalc(root->left) + heightcalc(root->right)+1;
	
	int ld=diameter(root->left);
	int rd=diameter(root->right);
	return max(curr_diameter,max(ld,rd));
}
int main()
{
	Bt* root=takeinput();
	cout<<heightcalc(root)<<" "<<diameter(root);
}
