template<int MOD>
struct mymodint{
  ll value;
  constexpr mymodint(ll v=0) noexcept:value(v%MOD){
    if(value<0) value+=MOD;
  }
  constexpr int getmod() const{
    return MOD;
    
  }
  
  constexpr mymodint operator -() const noexcept{
    return mymodint(value?MOD-value:0);
  }
  
  constexpr mymodint operator+(const mymodint& x) const noexcept{
    return mymodint(*this)+=x;
  }
  
  constexpr mymodint operator-(const mymodint& x) const noexcept{
    return mymodint(*this)-=x;
  }
  
  constexpr mymodint operator*(const mymodint& x) const noexcept{
    return mymodint(*this)*=x;
  }
  
  constexpr mymodint operator/(const mymodint& x) const noexcept{
    return mymodint(*this)/=x;
  }
  
  constexpr mymodint& operator+=(const mymodint& x) noexcept{
    value+=x.value;
    if(value>=MOD) value-=MOD;
    return *this;
  }
  
  constexpr mymodint& operator-=(const mymodint& x) noexcept{
    value-=x.value;
    if(value<0) value+=MOD;
    return *this;
  }
  
  constexpr mymodint& operator*=(const mymodint& x) noexcept{
    value=value*x.value%MOD;
    return *this;
  }
  
  constexpr mymodint& operator/=(const mymodint& x) noexcept{
    ll a=x.value,b=MOD,u=1,v=0;
    while(b){
      ll t=a/b;
      a-=t*b; swap(a,b);
      u-=t*v; swap(u,v);
    }
    value=value*u%MOD;
    if(value<0) value+=MOD;
    return *this;
  }
  
  constexpr bool operator==(const mymodint& x) const noexcept{
    return this->value==x.value;
  }
  
  constexpr bool operator!=(const mymodint& x) const noexcept{
    return this->value!=x.value;
  }
  
  friend constexpr istream& operator>>(istream& is,mymodint<MOD>& x){
    ll y; is>>y;
    x=mymodint(y);
    return is;
  }
  
  friend constexpr ostream& operator<<(ostream &os,const mymodint<MOD>& x) noexcept{
    return os<<x.value;
  }
  
  friend constexpr mymodint<MOD> modpow(mymodint<MOD> a,ll n) noexcept{
    mymodint<MOD> r=1;
    while(n){
      if(n&1) r*=a;
      a*=a;
      n>>=1;
    }
    return r;
  }
};

const int MOD=998244353;
using mint=mymodint<MOD>;
