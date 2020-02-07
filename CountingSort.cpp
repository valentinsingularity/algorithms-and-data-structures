#include<iostream>
#include<vector>
using namespace std;

vector<int> CountingSort(vector<int> A, int n,int k)
{
	int i,j;
	vector< vector<int> > m(k+1,vector<int>(n+1));
	for(i=1;i<=n;i++)
	{
		m[A[i]][m[A[i]][0]+1]=A[i];
		m[A[i]][0]++;  //m[i][0] stores the numeber of elements inserted into the row i
	}
	n=1;
	for(i=1;i<=k;i++)
	   for(j=1;j<=m[i][0];j++)
	   {
	   	 A[n]=m[i][j];
	   	 n++;
	   }
	return A;
}

int main()
{
	int n,k,i;
	cin>>n>>k;
	vector<int> A(n+1);
	for(i=1;i<=n;i++) cin>>A[i];
    A=CountingSort(A,n,k);
	for(i=1;i<=n;i++) cout<<A[i]<<" ";
	
	return 0;
}
