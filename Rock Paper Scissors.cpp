

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <string>
using namespace std;

//function prototyping
string computerchoice();
string get_user_response();
void compare_choices(int, int);

//MAIN FUNCTION
int main()
{
	int compchoice, userchoice;
	string displaycompchoice;
	displaycompchoice = computerchoice(compchoice); //number generated and computer symbol saved
	get_user_response(userchoice); // user chooses

	cout << displaycompchoice << endl; // display computer choice


	compare_choices(compchoice, userchoice);

	system("PAUSE");
	return 0;

}

//CREATING NEW FUNCTIONS

string computerchoice(int &computernumber) //computer picks its move
{
	int computermove;
	string computersymbol;
	srand((unsigned)time(0));
	computermove = 1 + (rand() % 5);// mod 6 gives remainders 0 to 4; adding 1 makes choices 1 through 5 

	if (computermove == 1)
			computersymbol = "Rock";

	if (computermove == 2)
		computersymbol = "Paper";

	if (computermove == 3)
		computersymbol = "Scissors";

	if (computermove == 4)
		computersymbol = "Lizard";

	if (computermove == 5)
		computersymbol = "Spock";

	computernumber = computermove; //saving computerchoice into variable to pass later
	return computersymbol; //to display later
}

string get_user_response(int &usernumber) // let user pick his/her move
{
	int usermove;
	string usersymbol;
	cout << "Select your move by entering a number 1-5" << endl;
	cout << "1) Rock" << endl;
	cout << "2) Paper" << endl;
	cout << "3) Scissors" << endl;
	cout << "4) Lizard" << endl;
	cout << "5) Spock" << endl;

	cin >> usermove;

	if (usermove == 1)
		usersymbol = "Rock";

	if (usermove == 2)
		usersymbol = "Paper";

	if (usermove == 3)
		usersymbol = "Scissors";

	if (usermove == 4)
		usersymbol = "Lizard";

	if (usermove == 5)
		usersymbol = "Spock";

	usernumber = usermove; //saving userchoice into variable to pass later
	return usersymbol; //to display later
}

void compare_choices(int computernumber, int usernumber) // compare computer and user selections and decide winner
{

	if (computernumber == usernumber) //tie; reselect both computer and user
	{
		computerchoice(computernumber);
		get_user_response(usernumber);

	}

	if (computernumber != usernumber) //checks for computer or user win
	{
		//Paper covers Rock and disproves Spock (2 wins against 1 and 5)
		if (computernumber == 2 && (usernumber == 1 || usernumber == 5)) //first line user loses
			cout << "Sorry, you lost!" << endl;
		else if (usernumber == 2 && (computernumber == 1 || computernumber == 5)) //second line user wins
			cout << "You won!" << endl;

		//Rock crushes Scissors and Lizard (1 wins against 3 and 4)
		else if (computernumber == 1 && (usernumber == 3 || usernumber == 4))
			cout << "Sorry, you lost!" << endl;
		else if (usernumber == 1 && (computernumber == 3 || computernumber == 4)) //second line user wins
			cout << "You won!" << endl;

		//Lizard eats Paper and poisons Spock (4 wins against 2 and 5)
		else if (computernumber == 4 && (usernumber == 2 || usernumber == 5))
			cout << "Sorry, you lost!" << endl;
		else if (usernumber == 4 && (computernumber == 2 || computernumber == 5))
			cout << "You won!" << endl;

		//Spock vaporizes Rock and smashes Scissors (5 wins against 1 and 3)
		else if (computernumber == 5 && (usernumber == 1 || usernumber == 3))
			cout << "Sorry, you lost!" << endl;
		else if (usernumber == 5 && (computernumber == 1 || computernumber == 3))
			cout << "You won!" << endl;

		//Scissors cuts Paper and decapitates Lizard (3 wins against 2 and 4)
		else if (computernumber == 3 && (usernumber == 2 || usernumber == 4))
			cout << "Sorry, you lost!" << endl;
		else if (usernumber == 3 && (computernumber == 2 || computernumber == 4))
			cout << "You won!" << endl;

		else // default; nobody wins or ties; replay
		{
			computerchoice(computernumber);
			get_user_response(usernumber);

		}

	}

}
