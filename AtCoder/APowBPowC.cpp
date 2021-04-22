#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long int ll;

#define sim template < class c
#define ris return * this
#define dor > debug & operator <<
#define eni(x) sim > typename \
  enable_if<sizeof dud<c>(0) x 1, debug&>::type operator<<(c i) {
sim > struct rge { c b, e; };
sim > rge<c> range(c i, c j) { return rge<c>{i, j}; }
sim > auto dud(c* x) -> decltype(cerr << *x, 0);
sim > char dud(...);
struct debug {
#ifdef LOCAL
~debug() { cerr << endl; }
eni(!=) cerr << boolalpha << i; ris; }
eni(==) ris << range(begin(i), end(i)); }
sim, class b dor(pair < b, c > d) {
  ris << "(" << d.first << ", " << d.second << ")";
}
sim dor(rge<c> d) {
  *this << "[";
  for(auto it = d.b;it != d.e;++it)
    *this << ", " + 2 * (it == d.b) << *it;
  ris << "]";
}
#else
sim dor(const c&) { ris; }
#endif
};
#define imie(...) " [" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "

ll bin_pow(ll a, ll b){
  ll res = 1;
  while(b > 0){
    if(b & 1)res = res * a % 4;
    a = a * a % 4;
    b >>= 1;
  }
  return res;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  ll a, b, c;cin >> a >> b >> c;
  ll p = bin_pow(b, c);
  vector<vector<ll>> arr(10, vector<ll>(4));
  arr[1] = {1, 1, 1, 1};
  arr[2] = {6, 2, 4, 8};
  arr[3] = {1, 3, 9, 7};
  arr[4] = {6, 4, 6, 4};
  arr[5] = {5, 5, 5, 5};
  arr[6] = {6, 6, 6, 6};
  arr[7] = {1, 7, 9, 3};
  arr[8] = {6, 8, 4, 2};
  arr[9] = {1, 9, 1, 9};
  cout << arr[a % 10][p] << endl;
}
