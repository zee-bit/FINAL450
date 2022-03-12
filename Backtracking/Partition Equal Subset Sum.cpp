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

bool solve() {
	int N;
	cin >> N;
	vi arr(N);
	rep(i, 0, N) cin >> arr[i];

	int sum = accumulate(all(arr), 0);
    if(sum & 1) return 0;
    sum /= 2;
    
    // ---------------- Normal 2D DP solution ----------------------------
    vector<vector<bool>> dp(N+1, vector<bool>(sum+1, false));
    
    // Base cases
    for(int i = 0; i <= N; i++)
        dp[i][0] = true;
    
    for(int j = 1; j <= sum; j++) 
        dp[0][j] = false;
    
    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= sum; j++) {
            bool skip = dp[i-1][j];
            bool take = false;
            if(j >= arr[i-1])
                take = dp[i-1][j-arr[i-1]];
            
            dp[i][j] = skip | take;
        }
    }
    return dp[N][sum];
    // ----------------- Space-optimized DP solution ------------------------
    vector<bool> prev(sum+1, false), curr(sum+1, false);

    prev[0] = curr[0] = true; // since dp[0][0] = true
    if(arr[0] <= k) prev[arr[0]] = true;

    // replace dp[i-1] with prev and dp[i] with curr in previous code
    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= sum; j++) {
            bool skip = prev[j];
            bool take = false;
            if(j >= arr[i-1])
                take = prev[j-arr[i-1]];
            
            curr[j] = skip | take;
        }
        prev = curr;
    }
    return prev[sum];
    // ---------------------------------------------------------------------
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