#include <iostream>
#include <cmath>
#include <iomanip>
#include <cstdio> 
using namespace std;

typedef struct Pos
{
	double x;//x,y要用double类型的变量接受数据，题目中说输入数据一行由4个实数组成，实数包含有理数和无理数，无理数即无限不循环小数。 
	double y;//用int类型接受变量会报错Output Limit Exceed 
}Pos;

int main()
{
	Pos a,b;
	while(~scanf("%lf%lf%lf%lf",&a.x, &a.y, &b.x, &b.y))//scanf接受double类型的数据要用%lf，如果用%f接收数据直接wrong answer 
	{		
	double distance = sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
	cout << fixed << setprecision(2) << distance << endl;
	}
	return 0;
	
}
