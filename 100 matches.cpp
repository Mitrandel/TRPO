#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

const int InitialCount=100;
int Count,Num,Player;
bool Correct;

int main ()
{
    setlocale(LC_ALL, "Russian");    
    srand(time(0));
    system ("cls");
    Player=1;
    Count=InitialCount;
	do
	{
  	if (Player==1)
	{
    	do
		{
        cout<<"��� ���. �� ����� "<<Count<<" ������.\n";
        cout<<"������� ������ �� ������?\n";
        cin>>Num;
        	if(Num>=1&&Num<=10&&Num<=Count)
          		Correct=true;
        	else
        	{
            cout<<"�������! ��������� ����!\n";
            Correct=false;
        	} 
    	}
    	while (!Correct);
   	}
    else
    {
    	do
			{
     		Num=rand()%10+1;
      		if (Num>Count)
        		Num=Count;
      			cout<<"��� ���. � ���� "<<Num<<" ������\n";
			}
        while (!Correct);   
    }
    Count-=Num;
    if (Player==1) 
        Player=2;
    else 
        Player=1;
    }
 	while (Count>0);
  	if (Player=1)
    	cout<<"�� ��������!";
  	else 
  		cout<<"�� ���������!";
  	system("pause");	
    return 0;
}