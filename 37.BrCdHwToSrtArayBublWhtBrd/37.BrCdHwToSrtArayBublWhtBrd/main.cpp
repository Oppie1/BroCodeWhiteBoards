#include <iostream>
using namespace std;



//Declare a void function prototype named sort with int array[] and int size parameters.
//CODE:
void sort(int array[], int size);


int main() {

	//Construct an array with unsorted numbers.
	//CODE:
	int array[] = { 7, 3, 5, 1 };

	//Declare an int var named size that will take the sizeof() the array and divide it 
	//by one element of the array.
	//CODE:
	int size = sizeof(array) / sizeof(array[0]);
	
	cout << "Unsorted Numbers: " << endl;

	//Use range-based/for-each loop to print out unsorted numbers
	//CODE:
	for (int element : array) {

		cout << element << endl;
	}

	//Use sort function with arg array and size to sort the numbers.
	//CODE:
	sort(array, size);
	
	cout << "\nSorted Numbers: " << endl;

	for (int element : array) {

		cout << element << endl;
	}

}

void sort(int array[], int size) {

	//Declare a local int var to the function named temp which will hold the number to be swapped.
	//CODE:
	int temp;

	//Use a for loop with i = 0 with i less than the size of the array - 1 since we do not want to 
	//compare already sorted vars such as i = 0, on the second iteration where i = 1. For instance
	//i = 0 is 7 and by the time i = 0 -> and then j = (0 - 3) executes fully we dont need to sort
	//7 again. It went from index location 0 to index location 3 by the time j has fully executed.
	//And so when i = 1 we are just talking about the next iteration not an index location. Because
	//in reality when i = 1 -> j just = 0 again which is the first index location where 3 is the 
	//current value -> (3,5,1,7).

	//i = 0 ->  (7, 3, 5, 1)
	//1st iteration: i = 0 -> 0 < 4 - 1 -> 0 < 3 -> true execute nested loop (j -> 0 - 3)
	
	//i = 1 ->  (3, 5, 1, 7)
	//2nd iteration: i = 1 -> 1 < 4 - 1 -> 1 < 3? -> true execute nested loop (j -> 0 - 2)  
	//***Because i now equals 1 we will only end up comparing j = 0,1,2. This i value is used
	//in the j for loop so it doesnt iterate past index 2 (3rd element) because last value in
	//array has already been sorted fully. What happend is the size of the array being evaluated
	//is 4-1-1 and so 2. This means it is no longer valueated to index 3 (0-3) it is now 0-2)

	//i = 2 -> (3,1,5,7)
	//3rd iteration: i = 2 -> 3 < 4 - 1 -> 2 < 3? -> true execute nested loop (j=0-1)
	//***Because i = 2 we will only be comparing for j = 0, 1. This i value is used in the j
	//for loop so it doesnt iterate past index 1. Because the values after have already been sorted.

	//i = 3 -> 3<3? False stop outer loop as function ends.

	for (int i = 0; i < size - 1; i++) {


	//i = 0 -> j = 0 -> (7, 3, 5, 1)
	//1st iteration: j = 0 i = 0 -> 0 < 4 - 0 - 1 (3) -> true execute if statement
	//2nd iteration: j = 1 i = 0 -> 1 < 4 - 0 - 1 (3) -> true execute if statement
	//3rd iteration: j = 2 i = 0 -> 2 < 4 - 0 - 1 (3) -> true execute if statement


	//i = 1 -> j = 0 -> (3, 5, 1 7)
	//1st iteration: j = 0 i = 1 -> 0 < 4 - 1 - 1 (2) -> true execute if statement. (3,5,1,7)
	//2nd iteration: j = 1 i = 1 -> 1 < 4 - 1 - 1 (2) -> true execute if statement  {3,1,5,7}
	//3rd iteration: j = 2 i = 2 < 2? False, stop sorting and go back to i/outer loop. 
	//***So by default that i is = 1 we only sort those first 3 numbers. The last iteration is not
	//even attempted.

	//i = 2 -> j = 0 (3,1,5,7)
	//1st iteration: j = 0 -> 0 < 4 - 2 - 1 (1) 0 < 1 -> true, execute if statement. (3,1,5,7)
	//2nd iteration: j = 1 -> 1 < 4 - 2 - 1 (1)  1 < 1 -> false stop looping return to i loop. (1,3,5,7)
		for (int j = 0; j < size - i - 1; j++) {


	//i = 0 j=0 -> (7, 3, 5, 1)
	//array[0]>array[0+1(1)] -> 7>3? -> True, execute if statement.
	//j = 1 -> (3,7,5,1)
	//array[1]>array[1+1(2)] -> 7>5? True, execute if statement.
	//j = 2 (3,5,7,1) 7>1 True
	//j = 3 -> stops after incrementing for loop.

	//i=1 j=0 ->(3,5,1,7)
	//j=0-> 3>5 False go to j = 1
	//j=1->5>1 true 

	//i=2 (3,1,5,7)
	//j=0 3>1 true
	
			if (array[j] > array[j + 1]) {

	//Assign temp var to array[j] (0 index, value 7)
	//Assign temp var to array[j] (1 index, value 7)
	//Assign temp var to 7 at index 2.
	//No index three as it stops at 4 loop.

	//Assign temp to 5

	//Assign temp to 3
			
				temp = array[j];

	//Assign array[j] (index 0) to the value at array[j+1] -> (index 1, value 3) Now 3 is at index 0.
	//Assign array[j] (index 1) to the value at array[j+1] -> (index 2, value 5) Now 5 is at index 1.[j]
	//Assign array[j] (index 2 to the value at array[j+1} -> index 3, value 1) Now 1 is at index 2.
	
	//Assign array[j] = 1

	//assign array[j] = 1

				array[j] = array[j + 1];
	//Assign array[j+1] (index 1) to the value in temp which is 7. -> array is now: 3,7,5,1
	//Assign array[j+1] (index 2) to the value in temp which is 7. -> array is now: 3,5,7,1
	//Assign array[j+1] index 3 to the value of temp which is 7 -> so now array is 3,5,7,1

	//Assign array[j+1] = 5 -> 3,1,5,7
	//Then back to iteration j loop

	//Assign array[j+1] 0+1 so 1 to to temp which is index 3 and then go to j loop
				array[j + 1] = temp;


			}

		}
	}
}