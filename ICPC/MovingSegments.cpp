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

  int t;cin >> t;
  while(t--){
    int n;cin >> n;
    vector<pair<pair<int, int>, int>> arr;
    for(int i = 0;i < n;i++){
      int a, b, c;cin >> a >> b >> c;
      arr.push_back({{a, b}, c});
    }
    sort(arr.begin(), arr.end());
    priority_queue<pair<pair<int, int>, int>> q;
    map<int, int> cnt;
    bool valid = true;
    for(int i = 0;i < n;i++){
      int a = arr[i].first.first;
      int b = arr[i].first.second;
      int c = arr[i].second;
      if(q.empty()){
        q.push({{-b, a}, c});
        cnt[c]++;
      }
      else{
        while(!q.empty() && -q.top().first.first < a){
          cnt[q.top().second]--;
          q.pop();
        }
        q.push({{-b, a}, c});
        cnt[c]++;
        if(cnt[c] > 2)valid = false;
      }
    }
    if(valid)cout << "YES";
    else cout << "NO";
    cout << endl;
  }
}
