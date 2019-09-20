#include <stdio.h>
#include <stdlib.h>
#include "blacksmith.h"

void freeBuffers(char **items, unsigned char *saveState) {
  for (int i = 0; i < NUM_ITEMS; i++)
  {
    free(items[i]);
  }
  free(items);

  free(saveState);
}

		 
