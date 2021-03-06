#include<stdio.h>
#include<iostream>
using namespace std;

	
void printSum(int candidates[], int index[], int n) {
  for (int i = 1; i <= n; i++)
    cout << candidates[index[i]] << ((i == n) ? "" : "+");
  cout << endl;
}
 
void solveUtil(int target, int sum, int candidates[], int sz, int index[], int n) {
  if (sum > target)
    return;
  if (sum == target)
    printSum(candidates, index, n);
 
  for (int i = index[n]; i < sz; i++) {
    index[n+1] = i;
    solveUtil(target, sum + candidates[i], candidates, sz, index, n+1);
  }
}
 
void solve(int target, int candidates[], int sz) {
  int index[10000];
  index[0] = 0;
  solveUtil(target, 0, candidates, sz, index, 0);
}
int main()
{
 int a[] = {10, 1, 2, 7, 6, 1, 5};
   int sum=8;
   solve(sum,a,7);
  return 0;
}
