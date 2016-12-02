#include<iostream>
#include<fstream>
using namespace std;
int main(){
   ifstream input("aplusbb.in");
   ofstream output("aplusbb.out");
   int a, b;
   input >> a >> b;
   output << a + (long long)(b) * b;
   return 0;
}
