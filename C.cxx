#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vb = vector<bool>;
using vvb = vector<vb>;
using vi = vector<int>;
using vvi = vector<vi>;
using vl = vector<ll>;
using vvl = vector<vl>;
using vc = vector<char>;
using vvc = vector<vc>;
using vs = vector<string>;
const ll modd =1e9 + 7,inf = 1e18;
const ll mod = 998244353;
#define pb push_back
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
void setIO()
{
    fast;
    #ifndef ONLINE_JUDGE
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    #endif
}
vl fact(3e5 + 5,1);
ll binpow(ll a,ll b)
{
    if (b == 0)return 1;
    if (b == 1)return a;
    ll ret = binpow(a,b/2);
    if (b%2 == 0)return (ret * ret)%mod;
    return ((ret * ret)%mod * a)%mod;
}
ll inv(ll a)
{
    return (binpow(a,mod - 2)%mod + mod)%mod;
}
ll gauss(ll n) {
  return (n * (n + 1) % mod) * inv(2) % mod;
}
ll binom(ll a,ll b)
{
    if (b < 0 or a < 0) return 0;
    return (((fact[a] * inv(fact[b]))%mod * inv(fact[a - b]))%mod + mod)%mod;
}
int main()
{
    setIO();
    for (int i = 1;i<=3e5;i++)fact[i] = (i * fact[i - 1])%mod;  
    
    ll n,k;
    cin >> n >> k;
    
    vector<pair<ll,ll>>vp;
    
    for(int i = 0; i < n; i++){
        
        ll l,r;
        cin >> l >> r;
        
        vp.push_back({l,1});
        vp.push_back({r + 1, -1});
    }
    
    sort(vp.begin(),vp.end());
    
    ll ans = 0;
    
    ll cnt = 0;
    for(int i = 0; i < 2 * n; i++){
        
        if(vp[i].second == 1){
            
            if(cnt >= k - 1){
                ans = (ans % mod + binom(cnt,k - 1) % mod) % mod;
            }
            cnt++;
            
        }else{
            cnt--;
        }
    }
    cout << ans << "\n";
    
    
    return 0;
}
