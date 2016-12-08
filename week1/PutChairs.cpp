#include<fstream>
#include<iomanip>
#include<cmath>
using namespace std;
int main(){
  ifstream input("chairs.in");
  ofstream output("chairs.out");
  int a, b, c;
  input >> a >> b >> c;
  output << setprecision(8) << (a+b+c)/6.0 << endl;
  return 0;
}
