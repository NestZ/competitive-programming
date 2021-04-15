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

vector<int> ft(500010, 0);

int sum(int k){
  int s = 0;
  while(k >= 1){
    s += ft[k];
    k -= k & -k;
  }
  return s;
}

void add(int k, int x){
  while(k < 500010){
    ft[k] += x;
    k += k & -k;
  }
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, q;cin >> n >> q;
  vector<int> arr(n + 1);
  vector<int> ans(q);
  vector<int> lst(n + 1);
  vector<vector<int>> ql(n + 1);
  vector<vector<int>> qid(n + 1);
  for(int i = 1;i <= n;i++)cin >> arr[i];
  for(int i = 0;i < q;i++){
    int l, r;cin >> l >> r;
    ql[r].push_back(l);
    qid[r].push_back(i);
  }
  for(int i = 1;i <= n;i++){
    if(lst[arr[i]] > 0)
      add(lst[arr[i]], -1);
    add(i, 1);
    lst[arr[i]] = i;
    for(int j = 0;j < (int)ql[i].size();j++){
      ans[qid[i][j]] = sum(i) - sum(ql[i][j] - 1);
    }
  }
  for(int i = 0;i < q;i++)
    cout << ans[i] << endl;
}
