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

  int n, k;cin >> n >> k;
  vector<int> both, fst, snd;
  for(int i = 0;i < n;i++){
    int t, a, b;cin >> t >> a >> b;
    if(a + b == 2)both.push_back(t);
    else if(a == 1)fst.push_back(t);
    else if(b == 1)snd.push_back(t);
  }
  sort(both.begin(), both.end());
  sort(fst.begin(), fst.end());
  sort(snd.begin(), snd.end());
  int ptr_b = 0, ptr_f = 0, ptr_s = 0;
  int wa = k, wb = k;
  int ans = 0;
  while(wa > 0 || wb > 0){
    if(ptr_b >= (int)both.size()){
      if(wa > 0 && (int)fst.size() == 0)break;
      if(wb > 0 && (int)snd.size() == 0)break;
    }
    if(wa > 0 && wb > 0){
      if(ptr_b >= (int)both.size()){
        if(ptr_f < (int)fst.size() && ptr_s < (int)snd.size()){
          wa--; wb--;
          ans += fst[ptr_f++] + snd[ptr_s++];
        }
        else break;
      }
      else{
        if(ptr_f < (int)fst.size() && ptr_s < (int)snd.size()){
          if(both[ptr_b] <= fst[ptr_f] + snd[ptr_s]){
            wa--; wb--;
            ans += both[ptr_b++];
          }
          else{
            wa--; wb--;
            ans += fst[ptr_f++] + snd[ptr_s++];
          }
        }
        else{
          wa--; wb--;
          ans += both[ptr_b++];
        }
      }
    }
    else assert(false);
  }
  if(wa == 0 && wb == 0)cout << ans;
  else cout << -1;
  cout << endl;
}
