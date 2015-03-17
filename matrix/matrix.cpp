#include<iostream>
#include<vector>

using namespace std;

vector<vector<int> > A;

int k, ans;

void df(int i){
  if (i==16){
    ++ans;
    return;
  }
  for (int j=1; j<8; ++j){
    A[i/4][i%4]=j;
    if (i==3)
      k=A[0][0]+A[0][1]+A[0][2]+A[0][3];
    else 
      if (i%4==3)
	if (A[i/4][0]+A[i/4][1]+A[i/4][2]+A[i/4][3]!=k)
	  continue;
    if (i/4==3)
      if (A[0][i%4]+A[1][i%4]+A[2][i%4]+A[3][i%4]!=k)
	continue;
    if (i==14)
      if (A[0][1]+A[0][2]+A[1][0]+A[2][0]+A[1][3]+A[2][3]+A[3][1]+A[3][2]!=2*k)
	continue;
    df(i+1);
  }
  return;
}
    
    

int main(){
  ans=0;
  A=vector<vector<int> >(4,vector<int>(4,0));
  df(0);
  cout<<ans<<endl;
  return 0;
}
