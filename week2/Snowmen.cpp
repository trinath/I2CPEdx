// Src: https://courses.edx.org/courses/course-v1:ITMOx+I2CPx+3T2016/courseware/823f3cd014574b93afb5520087401895/e83f246a26c6436e929d33bb449b9807/
#include<iostream>
#include<fstream>

using namespace std;

int main()
{
  ifstream input("snowmen.in");
  ofstream output("snowmen.out");

  int i, n, index, value, refIndex;
  long result;
  input >> n;
  int *past = new int[n+1];
  long *mass = new long[n+1];
  int *snowmen = new int[n+1];
  result = 0;
  mass[0] = 0;
  past[0] = 0;
  snowmen[0] = 0;
  for(i = 1; i <= n; i++){
    input >> index >> value;
    if(value == 0){
      refIndex = past[index]; // get previous index
      past[i] = past[refIndex];
      snowmen[i] = snowmen[refIndex];
      mass[i] = mass[refIndex];
    } else{
      past[i] = index;
      snowmen[i] = value;
      mass[i] = (long) value + mass[index];
    }
    result += mass[i];
  }
  output << result << "\n";
  return 0;

}
