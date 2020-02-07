#include <iostream>
using namespace std;

void partition(int A[],int p,int r,int indices[])
{
	int q,t,x,j,aux;
	q=p;
	t=r;
	x=A[p];
	j=p;
	while(j<=t)
	{
		if(A[j]<x)
		{
			aux=A[j];
			A[j]=A[q];
			A[q]=aux;
			j++;
			q++;	
		}
		else if(A[j]>x)
		{
			aux=A[j];
			A[j]=A[t];
			A[t]=aux;
			t--;
		}
		else j++;
	}
	indices[0]=q;
	indices[1]=t;
}

void quicksort(int A[],int p,int r)
{
	if(p<r)
	{
	    int indices[2];
	    partition(A,p,r,indices);
	    int q=indices[0];
	    int t=indices[1];
	    quicksort(A,p,q-1);
	    quicksort(A,t+1,r);
	}
}


int main()
{
	int A[100000],n,i;
	cin>>n;
	for(i=1;i<=n;i++) cin>>A[i];
	quicksort(A,1,n);
	for(i=1;i<=n;i++) cout<<A[i]<<" ";
	cout<<endl;
	
	return 0;
}
