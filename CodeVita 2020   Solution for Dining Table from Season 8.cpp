/*
CodeVita 2020 | Solution for Dining Table from Season 8
Problem Statement:- 
In a Conference ,attendees are invited for a dinner after the conference.The Co-ordinator,Sagar arranged around round tables for dinner and want to have an impactful seating experience for the attendees.Before finalizing the seating arrangement,he wants to analyze all the possible arrangements.These are R round tables and N attendees.In case where N is an exact multiple of R,the number of attendees must be exactly N//R,,If N is not an exact multiple of R, then the distribution of attendees must be as equal as possible.Please refer to the example section before for better understanding.
For example, R = 2 and N = 3
All possible seating arrangements are
(1,2) & (3)
(1,3) & (2)
(2,3) & (1)
Attendees are numbered from 1 to N.

Input Format:
The first line contains T denoting the number of test cases.
Each test case contains two space separated integers R and N, Where R denotes the number of round tables and N denotes the number of attendees.

Output Format:
Single Integer S denoting the number of possible unique arrangements.

Constraints:
0 <= R <= 10(Integer)
0 < N <= 20 (Integer)

Sample Input 1:
1
2 5
Sample Output 1:
10

Explanation:
R = 2, N = 5

(1,2,3) & (4,5)

(1,2,4) & (3,5)

(1,2,5) & (3,4)

(1,3,4) & (2,5)

(1,3,5) & (2,4)

(1,4,5) & (2,3)

(2,3,4) & (1,5)

(2,3,5) & (1,4)

(2,4,5) & (1,3)

(3,4,5) & (1,2)

Arrangements like

(1,2,3) & (4,5)

(2,1,3) & (4,5)

(2,3,1) & (4,5) etc.

But as it is a round table,all the above arrangements are same.
*/

#include <bits/stdc++.h>
using namespace std;

int fact(int n){
  int fact=1;
  while(n){
    fact *= n;
    n--;
  }
  return fact;
}

int combination(int n,int r){
  int fn = fact(n),fr = fact(r);
  return fn/(fr*(fact(n-r)));
}

int main()
{
  int r,n,c=1;
  cin>>r>>n;
  int tp1 = (n/r)+1,tp2 = n/r;
  int tn1 = n%r,tn2 = r - tn1;

  while(tn1){
    c  *= combination(n,tp1);
    n -= tp1;
    tn1--;
  }
  while(tn2){
    c  *= combination(n,tp2);
    n -= tp2;
    tn2--;
  }
  cout<<c; 
}