#include <iostream>
using namespace std;

class Node
{
	public:
		
		int val;
		Node *L;
		Node *R;
		
		Node(int value) : val(value) , L(NULL) , R(NULL){}
};

void search_D(Node *n)
{
	if(n == NULL)
	{
		return;
	}
	else
	{
		cout << n->val << " ";
		search_D(n->L);
		search_D(n->R);
	}
}

void search_B(Node *n)
{
	if(n == NULL)
	{
		return;
	}
	else
	{
		search_B(n->L);
		search_B(n->R);
		cout << n->val << " ";
	}
}

int main(int argc, char** argv) 
{
	Node *n = new Node(1);
	n->L = new Node(2);
	n->R = new Node(3);
	n->L->L = new Node(4);
	n->L->R = new Node(5);
	n->R->L = new Node(6);
	n->R->R = new Node(7);
	
	cout << "DFS: ";
	search_D(n);
	cout << endl;
	
	cout << "BFS: ";
	search_B(n);
	cout << endl;
	
	delete n->R->R;
	delete n->R->L;
	delete n->L->R;
	delete n->L->L;
	delete n->R;
	delete n->L;
	delete n;
	return 0;
}
