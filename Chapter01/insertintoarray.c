// Inserting an element in an array
// 
// Filename:  insertintoarray.c
// Chapter:   1
// Page:      11
// Created:   2022-03-16
// Uppdated:  2022-03-19
// Edited by: Niklas Engvall

// Orginal code example by Bintu Harwani, from the book Practical C Programming, 1st ed, feb 2020.
// 
// Description:
// This simple example shows how to insert a value in an array. The max size of the array is 100 elements and you will 
// be able to tell how many elements and also input them. When done, the application will print them on your console 
// and you will be asked where in the array you want to put in a new element and rearange already stored elements from 
// that position so no value is owerwritten.


#include <stdio.h>                // Standard C library we need for functions printf and scanf.
#define max_array_size 100        // Allow us to store 100 elements. 

int main(void)
{
	int intArray[max_array_size]; // Declare and initiate an integer array with 100 elements. Can store +/- values
	int n;                        // Stores how many elements the users want to add to the array.
	int k;                        // Stores the index where the user want to input a new element.
	int i;                        // Variable used in loops. 

	// Ask how many elements the user want to input and let the user input them
	printf("Enter how many elements you want to add to the array (between 1 and %d): ", max_array_size); 
	do {
		if(scanf("%d", &n) == EOF) // If error occurs during input before value is recieved, we get EOF.
			return 1; // Exit the function and in thiss case it's main so we exit to the calling operating system.
		if(n < 1 || n > max_array_size) { // Check if user inputs a valid value
			printf("\nERROR: Ony values between 1 and %d are allowed!\n", max_array_size);
			printf("Enter how many elements you want to add to the array (between 1 and %d): ", max_array_size);
		}
	} while (n < 1 || n > max_array_size); // Only allow values between 1 and max_array_size
	
	printf("n = %d\n", n); 
	
	for(i = 0; i <= n - 1; i++ ) {
   		printf("Enter %d element: \n", i + 1); 
		if(scanf("%d", &intArray[i]) == EOF)
			return 2;  
	}
	
	// Print and show all elements that is stored in the array
	printf("\nThe array is:\n"); 
	for(i = 0; i <= n - 1; i++)
		printf("%d\n", intArray[i]);

	// Ask user at which position in the array he/she wants to insert a new element
	// must be a positive value, between 1 and variable n
	printf("\nEnter position where to insert: ");
	do {
		if(scanf("%d", &k) == EOF) // If error occurs during input before value is recieved, we get EOF.
			return 3; // Exit the function and in thiss case it's main so we exit to the calling operating system.
		if(k < 1 || k > max_array_size) { // Check if user inputs a valid value
			printf("\nERROR: Ony values between 1 and %d are allowed!\n", max_array_size);
			printf("\nEnter position where to insert: ");
		}
	} while (k < 1 || k > max_array_size); // Only allow values between 1 and max_array_size
	k--; // Subtract the element position by 1, arrays stores its first value att index 0.

	// Move all elements from last to the index where we want to insert a new element.	
	for(i = n - 1; i >= k; --i)
		intArray[i + 1] = intArray[i]; // move element with index n to index n + 1.

	// Ask user for a new value to insert at choosen index position.
	printf("\nEnter the value to insert: "); 
	if(scanf("%d", &intArray[k]) == EOF)
		return 4;  

	// Print and show all elements that is stored in the array after insertion by a new value.
	printf("\nArray after insertion of element: \n");
	for(i = 0; i <= n; i++)
		printf("%d\n", intArray[i]);

	return 0;
}
