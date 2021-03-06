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

int getMinCoins(int idx, int amt, vector<int> &nums, vector<vector<int>> &dp) {
    if(idx == 0) {
        if(amt % nums[idx] == 0) return amt / nums[idx];
        return 1e8;
    }
    
    if(dp[idx][amt] != -1) return dp[idx][amt];
    
    int take = 1e8;
    if(amt - nums[idx] >= 0)
        take = 1 + getMinCoins(idx, amt - nums[idx], nums, dp);
    int skip = getMinCoins(idx - 1, amt, nums, dp);
    return dp[idx][amt] = min(take, skip);
}

int numWays(int idx, int amt, vector<int> &nums, vector<vector<int>> &dp) {
    if(idx == 0) {
        return amt % nums[idx] == 0;
    }
    
    if(dp[idx][amt] != -1) return dp[idx][amt];
    
    int skip = numWays(idx - 1, amt, nums, dp);
    int take = 0;
    if(nums[idx] <= amt)
        take = numWays(idx, amt - nums[idx], nums, dp);
    
    return dp[idx][amt] = skip + take;
}

int solve() {
	int n, amt;
	cin >> n >> amt;
	vector<int> arr(n);
	rep(i, 0, n) {cin >> arr[i];}

	// 1. Min coins needed to get required amount
	// Memoization
	vector<vector<int>> dp(n, vector<int>(amount + 1, -1));
	int minCoins = getMinCoins(n-1, amount, arr, dp);
	cout << minCoins >= 1e8 ? -1 : minCoins;

	// Optimized Tabulation
	vector<int> dp(amt+1, INT_MAX);
	dp[0] = 0;
	for(int i = 1; i <= amt; i++) {
		for(int j = 0; j < n; j++) {
			if(i - arr[j] >= 0 && dp[i - arr[j]] != INT_MAX)
				dp[i] = min(dp[i], 1 + dp[i - arr[j]]);
		}
	}
	cout << dp[amt] == INT_MAX ? -1 : dp[amt];


	// 2. Number of ways to get required amount
	vector<int> dp(amt + 1, 0);
	dp[0] = 1; // for amt=0, {} is one solution
	for(int i = 0; i < n; i++) {
		for(int j = 1; j <= amt; j++) {
			if(j - arr[i] >= 0)
				dp[j] += dp[j - arr[i]];
		}
	}
	cout << dp[amt];
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