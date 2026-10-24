void dijkstra(const WGraph &graph,int s,vll &dis,vi &prev){
  int n=graph.size();
  dis.resize(n,INF);
  prev.resize(n,-1);
  priority_queue<pli,vector<pli>,greater<pli>> pq;
  dis[s]=0;
  pq.emplace(dis[s],s);
  while(!pq.empty()){
    pli v=pq.top(); pq.pop();
    if(dis[v.second]<v.first) continue;
    for(auto &p:graph[v.second]){
      if(chmin<ll>(dis[p.first],dis[v.second]+p.second)){
        prev[p.first]=v.second;
        pq.emplace(dis[p.first],p.first);
      }
    }
  }
}

vi get_path(const vi &prev,int t){
  vi path;
  for(int i=t;i!=-1;i=prev[i]) path.push_back(i);
  reverse(all(path));
  return path;
}
