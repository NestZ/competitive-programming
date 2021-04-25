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
  vector<tuple<int, int, int>> arr;
  vector<int> ans(n);
  for(int i = 0;i < n;i++){
    int a, b;cin >> a >> b;
    arr.push_back({a, b, i});
  }
  sort(arr.begin(), arr.end());
  priority_queue<tuple<int, int, int>> q;
  int mx = 1;
  for(int i = 0;i < n;i++){
    int cur_s = get<0>(arr[i]);
    int cur_e = get<1>(arr[i]);
    int ind = get<2>(arr[i]);
    if(q.empty())q.push({-cur_e, cur_s, ind});
    else{
      while(!q.empty() && -get<0>(q.top()) < get<0>(arr[i]))
        q.pop();
      q.push({-cur_e, cur_s, ind});
    }
    mx = max(mx, (int)q.size());
  }
  set<int> have;
  for(int i = 1;i <= mx;i++)
    have.insert(i);
  for(int i = 0;i < n;i++){
    int cur_s = get<0>(arr[i]);
    int cur_e = get<1>(arr[i]);
    int ind = get<2>(arr[i]);
    if(q.empty()){
      q.push({-cur_e, cur_s, ind});
      ans[ind] = *(have.begin());
      have.erase(have.begin());
    }
    else{
      while(!q.empty() && -get<0>(q.top()) < get<0>(arr[i])){
        have.insert(ans[get<2>(q.top())]);
        q.pop();
      }
      q.push({-cur_e, cur_s, ind});
      ans[ind] = *(have.begin());
      have.erase(have.begin());
    }
  }
  cout << mx << endl;
  for(int i : ans)cout << i << ' ';
  cout << endl;
}
