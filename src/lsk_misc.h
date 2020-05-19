#ifndef LSK_ERROR_H
#define LSK_ERROR_H
#include <raylib.h>

/* Error routine */
void error(const char* msg);

/* Square of the cartesian distance between two points */
float vdist2(Vector2 v1, Vector2 v2);

/* Cartesian distance between two points */
float vdist(Vector2 v1, Vector2 v2);

/* Dot product */
inline float vdot(Vector2 v1, Vector2 v2);

/* Angle between two vectors */
float vangle(Vector2 v1, Vector2 v2);

inline Vector2 vadd(Vector2 v1, Vector2 v2);
inline Vector2 vsub(Vector2 v1, Vector2 v2);

/* Return a rotated vector of angle (radians) */
inline Vector2 vrot(Vector2 v, float angle);

/* Return the square of the magnitude of the vector */
inline float vnorm2(Vector2 v);

/* Return the magnitude of the vector */
inline float vnorm(Vector2 v);

/* Return true if the vector is stricly zero */
inline bool vzero(Vector2 v);

/* Return true if the vector is almost zero (magnitude less than tol) */
inline bool vzero_tol(Vector2 v, float tol);

/* Return a vector with the direction of v and a magnitude of 1 */
Vector2 vnormalized(Vector2 v);

#endif
