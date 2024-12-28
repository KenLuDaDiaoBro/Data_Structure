#include <iostream>
#include <queue>
#include <list>
using namespace std;
//5
//1 2 3 4 5
//1 2 3 4 5
void cut(queue<int>* pre , queue<int> in , queue<long long>* Index , int stand[] , long long pow , int shaft)
{
	if(in.size() != 0)
	{ 
		//cout << pow << endl;
		int pp = pre->front();
		int ii = in.front();
		stand[pow - 1] = pp;
		pre->pop();
		Index->push(pow - 1);
		
		queue<int> temF;
		queue<int> temB;
		bool meet = false; //¦× 
		int s = in.size();
		for(int i = 0 ; i < s ; i++)
		{
			int now = in.front();
			in.pop();
			if(now == stand[pow - 1] && meet == false)
			{
				meet = true;
			}
			else if(meet == false)
			{
				temF.push(now);
			}
			else
			{
				temB.push(now);
			}
		}
		pow -= 1;
		cut(pre , temF , Index , stand , (pow + shaft) / 2 , shaft);
		cut(pre , temB , Index , stand , pow , (pow + shaft) / 2);
	}
}

int main(int argc, char** argv) 
{
	int l;
	cin >> l;
	int p;
	queue<int> pre;
	for(int i = 0 ; i < l ; i++)
	{
		cin >> p;
		pre.push(p);
	}
	queue<int> in;
	for(int i = 0 ; i < l ; i++)
	{
		cin >> p;
		in.push(p);
	}
	
	long long pow = 0;
	int sprt = l;
	while(sprt > 0)
	{
		pow = pow * 2 + 1;
		sprt--;
	}
	
	int stand[pow];
	queue<int>* P = &pre;
	queue<long long> Index;
	queue<long long>* I = &Index;
	cut(P , in , I , stand , pow , 0);
	bool print = false;
	for(long long i = 0 ; i < pow ; i++)
	{
		if(print == true)
		{
			cout << " ";
			print = false;
		}
		for(int j = 0 ; j < Index.size() ; j++)
		{
			long long now = Index.front();
			if(now == i)
			{
				cout << stand[i];
				print = true;
			}
			Index.pop();
			Index.push(now);
		}
	}
	cout << endl;
	return 0;
}
