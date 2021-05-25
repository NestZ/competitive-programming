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

vector<pair<int, int>> ans;

void build_small(string &s, int num){
  bool open = true;
  int n = s.length();
  for(int i = 0;i < num;i++, open = !open){
    if(open && s[i] == '(')continue;
    if(!open && s[i] == ')')continue;
    for(int j = i + 1;j < n;j++){
      if((open && s[j] == '(') ||
          (!open && s[j] == ')')){
        reverse(s.begin() + i, s.begin() + j + 1);
        ans.push_back({i + 1, j + 1});
        break;
      }
    }
  }
}

void build_big(string &s, int pos){
  int n = s.length();
  int cnt = (n - pos) / 2;
  for(int i = pos;i < pos + cnt;i++){
    if(s[i] == '(')continue;
    for(int j = i + 1;j < n;j++){
      if(s[j] == '('){
        reverse(s.begin() + i, s.begin() + j + 1);
        ans.push_back({i + 1, j + 1});
        break;
      }
    }
  }
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;cin >> t;
  while(t--){
    ans.clear();
    int n, k;cin >> n >> k;
    string s;cin >> s;
    build_small(s, 2 * (k - 1));
    build_big(s, 2 * (k - 1));
    cout << ans.size() << endl;
    for(auto p : ans){
      cout << p.first << ' ' << p.second << endl; 
    }
  }
}
