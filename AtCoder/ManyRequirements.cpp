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

vector<vector<int>> comb;

void fuck(int cur_num, int cur_cnt, int mx_num, int mx_cnt, vector<int> &arr){
  if(cur_cnt > mx_cnt){
    comb.push_back(arr);
    return;
  }
  for(int i = cur_num;i <= mx_num;i++){
    arr.push_back(i);
    fuck(i, cur_cnt + 1, mx_num, mx_cnt, arr);
    arr.pop_back();
  }
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m, q;cin >> n >> m >> q;
  int mx = 0;
  vector<int> arr;
  fuck(1, 1, m, n, arr);
  vector<pair<pair<int, int>, pair<int, int>>> que;
  for(int i = 0;i < q;i++){
    int a, b, c, d;cin >> a >> b >> c >> d;
    a--; b--;
    que.push_back({{a, b}, {c, d}});
  }
  for(auto v : comb){
    int cur = 0;
    for(auto p : que){
      int a = p.first.first;
      int b = p.first.second;
      int c = p.second.first;
      int d = p.second.second;
      if(v[b] - v[a] == c)cur += d;
    }
    mx = max(cur, mx);
  }
  cout << mx << endl;
}
