## Union-Find

### 상호 배타적 집합
* 상호 배타적인 부분 집합들로 나눠진 원소들에 대한 정보를 저장하고 조작하는 자료구조
* 초기화
  * n 개의 원소가 각각의 집합에 포함되어 있도록 초기화
* union 연산
  * 두 원소 a, b가 주어질 때 이들이 속한 두 집합을 하나로 합침
* find 연산
  * 어떤 원소 a가 주어질 때 이 원소가 속한 집합 반환
  
### 배열로 상호 배타적 집합 표현하기 
```
belongsTo[i] = i번 원소가 속하는 집합의 번호
```
* 모든 원소를 순회하는데는 O(n)
* find 연산 O(1)

### 트리를 이용한 상호 배타적 집합 자료구조 구현
```
struct NaiveDisjointSet{
  vector<int> parent;
  NaiveDisjointSet(int n): parent(n) {
    for(int i=0; i<n; i++) {
      parent[i]=i;
    }
  }
  
  //u가 속한 트리의 루트의 번호를 반환
  int find(int u) const {
    if(u==parent[u]) return u;
    return find(parent[u]);
  }
  
  //u가 속한 트리와 v가 속한 트리를 합침
  void merge(int u, int v) {
    u=find(u);
    v=find(v);
    //u와 v가 이미 같은 트리에 속하는 경우를 걸러 낸다
    if(u==v) return;
    parent[u]=v;
  }
};
```
### 상호 배타적 집합의 최적화
* 트리가 한쪽으로 치우친 경우
  * 탐색 효율이 나쁜 경우
  * 높이가 더 낮은 트리를 더 높은 트리 밑에 집어넣음 -> 트리의 높이가 높아지는 상황 방지
  * 랭크에 의한 합치기
    * rank[]=해당 노드가 한 트리의 루트인 경우 해당 트리의 높이를 저장
  * 경로 압축  
  
```
struct OptimizedDisjointSet{
  vector<int> parent, rank;
  OptimizedDisjointSet(int n) : parent(n), rank(n, 1) {
    for(int i=0; i<n; ++i) {
      parent[i]=i;
    }
  }   
  //u가 속한 트리의 루트의 번호 반환
  int find(int u) {
    if(u==parent[u]) return u;
    return parent[u]=find(parent[u]);
  }
    
  //u가 속한 트리와 v가 속한 트리를 합침
  void merge(int u, int v) {
    u=find(u);
    v=find(v);
    //u와 v가 이미 같은 집합에 속하는 경우 걸러냄
    if(u==v) continue;
    if(rank[u]>rank[v]) swap(u, v);;
    //이제 rank[v]가 항상 rank[v] 이상이므로 u를 v의 자식으로 넣음
    parent[u]=v;
    if(rank[u]==rank[v]) ++rank[v];
  }
};
```
