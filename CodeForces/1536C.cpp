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

pair<int, int> mn(pair<int, int> &p){
  int fst = p.first;
  int snd = p.second;
  if(fst == 1 && snd == 1)return p;
  int g = __gcd(fst, snd);
  while(g != 1){
    fst /= g;
    snd /= g;
    g = __gcd(fst, snd);
  }
  return make_pair(fst, snd);
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;cin >> t;
  while(t--){
    int n;cin >> n;
    string s;cin >> s;
    int k = 0, d = 0;
    map<pair<int, int>, int> m;
    for(int i = 0;i < n;i++){
      if(s[i] == 'K')k++;
      else d++;
      pair<int, int> frac = make_pair(d, k);
      frac = mn(frac);
      m[frac]++;
      cout << m[frac] << ' ';
    }
    cout << endl;
  }
}
