#include<iostream>
#include<cstdlib>
#include<vector>
using namespace std;


class DEQueue
{
	public:
	DEQueue():A(100000)
	{
		head=0;
		tail=0;
	}
	DEQueue(int n):A(n)
	{
		head=0;
		tail=0;
	}
	unsigned int head;
	unsigned int tail;
	vector<int> A;
	void EnqueueFront(int x);
	void EnqueueRear(int x);
	int DequeueFront();
	int DequeueRear();
};

void DEQueue::EnqueueRear(int x)
{
	int reseted=0;
	tail++;
	if(tail > A.size()-1)
	{
		tail=0;
		reseted=1;
	}
	if(tail==head)
	{
		cout<<"Overflow";
		exit(0);
    }
	else
	{
		if(reseted) A[A.size()-1]=x;
		else A[tail-1]=x; 
	}
}

void DEQueue::EnqueueFront(int x)
{
	if(head==0) head=A.size()-1;
	else head--;
	if(head==tail) 
	{
		cout<<"Overflow";
		exit(0);
	}
	else A[head]=x;
}

int DEQueue::DequeueRear()
{
	int x;
	if(head==tail)
	{
		cout<<"Underflow";
		exit(0);
	}
	if(tail==A.size()-1)
	{
		x=A[0];
		tail--;
	}
	else if(tail==0)
	{
		x=A[A.size()-1];
		tail=A.size()-1;
	}
	else
	{
		x=A[tail-1];
		tail--;
	}
	return x;
}

int DEQueue::DequeueFront()
{
	int x;
	if(head==tail)
	{
		cout<<"Underflow";
		exit(0);
	}
	x=A[head];
	if(head==A.size()-1) head=0;
	else head++;
	return x;
}



int main()
{
	DEQueue q;

	q.EnqueueFront(3);
	q.EnqueueFront(5);
	q.EnqueueRear(10);
	q.EnqueueRear(8);
	cout<<q.DequeueRear()<<" ";
	cout<<q.DequeueFront()<<" ";
	cout<<q.DequeueRear()<<" ";
	q.EnqueueFront(100);
	cout<<q.DequeueRear()<<" ";
	cout<<q.DequeueFront()<<" ";
	cout<<endl;
	
	DEQueue q2(5);
	
	q2.EnqueueRear(10);
	q2.EnqueueRear(8);
	q2.EnqueueFront(3);
	q2.EnqueueFront(2);
	cout<<q2.DequeueFront()<<" ";
	cout<<q2.DequeueFront()<<" ";
	cout<<q2.DequeueFront()<<" ";
	cout<<q2.DequeueFront()<<" ";
	
	return 0;
}
