#ifndef STK_H
#define STK_H
#include <stdbool.h>

typedef enum {
  MENU=0,
  CREDIT,
  PLAY,
  END,
  STATE_NUM,  // Not a state, but gives the number of states
  CLOSE,  // Special state, used to close the main loop
} StateName;

typedef struct {
  bool use_ia;
} GameData;

typedef struct {
  StateName name;
  void (*init)(GameData* data); // optional
  StateName (*update)(void);
  void (*draw)(void);
  void (*suspend)(void); // optional
  // void (*free)(); // optional
} GameState;

#ifdef IMPL_MAIN_LOOP
// Add new state headers here:
#include "menu.h"
#include "credit.h"
#include "play.h"
#include "end.h"

int screenWidth = 600;
int screenHeight = 600;

// Add new GameState pointers here:
GameState* states[(int)STATE_NUM] = {
  &menu_state,
  &credit_state,
  &play_state,
  &end_state
};
#endif
#endif
