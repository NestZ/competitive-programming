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
  n *= 2;
  vector<pair<int, int>> arr;
  for(int i = 0;i < n;i++){
    char c;cin >> c;
    int num = -1;
    if(c == '-')cin >> num;
    arr.push_back({c, num});
  }
  bool valid = true;
  priority_queue<int, vector<int>, greater<int>> q;
  vector<int> ans;
  for(int i = n - 1;i >= 0;i--){
    char fst = arr[i].first;
    int snd = arr[i].second;
    if(fst == '-'){
      if(!q.empty() && snd > q.top()){
        valid = false;
        break;
      }
      q.push(snd);
    }
    else{
      if(q.empty()){
        valid = false;
        break;
      }
      ans.push_back(q.top());
      q.pop();
    }
  }
  if(valid){
    cout << "YES\n";
    for(int i = n / 2 - 1;i >= 0;i--)
      cout << ans[i] << ' ';
    cout << endl;
  }
  else cout << "NO\n";
}
