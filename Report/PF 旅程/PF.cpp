#include <iostream>
#include <queue>
#include <list>
using namespace std;

int count(queue<int> re , queue<int>* min , int sew[][3] , int l , int v_size)
{
	int row = re.size();
	row /= v_size;
	int col = v_size;
	int min_value;
	for(int i = 0 ; i < row ; i++)
	{
		int s;
		int e;
		queue<int> tem;
		int w = 0;
		for(int j = 1 ; j < col ; j++)
		{
			s = re.front();
			re.pop();
			tem.push(s);
			e = re.front();
			for(int k = 0 ; k < l ; k++)
			{
				if((s == sew[k][0] && e == sew[k][1]) || (s == sew[k][1] && e == sew[k][0]))
				{
					w += sew[k][2];
				}
			}
		}
		re.pop();
		tem.push(e);
		if(i == 0 || min_value > w)
		{
			min_value = w;
			while(min->size() != 0)
			{
				min->pop();
			}
			for(int i = 0 ; i < v_size ; i++)
			{
				min->push(tem.front());
				tem.pop();
			}
		}
	}
	//cout <<endl << "min ";
	for(int i = 0 ; i < min->size() ; i++)
	{
		int now = min->front();
		//cout << now << " ";
		min->pop();
		min->push(now);
	}
	return min_value;
}

void tri(list<int> v , int sew[][3] , int l , int v_size , int start , queue<int>* re)
{
	queue<int> edge;
	for(int i = 0 ; i < l ; i++)
	{
		bool find = false;
		for(int j = 0 ; j < edge.size() ; j++)
		{
			int now = edge.front();
			edge.pop();
			edge.push(now);
			if(now == sew[i][0] || now == sew[i][1])
			{
				find = true;
			}
		}
		for(int j = 0 ; j < v.size() ; j++)
		{
			int now = v.front();
			v.pop_front();
			v.push_back(now);
			if(now == sew[i][0] || now == sew[i][1])
			{
				find = true;
			}
		}
		if(find == false)
		{
			if(sew[i][0] == start)
			{
				edge.push(sew[i][1]);
			}
			else if(sew[i][1] == start)
			{
				edge.push(sew[i][0]);
			}
		}
	}
	v.push_back(start);
	if(v.size() == v_size)
	{
		for(int i = 0 ; i < v_size ; i++)
		{
			int now = v.front();
			v.pop_front();
			re->push(now);
			v.push_back(now);
		}
	}
	else if(edge.size() == 0)
	{
		//cout <<"§A¶ý" << endl; 
	}
	else
	{
		int e_l = edge.size();
		for(int i = 0 ; i < e_l ; i++)
		{
			int now = edge.front();
			tri(v , sew , l , v_size , now , re);
			edge.pop();
		}
	}
}

int main(int argc, char** argv) 
{
	int start;
	cin >> start;
	queue<int> input;
	int s;
	int e;
	int w;
	cin >> s;
	cin >> e;
	cin >> w;
	while(s != -1 && e != -1 && w != -1)
	{
		input.push(s);
		input.push(e);
		input.push(w);
		cin >> s;
		cin >> e;
		cin >> w;
	}
	int l = input.size();
	l /= 3;
	int sew[l][3];
	queue<int> v;
	v.push(start);
	for(int i = 0 ; i < l ; i++)
	{
		s = input.front();
		sew[i][0] = s;
		input.pop();
		e = input.front();
		sew[i][1] = e;
		input.pop();
		w = input.front();
		sew[i][2] = w;
		input.pop();
		int find_s = false;
		int find_e = false;
		for(int i = 0 ; i < v.size() ; i++)
		{
			int now = v.front();
			v.pop();
			v.push(now);
			if(now == s)
			{
				find_s = true;
			}
			if(now == e)
			{
				find_e = true;
			}
		}
		if(find_s == false)
		{
			v.push(s);
		}
		if(find_e == false)
		{
			v.push(e);
		}	
	}
	//cout << v.size();
	int v_size = v.size();
	
	queue<int> edge;
	list<int> vtex;
	list<int>* V = &vtex;
	//int min = step(V);
	queue<int> re;
	queue<int>* Re = &re;
	tri(vtex , sew , l , v_size , start , Re);
	for(int i = 0 ; i < re.size() ; i++)
	{
		if(i % v_size == 0)
		{
			//cout << endl;
		}
		int now = re.front();
		//cout << now << " ";
		re.pop();
		re.push(now);
	}
	
	queue<int> min;
	queue<int>* m = &min;
	int min_value =  count(re , m , sew , l , v_size);
	for(int i = 1 ; i < v_size ; i++)
	{
		int s = min.front();
		min.pop();
		int e = min.front();
		cout << i << ": <" << s << "," << e << ">" << endl;
	}
	cout << "The cost of minimum spanning tree: " << min_value << endl;
	
	return 0;
}
