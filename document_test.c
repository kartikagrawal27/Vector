/**
 * Machine Problem 1
 * CS 241 - Spring 2016
 */

#include "document.h"
 #include <stdio.h>

// test your document here
void print_vector(Vector * vector) {
        size_t size = Vector_size(vector);
        size_t capacity = vector->capacity;
        printf("vector size: %zu, vector capacity: %zu\n", size, capacity);
        printf("|");
        for (size_t i = 0; i < size; i++) {
                printf("%s|", Vector_get(vector, i));
        }
        for (size_t i = size; i < capacity; i++) {
                printf("__|");
        }
        printf("\n-----------------------------------------\n\n\n");
}

int main() 
{
	char * filename = "input.txt";
	Document *mydoc = Document_create_from_file(filename);
	print_vector(mydoc->vector);
	Document_write_to_file(mydoc, "output.txt");
	Document_destroy(mydoc);
	return 0; 
}