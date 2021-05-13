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

vector<vector<int>> parent(200010, vector<int>(30));

int lift(int s, int c){
  int cur = s;
  for(int i = 0;i < 30;i++){
    if((1 << i) & c){
      cur = parent[cur][i];
    }
  }
  return cur;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, q;cin >> n >> q;
  for(int i = 1;i <= n;i++){
    cin >> parent[i][0];
  }
  for(int i = 1;i < 30;i++){
    for(int j = 1;j <= n;j++){
      parent[j][i] = parent[parent[j][i - 1]][i - 1];
    }
  }
  for(int i = 0;i < q;i++){
    int a, b;cin >> a >> b;
    cout << lift(a, b) << endl;
  }
}
