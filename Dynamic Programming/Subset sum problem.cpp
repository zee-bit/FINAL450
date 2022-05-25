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

bool canPartition(vector<int> &arr, int idx, int &N, int target, vector<vector<int>> &dp) {
    if(target == 0) return 1;
    if(idx == N || target < 0) return 0;
    if(dp[idx][target] != -1) return dp[idx][target];
    
    return dp[idx][target] = canPartition(arr, idx+1, N, target, dp) || canPartition(arr, idx+1, N, target-arr[idx], dp);
}

bool solve() {
	int n;
	cin >> n;
	vector<int> nums(n);
	rep(i, 0, n) cin >> nums[i];

	int sum = accumulate(all(nums), 0);
	if(sum & 1) return false;
	sum /= 2;

	// DFS (Top-down/Bottom-up???)
	vector<vector<int>> dp(n+1, vector<int>(sum+1, -1));
	return canPartition(nums, 0, n, sum, dp);

	// DP (using 2-D array)
	vector<vector<bool>> dp(n, vector<bool>(sum+1, false));
	if(nums[0] <= sum) dp[0][nums[0]] = true;
	
	for(int i = 1; i < n; i++) {
		for(int j = 0; j <= sum; j++) {
			if(j == 0) dp[i][j] = true;
			else {
				int skip = dp[i-1][j];
				int take = false;
				if(nums[i] <= j)
					take = dp[i-1][j-nums[i]];
				dp[i][j] = skip | take;
			}
		}
	}
	cout << dp[n-1][sum];

	// DP (using 1-D array)
	vector<bool> dp(sum+1, false);
    dp[0] = true;
    for(int i = 0; i < n; i++) {
        for(int j = sum; j >= nums[i]; j--) {
            dp[j] = dp[j] || dp[j-nums[i]];
        }
    }
    return dp[sum];
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