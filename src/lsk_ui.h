#ifndef LSK_UI_H
#define LSK_UI_H
#include <raylib.h>

typedef struct {
  char* text;
  int fontsize;
  Vector2 position;
  Rectangle box;
  bool disabled;
} LSKButton;

void init_button(LSKButton* but, const char* text, int x, int y, int fontsize);
void draw_button(LSKButton* but);
bool button_pressed(LSKButton* but);
void free_button(LSKButton* but);

typedef struct {
  char* text;
  int fontsize;
  Vector2 position;
  Rectangle box;
  bool disabled;
} LSKLabel;

void init_label(LSKLabel* lab, const char* text, int x, int y, int fontsize);
void draw_label(LSKLabel* lab);
void free_label(LSKLabel* lab);

#endif
