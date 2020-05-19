#include <stdlib.h>
#include <raylib.h>
#include "menu.h"
#include "button.h"

typedef struct {
  Button play_button;
  Button about_button;
  bool* use_ia;
} MenuData;

static MenuData* data;

void menu_init(GameData* gdata){
  data = malloc(sizeof(MenuData));
  init_button(&data->play_button, "Play", 300, 400, 20);
  init_button(&data->about_button, "About this game", 300, 500, 20);
  data->use_ia = &gdata->use_ia;
}

void draw_title(const char* title, int x, int y){
  int width = MeasureText(title, 30);
  DrawText(title, x - width/2, y, 30, BLACK);
}

void menu_draw(void){
  ClearBackground(RAYWHITE);
  draw_title("Starter kit", 300, 200);
  draw_button(&data->play_button);
  draw_button(&data->about_button);
}

StateName menu_update(void){
  if (button_pressed(&data->play_button)){
    return PLAY;
  } else if (button_pressed(&data->about_button)){
    return CREDIT;
  }
  return MENU;
}

void menu_suspend(void){
  free_button(&data->play_button);
  free_button(&data->about_button);
  free(data);
  data = NULL;
}
