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

int mxN = 300010;
vector<int> st(4 * mxN, 0);

int xo(int a, int b){
  a += mxN; b += mxN;
  int res = 0;
  while(a <= b){
    if(a % 2 == 1)res ^= st[a++];
    if(b % 2 == 0)res ^= st[b--];
    a >>= 1; b >>= 1;
  }
  return res;
}

void update(int k, int x){
  k += mxN;
  st[k] = x;
  for(k >>= 1;k >= 1;k >>= 1){
    st[k] = st[2 * k] ^ st[2 * k + 1];
  }
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, q;cin >> n >> q;
  vector<int> arr(n + 1);
  for(int i = 1;i <= n;i++){
    cin >> arr[i];
    update(i, arr[i]);
  }
  for(int i = 0;i < q;i++){
    int t, x, y;cin >> t >> x >> y;
    if(t == 1){
      int cur = xo(x, x);
      update(x, cur ^ y);
    }
    else cout << xo(x, y) << endl;
  }
}
