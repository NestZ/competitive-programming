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

bool fuck(string s){
  int n = s.size();
  if(n == 1)return s == "8";
  if(n == 2){
    if(stoi(s) % 8 == 0)return true;
    swap(s[0], s[1]);
    return stoi(s) % 8 == 0;
  }
  vector<int> cnt(10);
  for(char x : s)cnt[x - '0']++;
  for(int i = 112;i < 1000;i += 8){
    auto c = cnt;
    for(char x : to_string(i))c[x - '0']--;
    if(all_of(c.begin(), c.end(), [](int x){ return x >= 0; }))
      return true;
  }
  return false;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  string s;cin >> s;
  if(fuck(s))cout << "Yes";
  else cout << "No";
  cout << endl;
}
