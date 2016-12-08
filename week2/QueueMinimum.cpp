// Src: https://courses.edx.org/courses/course-v1:ITMOx+I2CPx+3T2016/courseware/823f3cd014574b93afb5520087401895/e83f246a26c6436e929d33bb449b9807/
#include<iostream>
#include<cstdio>
#include<map>
#include<queue>
using namespace std;

class minQueue{
private:
  queue<int> parent;
  map<int, int> mp;
public:

  void push(int x){
    parent.push(x);
    mp[x]++;
  }

  void pop(){
    int y = parent.front();
    parent.pop();
    mp[y]--;
    if(mp[y] == 0) mp.erase(y);
  }

  int minq(){
    if(mp.size()) return mp.begin()->first;
    else return -1;
  }
};

int main(){
  freopen("queuemin.in", "r", stdin);
  freopen("queuemin.out", "w", stdout);
  int n, m;
  minQueue q;
  char s[2];
  scanf("%d", &n);
  while(n--){
    scanf("%s", s);
    if(s[0] == '+'){
      scanf("%d", &m);
      q.push(m);
    }
    else if(s[0] == '-'){
      q.pop();
    }
    else if(s[0] == '?'){
      printf("%d\n", q.minq());
    }
  }
  return 0;
}

/*
   Faster
   Use '\n' instead of endl
*/
