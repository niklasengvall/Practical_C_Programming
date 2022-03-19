// Deleting an element from an array
//
// Filename:  deöetefromarray.c
// Chapter:   1
// Page:      15
// Created:   2022-03-16
// Uppdated:  2022-03-19
// Edited by: Niklas Engvall

// Orginal code example by Bintu Harwani, from the book Practical C Programming, 1st ed, feb 2020.
// 
// Description:
// This simple example shows how to remove a value in an array. The max size of the array is 100 elements and you will 
// be able to tell how many elements and also input them. When done, the application will print them on your console 
// and you will be asked where in the array you want to remove a new element and rearange already stored elements from 
// that position.

#include <stdio.h> 
int main()
{
	const int max_array_size = 100; // Modern way to define constants instead of using #defines
	int intArray[max_array_size];	// Array that stores up to 100 elements 
	int i;                          // A variable used only for itterations
	int n;                          // Stores how many elements the users want to add to the array.
	int a;                          // Stores the index where the user want to delete a element.
	

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
	
	// Let the user input all elements
	for(i = 0; i <= n - 1; i++ ) {
   		printf("Enter %d element: \n", i + 1); 
		if(scanf("%d", &intArray[i]) == EOF)
			return 2;  
	}

	// Print and show all elements that is stored in the array
	printf("\nThe array is:\n"); 
	for(i = 0; i <= n - 1; i++)
		printf("%d\n", intArray[i]);
	
	// Ask user at which position in the array he/she wants to delete an element
	// must be a positive value, between 1 and variable n
	printf("\nEnter position of element to delete: ");
	do {
		if(scanf("%d", &a) == EOF) // If error occurs during input before value is recieved, we get EOF.
			return 3; // Exit the function and in thiss case it's main so we exit to the calling operating system.
		if(a < 1 || a > max_array_size) { // Check if user inputs a valid value
			printf("\nERROR: Ony values between 1 and %d are allowed!\n", max_array_size);
			printf("\nEnter position of element to insert: ");
		}
	} while (a < 1 || a > max_array_size); // Only allow values between 1 and max_array_size
	a--; // Subtract the element position by 1, arrays stores its first value att index 0.
	
	// Move all elements from deleted element position to last element -1.	
	for(i = a; i <= n - 2; i++)
	{
		intArray[i] = intArray[i + 1]; // Copy element i + 1 to element i aka shifting them 1 position up.
	}
	
	// The last position i the element list is set to 0.
	intArray[n - 1] = 0;
	
	// Print and show all elements that's now stored in the array after deleting an element.
	printf("Array after deleting the element is\n"); 
	for( i = 0; i <= n - 2; i++)
		printf("%d\n", intArray[i]);
	
	return 0;
}