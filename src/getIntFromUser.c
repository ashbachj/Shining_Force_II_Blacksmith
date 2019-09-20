#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int getIntFromUser(const char *request, const int maxValue) {
  int output = 0;
  printf("%s", request);
  while (1) {
    output = 0;
    char line[256];
    char *pEnd = NULL;
    fgets(line, sizeof line, stdin);
    line[strcspn(line, "\n")] = 0;
    output = strtol(line, &pEnd, 10);
    if (output > 0 && output <= maxValue && pEnd == 0) {
      break;
    } else if (line[0] == 'n' || strlen(line) == 0) {
      return -1;
    } else if (line[0] == 'q') {
      return -2;
    } else {
      printf("Invalid input. ");
    }
  }
  return output;
}
