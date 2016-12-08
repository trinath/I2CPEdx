// Src: https://courses.edx.org/courses/course-v1:ITMOx+I2CPx+3T2016/courseware/823f3cd014574b93afb5520087401895/e83f246a26c6436e929d33bb449b9807/
#include<iostream>
#include<string>
#include<fstream>
#include<stack>

// 8:14 8:24
using namespace std;
bool isBalanced(string s){
  stack<char> stk;
  bool result = true;
  for(int i = 0; i < s.size(); i++){
    switch (s[i]) {
      case '(':
      case '[':
        stk.push(s[i]);
        break;
      case ']':
        if(!stk.empty() && stk.top() == '[')
          stk.pop();
        else result = false;
        break;
      case ')':
        if(!stk.empty() && stk.top() == '(')
          stk.pop();
        else result = false;
        break;
    }
    if(result == false) break;
  }
  if(!stk.empty()) result = false;
  return result;
}


int main(){
  ifstream input("brackets.in");
  ofstream output("brackets.out");
  string line;
  while(getline(input, line)){
    output << (isBalanced(line) ? "YES" : "NO") << '\n';
  }
  return 0;
}
