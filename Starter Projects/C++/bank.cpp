#include <iostream>
#include <string>
#include <chrono>
#include <thread>
#include <vector>
#include <algorithm>
#include <sstream>
#include <cstdlib>
using namespace std;


/* This function is simply to display 3 consecutive dots
   in order, to mimic a processing animation
*/
void  processing()
{
	for(int i = 0; i < 3;++i)
	{
		this_thread::sleep_for(chrono::milliseconds(500));					// gives a breif pause for numbers to appear 
		cout << ".";
		cout.flush();
	}		
}

/* This function is to manually check whether the user types
   a numeric string which is the intended input
*/
bool isdigit(string s)
{
	if(s.empty())
	{
		return false;
	}
	for(char c : s)
	{
		if(!isdigit(c))
		{
			return false;						 //  if its not a digit
			cout << "N" << endl;
		}
	}
	return true;
	cout << "Y" << endl;
}


/* This function is to handle the cin operator and clear
   the operator to remove leftover junk that will cause
   infinite loops and undefined behavior of our program
*/
void clear()
{
	cin.clear();
	cin.ignore(1000,'\n');
}


/* This function is meant to mimic the withdrawal process of an 
   atm. It mainly handles user input, and loops, but has features
   like account numbers, withdrawal ammounts, and even the type of
   bills the user request
*/
void withdrawal()
{
	string user_account;
	vector <string> account = {"0075", "8180", "2234"};

	while(true)
	{

		cout << "Select which account you wish to withdraw from: 0075,8180,2234" << endl;
		cout << "Account: ";
		getline(cin,user_account);

		while(find(account.begin(),account.end(),user_account) == account.end())  			// basic loop that starts at the beginning and end and searches for whatever is in user_account
		{
			cout << "Could not read that try again\n";
			cout << "Select which account you wish to withdraw from: 0075,8180,2234" << endl;
			cout << "Account: ";
			getline(cin,user_account);
		}
		
		string bills;
		int num;
		cout << "How much would you like to withdraw today ?" << endl;
		cout << "$5,$10,$20,$50,$100,Press 8 for Other" << endl;
		cout << "$";
		cin >> num;	
		clear();

		while(true)
		{
			if(num != 5 && num != 10 && num != 20 && num != 50 && num != 100 && num != 8)
			{
				cout << "Sorry could not read the ammount try again\n";
				cout << "How much would you like to withdraw today ?" << endl;
				cout << "$5,$10,$20,$50,$100,Other" << endl;
				cout << "$";
				cin >> num;
				clear();
			}
			if(num == 8)
			{
				
				cout << "Enter the ammount $";
				getline(cin,bills);

				if(isdigit(bills))
				{
					break;
				}
				else 
				{
					cout << "Sorry could not read the ammount try again\n";
					continue;					
				}	
			}
			else
			{
				cout << "How would you like your bills ?" << endl;
												
				if(num == 5)
				{	
					cout << "$1,$5" << endl;
					cout <<"$";
					cin >> num;
					clear();
					break;
				}
				else if(num == 10)
				{
					cout << "$1,$5,$10" << endl;
					cout <<"$";
					cin >> num;
					clear();
					break;
				}
				else if(num == 20)
				{
					cout << "$1,$5,$10,$20" << endl;
					cout <<"$";
					cin >> num;
					clear();
					break;
				}
				else if(num == 50)
				{	
					cout << "$5,$10,$20,$50" << endl;
					cout <<"$";
					cin >> num;
					clear();
					break;
				}
				else if(num == 100)
				{
					cout << "$10,$20,$50,$100" << endl;
					cout <<"$";
					cin >> num;
					clear();
					break;
				}
			}
		}

	cout << "Dispensing Cash" << endl;
	processing();
	cout << "\nError: Insuficient funds" << "\nAccount #" << user_account <<  endl;
	break;	
 }
}		


void Deposit()
{
	string user_account;
	string garbage;
	int deposit_type;
	vector <string> account = {"0075", "8180", "2234"};

	while(true)
	{
		cout << "Select the account you wish to deposit into: 0075,8180,2234" << endl;
		cout << "Account: ";
		getline(cin,user_account);
		
		while(find(account.begin(),account.end(),user_account) == account.end())  			// basic loop that starts at the beginning and end and searches for whatever is in user_account
		{
			cout << "Could not read that try again\n";
			cout << "Select which account you wish to deposit into: 0075,8180,2234" << endl;
			cout << "Account: ";
			getline(cin,user_account);
		}
		break;
	}

	processing();

	while(true)
	{
		char choice;
		cout << "\nAre you depositing Cash or Checks ?";
		cout << "\nSelect 1 for Cash\n" << "Select 2 for Check or Checks" << endl;
		cin >> deposit_type;
		clear();

		if(deposit_type == 1)
		{
			cout << "\nPlease insert your cash in the charging port" << endl;
			getline(cin,garbage);															
			processing();
		}	
		else if(deposit_type == 2)
		{
			cout << "\nPlease insert your check/s in av port" << endl;
			getline(cin,garbage);
			processing();
		}
		else 
		{
			cout << "\nSorry couldnt read that" << endl;
			continue;																	// dont repeat yourself, a continue statement will reroute us to the beginning
		}

		cout << "\nThe ammount of " << rand() << " was deposited into account#" << user_account << endl;
			
		cout << "Do you wish to deposit more ? (y/n)" << endl;
		cin >> choice;
		processing();
		clear();
		
		if(choice == 'n' || 'N')
		{
			break;
		}
	}
}
			
