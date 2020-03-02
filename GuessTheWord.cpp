/******************************************************************************
                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.
*******************************************************************************/

#include <bits/stdc++.h>
#include <iostream>
#include <cstring>
#include <termios.h>
#include <unistd.h>
#include <ctype.h>
#include <typeinfo>

using namespace std;

#define MaxErrors 4
#define NumLetter 27

void HideStdinKeystrokes(){
	termios tty;
	tcgetattr(STDIN_FILENO, &tty);

	/* we want to disable echo */
	tty.c_lflag &= ~ECHO;
	tcsetattr(STDIN_FILENO, TCSANOW, &tty);
}

void ShowStdinKeystrokes(){
	termios tty;
	tcgetattr(STDIN_FILENO, &tty);

	/* we want to reenable echo */
	tty.c_lflag |= ECHO;
	tcsetattr(STDIN_FILENO, TCSANOW, &tty);
}

bool letterPreviouslyUsed (char userLetter, string letterGuessed){
  if (letterGuessed.find (userLetter) != string::npos){
      return true;
    }
  else{
      return false;
    }
}


int main (int argc, char **argv){
	string wordToGuess;
	string letterGuessed (NumLetter, '-');    //store the letter guessed
	int letterPos, numberOfTries = 0;
	int length;
	char userLetter;
	bool wordGuessed = false, letterUsed = false;
	cout << "Enter the word to be guessed >> ";

	HideStdinKeystrokes();  //hide the user input
	getline (cin, wordToGuess);
	ShowStdinKeystrokes(); //unhide the user input

  	length = wordToGuess.length ();

  	string wordProgress (length, '*');

  	while (!wordGuessed){
		cout << "\nPlease enter a letter >> ";
    	cout << wordProgress<<endl;
    	cin >> userLetter;
    	//cout << numberOfTries << " " << MaxErrors << endl;
    	letterUsed = letterPreviouslyUsed (userLetter, letterGuessed);
    	if (letterUsed){
			cout << "The letter was guessed already";
    	}
    	else{
    		for (int i = 0; i<letterGuessed.length();i++){
				if (letterGuessed[i] == '-'){
	            	letterGuessed[i] = userLetter;
                	break;
            	}
 			}
        	numberOfTries += 1;
        	if(numberOfTries == MaxErrors) wordGuessed = false;
   		}
   		for (int i = 0; i < wordProgress.length(); i++){
	   		if (userLetter == wordToGuess[i]){
	       		wordProgress[i] = userLetter;
           //break;
       		}
   		}
   		if (wordProgress.compare(wordToGuess)==0){
	   		wordGuessed = true;
	   		cout<<"Congrats!! You guessed the word";
   		}

	}
  	cout << wordToGuess << endl << wordProgress << endl;
  	cout << letterGuessed << endl;
  	return 0;
}
