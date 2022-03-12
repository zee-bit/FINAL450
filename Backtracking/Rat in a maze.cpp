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
const int dx[]={-1,0,1,0};
const int dy[]={0,1,0,-1};
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

void getPaths(vector<vector<int>> &mat, int i, int j, int N, string path, vector<string> &res) {
    if(i == N-1 && j == N-1) {
        res.push_back(path);
        return;
    }
    if(mat[i][j] == 0)
        return;
    
    mat[i][j] = 0;
    for(int d = 0; d < 4; d++) {
        int x = i + dx[d], y = j + dy[d];
        if(x < 0 || x >= N || y < 0 || y >= N || mat[x][y] == 0)
            continue;
        
        if(d == 0) getPaths(mat, x, y, N, path+"L", res);
        if(d == 1) getPaths(mat, x, y, N, path+"D", res);
        if(d == 2) getPaths(mat, x, y, N, path+"R", res);
        if(d == 3) getPaths(mat, x, y, N, path+"U", res);
    }
    mat[i][j] = 1;
}

void getPaths2(vector<vector<int>> &m, int n, string path, int x, int y, vector<string> &ans) {
    if(x < 0 || x >= n || y < 0 || y >= n || m[x][y] == 0) return;
    if(x == n-1 && y == n-1){
        ans.push_back(path);
        return;
    }
    m[x][y] = 0;
    getPaths2(m,n,path+"D",x+1,y,ans);
    getPaths2(m,n,path+"L",x,y-1,ans);
    getPaths2(m,n,path+"R",x,y+1,ans);
    getPaths2(m,n,path+"U",x-1,y,ans);
    m[x][y] = 1;
}

void solve() {
	int n;
	cin >> n;
	vvi mat(n, vi(n));
	rep(i,0,n) {
		rep(j,0,n) {
			cin >> mat[i][j];
		}
	}

	string path = "";
    vector<string> res;
    
    getPaths(mat, 0, 0, n, path, res);
    rep(i,0,res.size()) cout << res[i] << " ";
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
		solve();
	return 0;
}

#pragma GCC diagnostic pop