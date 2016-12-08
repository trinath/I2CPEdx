#include<fstream>
#include<iomanip>
#include<cmath>
#include<climits>
using namespace std;
int main(){
  ifstream input("team.in");
  ofstream output("team.out");
  int i, j, k, a[3][3];
  for(i = 0 ; i < 3; i++)
    for(j = 0; j < 3; j++)
      input >> a[i][j];
  int maxValue = INT_MIN;
  for(i = 0; i < 3; i++)
  {
    for(j = 0; j < 3; j++)
    {
      if(i != j){
        k = 3 - i - j;
        maxValue = max(maxValue, a[0][i]*a[0][i] + a[1][j] * a[1][j] + a[2][k] * a[2][k]);
      }
    }
  }
  output << setprecision(10) << sqrt(maxValue) << endl;
  return 0;
}
