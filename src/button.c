#include <stdlib.h>
#include "button.h"

void init_button(Button* but, const char* text, int x, int y, int fontsize){
  int l = 0;
  while(text[l++] != 0);
  but->text = malloc(l * sizeof(char));
  for(int i = 0; i < l; i++)
    but->text[i] = text[i];
  int width = MeasureText(text, fontsize);
  but->position.y = y;
  but->position.x = x - width/2;
  but->box.x = x - 5 - width/2;
  but->box.y = y - 5;
  but->box.width = width + 10;
  but->box.height = 10 + fontsize;
  but->fontsize = fontsize;
  but->disabled = false;
}

void draw_button(Button* but){
  if(but->disabled) return;
  DrawRectangleRec(but->box, BLACK);
  DrawText(but->text, but->position.x, but->position.y, but->fontsize, RAYWHITE);
}

bool button_pressed(Button* but){
  if(but->disabled) return false;
  return IsMouseButtonPressed(MOUSE_LEFT_BUTTON) && CheckCollisionPointRec(GetMousePosition(), but->box);
}

void free_button(Button* but){
  free(but->text);
}
