#include <iostream>
#include <stack>
using namespace std;

int main(int argc, char** argv) 
{
	int len;
	cin >> len;
	int t;
	cin >> t;
	while(t > 0)
	{
		int AsK[100];
		int A = 0;
		stack<int> st;
		for(int i = 0 ; i < len ; i++)
		{
			cin >> AsK[i];
		}
		for(int i = 1 ; i <= len ; i++)
		{
			st.push(i);
			while((st.empty() != true) && (AsK[A] == st.top()))
			{
				A++;
				st.pop();
			}
		}
		if(A == len)
		{
			cout << "Yes" << endl;
		}
		else
		{
			cout << "No" << endl;
		}
		t--;
	}
	return 0;
}
