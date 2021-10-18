#include <bits/stdc++.h>

using namespace std;

int level, moves;
long long int password;
long long int range;
long long int guess = -1;

void intro (){
	system("CLS");
	cout << "\tWelcome to - Guess the Password Game" << endl ;
	cout << "\t\t\t - By Satish  (UwU)"<< endl << endl;
}

void rules(){
	cout << "\tRules of the game : " << endl << endl;
	cout << "\t - You can only enter/input one integer at a time." << endl;
	cout << "\t - I would suggest you to sit with a calculator or a pen and paper :)" << endl;
	cout << "\t - After entering the number you will be told if the entered number was greater or less than the Password." << endl;
	cout << "\t - The message will be displayed for 5 seconds "<< endl;
	cout << "\t - If you run out of moves and didn't guess the Password then you loose else you win."<< endl ;
	cout << "\t - It is gaurenteed that the Password will be in range 0 to "<< range << endl << endl;
	
	cout << "Remaining moves are : " << moves << endl;
	if(guess != -1)
		cout << "Last entered number was : " << guess << endl << endl;
}
void sec(int wait){
	long long int st = time(0);
	st += wait;
	while(time(0) < st){ }
}

int main(){
	srand(time(0));
	password = rand();
	
	
	intro();
	cout << "\tSelect difficulty level - 1 , 2 , or 3  :  " ;
	cin >> level;
	
	if(level == 1) moves = 50, range = 100;
	if(level == 2) moves = 30 , range = 100000;
	if(level == 3) moves = 35 , range = 1000000000;
	
	if(level == 3) {
		password = (password * 79) % range ; // makes the password equally random 
	}
	
	if(level < 1 or level > 3){
		cout << "\n\tIdiot what level is that ?? " << endl;
		sec(5);
		main();
	}
	
	password = abs(password);
	password %= range;
	
	rules();	
	do{
		intro();
		rules();
				
		cout << "Enter the number :  ";
		
		cin >> guess;
		
		cout << endl;
		if(guess == password){
			cout << "\t You win :)" ;
			sec(8);
			exit(0);
		} 
		else if(guess < password){
			cout << "\tLess than password ..." << endl;
		}
		else{
			cout << "\tGreater than password ..." << endl;
		}
		
		sec(5);
	}
	while(moves--);
	
	cout << "\t   You are out of moves , You loose :(" << endl;
	sec(8);	
}
