/**
 * Machine Problem 1
 * CS 241 - Spring 2016
 */

#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

#include "document.h"
#include "vector.h"

Document *Document_create() {
  Document *document = (Document *)malloc(sizeof(Document));
  document->vector = Vector_create();
  assert(document);
  return document;
}

void Document_write_to_file(Document *document, const char *filename) {
  assert(document);
  assert(filename);

  FILE *fp = fopen(filename, "w");

  for(size_t i=0; i< Document_size(document);i++)
  {
    const char *myline = Document_get_line(document, i);
    if(myline==NULL)
      fprintf(fp,"\n");
    else
    {
        fprintf(fp,"%s\n", myline);
    }
  }
  fclose(fp);
}

Document *Document_create_from_file(char *filename) {
  assert(filename);
  
  Document *d1 = Document_create();
  FILE *fp = fopen(filename, "r");

  if(fp==NULL)
      return d1;

  size_t mysize = 0;
  char *myline = NULL;
  size_t i = 0;
  int number=0;

  while((number = getline(&myline, &mysize, fp)) && (number != -1))
  {
    if((number>0) && myline[number-1]=='\n')
    {
      myline[number-1]='\0';
    }
    Document_insert_line(d1, i, myline);
    i++;
  }

  if(myline)
      free(myline);

  fclose(fp);

  return d1;
}

void Document_destroy(Document *document) {
  assert(document);
  Vector_destroy(document->vector);
  free(document);
}

size_t Document_size(Document *document) {
  assert(document);
  return Vector_size(document->vector);
}

void Document_set_line(Document *document, size_t index, const char *str) {
  assert(document);
  Vector_set(document->vector, index, str);
}

const char *Document_get_line(Document *document, size_t index) {
  assert(document);
  return Vector_get(document->vector, index);
}

void Document_insert_line(Document *document, size_t index, const char *str) {
  assert(document);
  Vector_insert(document->vector, index, str);
}

void Document_delete_line(Document *document, size_t index) {
  assert(document);
  Vector_delete(document->vector, index);
}
