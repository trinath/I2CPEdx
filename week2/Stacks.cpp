// Src: https://courses.edx.org/courses/course-v1:ITMOx+I2CPx+3T2016/courseware/823f3cd014574b93afb5520087401895/e83f246a26c6436e929d33bb449b9807/
#include<iostream>
#include<fstream>
#include<map>

using namespace std;

int main(){
  ifstream input("stacks.in");
  ofstream output("stacks.out");
  int m, n;
  input >> n;
  map<int, int> stackCounter;

  for(int i = 0; i < n; i++){
    input >> m;
    if(i == 0 || m != 0){
      stackCounter[1]++;
    }
    else{
      // add 1 to min length stack;
      map<int, int>::iterator it = stackCounter.begin();
      stackCounter[it->first + 1]++;
      if(stackCounter[it->first] == 1){
        stackCounter.erase(it);
      }
      else{
        stackCounter[it->first]--;
      }
    }
  }
  output << stackCounter.rbegin()->first << endl;
  return 0;
}
