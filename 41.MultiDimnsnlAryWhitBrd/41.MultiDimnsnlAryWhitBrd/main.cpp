#include<iostream>
using namespace std;



int main() {

	//"questions" is the full array (on dimensional) "[]" is undefined but represents strings in the array.
	//CODE:
	string questions[] = { "Where was Adam born?",
							"What was Adams last name?",
							"Where does Adam live?",
							"What is earth?" };

	//"options" is the full array  -> options[] is a sub array -> options[][4] the 4 means
	//how many strings are in the sub array. This is a multidimensional array. Array of arrays.
	//CODE:
	string options[][4] = { {"A","B","C","D"},
								{"A","B","C","D"},
								{"A","B","C","D"},
								{"A","B","C","D"} };

	//This is an array that holds the answers. Correlates to "i" iteration.
	//CODE:
	char answerKey[] = { 'B','C','A','D' };

	//Here we take a full array options and divide it by one element/string of that array.
	//CODE:

	int size = sizeof(questions) / sizeof(questions[0]);

	//Initialized later through a cin >>
	char guess; 

	int score = 0; //Initialized for starting point of score++ increment step


	for (int i = 0; i < size; i++) {

		//0,1,2,3. Outer loop shows 1 question at a time and then goes to nested loop which will 
		//iterate and go through all options prior to going to if/else condition.This outer for
		//after end of whole program.
		cout << questions[i] << endl;

		//Since we are addressing 1 questions at a time we visit each set of options 0-3.
		//So its the size of one sub array / one element of that sub array. options[0] is sub array
		//options[0][0] means one element of that sub array. first [0] is which sub array and 
		//the second [0] is index location within tha sub array.
		for (int j = 0; j < sizeof(options[0])/sizeof(options[0][0]); j++) {

			//We use i first since the question will correspond with which ever set of options/sub array
			//current iteration is on. Then j for exact location within that sub array.
			cout << options[i][j] << endl;
	//i=0 j=0 -> [0][0]
	//i=3 j=1 -> [3][1]
	//i=3 j=3 -> [3][3]
	//ect...
		}

		cin >> guess;
		guess = toupper(guess);

		//Here we check guess is equal to the current i iteration which also scrolls through the answer key
		//in same way options corresponds with the questions array.
		if (guess == answerKey[i]) {

			cout << "Correct" << endl;

			//This increments user gets question right and tracks/tallies one point each correct answer.
			//We will use divided by all the questions (divisor) to get % correct later in code.
			score++;
		}

		else {

			cout << "Wrong" << endl;
			
			//Use current iteration i and answerKey to display correct answer to user.
			cout << "Answer is: " << answerKey[i] << endl;

			//**We do not increment score++ here and so the lack of the point will be used in expression
			//and result in lower number being divided and % right.
		}
		cout << "Correct guesses: " << score << endl;

		cout << "# of questions: " << size << endl;

		cout << "Score: " << (score / (double)size) * 100 << "%" << endl;

		//ex. 3    /    4 =    .75    *   100   = 75%
	}
}