
#include <bits//stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

// MACROS
#define int                     long long
#define pb                      push_back
#define MAX                     2e18+5
#define MIN                     -2e18-5
#define mod                     1000000007
#define eps                     1e-9
#define set(x)                  memset(x, 0, sizeof(x))
#define clr(x)                  memset(x, -1, sizeof(x))
#define ff                      first
#define ss                      second
#define rep(i,a,b)              for(int i=a;i<b;i++)
#define sz(x)                   x.size()
#define endl                    "\n"
#define deb(x)                  cout << #x << "=" << x << endl
#define deb2(x, y)              cout << #x << "=" << x << "," << #y << "=" << y << endl
#define all(x)                  x.begin(), x.end()
#define lb(a,x)                 lower_bound(all(a),x)
#define ub(a,x)                 upper_bound(all(a),x)

typedef priority_queue<int>     maxHeap;
typedef priority_queue<int,     vector<int>, greater<int>> minHeap;
typedef pair<int, int>          pii;
typedef vector<int>             vi;
typedef vector<string>          vs;
typedef vector<pii>             vpii;
typedef vector<vi>              vvi;
typedef map<int, int>            mpii;
typedef set<int>                seti;
typedef multiset<int>           mseti;
template<typename T> // find_by_order, order_of_key
using pbds = tree<T , null_type , less<T> , rb_tree_tag , tree_order_statistics_node_update>;
template<typename T, typename T1>T amax(T &a, T1 b) {if (b > a)a = b; return a;}
template<typename T, typename T1>T amin(T &a, T1 b) {if (b < a)a = b; return a;}
// typedef long long int           ll;


// cout << fixed << setprecision(9) <<
int mpow(int base, int exp);

const int T2 = 105; const int T3 = 1005; const int T4 = 10005; const int T5 = 100005;
const int N = 3e5;

int arr[N];


void solve() {
    int n, m;
    cin >> n >> m;
    int cs, cw, s, w;
    cin >> cs >> cw >> s >> w;
    if (s > w) {
        swap(s, w);
        swap(cs, cw);
    }
    int ans = MIN;
    for (int i = 0; i <= cs; i++) {
        int N = n, M = m, currcs = cs, currcw = cw;
        if (i * s <= N) {
            N -= i * s; currcs -= i;

            int wNcouldtake = N / w;
            wNcouldtake = min(wNcouldtake, currcw);
            N -= wNcouldtake * w;
            currcw -= wNcouldtake;

            int sMcouldtake = M / s;
            sMcouldtake = min(sMcouldtake, currcs);
            M -= sMcouldtake * s;
            currcs -= sMcouldtake;

            int wMcouldtake = M / w;
            wMcouldtake = min(wMcouldtake, currcw);
            M -= wMcouldtake * w;
            currcw -= wMcouldtake;
            amax(ans, cs + cw - (currcw + currcs));
        }
    }
    cout << ans << endl;






}


/* TIPS
1. for interactive prob remove fastio and endl
2. for vector pass as reference
3. dont use set and clr when n * t is very large use loop till n instead.
4. don't forget to clear the graph
5.

*/



int32_t main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#ifndef ONLINE_JUDGE
    // for getting input from input.txt
    freopen("input.txt", "r", stdin);
    // for writing output to output.txt
    freopen("output.txt", "w", stdout);
#endif
    int t = 1;
    cin >> t;
    for (int i = 1; i <= t; i++) {

        // cout<<"Case #"<<i<<": ";

        solve();


    }
    return 0;
}

int mpow(int base, int exp) {
    base %= mod;
    int result = 1;
    while (exp > 0) {
        if (exp & 1) result = ((int)result * base) % mod;
        base = ((int)base * base) % mod;
        exp >>= 1;
    }
    return result;
}

