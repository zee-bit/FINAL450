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

bool match(int i, int j, string &s, string &p, vector<vector<int>> &dp) {
    if(i < 0 && j < 0) return true;
    if(j < 0) return false;
    if(i < 0) {
        while(j >= 0) {
            if(p[j] != '*')
                return false;
            j--;
        }
        return true;
    }
    
    if(dp[i][j] != -1) return dp[i][j];
    
    if(s[i] == p[j] || p[j] == '?')
        return dp[i][j] = match(i-1, j-1, s, p, dp);
    if(p[j] == '*')
        return dp[i][j] = match(i-1, j, s, p, dp) || match(i, j-1, s, p, dp);
    return dp[i][j] = false;
}

void solve() {
	string s, p;
	cin >> s >> p;

	// Memoization
	int S = s.length(), P = p.length();
    vector<vector<int>> dp(S, vector<int>(P, -1));
    return match(S-1, P-1, s, p, dp);

    // Tabulation
    vector<vector<bool>> dp(S+1, vector<bool>(P+1, false));
    dp[0][0] = true;
    for(int i = 1; i <= S; i++)
    	dp[i][0] = false;
    for(int j = 1; j <= P; j++) {
    	bool flag = true;
    	for(int ii = 1; ii <= j; ii++) {
            if(p[ii-1] != '*') {
            	flag = false;
            	break;
            }
        }
        dp[0][j] = flag;
    }

    for(int i = 1; i <= S; i++) {
    	for(int j = 1; j <= P; j++) {
    		if(s[i-1] == p[j-1] || p[j-1] == '?')
			    dp[i][j] = dp[i-1][j-1];
			else if(p[j-1] == '*')
			    dp[i][j] = dp[i-1][j] || dp[i][j-1];
			else
				dp[i][j] = false;
    	}
    }
    cout << dp[S][P];
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