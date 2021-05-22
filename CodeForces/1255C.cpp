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
  vector<int> cnt(n + 1);
  vector<tuple<int, int, int>> arr;
  vector<int> ans;
  map<pair<int, int>, vector<int>> m;
  for(int i = 0;i < n - 2;i++){
    int a, b, c;cin >> a >> b >> c;
    cnt[a]++; cnt[b]++; cnt[c]++;
    arr.push_back({a, b, c});
    auto p1 = make_pair(a, b);
    auto p2 = make_pair(b, a);
    auto p3 = make_pair(b, c);
    auto p4 = make_pair(c, b);
    auto p5 = make_pair(a, c);
    auto p6 = make_pair(c, a);
    m[p1].push_back(i);
    m[p2].push_back(i);
    m[p3].push_back(i);
    m[p4].push_back(i);
    m[p5].push_back(i);
    m[p6].push_back(i);
  }
  int start = 0;
  for(int i = 0;i < n - 2;i++){
    int fst = get<0>(arr[i]);
    int snd = get<1>(arr[i]);
    int trd = get<2>(arr[i]);
    if(cnt[fst] == 1 || cnt[snd] == 1 || cnt[trd] == 1){
      start = i;
      break;
    }
  }
  int cur = start;
  for(int i = 0;i < n - 2;i++){
    int fst = get<0>(arr[cur]);
    int snd = get<1>(arr[cur]);
    int trd = get<2>(arr[cur]);
    if(i == 0){
      if(cnt[fst] == 1){
        ans.push_back(fst);
        if(cnt[trd] == 2)swap(snd, trd);
        ans.push_back(snd);
        ans.push_back(trd);
      }
      else if(cnt[snd] == 1){
        ans.push_back(snd);
        if(cnt[trd] == 2)swap(fst, trd);
        ans.push_back(fst);
        ans.push_back(trd);
      }
      else{
        ans.push_back(trd);
        if(cnt[snd] == 2)swap(fst, snd);
        ans.push_back(fst);
        ans.push_back(snd);
      }
    }
    else{
      int b1 = ans.back();
      int b2 = ans[(int)ans.size() - 2];
      if(fst != b1 && fst != b2){
        ans.push_back(fst);
      }
      else if(snd != b1 && snd != b2){
        ans.push_back(snd);
      }
      else if(trd != b1 && trd != b2){
        ans.push_back(trd);
      }
      else assert(false);
    }
    int b1 = ans.back();
    int b2 = ans[(int)ans.size() - 2];
    auto p = make_pair(b1, b2);
    auto v = m[p];
    for(int j : v){
      if(cur == j)continue;
      cur = j;
      break;
    }
    debug() << imie(i) imie(cur);
  }
  for(int i : ans)cout << i << ' ';
  cout << endl;
}
