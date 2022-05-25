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


int maxSize(int idx, int m, int n, vector<string> &strs, vector<vector<vector<int>>> &dp) {
    if(idx == 0) {
        int zeros = count(strs[idx].begin(), strs[idx].end(), '0');
        int ones = strs[idx].length() - zeros;
        
        if(zeros <= m && ones <= n) return 1;
        return 0;
    }
    
    if(dp[idx][m][n] != -1) return dp[idx][m][n];
    
    int skip = maxSize(idx - 1, m, n, strs, dp);
    
    int take = INT_MIN;
    int zeros = count(strs[idx].begin(), strs[idx].end(), '0');
    int ones = strs[idx].length() - zeros;
    if(zeros <= m && ones <= n)
        take = 1 + maxSize(idx - 1, m - zeros, n - ones, strs, dp);
    
    return dp[idx][m][n] = max(skip, take);
}

int findMaxForm(vector<string>& strs, int m, int n) {
    // Memoization [Top-down]
    int S = strs.size();
    vector<vector<vector<int>>> dp(S+1, vector<vector<int>>(m+1, vector<int>(n+1, 0)));
    return maxSize(S-1, m, n, strs, dp);
    
    // Tabulation [Bottom-up]
    for(int i = 0; i < S; i++) {
        for(int j = 0; j <= m; j++) {
            for(int k = 0; k <= n; k++) {
                if(i == 0) {
                    int zeros = count(strs[i].begin(), strs[i].end(), '0');
                    int ones = strs[i].length() - zeros;

                    if(zeros <= j && ones <= k) dp[i][j][k] = 1;
                    else dp[i][j][k] = 0;
                    continue;
                }
                int skip = dp[i - 1][j][k];
    
                int take = INT_MIN;
                int zeros = count(strs[i].begin(), strs[i].end(), '0');
                int ones = strs[i].length() - zeros;
                if(zeros <= j && ones <= k)
                    take = 1 + dp[i - 1][j - zeros][k - ones];

                dp[i][j][k] = max(skip, take);
            }
        }
    }
    
    return dp[S-1][m][n];
    
    // Optimized Tabulation [Bottom-up]
    int dp[m+1][n+1];
    memset(dp, 0, sizeof dp);
    
    for(string &str : strs) {
        int zeros = count(str.begin(), str.end(), '0');
        int ones = str.length() - zeros;
        
        for(int j = m; j >= zeros; j--) {
            for(int k = n; k >= ones; k--) {
                dp[j][k] = max(dp[j][k], 1 + dp[j - zeros][k - ones]);
            }
        }
    }
    
    return dp[m][n];
}

void solve() {
	
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