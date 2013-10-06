#include <stdlib.h>
#include "string.h"
#include "common.h"

#define min(a, b)\
  ({ __typeof__ (a) _a = (a);\
     __typeof__ (b) _b = (b);\
     _a < _b ? _a : _b; })

#define max(a, b)\
  ({ __typeof__ (a) _a = (a);\
     __typeof__ (b) _b = (b);\
     _a > _b ? _a : _b; })

int byte_cmp(unsigned char * a, unsigned char * b) {
  int alen = byte_array_len(a);
  int blen = byte_array_len(b);

  if(alen > blen) {
    return 1;
  } else if (blen > alen) {
    return -1;
  }

  int i;
  for(i = 0; i < alen; i++) {
    if(a[i] > b[i]) {
      return 1;
    } else if (a[i] < b[i]) {
      return -1;
    }
  }

  return 0;
}

int byte_array_len(unsigned char * a) {
  int count = 0;

  if(a != NULL) {
    while(a[count] != '\0') {
      count++;
    }
  }

  return count;
}
