#ifndef FUNCTIONS_H
#define FUNCTIONS_H

void readItemList(char **buffer);
void readSaveState(unsigned char *buffer, unsigned long fileLength, const char *filename);
void displayCharacterItems(unsigned char *saveState, char **items, unsigned long  fileLength, int character);
void freeBuffers(char **items, unsigned char *saveState);
void transformItem(unsigned char *saveState, int itemTransform, unsigned long offset);

int getIntFromUser(const char *request, const int maxValue);

#endif
