#include <iostream>
#include <string>
#include <stack> 
using namespace std;
//A+B*C-D
//-+A*BCD
int main(int argc, char** argv) 
{
	string l;
	cin >> l;
	int len = l.length();
	stack<int> st;
	stack<int> ans;
	for(int i = len - 1 ; i >= 0 ; i--)
	{
		switch(l[i])
		{
			case ')':
				st.push(l[i]);
				break;
				
			case '(':
				while(st.top() != ')')
				{
					ans.push(st.top());
					st.pop();
				}
				break;
				
			case '+':
				if(st.top() == '*' || st.top() == '/')
				{
					ans.push(st.top());
					st.pop();
				}
				st.push(l[i]);
				break;
				
			case '-':
				if(st.top() == '*' || st.top() == '/')
				{
					ans.push(st.top());
					st.pop();
				}
				st.push(l[i]);
				break;
				
			case '*':
				st.push(l[i]);
				break;
				
			case '/':
				st.push(l[i]);
				break;
				
			case '^':
				if(st.top() == '*' || st.top() == '/' || st.top() == '+' || st.top() == '-')
				{
					ans.push(st.top());
					st.pop();
				}
				st.push(l[i]);
				break;
				
			default:
				ans.push(l[i]);
				break;
		}
	}
	while(st.empty() == false)
	{
		ans.push(st.top());
		st.pop();
	}
	while(ans.empty() == false)
	{
		int A = ans.top();
		cout << (char)A;
		ans.pop();
	} 
	cout << endl;
	return 0;
}
