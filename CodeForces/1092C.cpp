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

bool check_suf(string suf, multiset<string> &all){
  all.erase(all.find(suf));
  int len = suf.length();
  for(int i = 1;i < len;i++){
    string sub = suf.substr(len - i, i);
    auto ptr = all.find(sub);
    if(ptr == all.end())return false;
    all.erase(ptr);
  }
  if((int)all.size() == 0)return true;
  return false;
}

pair<bool, set<string>> check_pre(string pre, string suf, multiset<string> &all){
  all.erase(all.find(pre));
  int len = pre.length();
  set<string> pres;
  pres.insert(pre);
  for(int i = 1;i < len;i++){
    string sub = pre.substr(0, i);
    auto ptr = all.find(sub);
    if(ptr == all.end())
      return {false, pres};
    pres.insert(sub);
    all.erase(ptr);
  }
  return {check_suf(suf, all), pres};
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;cin >> n;
  vector<string> arr(2 * n - 2);
  vector<char> ans(2 * n - 2);
  multiset<string> all;
  int fst = -1, snd = -1;
  for(int i = 0;i < 2 * n - 2;i++){
    cin >> arr[i];
    all.insert(arr[i]);
    if((int)arr[i].length() == n - 1){
      if(fst == -1)fst = i;
      else snd = i;
    }
  }
  multiset<string> tmp1(all), tmp2(all);
  auto chf = check_pre(arr[fst], arr[snd], tmp1);
  auto chs = check_pre(arr[snd], arr[fst], tmp2);
  if(chf.first){
    auto s = chf.second;
    for(int i = 0;i < 2 * n - 2;i++){
      if(s.count(arr[i])){
        ans[i] = 'P';
        s.erase(s.find(arr[i]));
      }
      else ans[i] = 'S';
    }
  }
  else if(chs.first){
    auto s = chs.second;
    for(int i = 0;i < 2 * n - 2;i++){
      if(s.count(arr[i])){
        ans[i] = 'P';
        s.erase(s.find(arr[i]));
      }
      else ans[i] = 'S';
    }
  }
  else assert(false);
  for(int i = 0;i < 2 * n - 2;i++)
    cout << ans[i];
  cout << endl;
}
