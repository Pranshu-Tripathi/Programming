/* NEVER DECLARE ll as UNSIGNED LONG LONG :( */
# include <bits/stdc++.h>
# define ull unsigned long long
# define ll long long
# define double long double
# define pll pair<ll,ll>
# define pb push_back
# define fi first
# define se second
# define mp make_pair
# define max3(a,b,c) max(a,max(b,c))
# define min3(a,b,c) min(a,min(b,c))
# define all(x) x.begin(),x.end()
# define fill(a,b) memset(a,b,sizeof(a))
# define gcd(m,n)  __gcd(m, n)
# define pr_double(x) cout << fixed << setprecision(9) << x
# define endl "\n"

using namespace std;
const ll INF = 922337203685477110;
const ll N = 300005;
const ll mod = 1e9+7;
const ll M = 22;
vector <ll> have[N],want[N];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ll t; cin>>t;
  while(t--)
  {
      ll n,m; cin>>n>>m;
      ll a[n+3],b[n+3],c[m+3]; ll ans[m+3]; vector <ll> extra;
      for(ll i=0;i<n;i++) cin>>a[i];
      for(ll i=0;i<n;i++)
      {
          cin>>b[i];
          if(b[i]==a[i]) have[b[i]].pb(i);
          else want[b[i]].pb(i);
      }
      for(ll i=0;i<m;i++) cin>>c[i];
      for(ll i=0;i<m;i++)
      {
          ll k = c[i];
          if(want[c[i]].size()!=0)
          {
              while(extra.size())
              {
                  ans[extra.back()]=want[k].back();
                  extra.pop_back();
              }
              ans[i]=want[c[i]].back();
              want[c[i]].pop_back();
              have[c[i]].pb(ans[i]);
          }
          else
          {
              if(have[k].size()!=0)
              {
                  while(extra.size())
                  {
                      ans[extra.back()] = have[k].back();
                      extra.pop_back();
                  }

                    ans[i] = have[k].back();

              }
              else{
                extra.pb(i);
              }
          }
      }
      //for(ll i=0;i<m;i++) cout<<ans[i]+1<<" ";
      //cout<<endl;
      if(extra.size()==0)
      {
          ll ok=1;
          for(ll i=0;i<=n;i++)
          {
              if(want[i].size()!=0)
              {
                  ok=0; break;
              }
          }
          if(!ok) cout<<"NO"<<endl;
          else{
          cout<<"YES"<<endl;
          for(ll i=0;i<m;i++) cout<<ans[i]+1<<" ";
          cout<<endl;
          }
      }
      else cout<<"NO"<<endl;
      for(ll i=0;i<=n+2;i++)
      {
          have[i].clear(); want[i].clear();
      }
  }
}
