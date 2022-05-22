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

int dfs(int r, int c1, int c2, vector<vector<int>> &arr, vector<vector<vector<int>>> &dp) {
	if(c1 < 0 || c2 < 0 || c1 >= n || c2 >= n)
		return -1e8;
	if(r == m-1) {
		if(c1 == c2) return arr[r][c1];
		else return arr[r][c1] + arr[r][c2];
	}

	if(dp[r][c1][c2] != -1) return dp[r][c1][c2];

	int ans = INT_MIN;
	for(int i = -1; i <= 1; i++) {
		for(int j = -1; j <= 1; j++) {
			int val = dfs(r+1, c1+i, c2+j, arr, dp);
			if(c1 == c2) val += arr[r][c1];
			else val += arr[r][c1] + arr[r][c2];
			ans = max(ans, val);
		}
	}
	return dp[r][c1][c2] = ans;
}

void solve() {
	int m, n;
	cin >> m >> n;
	vector<vector<int>> grid;
	rep(i, 0, m) {
		rep(j, 0, n)
			cin >> grid[i][j];
	}

	// Memoization
	vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>(n, -1)));
	cout << dfs(0, 0, n-1, grid, dp) << "\n";

	// Tabulation
	for(int j1 = 0; j1 < n; j1++) {
		for(int j2 = 0; j2 < n; j2++) {
			if(j1 == j2) dp[m-1][j1][j2] = arr[m-1][j1];
			else dp[m-1][j1][j2] = arr[m-1][j1] + arr[m-1][j2];
		}
	}

	for(int r = m-2; r >= 0; r--) {
		for(int j1 = 0; j1 < n; j1++) {
			for(int j2 = 0; j2 < n; j2++) {

				int ans = -1e8;
                for(int i = -1; i <= 1; i++) {
                    for(int j = -1; j <= 1; j++) {
                        int val = 0;

                        if(j1 == j2) val += arr[r][j1];
                        else val += arr[r][j1] + arr[r][j2];
                        
                        if(j1+i >= 0 and j1+i < n and j2+j >= 0 and j2+j < n)
                            val += dp[r+1][j1+i][j2+j];
                        else
                            val += -1e8;

                        ans = max(ans, val);
                    }
                }

                dp[r][j1][j2] = ans;
			}
		}
	}
	cout << dp[0][n-1][n-1];
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