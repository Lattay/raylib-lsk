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

inline float vdot(Vector2 v1, Vector2 v2){
  return v1.x * v2.x + v1.y * v2.y;
}

float vangle(Vector2 v1, Vector2 v2){
  float dot = vdot(v1, v2);
  float det = v1.x * v2.y - v1.y * v2.x;
  return atan2f(det, dot);
}

inline Vector2 vadd(Vector2 v1, Vector2 v2){
  return (Vector2){v1.x + v2.x, v1.y + v2.y};
}

inline Vector2 vsub(Vector2 v1, Vector2 v2){
  return (Vector2){v1.x - v2.x, v1.y - v2.y};
}

inline Vector2 vrot(Vector2 v, float angle){
  return (Vector2){cosf(angle) * v.x - sinf(angle) * v.y, sinf(angle) * v.x + cosf(angle) * v.y};
}

inline float vnorm2(Vector2 v){
  return v.x * v.x + v.y * v.y;
}

inline float vnorm(Vector2 v){
  return sqrt(vnorm2(v));
}

inline bool vzero(Vector2 v){
  return v.x == 0.0 && v.y == 0.0;
}

Vector2 vnormalized(Vector2 v){
  if(!vzero(v)){
    float n = vnorm(v);
    return (Vector2){v.x / n, v.y / n};
  } else {
    return (Vector2){1, 0};
  }
}

inline bool vzero_tol(Vector2 v, float tol){
  return vnorm2(v) < tol * tol;
}
