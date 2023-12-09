#include <iostream>
using namespace std;

int main(int argc, char** argv) 
{
	int score[5];
	int ToTle = 0;
	for(int i = 0 ; i < 5 ; i++)
	{
		cin >> score[i];
		cout << "第" << i + 1 << "位學生的分數是" << score[i] << endl;
		ToTle += score[i]; 
	} 
	cout << "5位學生的總分是" << ToTle << "分" << endl;
	system("pause"); 
	return 0;
}
