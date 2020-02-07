#include<iostream>
#include<cstdlib>
#include<vector>
using namespace std;

void printOptimalMultiplication(vector< vector<int> > order,int i, int j)
{
	if(i==j)
	{
		cout<<"A"<<i;
	} 
	else
	{
        int k=order[i][j];
        cout<<"(";
	    printOptimalMultiplication(order,i,k);
	    cout<<" * ";
	    printOptimalMultiplication(order,k+1,j);
	    cout<<")";
    }
}

int main()
{
	int i,j,n,k,l,r,length;
	cin>>n;
	vector<int> dim(n+1);
	vector< vector <int> > m(n+1); 
	for(i=0;i<n+1;i++) m[i].resize(n+1);
	vector< vector <int> > order(n+1);
	for(i=0;i<n+1;i++) order[i].resize(n+1);
	
	for(i=1;i<=n;i++) 
	{
		cin>>k>>l;
		if(i==1) 
		{
		   dim[i-1]=k;
		   dim[i]=l;
	    }
	    else if(k!=dim[i-1])
	         {
	        	cout<<"Incompatible dimensions"<<endl;
	        	exit(0);
	         }
	         else
	         {
	         	dim[i]=l;
	         }
	}		  
	
    
    for(length=1;length<n;length++)
    {
       for(i=1;i<n-length+1;i++)
        {
        	j=i+length;
        	k=i;
        	m[i][j]=m[i][k]+m[k+1][j]+dim[i-1]*dim[k]*dim[j];
        	order[i][j]=k;
        	for(k=i+1;k<j;k++)
        	{
        	        r=m[i][k]+m[k+1][j]+dim[i-1]*dim[k]*dim[j];
        		  	if(r < m[i][j]) 
					{
						m[i][j]=r;
        	     	  	order[i][j]=k;
					}
        	}   	
        }
    }
    
    
    cout<<"Minimum number of scalar multiplications: "<<m[1][n]<<endl;
    printOptimalMultiplication(order,1,n);
	
	return 0;
}
