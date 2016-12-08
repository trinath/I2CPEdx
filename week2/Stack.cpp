// Src: https://courses.edx.org/courses/course-v1:ITMOx+I2CPx+3T2016/courseware/823f3cd014574b93afb5520087401895/e83f246a26c6436e929d33bb449b9807/
#include<iostream>
#include<fstream>
using namespace std;

struct link{
  int n;
  link *next;
  link(int _n){
    n = _n;
    next = NULL;
  }
};

class stack{
private:
  link *head;
public:
  stack(){
    head = NULL;
  }
  void push(int x){
    link *temp = new link(x);
    temp->next = head;
    head = temp;
  }
  int pop(){
    link *temp; int result = -1;
    if(head != NULL){
      temp = head;
      result = head->n;
      head = head->next;
      delete temp;
    }
    return result;
  }
  ~stack(){
    link *temp;
    while(head){
      pop();
    }
    head = NULL;
  }
};

int main(){
  ifstream input("stack.in");
  ofstream output("stack.out");
  int n, m;
  stack stk;
  string s;
  input >> n;
  while(n--){
    input >> s;
    if(s == "+"){
      input >> m;
      stk.push(m);
    }
    else if(s == "-"){
      output << stk.pop() << "\n";
    }
  }
  return 0;
}

/*
   Faster
   Use '\n' instead of endl
*/
