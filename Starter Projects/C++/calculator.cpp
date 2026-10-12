#include <iostream>
#include <cmath>
#include <string>
using namespace std;
double add(int a, int b)
{
	return a + b;
}

double subtraction(int a, int b)
{
	return a - b;
}

double multiply(int a, int b)
{
	return a * b;
}

double division(int a, int b)
{
	return a / b;
} 

double squared(int a)
{
	return a * a;
}



void clear()
{
	cin.clear();
	cin.ignore(1000,'\n');
}

bool isvalid(char c)
{
	if(c == '+')
	{
		return true;
	}
	else if(c == '-')
	{
		return true;
	}
	else if(c == 'x')
	{
		return true;
	}
	else if(c == '/')
	{
		return true;
	}
	else 
	{
		return false;
	}
}

int main()
{
	while(true)
	{
		cout << "  (+/-) "  << "  2nd" << endl;
			
		cout << " 7 8 9  /" << endl;
			
		cout <<	" 4 5 6  x" << endl;
			
		cout << " 1 2 3  +" << endl;
			
		cout << " C 0 .  -" << endl;

		string input;
		string operation;
		
		getline(cin,input);

		bool expected_num = true;							// state flag: true for expecting numbers
															//             false for expecting operators

		size_t i = 0;

		while(i < input.size())								// go until the input size
		{
			if(expected_num)
			{
				if(isdigit(input[i]) || input[i] == '.')	//if it is a digit or if num includes a decimal
				{
					bool dot_found = false;					//state flag: true for found dot
														    //            false for not found yet
					while(i < input.size() && (isdigit(input[i]) || input[i] == '.') && !dot_found)	
					{
						if(input[i] == '.')
						{
							dot_found = true;				// when we find 1 singular dot
						}
						++i;								// consume number
					}
				}
				
				expected_num = false;

				while(!isdigit(input[i]))
				{
					cout << "invalid input press C to clear\n";		// if a number is not a valid number
				}	
			}

			else if(expected_num)									// now set to false because we now expect a operator									
			{
				if(isvalid(input[i]))
				{
					++i; 											// consume operator
					expected_num = true;						    // now expecting a number again 		
				}		
				else 
				{
					cout << "err" << endl;
					break;
				}
			}
			
		}
		

		int user_input = stoi(input);						// stoi to change string to num

		while(user_input >= 0 && user_input <= 9)

		{
			
		}

		
		
	}
}
