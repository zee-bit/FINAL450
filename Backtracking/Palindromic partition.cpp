// // #include <bits/stdc++.h>
// // using namespace std;
// // using namespace std::chrono;
// // typedef long long ll;
// // typedef long double ld;
// // struct custom_hash;
// // #define ff first
// // #define I insert
// // #define ss second
// // #define maxN 300002
// // #define inf INT_MAX
// // #define ninf INT_MIN
// // #define pb push_back
// // #define popb pop_back
// // #define pf push_front
// // #define pi 3.14159265
// // #define ub upper_bound
// // #define lb lower_bound
// // #define popf pop_front
// // #define mod 1000000007
// // #define vi vector<int> 
// // #define mll map<ll, ll>
// // #define vll vector <ll>
// // const int dx4[]={-1,0,1,0};
// // const int dy4[]={0,1,0,-1};
// // #define vvi vector<vector<int> >
// // #define all(v) v.begin(), v.end()
// // #define rall(v) v.rbegin(), v.rend()
// // const int dx8[]={-1,-1,-1,0,1,1,1,0};
// // const int dy8[]={-1,0,1,1,1,0,-1,-1};
// // #define ust unordered_set<ll, custom_hash>
// // #define rep(i, a, b) for(ll i = a; i < ll(b); i++)
// // #define umll unordered_map<ll, ll, custom_hash>
// // #define fast ios_base::sync_with_stdio(false);cin.tie(NULL);
// // struct custom_hash { size_t operator()(uint64_t x) const { static const uint64_t FIXED_RANDOM =
// // chrono::steady_clock::now().time_since_epoch().count();x ^= FIXED_RANDOM;return x ^ (x >> 16);}};
// // ll power(ll x,ll n) {ll result=1; while(n) {if(n%2==1) result=result*x; n=n/2; x=x*x;} return result;}
// // ll gcd(ll a, ll b) {return b ? gcd(b, a%b) : a;} 
// // ll lcm(ll a , ll b){return (a*b)/gcd(a,b);}
// // ll BS(ll a[],ll s,ll n,ll val) {ll mid,beg=s,end=n-1; while(beg<=end)
// // {mid=(beg+end)/2; if(val==a[mid]){break;} else if(val>a[mid]){beg=mid+1;}else{end=mid-1;}} return mid;}
// // inline ll mul(ll x,ll y,ll m){ll z=1LL*x*y;if (z>=m){z%=m;} return z;}
// // ll powmod(ll x,ll y,ll m){ll r=1;while(y){if(y&1){r=mul(r,x,m);}y>>=1;x=mul(x,x,m);}return r;}
// // #pragma GCC diagnostic push
// // #pragma GCC diagnostic ignored "-Wunused-result"

// // //========================================XXXXXXXXXXXXXXXX=======================================

// // bool isPalindrome(string s, int start, int end) {
// //     while(start < end) {
// //         if(s[start] != s[end])
// //             return false;
// //         start++;
// //         end--;
// //     }
// //     return true;
// // }

// // void getPalindromes(string s, int start, vector<string> &curr, vector<vector<string>> &res) {
// //     if(start == s.length()) {
// //         res.push_back(curr);
// //         return;
// //     }
       
// //     for(int end = start; end < s.length(); end++) {
// //         if(isPalindrome(s, start, end)) {
// //             string pal = s.substr(start, end - start + 1);
// //             curr.push_back(pal);
// //             getPalindromes(s, end + 1, curr, res);
// //             curr.pop_back();
// //         }
// //     }
// // }

// // void solve() {
// // 	string s;
// // 	cin >> s;

// // 	vector<string> curr;
// //     vector<vector<string>> res;
// //     getPalindromes(s, 0, curr, res);
// //     rep(i, 0, res.size()) {
// //     	rep(j, 0, res[i].size()) {
// //     		cout << res[i][j] << " ";
// //     	}
// //     	cout << "\n";
// //     }
// // }

// // int main() {
// // 	fast;
// // 	#ifndef ONLINE_JUDGE
// //   		freopen("../input.txt", "r", stdin);
// //   		freopen("../output.txt", "w", stdout);
// // 	#endif
// // 	int t = 1;
// // 	// cin >> t;
// // 	while(t--)
// // 		solve();
// // 	return 0;
// // }

// // #pragma GCC diagnostic pop

