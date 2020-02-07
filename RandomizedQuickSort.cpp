#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

void randomized_partition(int A[],int p,int r,int indices[])
{
	int q,t,x,j,i,aux;
	q=p;
	t=r;
	x=A[p];
	j=p;
	srand(time(NULL));
	i=p + (rand() % (r-p+ 1  ) );
	aux=A[p];
	A[p]=A[i];
	A[i]=aux;
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

void randomized_quicksort(int A[],int p,int r)
{
	if(p<r)
	{
	    int indices[2];
	    randomized_partition(A,p,r,indices);
	    int q=indices[0];
	    int t=indices[1];
	    randomized_quicksort(A,p,q-1);
	    randomized_quicksort(A,t+1,r);
	}
}


int main()
{
	int A[100000],n,i,srt_seq[100000],rev_seq[100000],rand_seq[100000];
	cin>>n;
	for(i=1;i<=n;i++) cin>>A[i];
	randomized_quicksort(A,1,n);
	for(i=1;i<=n;i++) cout<<A[i]<<" ";
	cout<<endl;
	
	srand(time(NULL));
        for(i=1;i<=n;i++) 
	{
                srt_seq[i]=i;
		rev_seq[i]=n-i+1;
		rand_seq[i]=rand()%1001;
	}
	
	randomized_quicksort(srt_seq,1,n);
	randomized_quicksort(rev_seq,1,n);
	randomized_quicksort(rand_seq,1,n);
	for(i=1;i<=n;i++) cout<<srt_seq[i]<<" ";
	cout<<endl;
	for(i=1;i<=n;i++) cout<<rev_seq[i]<<" ";
	cout<<endl;
	for(i=1;i<=n;i++) cout<<rand_seq[i]<<" ";
	cout<<endl;

	return 0;
}
