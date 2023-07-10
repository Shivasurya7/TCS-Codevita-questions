/*
Problem Statement:-
Compute the nearest larger number by interchanging its digits updated.Given 2 numbers a and b find the smallest number greater than b by interchanging the digits of a and if not possible print -1.

Input Format:
2 numbers a and b, separated by space.

Output Format:
A single number greater than b.
If not possible, print -1

Constraints
1 <= a,b <= 10000000

Example 1:
Sample Input:
459 500

Sample Output:
549

Example 2:
Sample Input:
645757 457765

Sample Output:
465577
*/

#include <bits/stdc++.h>
using namespace std;
int KthPermutation(vector <int> num,int k){
  int n = num.size(),f=1,ans = 0;
  for(int i = 1; i < n; i++){
    f *= i;
  }
  k--;
  while(true){
    ans = (ans * 10) + num[k/f];
    num.erase(num.begin()+k/f);
    if(num.size() ==  0){
      break;
    }
    k = k%f;
    f = f/num.size();
  }
  return ans;
}

int main()
{
  int p,n,t,f=1;
  cin>>p>>n;
  vector <int> num;
  while(p > 0){
    num.push_back(p%10);
    p /= 10;
  }
  sort(num.begin(),num.end());
  for(int i = 1; i <= num.size(); i++){
    f *= i;
  }
  for(int i = 1; i <= f; i++){
    t = KthPermutation(num,i);
    if(t > n){
        cout<<t;
        return 0;
    }
  }
  cout<<-1;
}