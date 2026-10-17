template<typename T,typename F>
struct SegmentTree{
  F op;// 関数
  T e;
  int n,size;
  vector<T> data;// 木
  
  SegmentTree(int N,F op,T e):op(op),e(e){// 初期化
    n=1;
    while(n<N) n*=2;
    data.assign(2*n,e);
    size=N;
  }
  
  void set(int i,T value){// 値の変更 set(a,b)でa番目をbにする
    i+=n;
    data[i]=value;
    while(i>1){
      i/=2;
      data[i]=op(data[i*2],data[i*2+1]);
    }
  }
  
  T prod(int l,int r){// 半開区間[l,r)で受け取り、min or maxを出力
    l+=n; r+=n;//data上のindexに移動
    T l_value=e,r_value=e;
    while(l<r){//同じマスに到達するまで
      if(l%2==1){//lが右にいる場合(左の子は計算結果に入れられない)
        l_value=op(l_value,data[l]);
        l++;//別の親へ
      }
      if(r%2==1){//rが右にいる場合(右の子は計算結果に入れられない)
        r--;//別の親へ
        r_value=op(data[r],r_value);
      }
      l/=2; r/=2;// l,rを1段上へ
    }
    return op(l_value,r_value);
  }
  
  //max限定
  int max_right(int l, T x){
    if(l>=size) return size;
    l+=n;
    T sum=e;
    while(true){
      while(l%2==0) l/=2;
      if(op(sum,data[l])<x){
        sum=op(sum,data[l]);
        l++;
        if((l&-l)==l) break;
      }
      else{
        while(l<n){
          l*=2;
          if(op(sum,data[l])<x){sum=op(sum,data[l]); l++;}
        }
        return l-n;
      }
    }
    return size;
  }
  
  //min限定
  int min_left(int r, T x){
    if(r>size) return 0;
    r+=n;
    T sum=e;
    while(true){
      while(r%2==0) r/=2;
      if(op(sum,data[r])>x){
        sum=op(sum,data[r]);
        r--;
        if((r&-r)==r) break;
      }
      else{
        while(r<n){
          r*=2;
          if(op(sum,data[r])>x){sum=op(sum,data[r]); r--;}
        }
        return r-n;
      }
    }
    return 0;
  }
};
/* 宣言：
auto f=[](int a,int b){return min/max(a,b);};
SegmentTree<int,decltype(f)> seg(n,f,+/-INF);
//関数に応じてINFを0に
*/
