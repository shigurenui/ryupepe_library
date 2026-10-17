template<typename T>
struct FenwickTree{
  int n;
  vector<T> bit;//v[1],v[2],...,v[n](1-indexed)
  
  FenwickTree(int n):n(n),bit(n+1,0){}
  
  void add(int a,T w){//v[a]にwを加える
    for(int i=a;i<=n;i+=i&-i) bit[i]+=w;
  }
  
  T sum(int a){//v[1]+v[2]+...+v[a]を求める
    T wa=0;
    for(int i=a;i>0;i-=i&-i) wa+=bit[i];
    return wa;
  }
  
  int lowerBound(T w){//v[1]+v[2]+...+v[x]>=wなる最小のxを求める
    if(w<=0) return 0; 
    int x=0,limit=1;
    while(limit<=n) limit*=2;
    limit/=2;
    for(int i=limit;i>0;i/=2){ 
      if(x+i<=n&&bit[x+i]<w){ 
        w-=bit[x+i]; 
        x+=i; 
      }
    }
    return x+1; 
  }
};
