#include <stdlib.h>
#include <stdio.h>

void readSaveState(unsigned char *buffer, unsigned long fileLength, char *filename)
{
  FILE *fp;

  printf("Reading save state from file %s.\n", filename);
  fp = fopen(filename, "rb");
  if (fp == NULL) {
    fprintf(stderr, "Error loading save state: %s.\nExiting.\n", filename);
    exit(EXIT_FAILURE);
  }

  fread(buffer, sizeof *buffer, fileLength, fp);
  fclose(fp);
}
