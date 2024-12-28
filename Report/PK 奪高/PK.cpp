#include <iostream>
using namespace std;

class Node
{
	public:
		
		int v;
		Node *Lnext , *Rnext;
		
		Node(int value): v(value) , Lnext(NULL) , Rnext(NULL){};
};

int Max = 0;
Node *O = new Node(0);

void plant(int n , Node *m , int level)
{
	level++;
	if(n < m->v)
	{
		if(m->Lnext == NULL)
		{
			m->Lnext = new Node(n);
			if(level > Max)
			{
				Max = level;
			}
		} 
		else
		{
			plant(n , m->Lnext , level);
		}
	}
	else if(m->v < n)
	{
		if(m->Rnext == NULL)
		{
			m->Rnext = new Node(n);
			if(level > Max)
			{
				Max = level;
			}
		}
		else
		{
			plant(n , m->Rnext , level);	
		}
	}
}

int main(int argc, char** argv) 
{
	int n;
	cin >> n;
	for(int i = 0 ; i < n ; i++)
	{
		int num;
		cin >> num;
		plant(num , O , 0);
	}
	cout << Max << endl;
	return 0;
}
