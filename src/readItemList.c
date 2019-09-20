#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void readItemList(char **buffer)
{
  const char *itemFilename = "items.txt";
  FILE *fp;
  char *line = NULL;
  size_t len = 0;
  ssize_t read;
  printf("reading file %s.\n", itemFilename);
  fp = fopen(itemFilename, "r");
  if (fp == NULL) {
    exit(EXIT_FAILURE);
  }
  int i = 0;
  while (getline(&line, &len, fp) != -1) {
    line[strcspn(line, "\n")] = 0;
    strcpy(buffer[i], line);
    i++;
  }
  fclose(fp);
}
