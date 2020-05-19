#include "math.h"

/*
 * Square of the cartesian distance between two points
 */
float vdist2(Vector2 v1, Vector2 v2){
  return (v2.x - v1.x)*(v2.x - v1.x) + (v2.y - v1.y)*(v2.y - v1.y);
}