// #include <bits/stdc++.h>
// using namespace std;
// using namespace std::chrono;
// typedef long long ll;
// typedef long double ld;
// struct custom_hash;
// #define ff first
// #define I insert
// #define ss second
// #define maxN 300002
// #define inf INT_MAX
// #define ninf INT_MIN
// #define pb push_back
// #define popb pop_back
// #define pf push_front
// #define pi 3.14159265
// #define ub upper_bound
// #define lb lower_bound
// #define popf pop_front
// #define mod 1000000007
// #define vi vector<int> 
// #define mll map<ll, ll>
// #define vll vector <ll>
// const int dx4[]={-1,0,1,0};
// const int dy4[]={0,1,0,-1};
// #define vvi vector<vector<int> >
// #define all(v) v.begin(), v.end()
// #define rall(v) v.rbegin(), v.rend()
// const int dx8[]={-1,-1,-1,0,1,1,1,0};
// const int dy8[]={-1,0,1,1,1,0,-1,-1};
// #define ust unordered_set<ll, custom_hash>
// #define rep(i, a, b) for(ll i = a; i < ll(b); i++)
// #define umll unordered_map<ll, ll, custom_hash>
// #define fast ios_base::sync_with_stdio(false);cin.tie(NULL);
// struct custom_hash { size_t operator()(uint64_t x) const { static const uint64_t FIXED_RANDOM =
// chrono::steady_clock::now().time_since_epoch().count();x ^= FIXED_RANDOM;return x ^ (x >> 16);}};
// ll power(ll x,ll n) {ll result=1; while(n) {if(n%2==1) result=result*x; n=n/2; x=x*x;} return result;}
// ll gcd(ll a, ll b) {return b ? gcd(b, a%b) : a;} 
// ll lcm(ll a , ll b){return (a*b)/gcd(a,b);}
// ll BS(ll a[],ll s,ll n,ll val) {ll mid,beg=s,end=n-1; while(beg<=end)
// {mid=(beg+end)/2; if(val==a[mid]){break;} else if(val>a[mid]){beg=mid+1;}else{end=mid-1;}} return mid;}
// inline ll mul(ll x,ll y,ll m){ll z=1LL*x*y;if (z>=m){z%=m;} return z;}
// ll powmod(ll x,ll y,ll m){ll r=1;while(y){if(y&1){r=mul(r,x,m);}y>>=1;x=mul(x,x,m);}return r;}
// #pragma GCC diagnostic push
// #pragma GCC diagnostic ignored "-Wunused-result"

// //========================================XXXXXXXXXXXXXXXX=======================================

// void solve() {
//     int x, y, a, b;
//     cin >> x >> y >> a >> b;
//     int dis = abs(x-y);
//     int X = abs(x-a) + abs(y-b);
//     int Y = abs(x-b) + abs(y-a);
//     cout << min({dis, X, Y});
// }

// int main() {
//     fast;
//     #ifndef ONLINE_JUDGE
//           freopen("../input.txt", "r", stdin);
//           freopen("../output.txt", "w", stdout);
//     #endif
//     int t = 1;
//     // cin >> t;
//     while(t--)
//         solve();
//     return 0;
// }

// #pragma GCC diagnostic pop

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

void dfs(int node, vvi &adj, int &nodes, int &ones, vi &deg, vector<bool> &vis) {
    nodes++;
    vis[node] = true;
    if(deg[node] != 1)
        ones++;

    for(int child : adj[node]) {
        if(!vis[child]) {
            dfs(child, adj, nodes, ones, deg, vis);
        }
    }
}

void solve() {
    int n, m;
    cin >> n >> m;
    vvi adj(n+1);
    vector<bool> vis(n+1);
    vi degree(n+1, 0), res(n+1, 0);

    rep(i, 0, m) {
        int x, y;
        cin >> x >> y;
        adj[x].pb(y);
        adj[y].pb(x);
        degree[x]++;
        degree[y]++;
    }

    int nodes = 0, ones = 0, ans = 0;
    rep(i, 1, n+1) {
        if(!vis[i]) {
            nodes = 0, ones = 0;
            dfs(i, adj, nodes, ones, degree, vis);
            if(ones == 1)
                res[nodes]++;
        }
    }
    rep(i, 1, n+1) {
        if(res[i] == 1)
            ans++;
    }
    cout << ans;
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