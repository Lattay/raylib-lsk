#ifndef LSK_ERROR_H
#define LSK_ERROR_H
#include <raylib.h>

/*
 * Error routine
 */
void error(const char* msg);

/*
 * Square of the cartesian distance between two points
 */
float vdist2(Vector2 v1, Vector2 v2);

/*
 * Cartesian distance between two points
 */
float vdist(Vector2 v1, Vector2 v2);
#endif
