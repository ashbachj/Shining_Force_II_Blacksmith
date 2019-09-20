#include <stdio.h>
#include <stdlib.h>

void transformItem(unsigned char *saveState, int itemTransform, unsigned long offset)
{
  saveState[offset] = (unsigned char) itemTransform;
}
