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

  int n;cin >> n;
  string s, t;cin >> s >> t;
  int cnta = count(s.begin(), s.end(), 'a') +
    count(t.begin(), t.end(), 'a');
  int cntb = count(s.begin(), s.end(), 'b') +
    count(t.begin(), t.end(), 'b');
  if(cnta % 2 ||  cntb % 2){
    cout << -1 << endl;
    return 0;
  }
  vector<int> ba, ab;
  vector<pair<int, int>> ans;
  for(int i = 0;i < n;i++){
    if(s[i] == 'a' && t[i] == 'b')
      ab.push_back(i + 1);
    if(s[i] == 'b' && t[i] == 'a')
      ba.push_back(i + 1);
  }
  while((int)ba.size() >= 2){
    int fst = ba.back();
    int snd = ba[(int)ba.size() - 2];
    ans.push_back({fst, snd});
    ba.pop_back();
    ba.pop_back();
  }
  while((int)ab.size() >= 2){
    int fst = ab.back();
    int snd = ab[(int)ab.size() - 2];
    ans.push_back({fst, snd});
    ab.pop_back();
    ab.pop_back();
  }
  if((int)ba.size() > 0){
    ans.push_back({ab.back(), ab.back()});
    ans.push_back({ab.back(), ba.back()});
  }
  cout << ans.size() << endl;
  for(auto p : ans)
    cout << p.first << ' ' << p.second << endl;
}
