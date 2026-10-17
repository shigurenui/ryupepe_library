struct UnionFind{
  vi self_parent; //self_parent[i]:iの根の番号
  vi self_size;
    
  UnionFind(int n):self_parent(n),self_size(n,1){
    rep(i,n) self_parent[i]=i;
  }
    
  int find(int x){ //データxが属する木の根を再帰で得る：find(x)={xの木の根}
    if(self_parent[x]==x) return x;
    return self_parent[x]=find(self_parent[x]);
  }
    
  void unite(int x,int y){ //xとyの木を併合
    int rx=find(x); //xの根をrx
    int ry=find(y); //yの根をry
    if (rx==ry) return; //xとyの根が同じ(=同じ木にある)時はそのまま
    if(self_size[rx]<self_size[ry]) swap(rx,ry);
    self_parent[ry]=rx; //xとyの根が同じでない(=同じ木にない)時：xの根rxをyの根ryにつける
    self_size[rx]+=self_size[ry];
  }
    
  bool same(int x,int y){ //2つのデータx, yが属する木が同じならtrueを返す
    int rx=find(x);
    int ry=find(y);
    return rx==ry;
  }
  
  int size(int x){
    return self_size[find(x)];
  }
};
