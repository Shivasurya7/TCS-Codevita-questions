/*
Roco is an island near Africa which is very prone to forest fire. Forest fire is such that it destroys the complete forest. Not a single tree is left.This island has been cursed by God , and the curse is that whenever a tree catches fire, it passes the fire to all its adjacent tree in all 8 directions,North, South, East, West, North-East, North-West, South-East, and South-West.And it is given that the fire is spreading every minute in the given manner, i.e every tree is passing fire to its adjacent tree.Suppose that the forest layout is as follows where T denotes tree and W denotes water.

Your task is that given the location of the first tree that catches fire, determine how long would it take for the entire forest to be on fire. You may assume that the lay out of the forest is such that the whole forest will catch fire for sure and that there will be at least one tree in the forest

Input Format:
First line contains two integers, M, N, space separated, giving the size of the forest in terms of the number of rows and columns respectively.
The next line contains two integers X,Y, space separated, giving the coordinates of the first tree that catches the fire.
The next M lines, where ith line containing N characters each of which is either T or W, giving the position of the Tree and Water in the  ith row of the forest.
Output Format:

Single integer indicating the number of minutes taken for the entire forest to catch fire

Constrains:
3 ≤ M ≤ 20
3 ≤ N ≤ 20

Sample Input 1:
3 3
W T T
T W W
W T T
Sample Output 1:
5

Explanation:
In the second minute,tree at (1,2) catches fire,in the third minute,the tree at (2,1) catches fire,fourth minute tree at (3,2) catches fire and in the fifth minute the last tree at (3,3) catches fire.
Sample Input 2:
6 6
1 6
W T T T T T
T W W W W W
W T T T T T
W W W W W T
T T T T T T
T W W W W W

Sample Output 2:
16
*/

// my own solution

#include <bits/stdc++.h>
using namespace std;


void fire(vector <vector<int>>& a,int r,int c,int i,int j,int ct = 1){
  if(a[i][j] <= ct and a[i][j] != 0){
    return;
  }
  a[i][j] = ct;
  if(i+1 < r and j+1 < c){ //south east
    if(a[i+1][j+1] >= 0){
      fire(a,r,c,i+1,j+1,ct+1);
    }
  }
  if(i+1 < r and j-1 > -1){ //south west
    if(a[i+1][j-1] >= 0){
      fire(a,r,c,i+1,j-1,ct+1);
    }
  }
  if(i-1 > -1 and j-1 > -1){ //north west
    if(a[i-1][j-1] >= 0){
      fire(a,r,c,i-1,j-1,ct+1);
    }
  }
  if(i-1 > -1 and j+1 < c){ //north east
    if(a[i-1][j+1] >= 0){
      fire(a,r,c,i-1,j+1,ct+1);
    }
  }
  if(i+1 < r){ //south
    if(a[i+1][j] >= 0){
      fire(a,r,c,i+1,j,ct+1);
    }    
  }
  if(i-1 > -1){ //north
    if(a[i-1][j] >= 0){
      fire(a,r,c,i-1,j,ct+1);
    }
  }
  if(j-1 > -1){ //west
    if(a[i][j-1] >= 0){
      fire(a,r,c,i,j-1,ct+1);
    }
  }
  if(j+1 < c){ //east
    if(a[i][j+1] >= 0){
      fire(a,r,c,i,j+1,ct+1);
    }
  }
  return;
}

int main()
{
  int r,c,r1,c1,mt=0;
  cin>>r>>c;
  cin>>r1>>c1;
  vector <vector<int>> arr;
  vector <int> a(c);
  for(int i = 0; i < r; i++){
    for(int j = 0; j < c; j++){
      char t;
      cin>>t;
      if(t == 't'){
        a[j] = 0;
      }
      else{
        a[j] = -1;
      }
    }
    arr.push_back(a);
  }
  
  fire(arr,r,c,r1,c1);

  for(int i = 0; i < r; i++){
    for(int j = 0; j < c; j++){
      if(mt < arr[i][j])
      {
        mt = arr[i][j];
      }    
    }
  }
  cout<<mt;
}

// another solution

#include <bits/stdc++.h>
using namespace std;


void fire(vector <vector<int>>& a,int r,int c,int i,int j,int ct = 1){
  if(i < 0 or i > r-1 or j < 0 or j > c-1){
    return;
  }
  if(a[i][j] == -1){
    return;
  }
  if(a[i][j] <= ct and a[i][j] != 0){
    return;
  }
  a[i][j] = ct;
  fire(a,r,c,i+1,j+1,ct+1);
  fire(a,r,c,i+1,j-1,ct+1);
  fire(a,r,c,i-1,j-1,ct+1);
  fire(a,r,c,i-1,j+1,ct+1);
  fire(a,r,c,i+1,j,ct+1);
  fire(a,r,c,i-1,j,ct+1);
  fire(a,r,c,i,j-1,ct+1);
  fire(a,r,c,i,j+1,ct+1);
}

int main()
{
  int r,c,r1,c1,mt=0;
  cin>>r>>c;
  cin>>r1>>c1;
  vector <vector<int>> arr;
  vector <int> a(c);
  for(int i = 0; i < r; i++){
    for(int j = 0; j < c; j++){
      char t;
      cin>>t;
      if(t == 't'){
        a[j] = 0;
      }
      else{
        a[j] = -1;
      }
    }
    arr.push_back(a);
  }
  
  fire(arr,r,c,r1,c1);

  for(int i = 0; i < r; i++){
    for(int j = 0; j < c; j++){
      if(mt < arr[i][j])
      {
        mt = arr[i][j];
      }    
    }
  }
  cout<<mt;
}