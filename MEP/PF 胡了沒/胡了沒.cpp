#include <iostream>
#include <algorithm>
#include <list>
//5 6 7 9 10 11 19 20 20 20 20 21 27 27 33 33 33
using namespace std;
//找刻子
bool Three(list<int> PDF)
{
	bool SS = false;
	bool ano;
	if(PDF.empty() == true)
	{
		SS = true;
	}
	else if (PDF.size() % 3 == 0)
	{
		list<int> ::iterator i = PDF.begin();
		list<int> ::iterator Next = PDF.begin();
		list<int> ::iterator NNext = PDF.begin();
		int A = *i;
		Next ++;
		NNext ++;
		NNext ++;
		if(A == *Next && A == *NNext)
		{
			PDF.pop_front();
			PDF.pop_front();
			PDF.pop_front();
			ano = Three(PDF);
			if(ano == true)
			{
				SS = true;
			}
		}
	}
	return SS;
}
//找順子
bool Snake(list<int> C)
{
	bool SS = false;
	bool ano;
	if(C.empty() == true)
	{
		SS = true;
	}
	else if(C.size() % 3 == 0)
	{
		bool Find_Mid = false;
		bool Find_End = false;
		bool Find_Next = false;
		bool Find_NNext = false;
		list<int> ::iterator i = C.begin();
		list<int>  :: iterator Mid = C.begin();
		list<int>  :: iterator End = C.begin();
		int A = *i;
		Mid ++;
		End ++;
		End ++;
		if(A == *Mid)
		{
			Find_Next = true;
		}
		if(A == *End)
		{
			Find_NNext = true;
		}
		for(list<int>  :: iterator j = C.begin() ; j != C.end() ; j++)
		{
			if(*j == A + 1 && Find_Mid == false)
			{
				Mid = j;
				Find_Mid = true;
			}
			if(*j == A + 2 && Find_Mid == true && Find_End == false)
			{
				End = j;
				Find_End = true;
			}
		} 
		if(Find_Mid == true && Find_End == true && Find_Next == true && Find_NNext == true)
		{
			if(SS != true)
			{
				C.pop_front();
				C.pop_front();
				C.pop_front();
				ano = Snake(C);
				if(ano == true)
				{
					SS = true;
				}
			}
			else
			{
				C.push_front(A);
				C.push_front(A);
				C.erase(Mid);
				C.erase(End);
				if(ano == true)
				{
					SS = true;
				}
			}
		}
		else
		{
			if(Find_Mid == true && Find_End == true)
			{
				C.erase(i);
				C.erase(Mid);
				C.erase(End);
				ano = Snake(C);
				if(ano == true)
				{
					SS = true;
				}
			} 
			else
			{
				list<int> :: iterator Next = C.begin();
				list<int> :: iterator NNext = C.begin();
				Next ++;
				NNext ++;
				NNext ++;
				if(A == *Next && A == *NNext)
				{
					C.pop_front();
					C.pop_front();
					C.pop_front();
					ano = Snake(C);
					if(ano == true)
					{
						SS = true;
					}
				}
			}
		}
	}
	return SS;	
} 
//分類 
bool hat(int NE[] , int n)
{
	bool Ho = false;
	list<int> M;
	list<int> P;
	list<int> S;
	list<int> Z;
	for(int i = 0 ; i < 15 ; i++)
	{
		int TyPe = (NE[i]) / 9;
		switch ( TyPe )
      	{
         	case 0:
	            M.push_back(NE[i] + 1);
	            break;
	       	case 1:
	            P.push_back(NE[i] - 9 + 1);;
	            break;
	       	case 2:
	       		S.push_back(NE[i] - 18 + 1);
	       		break;
	        case 3:
	        	Z.push_back(NE[i] - 27 + 1);
	        	break;
	       	default:
	            break;
      	}
	}
	bool Check = false;
	Check = Snake(M);
	if(Check)
	{
		Check = Snake(P);
		if(Check)
		{
			Check = Snake(S);
			if(Check)
			{
				Check = Three(Z);
				if(Check)
				{
					Ho = true;
				}
			}
		}
	}
	return Ho;
}
//找出所有可能的眼睛 並存在Two 
list<int> find_eye(int Card [], int n )
{
	list<int> Two;
	for(int i = 0 ; i < 16 ; i++)
	{
		if(Card[i] == Card[i + 1])
		{
			Two.push_back(Card[i]);
		}
	}
	Two.unique();
	return Two;
}
//生成沒有眼睛的牌型 
bool No_EyE(int Card[] , int n , int EyE)
{
	bool Ho = true;
	int NE [15];
	int A = 0;
	for(int i = 0 ; i < 15 ; i++)
	{
		while(Card[i + A] == EyE && A < 2)
		{
			A++;
		}
		NE[i] = Card[i + A];
	}
	Ho = hat(NE , 15);
	return Ho;
}



int main(int argc, char** argv) 
{
	int result = 0;
	int Card[17];
	for(int i = 0 ; i < 17 ; i++)
	{
		cin >> Card[i];
	}
	sort(Card, Card + 17);
	list<int> Two = find_eye(Card , 17);
	int B = 0; //第幾種眼睛 
	if(Two.empty() != true)
	{
		for(list<int> ::iterator E = Two.begin() ; E != Two.end() ; E++)
		{
			int EyE = *E;
			bool Ken = No_EyE(Card , 17 , EyE);
			if(Ken)
			{
				result = 1;
			}
		}
	}
	cout << result << endl;
	return 0;
}
