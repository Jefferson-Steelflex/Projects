#include <iostream>
using namespace std;

void clear()
{
	cin.clear();
	cin.ignore(1000,'\n');
}

int main()
{
	cout << "  (+/-) "  << "   2nd" << endl;
	
	cout << " 7 8 9  ÷" << endl;
	
	cout <<	" 4 5 6  x" << endl;
	
	cout << " 1 2 3  +" << endl;
	
	cout << " C 0 .  -" << endl;

	char input;

	while(!(cin >> input))
	{
		cout <<"err" << endl;
		clear();
	}

	
	
}
