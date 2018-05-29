/**
 * Machine Problem 1
 * CS 241 - Spring 2016
 */

/* An automatically-expanding array of strings. */
#include "vector.h"
#include <assert.h>
#include <string.h>
#include <stdio.h>

#define INITIAL_CAPACITY 10

Vector *Vector_create() {
  // your code here
  Vector *v1 = (Vector*)malloc(sizeof(Vector));
  v1->capacity  = INITIAL_CAPACITY;
  v1->array = malloc(INITIAL_CAPACITY * sizeof(char*));
  v1->size = 0;
  return v1;
}

void Vector_destroy(Vector *vector) {
  assert(vector);

  for (int i = 0; i < (int)vector->size; i++) 
  {
    free(vector->array[i]);
    vector->array[i]=NULL;
  }

  free(vector->array);
  free(vector);
  // your code here
}

size_t Vector_size(Vector *vector) {
  assert(vector);
  // your code here
  return vector->size;
}

void Vector_resize(Vector *vector, size_t new_size) {
  assert(vector);
  size_t mysize;


  if(new_size<vector->size)
  {
    for(int i= new_size ; i< (int)vector->size; i++)
    {
      free(vector->array[i]);
      vector->array[i]=NULL;
    }
    vector->size = new_size;
  }
  else if((new_size>vector->size) && (new_size < vector->capacity))
  {
    for(int i=vector->size; i< (int)new_size;i++)
    {
      vector->array[i]=NULL;
    }
    vector->size = new_size;
  }
  else 
  {
    int old_size=vector->size;
    if(new_size<vector->capacity*2)
    {
        vector->array = realloc(vector->array, vector->capacity * 2 * sizeof(char *));
        mysize = vector->capacity*2;
        vector->size = new_size;
    }
    else
    {
        vector->array =realloc(vector->array, new_size * sizeof(char *));
        mysize = new_size;
        vector->size = new_size;
    }
    vector->capacity = mysize;
    for(int i = old_size ; i< (int)vector->capacity;i++)
    {
        vector->array[i]=NULL;
    }    
  }
}

void Vector_set(Vector *vector, size_t index, const char *str) {
  assert(vector);
  
  if(str==NULL && vector->array[index] == NULL)
  	return;
  else if(str!=NULL && vector->array[index]==NULL)
  {
  	vector->array[index]= strdup(str);
  }
  else if(str!=NULL && vector->array[index]!=NULL)
  {
  	free(vector->array[index]);
  	vector->array[index]=strdup(str);
  }   
  else if(str==NULL && vector->array[index] !=NULL)
  {   
  	free(vector->array[index]);
	vector->array[index] = NULL;
  }
}

const char *Vector_get(Vector *vector, size_t index) {
  assert(vector);
  // your code here

  if((vector->array[index])==NULL)
    return NULL;
  else
  {
    char* temp = vector->array[index];
    return temp;
  } 
    
}

void Vector_insert(Vector *vector, size_t index, const char *str) {
  assert(vector);
  if(index>=vector->size)
  {
    Vector_resize(vector, index+1);
      if(str==NULL)
      {
        vector->array[index] = NULL;
      }
      else
      {
        vector->array[index] = strdup(str);
      }
  }
  else
  {
    Vector_resize(vector, vector->size+1);
    for(int i = vector->size; i > (int)index;i--)
    {
      vector->array[i] = vector->array[i-1];
    }
    if(str==NULL)
      {
        vector->array[index] = NULL;
      }
      else
      {
        vector->array[index] = strdup(str);
      }
  }
  
}

void Vector_delete(Vector *vector, size_t index) {
  assert(vector);
  assert(index<vector->size);

  if(index==vector->size-1)
  {
    free(vector->array[index]);
    vector->array[index]=NULL;
  }
  else
  {
    free(vector->array[index]);
    vector->array[index]=NULL;
    for(int i=index;i< (int)vector->size-1;i++)
    {
      vector->array[i] = vector->array[i+1];
    }
  }
  vector->size--;
/*
  if(index>=vector->size)
      return;
  else if(index==)*/
  // your code here, what asserts might you want?
}

void Vector_append(Vector *vector, const char *str) {
  assert(vector);

  if(vector->size == vector->capacity)
  {
      Vector_resize(vector, (vector->capacity)+1);
      vector->size--;
  }

  if(str==NULL)
      vector->array[vector->size]=NULL;
  else
  {
    vector->array[vector->size] = strdup(str);
  }
  vector->size++;
  // your code here
}
