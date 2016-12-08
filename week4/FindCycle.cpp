#include<iostream>
#include<vector>
#include<set>
#include<cstring>
#include<fstream>

using namespace std;
struct edge{
  int from;
  int to;
};

set<int> v[100001];
bool inStack[100001];
bool visited[100001];
edge result;

bool isCycle(int start){
  set<int>::iterator it;
  if(visited[start] == false){
    visited[start] = true;
    inStack[start] = true;

    for(it = v[start].begin(); it != v[start].end(); it++){
      if(!visited[*it] && isCycle(*it)){
        return true;
      }
      else if(inStack[*it] == true){
        result.from = start; result.to = *it;
        return true;
      }
    }
  }
  inStack[start] = false;
  return false;
}

int main(){
  int i, n, m, a, b, start, parent;
  ifstream input("cycle.in");
  ofstream output("cycle.out");

  input >> n >> m;
  start = -1;
  result.from = -1; result.to = -1;
  memset(visited, false, sizeof(visited));
  memset(inStack, false, sizeof(inStack));
  for(i = 0; i < m; i++){
    input >> a >> b;
    v[a].insert(b);
    if(start == -1) start = a;
  }
  if(isCycle(start)){
    output << "YES" << endl;
    output << result.from << " " << result.to << endl;
  }
  else
    output << "NO" << endl;
  return 0;
}
