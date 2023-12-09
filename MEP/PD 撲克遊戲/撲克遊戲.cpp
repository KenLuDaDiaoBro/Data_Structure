#include <iostream>
#include <stack>
using namespace std;

int main(int argc, char** argv) 
{
	int AsK[100];
	int A = 0;
	stack<int> st;
	for(int i = 0 ; i < 3 ; i++)
	{
		cin >> AsK[i];
	}
	for(int i = 1 ; i <= 3 ; i++)
	{
		st.push(i);
		while((st.empty() != true) && (AsK[A] == st.top()))
		{
			A++;
			st.pop();
		}
	}
	if(A == 3)
	{
		cout << "Yes" << endl;
	}
	else
	{
		cout << "No" << endl;
	}
	return 0;
}
