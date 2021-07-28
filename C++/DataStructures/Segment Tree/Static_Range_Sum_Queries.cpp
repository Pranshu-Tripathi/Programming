/*
Champions Never Break. Believe in Yourself while Others Doubt You.
What defines us is .... How Will We Rise After Falling
Lazy People Work A little bit and start worrying they should be winning....
Winners work as hard as possible and and yet worry about are they being lazy
*/
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define fast                   \
  ios::sync_with_stdio(false); \
  cin.tie(NULL),               \
      cout.tie(NULL)
#define cy cout << "YES" << endl
#define cn cout << "NO" << endl
#define ld long double
#define mod 1000000007
#define slen(x) x.length()
#define debug(a...)    \
  cout << #a << ": ";  \
  for (auto it : a)    \
    cout << it << " "; \
  cout << endl;
#define fillall(x, val) memset(x, val, sizeof(x))
#define display(a...)  \
  for (auto it : a)    \
    cout << it << ' '; \
  cout << endl;
#define all(x) x.begin(), x.end()
#define maximum_int __INT_MAX__
#define minimum_int __WINT_MIN__
#define INF LLONG_MAX
#define NEG_INF LLONG_MIN

bool sortBySecond(const pair<ll, ll> &a, const pair<ll, ll> b)
{
  return a.second > b.second;
}
int ncr[1001][1001];
bool vis_ncr[1001][1001];
ll NCR(int n, int r)
{
  if (n < r)
    return 0;
  if (vis_ncr[n][r])
    return ncr[n][r];
  if (r == 0)
    return 1;
  if (r == 1)
    return n;
  if (n == 0)
    return 0;
  ncr[n][r] = NCR(n - 1, r) + NCR(n - 1, r - 1);
  vis_ncr[n][r] = true;
  return ncr[n][r];
}
// template<typename... T>
// void log(T&&... args) {
//     ((cout << args << " "), ...);
//     cout << "\n";
// }
template <typename K, typename V>
void printMapMultipleValue(map<K, V> const &mp, string name)
{
  cout << name << ":\n";
  for (auto const &pa : mp)
  {
    cout << pa.first << " : ";
    cout << "{";
    for (auto const &x : pa.second)
      cout << x << ',';
    cout << "}\n";
  }
}
template <typename K, typename V>
void printMap(map<K, V> const &mp, string name)
{
  cout << name << ":" << endl;
  for (auto const &pa : mp)
    cout << "{" << pa.first << " : " << pa.second << "}" << endl;
}

bool isPrime[100006];
void _seive()
{
  memset(isPrime, true, sizeof(isPrime));
  isPrime[1] = false;
  isPrime[0] = false;
  for (int i = 2; i * i <= 100005; i++)
  {
    for (int j = i * i; j <= 100005; j += i)
    {
      isPrime[j] = false;
    }
  }
}
ll expo(int a, int b)
{
  if (b == 0)
    return 1;
  else if (b == 1)
    return a;
  else if (b % 2 == 0)
  {
    ll ret = expo(a, b / 2);
    ret = (ret % mod * ret % mod) % mod;
    return ret;
  }
  else
  {
    ll ret = expo(a, b / 2);
    ret = (ret % mod * ret % mod) % mod;
    ret = (ret % mod * a % mod) % mod;
    return ret;
  }
}
ll inverseMod(ll a, ll m) { return expo(a, m - 2) % m; }
ll fact[100005];
void factorial()
{
  fact[0] = fact[1] = 1;
  for (int i = 2; i < 100005; i++)
    fact[i] = (fact[i - 1] % mod * i % mod) % mod;
}
ll GCD(ll a, ll b)
{
  if (a == 0)
    return b;
  return GCD(b % a, a);
}
ll mult(ll a, ll b) { return (a % mod * b % mod) % mod; }
ll add(ll a, ll b)
{
  a += b;
  if (a >= mod)
    return a - mod;
  return a;
}
ll sub(ll a, ll b)
{
  a -= b;
  if (a < 0)
    return a + mod;
  return a;
}

/*********************************Coding Arena******************************/

void _run()
{
    int n,q;
    cin >> n >> q;
    vector<ll> v(n);
    for(int i = 0 ; i < n ; i++)
        cin >> v[i];
    for(int i = 1 ; i < n ; i++)
        v[i] += v[i-1];
    //display(v);
    while(q--)
    {
        int l,r;
        cin >> l >> r;
        l--,r--;
        ll ans = v[r];
        if(l > 0)
            ans -= v[l-1];
        cout << ans << endl;
    }
}

/*********************************TestCase Function***************************/

int main()
{
  fast;
  int test = 1;
  //cin >> test;
  while (test--)
    _run();
  // for(int i = 1 ; i <= test ; i++)
  // {
  //     int ans = _run();
  //     cout << "Case #"<<i << ": " << ans << endl;
  // }
  return 0;
}


/*
 Comic Sans MS, 'Comic Sans', normal
*/