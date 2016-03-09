// Write a function to print all of the permutations for the elements of an array containing n distinct integer values
#include<iostream>
using namespace std;

void swap(int *x, int *y)
{
	int temp;
	temp = *x;
	*x = *y;
	*y = temp;
}

void perms(int A[], int n){
  if(n-1 == 0){
    cout << A<< endl;
  }
  for (int i = n; i < n-1; i++) {
    /* code */
  }
}

int main() {
  int n = 4;
  int A[n] = {1,2,3,4};
  perms(A,n);
  return 0;
}
