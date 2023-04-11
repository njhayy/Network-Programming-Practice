#ifndef _MESSAGE_OBJECTC_H
#define _MESSAGE_OBJECTC_H

#include <stdint.h>

typedef struct {
  uint32_t type;
  char data[1024];
} messageObject;

#define MSG_PING 1
#define MSG_PONG 2
#define MSG_TYPE1 11
#define MSG_TYPE2 21

#endif
