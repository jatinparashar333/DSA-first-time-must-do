//level order traversal using queue
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
BinaryNode* takeInput(){
	int data;
	cin >> data;
	if(data == -1){
		return NULL;
	}
	BinaryNode* root = new BinaryNode(data);
	queue<BinaryNode*> q;
	q.push(root);

	while(q.size() != 0){
		BinaryNode* front = q.front();
		q.pop();
		int leftChild;
		cin >> leftChild;
		if(leftChild != -1){
			BinaryNode* child = new BinaryNode(leftChild);
			front -> left = (child);
			q.push(child);
		}
		int rightChild;
		cin >> rightChild;
		if(rightChild != -1){
			BinaryNode* child = new BinaryNode(rightChild);
			front -> right = (child);
			q.push(child);
		}
	}
	return root;
}
void levelOrder(BinaryNode* node)
    {
    	
      queue<BinaryNode* > q;
      q.push(node);
      while(!q.empty())
      {
          int n=q.size();
          for(int i=1;i<=n;i++)
          {
              BinaryNode* temp=q.front();
              q.pop();
              v.push_back(temp->data);
              if(temp->left)
              {
                  q.push(temp->left);
              }
              if(temp->right)
              {
                  q.push(temp->right);
              }
          }
      }
    }
    
    int main()
    {
    	BinaryNode* node=takeInput();
    	levelOrder(node);
    	vector<int> :: iterator it;
    	for(it=v.begin();it!=v.end();it++)
    	{
    		cout<<(*it)<<" ";
		}
	}
