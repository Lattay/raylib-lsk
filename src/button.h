#ifndef STK_BUTTON_H
#define STK_BUTTON_H
#include <raylib.h>

typedef struct {
  char* text;
  int fontsize;
  Vector2 position;
  Rectangle box;
  bool disabled;
} Button;

void init_button(Button* but, const char* text, int x, int y, int fontsize);
void draw_button(Button* but);
bool button_pressed(Button* but);
void free_button(Button* but);

#endif
