#include <stdlib.h>
#include <math.h>
#include "error.h"
#include "play.h"
#include "button.h"

typedef enum {
  WIN
} PlayState;

typedef struct {
  PlayState state;
} PlayData;

static PlayData* data;

void play_init(GameData* gdata){
  data = malloc(sizeof(PlayData));
}

/*
 * Transition to a different play state
 */
void transit(PlayState new_state){
  data->state = new_state;
}

StateName play_update(){
  
  return END;
}

void play_draw(){
  ClearBackground(RAYWHITE);

  switch(data->state){
    default: ; // pass
  }
}

void play_suspend(){
  free(data);
  data = NULL;
}
