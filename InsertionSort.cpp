#include <iostream>
#include <cstdlib>
#include <ctime>
#include <chrono>
using namespace std;
#define GMAX 1000
#define NMAX 100000

void GInsertionSort(int A[],int n,int g[],int k)
{
  int i,j,r,key;
  for(r=1;r<=k;r++)
	for(j=1;j<=n;j+=g[r])
	{
		key=A[j];
		i=j-g[r];
		while(i>0 && A[i]>key)
		{
		  A[i+g[r]]=A[i];
		  i-=g[r];
		  A[i+g[r]]=key;
		}
	} 
		
}

void InsertionSort(int A[],int n)
{   
    int i,j,key;
	for(j=1;j<=n;j++)
	{
		key=A[j];
		//Insert A[j] into the sorted sequence
		i=j-1;
		while(i>0 && A[i]>key)
		{
		  A[i+1]=A[i];
		  i--;
		  A[i+1]=key;
		}
	} 
}

int main()
{
	int k,g[GMAX],i,n,srt_seq[NMAX],rev_seq[NMAX],rand_seq[NMAX],j;
	
/*	
	cin>>k;
	for(i=1;i<=k;i++) cin>>g[i];
*/
    k=3;
    g[1]=4;
    g[2]=2;
    g[3]=1;

    cin>>n;
    srand(time(NULL));
    
    for(i=1;i<=n;i++) 
	{
		srt_seq[i]=i;
		rev_seq[i]=n-i+1;
		rand_seq[i]=rand()%1001;
		
	}
	
	
	
    cout<<"Computing the execution times of GInsertionSort: "<<endl;
    auto start = std::chrono::high_resolution_clock::now();
    GInsertionSort(srt_seq,n,g,k);
    auto elapsed = std::chrono::high_resolution_clock::now() - start;
    long long ms = std::chrono::duration_cast<std::chrono::nanoseconds>(elapsed).count();
    cout<<"Sorted sequence: "<<ms<<" nanoseconds"<<endl;
    
    start = std::chrono::high_resolution_clock::now();
    GInsertionSort(rev_seq,n,g,k);
    elapsed = std::chrono::high_resolution_clock::now() - start;
    ms = std::chrono::duration_cast<std::chrono::microseconds>(elapsed).count();
    cout<<"Reverse sorted sequence: "<<ms<<" microseconds"<<endl;
    
    cout<<"Trials for random sequence: "<<endl;
    long long sum=0;
    for(i=1;i<=10;i++)
    {
    if(i!=1) for(j=1;j<=n;j++) rand_seq[j]=rand()%1001;
    start = std::chrono::high_resolution_clock::now();
    GInsertionSort(rand_seq,n,g,k);
    elapsed = std::chrono::high_resolution_clock::now() - start;
    ms = std::chrono::duration_cast<std::chrono::microseconds>(elapsed).count();
    cout<<ms<<" microseconds"<<endl;
    sum+=ms;
    }
    cout<<"Average random time: "<<sum/10<<" microseconds"<<endl;
    
/*    
    
    for(i=1;i<=n;i++) 
	{
		srt_seq[i]=i;
		rev_seq[i]=n-i+1;
		rand_seq[i]=rand()%1001;
		
	}
	cout<<endl<<"Computing the execution times of the original InsertionSort: "<<endl;
	
    start = std::chrono::high_resolution_clock::now();
    InsertionSort(srt_seq,n);
    elapsed = std::chrono::high_resolution_clock::now() - start;
    ms = std::chrono::duration_cast<std::chrono::nanoseconds>(elapsed).count();
    cout<<"Sorted sequence: "<<ms<<" nanoseconds"<<endl;
    
    start = std::chrono::high_resolution_clock::now();
    InsertionSort(rev_seq,n);
    elapsed = std::chrono::high_resolution_clock::now() - start;
    ms = std::chrono::duration_cast<std::chrono::microseconds>(elapsed).count();
    cout<<"Reverse sorted sequence: "<<ms<<" microseconds"<<endl;
    
    cout<<"Trials for random sequence: "<<endl;
    sum=0;
    for(i=1;i<=10;i++)
    {
    if(i!=1) for(j=1;j<=n;j++) rand_seq[j]=rand()%1001;
    start = std::chrono::high_resolution_clock::now();
    InsertionSort(rand_seq,n);
    elapsed = std::chrono::high_resolution_clock::now() - start;
    ms = std::chrono::duration_cast<std::chrono::microseconds>(elapsed).count();
    cout<<ms<<" microseconds"<<endl;
    sum+=ms;
    }
    cout<<"Average random time: "<<sum/10<<" microseconds"<<endl;
    
    
 */   
    
	return 0;
}

