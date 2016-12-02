#include<iostream>
#include<fstream>
#include<vector>
#include<cmath>
#include<climits>
using namespace std;
int main(){
   ifstream input("prepare.in");
   ofstream output("prepare.out");
   int i, x, n, result = 0, maxValue, minDiff = INT_MAX;
   bool isP = false;
   bool isT = false;
   vector<int> t, p;

   input >> n;
   for(i = 0; i < n; i++){
     input >> x;
     t.push_back(x);
   }
   for(i = 0; i < n; i++){
     input >> x;
     p.push_back(x);
   }
   for(i = 0; i < n; i++){
     maxValue = max(t[i], p[i]);
     if(abs(t[i]-p[i]) < minDiff) minDiff = abs(t[i] - p[i]);
     result += maxValue;
     if(!isP && maxValue == p[i]) isP = true;
     else if(!isT && maxValue == t[i]) isT = true;
   }
   if(!isP || !isT) output << result-minDiff << endl;
   else output << result << endl;
   return 0;
}
