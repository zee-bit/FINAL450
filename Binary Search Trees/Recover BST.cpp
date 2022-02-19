#include <bits/stdc++.h>
using namespace std;
using namespace std::chrono;
typedef long long ll;
typedef long double ld;
struct custom_hash;
#define ff first
#define I insert
#define ss second
#define maxN 300002
#define inf INT_MAX
#define ninf INT_MIN
#define pb push_back
#define popb pop_back
#define pf push_front
#define pi 3.14159265
#define ub upper_bound
#define lb lower_bound
#define popf pop_front
#define mod 1000000007
#define vi vector<int> 
#define mll map<ll, ll>
#define vll vector <ll>
const int dx4[]={-1,0,1,0};
const int dy4[]={0,1,0,-1};
#define vvi vector<vector<int> >
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
const int dx8[]={-1,-1,-1,0,1,1,1,0};
const int dy8[]={-1,0,1,1,1,0,-1,-1};
#define ust unordered_set<ll, custom_hash>
#define rep(i, a, b) for(ll i = a; i < ll(b); i++)
#define umll unordered_map<ll, ll, custom_hash>
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);
struct custom_hash { size_t operator()(uint64_t x) const { static const uint64_t FIXED_RANDOM =
chrono::steady_clock::now().time_since_epoch().count();x ^= FIXED_RANDOM;return x ^ (x >> 16);}};
ll power(ll x,ll n) {ll result=1; while(n) {if(n%2==1) result=result*x; n=n/2; x=x*x;} return result;}
ll gcd(ll a, ll b) {return b ? gcd(b, a%b) : a;} 
ll lcm(ll a , ll b){return (a*b)/gcd(a,b);}
ll BS(ll a[],ll s,ll n,ll val) {ll mid,beg=s,end=n-1; while(beg<=end)
{mid=(beg+end)/2; if(val==a[mid]){break;} else if(val>a[mid]){beg=mid+1;}else{end=mid-1;}} return mid;}
inline ll mul(ll x,ll y,ll m){ll z=1LL*x*y;if (z>=m){z%=m;} return z;}
ll powmod(ll x,ll y,ll m){ll r=1;while(y){if(y&1){r=mul(r,x,m);}y>>=1;x=mul(x,x,m);}return r;}
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wunused-result"

//========================================XXXXXXXXXXXXXXXX=======================================

struct Node {
	int data;
	Node *left;
	Node *right;

	Node(int val) {
		data = val;
		left = NULL;
		right = NULL;
	}
};

Node *buildTree() {
	//			 4
	//		   /   \
	//		  2    7
	//		 / \  / \
	//		1  3 5  8
	//		     \
	// 		     6
	Node* root = new Node(4);
    root->left = new Node(2);
    root->right = new Node(7);
    root->left->left = new Node(1);
    root->left->right = new Node(3);
    root->right->left = new Node(5);
    root->right->right = new Node(8);
    root->right->left->right = new Node(6);
    return root;
}

// METHOD-1
void getNodes(Node *node, vector<int> &nodes) {
    if(!node) return;
    getNodes(node -> left, nodes);
    nodes.push_back(node -> val);
    getNodes(node -> right, nodes);
}

void swapNodes(Node *node, vector<int> &nodes, int &idx) {
    if(!node) return;
    swapNodes(node -> left, nodes, idx);
    
    if(nodes[idx] != node -> val)
        node -> val = nodes[idx];
    idx++;
    
    swapNodes(node -> right, nodes, idx);
}


// METHOD-2
void getSwapNodes(Node *node, Node *&prev, Node *&first, Node *&second) {
    if(!node) return;
    
    getSwapNodes(node -> left, prev, first, second);
    
    if(prev && prev -> val > node -> val) {
        if(first == NULL) {
            first = prev;
            second = node;
        }
        else
            second = node;
    }
    prev = node;
    
    getSwapNodes(node -> right, prev, first, second);
}

bool solve() {
	Node *root = buildTree();
	int N = countNodes(root);

	// METHOD-1
	vector<int> nodes;
    getNodes(root, nodes);
    sort(nodes.begin(), nodes.end());
    
    int idx = 0;
    swapNodes(root, nodes, idx);
    
    // METHOD-2
    Node *prev = NULL, *first = NULL, *second = NULL;
    getSwapNodes(root, prev, first, second);
    swap(first -> val, second -> val);
}

int main() {
	fast;
	#ifndef ONLINE_JUDGE
  		freopen("../input.txt", "r", stdin);
  		freopen("../output.txt", "w", stdout);
	#endif
	int t = 1;
	// cin >> t;
	while(t--)
		cout << solve();
	return 0;
}

#pragma GCC diagnostic pop