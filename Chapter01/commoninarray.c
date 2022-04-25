// Finding the common elements in two arrays and store them in a third array
//
// Filename:  commoninarray.c
// Chapter:   1
// Page:      25-26
// Created:   2022-04-25
// Uppdated:  2022-04-25
// Edited by: Niklas Engvall

// Orginal code example by Bintu Harwani, from the book Practical C Programming, 1st ed, feb 2020.
// 
// Description: This example Asks for lenght and values of two arrays, stores the common values if any in a third array and then 
//              compares the arrays and tell the user if there is common values in both arrays and show which values.

#include <stdio.h>

#define max 100		// Max numbers of elements in all arrays

int ifexists(int [], int , int);

int ifexists(int z[], int u, int v) // gets a copy of result_array, copy of k (no of stored common values) and copy of value in array_1[i]
{
	if (u == 0) return 0; // If k aka u == 0 then return 0, we have a common value and nothing is stored in common_array
	
	for (int i = 0; i <= u; i++) 	// Loop through all common_array elements
		if (z[i] == v) return 1; 	// Compare value in common_array with array_1 value, If same value appears return 1, 
									// no need to store same value twice
	
	return 0;						// If we didn't found a duplicate value of array[i] in the common_array, we have a common value which is not
									// stored yet in common_array
}

int main(void)
{
	int array_1[max], array_2[max], common_values[max];
	int a1_no_elements, a2_no_elements;
	int i, j, k = 0;													// Simple loop counters

	// Let the user input number of elements to store in the first array	
	printf("Enter length of first array:"); 
	scanf("%d", &a1_no_elements); 
	
	// Let the user input all the elements in the first array
	printf("Enter %d elements of first array\n", a1_no_elements); 
	for(i = 0; i < a1_no_elements; i++ )
		scanf("%d", &array_1[i]); 
	
	// Let the user input number of elements to store in the second array
	printf("\nEnter length of second array:"); 
	scanf("%d", &a2_no_elements); 
	
	// Let the user input all the elements in the first array
	printf("Enter %d elements of second array\n", a2_no_elements); 
	for(i = 0; i < a2_no_elements; i++ )
		scanf("%d", &array_2[i]); 

	// Scan for common values, start to compare array_1 first value with all of array_2 values, then repeat with next array_1 value and repeat
	// until we have gone though all array_1 elements	
	for (i = 0; i < a1_no_elements; i++) {
		for (j = 0; j < a2_no_elements; j++) {
			// If we find equal values 
			if (array_1[i] == array_2[j]) {
				// Check if the value already is stored in the common_value array
				if(!ifexists(common_values, k, array_1[i])) { //Send an adress copy of common values and copy of k and a copy of value in array_1[i]
					// Store common value 
					common_values[k] = array_1[i];
					// Increase index of common value
					k++;
				}
			}
		}
	}
	
	// If there is common values in array_1 and array_2 print them on the console
	if(k > 0) {
		printf("\nThe common elements in the two arrays are:\n"); 

		for( i = 0; i < k; i++)					// Loop through all common_array values
			printf("%d\n", common_values[i]); 
	}
	
	// If there ar no common values tell the user 
	if(k == 0) printf("There are no common elements in two arrays\n");

	return 0;
}