void Balance()
{
	char choice;
	string user_account;
	vector <string> account = {"0075", "8180", "2234"};
	
		while(true)
		{
	
			cout << "\nSelect the accout you wish to check the balance: 0075,8180,2234" << endl;
			cout << "Account: ";
			getline(cin,user_account);
	
			while(find(account.begin(),account.end(),user_account) == account.end())  			// basic loop that starts at the beginning and end and searches for whatever is in user_account
			{
				cout << "Could not read that try again\n";
				cout << "Select which account you wish to withdraw from: 0075,8180,2234" << endl;
				cout << "Account: ";
				getline(cin,user_account);
			}

			if(user_account == "0075")
			{
				cout << "\nYour account number 0075 has a balance of $-12,670" << endl;
			}
			else if(user_account == "8180")
			{
				cout << "\nYour account number 8180 has a balance of $-112,890" << endl;
			}
			else if(user_account == "2234")
			{
				cout << "\nYour account number 2234 has a balance of $-9.70" << endl;
			}

			cout << "\nwould you like to check other accounts (y/n) ?" << endl;
			cin >> choice;
			clear();
			
			if(choice == 'n')
			{
				break;
			}		
		}
}	


void Transfer()	
{
	char choice;
	string to;
	string from;
	string user_input;
	string pin = "1234";
	vector <string> account = {"0075", "8180", "2234"};

	while(true)
	{		
		cout << "\nSelect the accout you wish to transfer to: 0075,8180,2234" << endl;
		cout << "Account: ";
		getline(cin,to);
		
		while(find(account.begin(),account.end(),to) == account.end())  			// basic loop that starts at the beginning and end and searches for whatever is in to and checks if its in the vector
		{
			cout << "Could not read that try again\n";
			cout << "Select which account you wish to transfer to: 0075,8180,2234" << endl;
			cout << "Account: ";
			getline(cin,to);
		}

		cout << "\nSelect which account to transfer from: 0075, 8180,2234" << endl;
		cout << "Account: ";
		getline(cin,from);
				
		while(find(account.begin(),account.end(),from) == account.end() || from == to)  	
		{
			cout << "Cannot transfer from the same account try again\n";
			cout << "Select which account to transfer from: 0075,8180,2234" << endl;
			cout << "Account: ";
			getline(cin,from);
		}

		int ammount;
		cout << "Enter the ammount you wish to transfer: $";
		cin >> ammount;
		clear();
		if(ammount )

		processing();

		cout << "\nYou are transfering " << "$" << ammount << " from account#" << from << " to account#" << to << endl;
		cout << "Please enter your pin to confirm" << endl;
		getline(cin,user_input);

		processing();
		cout << "\nYour Transfer has been succesfully processed" << endl;

		cout << "Would you like a receipt (y/n) ?" << endl;
		cin >> choice;
		clear();
		processing();

		if(choice == 'y')
		{
			cout << "\nIm sorry, we are out of paper" << endl;
		}
		
		cout << "would you like to make another transfer (y/n) ?" << endl;	
		cin >> choice;
		clear();

		if(choice == 'n')
		{
			break;
		}	
	}
	
}

int main()
{
	string user_input;
	string pin = "1234";

	cout << "Hello Welcome to my ATM" << endl;
	cout << "Please insert your atm card: ";
	getline(cin,user_input);

	this_thread::sleep_for(chrono::milliseconds(1000));
	cout << "Processing" << endl;
	this_thread::sleep_for(chrono::milliseconds(500));
	cout.flush();
	
	processing();

	cout <<  "\nEnter your pin: ";

	
	while(getline(cin,user_input))
	{
		if(user_input == pin)
		{
			break;
			clear();
		}
		else
		{
			cout << "Sorry that Pin was incorrect try again." << endl;
			cout <<  "Enter Pin: ";
		}
	}

	processing();

	while(true)
	{
		
		int dash_input;
		cout << "\nWelcome to my ATM\n";
		cout << "\n1.) Withdraw" << endl;
		cout << "2.) Deposit" << endl;
		cout << "3.) Check account balance" << endl;
		cout << "4.) Make a Transfer" << endl;
		cout << "5.) Exit" << endl;
		cin >> dash_input;
		clear();


		if(dash_input != 1 && dash_input != 2 && dash_input != 3 && dash_input != 4 && dash_input != 5)
		{
			cout << "I couldnt read that try again" << endl;
			continue;
		}
		else 
		{
			if(dash_input == 1)
			{
				processing(); 
				cout << endl;
				withdrawal();
			}
			if(dash_input == 2)
			{
				processing(); 
				cout << endl;
				Deposit();
			}
			if(dash_input == 3)
			{
				processing();
				cout << endl;
				Balance();
			}
			if(dash_input == 4)
			{
				processing();
				cout << endl;
				Transfer();
			}
			if(dash_input == 5)
			{
				cout << "Have a nice day" << endl;
				break;
			}
		}
		
		
	}
	
	

		
	
	

	
	

}

