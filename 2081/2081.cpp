#include <iostream>
using namespace std;

int main()
{
	int n;
	cin >> n;
	while(n--)
	{
		char tele[11];
		for(int i=0;i<11;++i)
		{
			cin >> tele[i];
		}
		cout << "6" ;
		for(int i=6;i<11;++i)
		{
			cout << tele[i] ;
		}
		cout << endl;
	}
	return 0;
}
