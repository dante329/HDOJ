#include <iostream>
#include <cmath>
#include <iomanip>
#include <cstdio> 
using namespace std;

typedef struct Pos
{
	double x;//x,yҪ��double���͵ı����������ݣ���Ŀ��˵��������һ����4��ʵ����ɣ�ʵ���������������������������������޲�ѭ��С���� 
	double y;//��int���ͽ��ܱ����ᱨ��Output Limit Exceed 
}Pos;

int main()
{
	Pos a,b;
	while(~scanf("%lf%lf%lf%lf",&a.x, &a.y, &b.x, &b.y))//scanf����double���͵�����Ҫ��%lf�������%f��������ֱ��wrong answer 
	{		
	double distance = sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
	cout << fixed << setprecision(2) << distance << endl;
	}
	return 0;
	
}
