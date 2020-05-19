#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "lsk_misc.h"

void error(const char* msg){
  perror(msg);
  exit(1);
}

float vdist2(Vector2 v1, Vector2 v2){
  return (v2.x - v1.x)*(v2.x - v1.x) + (v2.y - v1.y)*(v2.y - v1.y);
}

float vdist(Vector2 v1, Vector2 v2){
  return sqrt(vdist2(v1, v2));
}
