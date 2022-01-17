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

// Binary Search approach. O(NlogN)
int BS_approach(vi &arr) {
	int N = arr.size();

	auto small_or_equal = [&](int ele) {
		int cnt = 0;
		for(int &num : arr) {
			if(num <= ele)
				cnt++;
		}
		return cnt;
	};

	int lo = 1, hi = N, mid, ans;
	while(lo <= hi) {
		mid = (lo + hi) / 2;
		if(small_or_equal(mid) > mid) {
			ans = mid;
			hi = mid - 1;
		}
		else
			lo = mid + 1;
	}
	return ans;
}

void solve() {
	int N;
	cin >> N;
	vi nums(N);
	rep(i,0,N) cin >> nums[i];

	// METHOD-1: BS [O(NlogN)]
	cout << BS_approach(nums);

	// METHOD-2: Array as Hashmap [O(N)]
	while(nums[0] != nums[nums[0]])
		swap(nums[0], nums[nums[0]]);
	cout << nums[0];

	// METHOD-3: Floyd's Cycle detection [O(N)]
	int slow = nums[0], fast = nums[nums[0]];
        
    while(slow != fast) {
        slow = nums[slow];
        fast = nums[nums[fast]];
    }
    
    slow = 0;
    while(slow != fast) {
        slow = nums[slow];
        fast = nums[fast];
    }
    return slow;
}

int main() {
	fast;
	#ifndef ONLINE_JUDGE
  		freopen("input.txt", "r", stdin);
  		freopen("output.txt", "w", stdout);
	#endif
	int t = 1;
	cin >> t;
	while(t--)
		solve();
	return 0;
}

#pragma GCC diagnostic pop