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

// Returns {Missing, Repeating}
void solve() {
	int N;
	cin >> N;
	vi arr(N);
	rep(i, 0, N) cin >> arr[i];

	// METHOD-1: Searching (Naive)
	vector<int> cnt(N + 1, 0), ans(2);
	for(int a : arr)
		cnt[a]++;
	for(int i = 1; i <= N; i++) {
		if(cnt[i] == 0)
			ans[0] = i;
		else if(cnt[i] > 1)
			ans[1] = i;
	}
	cout << ans[0] << " " << ans[1] << "\n";


	// METHOD-2: Bit Manipulation
	int full_xor = 0, arr_xor = 0;
	for(int a : arr) arr_xor ^= a;
	for(int i = 1; i <= N; i++) full_xor ^= i;

	int a_xor_b = full_xor ^ arr_xor;
	int mask = a_xor_b & (~(a_xor_b - 1));

	int g1 = 0, g2 = 0;
	for(int a : arr) {
		if(a & mask) g1 ^= a;
		else g2 ^= a;
	}
	for(int i = 1; i <= N; i++) {
		if(i & mask) g1 ^= i;
		else g2 ^= i;
	}

	for(int a : arr) {
		if(a == g1) {
			cout << g2 << " " << g1 << "\n";
			return;
		}
	}
	cout << g1 << " " << g2 << "\n";
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