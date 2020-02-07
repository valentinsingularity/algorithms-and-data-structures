#include<iostream>
#include<vector>
#include<set>
using namespace std;

float determinant(float px,float py,float qx,float qy,float rx, float ry)
{
	return px*(qy-ry)-py*(qx-rx)+(qx*ry-qy*rx);
}

int main()
{
	int i,j,k,n,s;
	float det;
	cin>>n;
	vector<float> x(n+1);
	vector<float> y(n+1);
	for(i=1;i<=n;i++) cin>>x[i]>>y[i];
	
	set<int> convex_hull;
	set<int>::iterator it;
	
	for(i=1;i<=n;i++)
	  for(j=1;j<=n;j++)
	    {
	   	   if(x[i]!=x[j] || y[i]!=y[j])
	   	   {
	   	   	  s=0;
	   	   	  for(k=1;k<=n;k++)
	   	   	    if(i!=k && j!=k)
	   	   	       {
	   	   	       	     det=determinant(x[i],y[i],x[j],y[j],x[k],y[k]);
 	   	   	       	     if(det>0) s++;
				     else if(det<0) s--; 	   	   	       	     
	   	   	       }
	   	   	  if(s == -(n-2) || s == n-2 )
			  {
			  	convex_hull.insert(i);
			  	convex_hull.insert(j);
			  } 
	   	   }
	    }
	
	for (it=convex_hull.begin(); it!=convex_hull.end(); ++it) cout<<*it<<" ";
	
	return 0;
}
