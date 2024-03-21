#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define ll long long 
#define lb lower_bound
#define bg begin
#define sz(a) int((a).size())
#define minii min_element
#define maxii max_element
#define rv reverse
#define fr front
#define bk back 
#define ppf pop_front
#define cl clear
#define ppb pop_back
#define no_cnt log10
#define up upper_bound
#define accu accumulate
#define pp pop_back
#define nl '\n'
#define in insert
#define pu push
#define er erase
#define pb push_back
#define ff first
#define ss second
const int MAXN = 2e5 + 5;
#define all(v) v.begin(),v.end()
#define allr(v) v.rbegin(),v.rend()
typedef vector<int> vi;
const int N = 1e6;
const int MX = 1e6;
#define Pi 3.14159265359
#define rep(i, n) for(int i = 0; i<n; ++i)
#define MOD 1000000007
#define mod (int )(1e9 + 7)
#define modd 998244353
#define pii pair<int, int>
#define lcm(a , b) (a*b)/(__gcd(a , b))

ll mex_kandupiddikyan(vector<ll>A) {
    set<int> b(A.begin(), A.end());
 
    int result = 0;
    while (b.count(result))
        ++result;
    return result;
}
 ll digitinde_sum(ll n)                                                            
{ 
    ll num=0;
    while(n>0)
    {
        num+=n%10;
        n=n/10;
    }
    return num;
}
 
// ll leastprimefactor(ll n)      least prime factor                                                                  // LEAST PRIME FACTOR OF A NUMBER
// {
//     for(ll i=2;i*i<=n;i++)
//     {
//         if(n%i==0)
//         {
//             return i;
//             break;
//         }
//     }
//     return n;
// }
 
ll fact(ll n)                             
{
    ll i=1;
    while(n>1)
    {
        i*=n;
        n-=1;
    }
    return i;
}

 // divisors
 
 // vector<ll>div;
 // for(ll i=1; i*i<=n; i++){
 //    if(n%i==0){
 //        div.push_back(i);
 //        if(i*i != n)
 //            div.push_back(n/i);
 //    }
 // }
// ll pref[MAXN];
 
 // remvoing specific factors
 
  // while(a[i]%2==0){
  //           a[i] = a[i]/2;
  //       }
  //       while(a[i]%3==0){
  //           a[i] = a[i]/3;
  //       }
 //odd_divisors
   // vector<ll>odd_divisors;
   //      for(ll i=2; i*i<=n; i++){
   //          if(n%i==0){
   //              if(n/i == i and i%2!=0) odd_divisors.push_back(i);
   //              else{
   //                  if(i%2!=0) odd_divisors.push_back(i);
   //                  if((n/i)%2!=0) odd_divisors.push_back(n/i);
   //              }   
   //          }
   //      }
 
int oru_power(int a, int b, int m)
{
  long long res = 1;
  while (b)
  {
    if (b & 1)
      res = res * a;
    res %= m;
    a = (1ll * a * a) % m;
    b = b >> 1;
  }
  return res;
}
 
 
void ith_divisors(int n){
    for (int i=1; i<=sqrt(n); i++)// for(ll i=1; i*i<=n; i++)
    {if (n%i == 0)
        { if (n/i == i)
                cout <<" "<< i;
  
            else 
                cout << " "<< i << " " << n/i;
        }
    }
}
ll power(ll x,ll y){
    if(x==0)return 1;
   ll ans=power(x/2,y);
    ans*=ans;
    ans%=MOD;
    if(x%2)ans*=y;
    ans%=MOD;
    return ans;
 
 
}
ll gcd(int a, int b){
    while(b){
        a%=b;
        swap(a,b);
    }
    return a;
}
bool prime_check_cheyan(int n)
{
    if (n == 1)
        return false;
    if (n == 2)
        return true;
    for (int i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
            return false;
    }
    return true;
}
 
ll binExpo(ll a,ll b){
    ll ans=1;
    while(b){
        if(b&1){
            ans=(ans*a)%mod;
        }
        a=(a*a)%mod;
        b>>=1;
    }
    return ans;
}
 
bool bit_check_cheyan(ll num, ll i) {
    return num & (1LL << i);
}
 
bool composite_check_cheyan(int n) {
    for (int i=2; i<=n/2; i++) {
        if (n%i == 0) return true;
    }
    return false;
}
 
int advance_prime(long long n) // onnula simple annu sieve elle athu .
{
    if (n < 2)
        return 0;
    if (n == 2)
        return 1;
    if (n % 2 == 0)
        return 0;
    for (long long i = 3; i <= sqrt(n); i += 2)
    {
        if (n % i == 0)
            return 0;
    }
    return 1;
}
ll inv(ll x){
    return binExpo(x,mod-2);
}
bitset<MX> is_prime;
vector<int> prime;
set<int>st;
void prime_in_vector( int  n )
{
    for ( int i = 3; i <= n; i += 2 ) is_prime[i] = 1;
 
    for ( int  i = 3; i * i <= n; i += 2 ) {
        if ( is_prime[i] == 1 ) {
            for ( int  j = i+i; j <= n; j += i ) {
                is_prime[j] = 0;
            }
        }
    }
 
    is_prime[2] = 1;
    prime.push_back (2);
 
    for ( int i = 3; i <= n; i += 2 ) {
        if ( is_prime[i] == 1 ) prime.push_back ( i );
    }
}
int highest_2_factor(int n) // like 2^5 or 2^6 ans
{
    int ans=1,div=1;
    int temp=n;
    for(int i=2;i*i<=n;i++)
    {
         while(temp%i==0)
         {
            ans*=i;
            div=i;
            temp/=i;
         }
    }
    if(temp==1)
    ans/=div;
    return ans;
}
void divisors_set( int n)
{
  if(n==1) return;
  int idx=0,pf=prime[idx];
  while(pf*pf<=n)
  {
     while(n%pf==0)
     {
       n/=pf;
       st.insert(pf);
     }
   
     pf=prime[++idx];
  }
  if(n != 1) st.insert(n);
}
void solve(){
// typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> pbds;
        ll n;
        cin>>n;
       vi a(n);
       for(auto&x : a) cin>>x;
        ll i=0;
        ll count=0;
        ll x=v[i];
        while(i<n){
           x = x & v[i];
           i++;
           if(x==0){
               count++;
               x=v[i];
           }
        }
        if(cnt == 0) cout << 1 << nl;
        else cout << cnt << nl;

}
int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 // freopen("input.txt", "r",stdin);
 // freopen("output.txt", "w",stdout);
    ll t;
    cin>>t;
    while(t--){
   solve();
}
    return 0;
}
