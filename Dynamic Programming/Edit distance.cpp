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

// first we compare last characters if same we will proceed 
// otherwise we can apply any one operation(1 operation is must) so return 1+min{insert,remove,replace}
// if we insert -→findfor(m,n-1) as that character at position stays now we compare n-1 and m;
// if we replace--→findfor(m-1,n-1)as we are replacing we move to next character from backward
// if we remove-→findfor(m-1,n) after removing we compare m-1 th with n th  of string 2

int editDistance(string &s, string &t, int S, int T, vector<vector<int>> &dp) {
	if(S < 0) return T+1;
	if(T < 0) return S+1;
	if(dp[S][T] != -1) return dp[S][T];

	if(s[S] == t[T])
		return dp[S][T] = editDistance(s, t, S-1, T-1, dp);
	else {
		return dp[S][T] = 1 + min({
			editDistance(s, t, S-1, T, dp),
			editDistance(s, t, S-1, T-1, dp),
			editDistance(s, t, S, T-1, dp)
		});
	}
}

void solve() {
	string s, t;
	cin >> s >> t;
	if(s == t) {cout << 0;return;}
	int S = s.length(), T = t.length();
	vector<vector<int>> dp(S+1, vector<int>(T+1, -1));

	// Top-down
	cout << editDistance(s, t, S-1, T-1, dp) << "\n";

	// Bottom-up
	for(int i = 0; i <= S; i++) {
		for(int j = 0; j <= T; j++) {
			if(i == 0)
				dp[i][j] = j;
			else if(j == 0)
				dp[i][j] = i;
			else {
				if(s[i-1] == t[j-1])
					dp[i][j] = dp[i-1][j-1];
				else
					dp[i][j] = 1 + min({dp[i-1][j], dp[i-1][j-1], dp[i][j-1]});
			}
		}
	}
	cout << dp[S][T];
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