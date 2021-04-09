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

const int mxN = 500010;
vector<vector<int>> tree(26, vector<int>(mxN + 1, 0));

void add(int k, int x, int idx){
  while(k <= mxN){
    tree[idx][k] += x;
    k += k & -k;
  }
}

int sum(int k, int idx){
  int s = 0;
  while(k >= 1){
    s += tree[idx][k];
    k -= k & -k;
  }
  return s;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;cin >> n;
  string s;cin >> s;
  for(int i = 1;i <= n;i++){
    int ch = s[i - 1] - 'a';
    add(i, 1, ch);
  }
  int q;cin >> q;
  for(int i = 0;i < q;i++){
    int t;cin >> t;
    if(t == 1){
      int idx;cin >> idx;
      int oc = s[idx - 1] - 'a';
      add(idx, -1, oc);
      char c;cin >> c;
      s[idx - 1] = c;
      add(idx, 1, c - 'a');
    }
    else{
      int l, r;cin >> l >> r;
      int cnt = 0;
      for(int j = 0;j < 26;j++){
        if(sum(r, j) > sum(l - 1, j))cnt++;
      }
      cout << cnt << endl;
    }
  }
}
