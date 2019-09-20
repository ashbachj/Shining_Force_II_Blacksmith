#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "blacksmith.h"

void displayCharacterItems(unsigned char *saveState, char **items, unsigned long  fileLength, int character)
{
  char characterName[10];
  int heldItems[4];
  int offset = OFFSET+character*CHARACTER_DATA_SIZE;
  memcpy(characterName, saveState+offset, 9);
  characterName[9] = '\0';
  printf("Character Name: %s\n", characterName);
  for (int i = 0; i < 4; i++) {
    heldItems[i] = saveState[offset+ITEM_OFFSET+2*i];
    // Items are equiped by adding 128
    char* itemName = heldItems[i] < 128 ? items[heldItems[i]] : items[heldItems[i]-128];
    printf("%d\t%s\n", i+1, itemName);
  }
}
