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

int n;

void q(int b, int i, int j){
  cout << b << ' ' << i + 1 << ' ' << j + 1 << endl;
}

pair<int, int> find_odd(vector<vector<int>> &arr){
  for(int i = 0;i < n;i++){
    for(int j = 0;j < n;j++){
      if(arr[i][j] != -1)continue;
      if((i + j) % 2){
        return {i, j};
      }
    }
  }
  return {-1, -1};
}

pair<int, int> find_even(vector<vector<int>> &arr){
  for(int i = 0;i < n;i++){
    for(int j = 0;j < n;j++){
      if(arr[i][j] != -1)continue;
      if((i + j) % 2 == 0){
        return {i, j};
      }
    }
  }
  return {-1, -1};
}

pair<int, int> fill_odd(int i, int j, int num,
    vector<vector<int>> &arr){
  auto p = find_odd(arr);
  arr[p.first][p.second] = num;
  return p;
}

pair<int, int> fill_even(int i, int j, int num,
    vector<vector<int>> &arr){
  auto p = find_even(arr);
  arr[p.first][p.second] = num;
  return p;
}

int main(){
  cin >> n;
  vector<vector<int>> arr(110, vector<int>(110, -1));
  int odd_x = 0, odd_y = -1;
  int even_x = 0, even_y = -1;
  int cnt_even = 0, cnt_odd = 0;
  int w_even = (n * n + 1) / 2, w_odd = n * n / 2;
  for(int i = 0;i < n * n;i++){
    int a;cin >> a;
    if(a == 3){
      if(cnt_even < w_even){
        auto p = fill_even(even_x, even_y, 2, arr);
        q(2, p.first, p.second);
        even_x = p.first;
        even_y = p.second;
        cnt_even++;
      }
      else if(cnt_odd < w_odd){
        auto p = fill_odd(odd_x, odd_y, 1, arr);
        q(1, p.first, p.second);
        odd_x = p.first;
        odd_y = p.second;
        cnt_odd++;
      }
      else assert(false);
    }
    else if(a == 2){
      if(cnt_odd < w_odd){
        auto p = fill_odd(odd_x, odd_y, 1, arr);
        q(1, p.first, p.second);
        odd_x = p.first;
        odd_y = p.second;
        cnt_odd++;
      }
      else{
        auto p = fill_even(even_x, even_y, 3, arr);
        q(3, p.first, p.second);
        even_x = p.first;
        even_y = p.second;
        cnt_even++;
      }
    }
    else{
      if(cnt_even < w_even){
        auto p = fill_even(even_x, even_y, 2, arr);
        q(2, p.first, p.second);
        even_x = p.first;
        even_y = p.second;
        cnt_even++;
      }
      else{
        auto p = fill_odd(odd_x, odd_y, 3, arr);
        q(3, p.first, p.second);
        odd_x = p.first;
        odd_y = p.second;
        cnt_odd++;
      }
    }
  }
}
