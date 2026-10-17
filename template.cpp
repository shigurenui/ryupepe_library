#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using ll=long long;
using ull=unsigned long long;
using ld=long double;
using vi=vector<int>;
using vll=vector<ll>;
using vull=vector<ull>;
using vld=vector<ld>;
using vb=vector<bool>;
using vc=vector<char>;
using vd=vector<double>;
using vs=vector<string>;
using vvi=vector<vi>;
using vvll=vector<vll>;
using vvull=vector<vull>;
using vvld=vector<vld>;
using vvb=vector<vb>;
using vvc=vector<vc>;
using vvd=vector<vd>;
using vvs=vector<vs>;
using pi=pair<int,int>;
using pll=pair<ll,ll>;
using pil=pair<int,ll>;
using pli=pair<ll,int>;
using pd=pair<double,double>;
using pld=pair<ld,ld>;
using vpi=vector<pi>;
using vpll=vector<pll>;
using vpil=vector<pil>;
using Graph=vvi;
using WGraph=vector<vector<pil>>;
using mi=map<int,int>;
using mll=map<ll,ll>;
using ms=map<string,int>;
using umi=unordered_map<int,int>;
using umll=unordered_map<ll,ll>;
using ums=unordered_map<string,int>;
using si=set<int>;
using sll=set<ll>;
using ss=set<string>;
using usi=unordered_set<int>;
using usll=unordered_set<ll>;
using uss=unordered_set<string>;
using msi=multiset<int>;
using msll=multiset<ll>;
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define rrep(i,n) for(int i=1; i<=(int)(n); i++)
#define YesNo(a) cout<<((a)?"Yes\n":"No\n")
#define YESNO(a) cout<<((a)?"YES\n":"NO\n")
#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(),(x).rend()
#define cout_fs(x) cout<<fixed<<setprecision(x)
const int inf=1e9+10;
const ll INF=1e18+10;
const int dx_4[4]={-1,0,0,1};
const int dy_4[4]={0,-1,1,0};
const int dx_8[8]={-1,-1,-1,0,0,1,1,1};
const int dy_8[8]={-1,0,1,-1,1,-1,0,1};

template<typename T>
bool chmax(T &a,const T &b){
  return(a<b?a=b,true:false);
}

template<typename T>
bool chmin(T &a,const T &b){
  return(a>b?a=b,true:false);
}

void solve(){
  // write code
}

int main(void){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  
  cout_fs(20);
  int testcase=1;
  // cin>>testcase;
  while(testcase--) solve();
}
