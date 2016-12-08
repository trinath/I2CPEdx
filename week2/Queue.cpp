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

class queue{
private:
  link *head;
  link *tail;
public:
  queue(){
    head = NULL;
    tail = NULL;
  }
  void push(int x){
    link *temp = new link(x);
    if(tail == NULL && head == tail){
      head = temp;
      tail = head;
    }
    else{
      tail->next = temp;
      tail = tail->next;
    }
  }
  int pop(){
    link *temp; int result = -1;
    if(head != NULL){
      temp = head;
      result = head->n;
      head = head->next;
      delete temp;
    }
    if(head == NULL) tail = NULL;
    return result;
  }
  ~queue(){
    link *temp;
    while(head){
      pop();
    }
    head = NULL;
    tail = NULL;
  }
};


int main(){
  ifstream input("queue.in");
  ofstream output("queue.out");
  int n, m;
  queue q;
  string s;
  input >> n;
  while(n--){
    input >> s;
    if(s == "+"){
      input >> m;
      q.push(m);
    }
    else if(s == "-"){
      output << q.pop() << "\n";
    }
  }
  return 0;
}

/*
   Faster
   Use '\n' instead of endl
*/
