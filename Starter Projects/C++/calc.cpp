#include <iostream>
#include <cmath>
#include <string>
using namespace std;

double addition(double a,double b) 											// return value and parameters should be doubles to allow accurate decimal numbers
{
	 return a + b;
}

double subtraction(double a ,double b)
{
	return a - b;
}

double  multiply(double a, double b)
{
	return a * b;
}

double division(double a, double b)
{
	return a / b;

	if(b == 0.0)
	{
		cout << "undefined" << endl;
	}
}

void clear()
{
	cin.clear();														//function to clear buffer leftover to avoid infinite loop/leftover characters 
	cin.ignore(1000, '\n');
}

void errormsg()
{
	cout << "invalid input, try again" << endl;
}

int main()
{

	while(true)
	{
		double num;
		double numz;

		cout << "Enter a digit: ";
		while(!(cin >> num)) 										    // if cin fails to read proper input(a number)
		{
			errormsg();													//clears the buffer to avoid infinite loop
			clear(); 
			cout << "Enter a digit: ";										 
		}

		cout << "Enter a digit: ";
		while(!(cin >> numz))
		{
			errormsg();
			cout << "Enter a digit: ";
			clear();
			
		}
	

		int input;
	
		cout << "\n1.)Addition\n2.)Subtraction\n3.)Multiplication\n4.)Division\n5.)Quit" << endl;
		
		while(!(cin >> input))
		{
			errormsg();
			cout << "\n1.)Addition\n2.)Subtraction\n3.)Multiplication\n4.)Division\n5.)Quit" << endl;
			clear();
		}

	
		if(input == 1)
		{
			cout << num << "+" << numz << "=" << addition(num,numz) << endl;
		}
		else if(input == 2)	
		{	
			cout << num << "-" << numz << "=" << subtraction(num,numz) << endl;;
		}
		else if(input == 3)
		{		
			cout << num << "x" << numz << "=" <<  multiply(num,numz) << endl;
		}
		else if(input == 4)
		{
			cout << num << "/" << numz << "=" <<  division(num,numz) <<endl;
		}	
		else if(input == 5)
		{
			break;
		}
		else
		{
			errormsg();
			cout << "1.)Addition\n2.)Subtraction\n3.)Multiplication\n4.)Division\n5.)Quit" << endl;
		}	


	}
	
}
