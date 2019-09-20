#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "blacksmith.h"
#include "functions.h"

int main(int argc, const char* argv[])
{
  char **items = (char**) calloc(NUM_ITEMS, sizeof(char*));
  unsigned char *saveState;
  const char *filename = "shining.sta";
  const char *outputFilename = "shining_out.sta";
  for (int i = 0; i < NUM_ITEMS; i++)
  {
    items[i] = (char*) calloc(MAX_ITEM_NAME_LENGTH, sizeof(char));
  }

  FILE *fp;
  fp = fopen(filename, "rb");
  if (fp == NULL) {
    fprintf(stderr, "Error loading save state: %s.\nExiting.\n", filename);
    exit(EXIT_FAILURE);
  }

  fseek(fp, 0, SEEK_END);
  unsigned long fileLength=ftell(fp);
  fseek(fp, 0, SEEK_SET);

  printf("Generating buffer of size %lu\n", fileLength);
  saveState=(unsigned char *)malloc(fileLength+1);
  if (!saveState) {
    fprintf(stderr, "Memory error!\n");
    fclose(fp);
    exit(EXIT_FAILURE);
  }
  fclose(fp);
  
  readItemList(items);

  for (int i = 0; i < NUM_ITEMS; i++) {
    printf("%d\t%s\n", i, items[i]);
  }
  
  readSaveState(saveState, fileLength, filename);
  for (int character = 0; character < NUMBER_OF_CHARACTERS; character++) {
    int editItem=0;
    displayCharacterItems(saveState, items, fileLength, character);
    const char *request = "Edit character's items? Select item 1-4, n for the next character,\nor q to quit without saving.\n";
    editItem = getIntFromUser(request, 4);
    if (editItem == -1) {
      continue;
    } else if (editItem == -2) {
      freeBuffers(items, saveState);
      return 0;
    }
    if (editItem > 0 && editItem < 5) {
      editItem--;
      const char *request = "Transform into which item? ";
      int itemTransform = getIntFromUser(request, NUM_ITEMS);
      printf("%d\n", itemTransform);
      if (itemTransform >= 0 && itemTransform < NUM_ITEMS) {
	unsigned long offset = OFFSET+character*CHARACTER_DATA_SIZE+ITEM_OFFSET+editItem*2;
	unsigned long secondOffset = SECOND_OFFSET+character*CHARACTER_DATA_SIZE+ITEM_OFFSET+editItem*2;
	if (offset >= fileLength || secondOffset >= fileLength) {
	  fprintf(stderr, "Something went wrong: %lu %lu %lu\n", offset, secondOffset, fileLength);
	  continue;
	}
	printf("Transformed %s into ", items[saveState[offset]]);
	transformItem(saveState, itemTransform, offset);
	transformItem(saveState, itemTransform, secondOffset);
	printf("%s.\n", items[saveState[offset]]);
      } else if (itemTransform == -1) {
	continue;
      } else if (itemTransform == -2) {
	freeBuffers(items, saveState);
	return 0;
      }
    }
  }
  printf("Saving output to %s.\n", outputFilename);
  fp = fopen(outputFilename, "wb");
  if (fp == NULL) {
    fprintf(stderr, "Error opening output file.\n");
  } else {
    fwrite(saveState, fileLength, 1, fp);
    fclose(fp);
  }
  freeBuffers(items, saveState);
  return 0;
}
