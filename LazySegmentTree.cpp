template<typename S,typename T,typename OP,typename EE,typename MAPPING,typename COMPOSITION,typename ID>
struct LazySegmentTree{
  int o,size,log;
  OP op;
  EE e;
  MAPPING mapping;
  COMPOSITION composition;
  ID id;
  vector<S> tree;
  vector<T> lazy;

  LazySegmentTree(int n,OP Op,EE E,MAPPING Mapping,COMPOSITION Composition,ID Id):LazySegmentTree(vector<S>(n,E()),Op,E,Mapping,Composition,Id){}
  LazySegmentTree(const vector<S> &v,OP Op,EE E,MAPPING Mapping,COMPOSITION Composition,ID Id):o((int)v.size()){
    op=Op;
    e=E;
    mapping=Mapping;
    composition=Composition;
    id=Id;
    size=std::bit_ceil((unsigned int)o);
    log=std::countr_zero((unsigned int)size);
    tree=vector<S>(2*size,e());
    lazy=vector<T>(size,id());
    rep(i,o) tree[size+i]=v[i];
    for(int i=size-1;i>=1;i--) update(i);
  }

  void update(int k){
    tree[k]=op(tree[2*k],tree[2*k+1]);
  }

  void all_apply(int k,T f){
    tree[k]=mapping(f,tree[k]);
    if(k<size) lazy[k]=composition(f,lazy[k]);
  }

  void push(int k){
    all_apply(2*k,lazy[k]);
    all_apply(2*k+1,lazy[k]);
    lazy[k]=id();
  }

  void set(int key,S value){
    key+=size;
    for(int i=log;i>=1;i--) push(key>>i);
    tree[key]=value;
    rrep(i,log) update(key>>i);
  }

  S get(int key){
    key+=size;
    for(int i=log;i>=1;i--) push(key>>i);

    return tree[key];
  }

  S prod(int l,int r){
    if(l==r) return e();

    l+=size; r+=size;
    for(int i=log;i>=1;i--){
      if(((l>>i)<<i)!=l) push(l>>i);
      if(((r>>i)<<i)!=r) push((r-1)>>i);
    }

    S l_value=e();
    S r_value=e();
    while(l<r){
      if(l&1) l_value=op(l_value,tree[l++]);
      if(r&1) r_value=op(tree[r--],r_value);
      l>>=1; r>>=1;
    }

    return op(l_value,r_value);
  }

  void apply(int l,int r,T func){
    if(l==r) return;

    l+=size; r+=size;
    for(int i=log;i>=1;i--){
      if(((l>>i)<<i)!=l) push(l>>i);
      if(((r>>i)<<i)!=r) push((r-1)>>i);
    }

    int new_l=l,new_r=r;
    while(new_l<new_r){
      if(new_l&1) all_apply(new_l++,func);
      if(new_r&1) all_apply(new_r--,func);
      new_l>>=1; new_r>>=1;
    }

    rrep(i,log){
      if(((l>>i)<<i)!=l) update(l>>i);
      if(((r>>i)<<i)!=r) update((r-1)>>i);
    }
  }

  template<bool (*func)(S)>
  int max_right(int l){
    auto f=[](S key){
      return func(key);
    };
    return max_right(l,f);
  }

  template<typename G>
  int max_right(int l,G g){
    if(l==o) return o;
    l+=size;
    for(int i=log;i>=1;i--) push(l>>i);
    S value=e();
    do{
      while((l&1)==0) l>>=1;
      if(!g(op(value,tree[l]))){
        while(l<size){
          push(l);
          l*=2;
          if(g(op(value,tree[l]))){
            value=op(value,tree[l]);
            l++;
          }
        }
        return l-size;
      }
      value=op(value,tree[l]);
      l++;
    }while((l&-l)!=l);
    return o;
  }

  template<bool (*func)(S)>
  int min_left(int r){
    auto f=[](S key){
      return func(key);
    };
    return min_left(r,f);
  }

  template<typename G>
  int min_left(int r,G g){
    if(r==0) return 0;
    r+=size;
    for(int i=log;i>=1;i--) push((r-1)>>i);
    S value=e();
    do{
      r--;
      while(r>1&&(r%2)) r>>=1;
      if(!g(op(tree[r],value))){
        while(r<size){
          push(r);
          r+=r+1;
          if(g(op(tree[r],value))){
            value=op(tree[r],value);
            r--;
          }
        }
        return r+1-size;
      }
      value=op(tree[r],value);
    }while((r&-r)!=r);
    return 0;
  }
};
