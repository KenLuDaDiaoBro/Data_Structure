#include <iostream>
#include <stack>
using namespace std;
stack<int> su3a8 ;
int re;

int main(int argc, char** argv) 
{
	char ch[100] = {0};
	for(int i = 0 ; i < 100 ; i++)
	{
		ch[i] = 'A';
	}
	cin.getline(ch , 100);
	
	int now = 0;
	while(ch[now] != 'A')
	{
		int cand;
		int cer;
		switch(ch[now])
		{
			case ' ':
				break;
			
			case '+':
				cer = su3a8.top();
				su3a8.pop();
				cand = su3a8.top();
				su3a8.pop();
				su3a8.push(cand + cer);
				//cout << su3a8.top() << endl;
				re = su3a8.top();
				break;
			
			case '-':
				cer = su3a8.top();
				su3a8.pop();
				cand = su3a8.top();
				su3a8.pop();
				su3a8.push(cand - cer);
				//cout << su3a8.top() << endl;
				re = su3a8.top();
				break;
				
			case '*':
				cer = su3a8.top();
				su3a8.pop();
				cand = su3a8.top();
				su3a8.pop();
				su3a8.push(cand * cer);
				//cout << su3a8.top() << endl;
				re = su3a8.top();
				break;
				
			case '/':
				cer = su3a8.top();
				su3a8.pop();
				cand = su3a8.top();
				su3a8.pop();
				su3a8.push(cand / cer);
				//cout << su3a8.top() << endl;
				re = su3a8.top();
				break;
				
			case '%':
				cer = su3a8.top();
				su3a8.pop();
				cand = su3a8.top();
				su3a8.pop();
				su3a8.push(cand % cer);
				//cout << su3a8.top() << endl;
				re = su3a8.top();
				break;
				
			default:
				int add = ch[now] - '0';
				su3a8.push(add);
				break;
		}
		now++;
	}
	
	cout << re << endl;
	
	return 0;
}
