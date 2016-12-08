// Src: https://courses.edx.org/courses/course-v1:ITMOx+I2CPx+3T2016/courseware/823f3cd014574b93afb5520087401895/e83f246a26c6436e929d33bb449b9807/
#include<iostream>
#include<stack>
#include<fstream>
#include<cstdlib>
#include<cstdio>
using namespace std;
int main(){
  ifstream input("postfix.in");
  ofstream output("postfix.out");
  string line;
  string number("");
  stack<int> s;
  int i, operand1, operand2;
  getline(input, line);

  line = line + ' ';
  for(i = 0; i < line.size(); i++){
    if(line[i] == ' '){
      if(number.size()){
        s.push(atoi(number.c_str()));
      }
      number = "";
      continue;
    }
    else if(line[i] >= '0' && line[i] <= '9') number += line[i];
    else {
      operand1 = s.top();
      s.pop();
      operand2 = s.top();
      s.pop();
      if(line[i] == '+') s.push(a+b);
      else if(line[i] == '-') s.push(a-b);
      else s.push(a*b);
    }
  }
  output << s.top() << '\n';
  return 0;
}
