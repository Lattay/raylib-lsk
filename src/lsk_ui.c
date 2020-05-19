#include <stdlib.h>
#include "lsk_ui.h"

void init_button(LSKButton* but, const char* text, int x, int y, int fontsize){
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

void draw_button(LSKButton* but){
  if(but->disabled) return;
  DrawRectangleRec(but->box, BLACK);
  DrawText(but->text, but->position.x, but->position.y, but->fontsize, RAYWHITE);
}

bool button_pressed(LSKButton* but){
  if(but->disabled) return false;
  return IsMouseLSKButtonPressed(MOUSE_LEFT_BUTTON) && CheckCollisionPointRec(GetMousePosition(), but->box);
}

void free_button(LSKButton* but){
  free(but->text);
}

void init_label(LSKLabel* lab, const char* text, int x, int y, int fontsize){
  int l = 0;
  while(text[l++] != 0);
  lab->text = malloc(l * sizeof(char));
  for(int i = 0; i < l; i++)
    lab->text[i] = text[i];
  int width = MeasureText(text, fontsize);
  lab->position.y = y;
  lab->position.x = x - width/2;
  lab->fontsize = fontsize;
  lab->disabled = false;
}

void draw_label(LSKLabel* lab){
  if(lab->disabled) return;
  DrawText(lab->text, lab->position.x, lab->position.y, lab->fontsize, BLACK);
}

void set_label(LSKLabel* lab, const char* text){
  free(lab->text);
  init_label(lab, text, lab->position.x, lab->position.y, lab->fontsize);
}

void free_label(LSKLabel* lab){
  free(lab->text);
}
