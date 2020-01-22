#include <iostream>
#include <time.h>
#include <stdio.h>

using namespace std;


int main()
{
	bool specialNum = false;
	bool reBorn = false;
	bool checkNum = false;//判斷選的數字是否超過49或小於1
	int inputNum = 0;
	int sameNum = 0;
	int difposSameNum = 0;
	int choose[7];
	int prize[7];

	srand(time(NULL));

	for (int i = 0; i < 7; i++)//產生樂透不重複7碼
	{
		prize[i] = rand() % 49 + 1;
		for (int j = 0; j < 7; j++)			//檢查有無重複
		{
			if (i == j)
			{
				break;
			}
			else if (prize[i] == prize[j])
			{
				prize[i] = rand() % 49 + 1;
				j = 0;
			}
		}
	}
	
	for (int i = 0; i < 7; i++)
	{
		while (true)
		{
			if (i == 6)
			{
				cout << "請輸入你選的特別號:" << endl;
				cin >> choose[i];
			}
			else
			{
				cout << "請輸入你選的第" << i + 1 << "個數字:" << endl;
				cin >> choose[i];
			}
			if (choose[i] <= 49 && choose[i] > 0)
			{
				break;
			}
			else if (choose[i] > 49 || choose[i] < 1)
			{
				cout << "數字錯誤，請重新輸入!" << endl;
			}
		}

	}
	cout << "你選的7碼:	";
	for (int i = 0; i < 7; i++)
	{
		cout << choose[i] << "	";
	}

	cout << "\n當期獎號:	";
	for (int i = 0; i < 7; i++)
	{
		cout << prize[i] << "	";
	}
	cout << "\n" << endl;

	for (int i = 0; i < 7; i++)			//兌獎
	{
		if (choose[6] == prize[6])
		{
			specialNum = true;
		}
		else if (choose[i] == prize[i])
		{
			sameNum++;
		}
	}

	switch (sameNum) //偵測 中哪種等級獎項
	{
	case 6:
		cout << "恭喜得到壹獎!" << endl;
		break;
	case 5:
		if (specialNum)
		{
			cout << "恭喜得到貳獎!" << endl;
			break;
		}
		cout << "恭喜得到參獎!" << endl;
		break;
	case 4:
		if (specialNum)
		{
			cout << "恭喜得到肆獎!" << endl;
			break;
		}
		cout << "恭喜得到伍獎 2000元!" << endl;
		break;
	case 3:
		if (specialNum)
		{
			cout << "恭喜得到陸獎 1000元!" << endl;
			break;
		}
		else
		{
			cout << "你沒中獎!" << endl;
			break;
		}
	case 2:
		if (specialNum)
		{
			cout << "恭喜得到柒獎 400元!" << endl;
			break;
		}
		else
		{
			cout << "你沒中獎!" << endl;
			break;
		}

	}

	for (int i = 0; i < 7; i++)			//偵測普獎
	{
		for (int j = 0; j < 7; j++)
		{
			if (choose[i] == prize[j])
			{
				difposSameNum++;
			}
		}
	}

	if (difposSameNum == 3)
	{
		cout << "恭喜得到柒普獎 400元!" << endl;
	}
	else if (sameNum <= 3 && !specialNum)
	{
		cout << "你沒中獎!" << endl;
	}

}

