#include<stdio.h>
int main()
{
  int n=5;
  int A[5] = { 4,3,2,1,2};
  int left = 1;
  int right = 1;
  int OUTPUT[5];

  for (int i = 0; i < n; i++)
  OUTPUT[i] = 1;
  for (int i = 0; i < n; i++) {
    OUTPUT[i] *= left;
    OUTPUT[n - 1 - i] *= right;
    left *= A[i];
    right *= A[n - 1 - i];
  }
   for(int i=0;i<n;i++)
    printf("%d ",OUTPUT[i]);
   
   return  0;
} 
