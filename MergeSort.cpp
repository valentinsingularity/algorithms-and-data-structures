#include <iostream>
#include <cstdlib>
#include <ctime>
#include <chrono>
#define NMAX 100000
using namespace std;


void Merge(int A[],int l,int m,int r)
{
	int i=l,j=m+1,k=1;
	int B[r-l+2];
	while(i<=m && j<=r)
	  if(A[i]<=A[j]) B[k++]=A[i++];
	  else B[k++]=A[j++]; 	  
	while(i<=m) B[k++]=A[i++];
	while(j<=r) B[k++]=A[j++];
	for(i=l;i<=r;i++) A[i]=B[i-l+1];
}


void MergeSort(int A[],int n)
{
	int l,m,r,final=0;
	while(!final)
	{
		l=1;
		final=1;
		while(l<n)
		{
			m=l;
			while(m<n && A[m]<=A[m+1]) m++;
			r=m+1;
			while((r<n && A[r]<=A[r+1]) || r==n-1) r++;
			if(r<=n)
			{
				Merge(A,l,m,r);
				final=0;
			}
			l=r+1;
		}
	}
}



int main()
{
	int n,i,j,srt_seq[NMAX],rev_seq[NMAX],rand_seq[NMAX];
	cin>>n;
	
	srand(time(NULL));
    for(i=1;i<=n;i++) 
	{
		srt_seq[i]=i;
		rev_seq[i]=n-i+1;
		rand_seq[i]=rand()%1001;
		
	}
    cout<<"Computing the execution times of MergeSort: "<<endl;
    auto start = std::chrono::high_resolution_clock::now();
    MergeSort(srt_seq,n);
    auto elapsed = std::chrono::high_resolution_clock::now() - start;
    long long ms = std::chrono::duration_cast<std::chrono::microseconds>(elapsed).count();
    cout<<"Sorted sequence: "<<ms<<" microseconds"<<endl;
    
    start = std::chrono::high_resolution_clock::now();
    MergeSort(rev_seq,n);
    elapsed = std::chrono::high_resolution_clock::now() - start;
    ms = std::chrono::duration_cast<std::chrono::milliseconds>(elapsed).count();
    cout<<"Reverse sorted sequence: "<<ms<<" milliseconds"<<endl;
    
    cout<<"Trials for random sequence: "<<endl;
    long long sum=0;
    for(i=1;i<=10;i++)
    {
    if(i!=1) for(j=1;j<=n;j++) rand_seq[j]=rand()%1001;
    start = std::chrono::high_resolution_clock::now();
    MergeSort(rand_seq,n);
    elapsed = std::chrono::high_resolution_clock::now() - start;
    ms = std::chrono::duration_cast<std::chrono::milliseconds>(elapsed).count();
    cout<<ms<<" milliseconds"<<endl;
    sum+=ms;
    }
    cout<<"Average random time: "<<sum/10<<" milliseconds"<<endl;
    
    	
	return 0;
}
