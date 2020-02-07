#include<iostream>
#include<vector>
#include<cstdlib>
#include<ctime>
#include<string>
using namespace std;

class Object{
	public:
	string name;
	int k;
	Object()
	{
		name=" ";
		k=0;
	}
	Object(string nname,int nk)
	{
		name=nname;
		k=nk;
	}
};

string ObjSearch(int k,vector< vector<Object> > T)
{
	int m,j,nj,aj,bj,h2;
	m=T.size();
	j=k%m;
	Object obj;
	obj=T[j][T[j].size()-3];
    nj=obj.k;
    obj=T[j][T[j].size()-2];
    aj=obj.k;
    obj=T[j][T[j].size()-1];
    bj=obj.k;
    h2=(aj*k+bj)%(nj*nj);
    return T[j][h2].name;
}

int main()
{
	
    unsigned int n,m,i,j;
	int k,h1,h2,aj,bj,nj,ok;
	string name;
    cin>>n>>m;
    vector<Object> unordered_list(n);
    vector< vector<Object> > obj_list(m);
    vector< vector<Object> > T(m);
    for(i=0;i<n;i++)
    {
    	cin>>name>>k;
    	Object obj=Object(name,k);
    	h1=k%m;
        obj_list[h1].push_back(obj);
        unordered_list.push_back(obj);
    }
    
    for(j=0;j<m;j++)
    {
    	nj=obj_list[j].size();
    	T[j].resize(nj*nj+3);
   
        ok=0;
        while(!ok)
        {
          ok=1;
    	  srand(time(NULL));
    	  aj=rand()%1001;
    	  bj=rand()%1001;
    	  vector<int> x(nj*nj);
    	  for(i=0;i<obj_list[j].size();i++)  //obtain h2 without collisions
    	  {  	
    	       k=obj_list[j][i].k;
    		   h2=(aj*k+bj)%(nj*nj);
               if(x[h2]==1)
                 {
                 	ok=0;
                 	break;
                 }
               else x[h2]=1;
    	  }
    	  
	    }
	    

	    for(i=0;i<obj_list[j].size();i++)
    	  {  	
    	       Object obj=obj_list[j][i];
    	       k=obj.k;
    		   h2=(aj*k+bj)%(nj*nj);
    		   T[j][h2]=obj;
          }
		T[j][nj*nj]= Object("nj",nj);
		T[j][nj*nj+1]= Object("aj",aj);
		T[j][nj*nj+2]= Object("bj",bj);
    }

   
    string s;
    
    for(i=0;i<n;i++)
    {
       s=ObjSearch(unordered_list[i].k,T);
       cout<<s<<endl;
    }
	return 0;
}
