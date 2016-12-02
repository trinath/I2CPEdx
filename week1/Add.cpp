#include<iostream>
#include<fstream>
using namespace std;
int main(){
   ifstream input("aplusb.in");
   ofstream output("aplusb.out");
   long a, b;
   input >> a >> b;
   output << (a+b) << endl;
   return 0;
}
