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

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int k;cin >> k;
  string t, a;cin >> t >> a;
  vector<int> cnt_t(10), cnt_a(10);
  vector<int> point_t(10), point_a(10);
  for(char c : t){
    if(c != '#')
      cnt_t[c - '0']++;
  }
  for(char c : a){
    if(c != '#')
      cnt_a[c - '0']++;
  }
  for(int i = 1;i <= 9;i++){
    cnt_t[i]++; cnt_a[i]++;
    for(int j = 1;j <= 9;j++){
      point_t[i] += j * (int)pow(10, cnt_t[j]);
      point_a[i] += j * (int)pow(10, cnt_a[j]);
    }
    cnt_t[i]--; cnt_a[i]--;
  }
  double ans = 0;
  for(int i = 1;i <= 9;i++){
    for(int j = 1;j <= 9;j++){
      int rem_all = 0;
      int rem_i = k - cnt_t[i] - cnt_a[i];
      int rem_j = k - cnt_t[j] - cnt_a[j];
      rem_i--; rem_j--;
      if(rem_i < 0 || rem_j < 0)continue;
      if(point_t[i] > point_a[j]){
        for(int l = 1;l <= 9;l++){
          rem_all += k - cnt_t[l] - cnt_a[l];
        }
        double pi = double(rem_i + 1) / (rem_all);
        double pj = double(rem_j + 1 - (i == j ? 1 : 0)) / (rem_all - 1);
        ans += pi * pj;
      }
    }
  }
  printf("%.9lf\n", ans);
}
