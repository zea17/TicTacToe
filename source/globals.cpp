#include "globals.hpp"

// ─── Game Play Globals ───────────────────────────────────────────────────────

int dimension = 3;
int number_of_players = 1;
int game_level = 1;
char current_turn = X_VALUE;

// ─── Grid ────────────────────────────────────────────────────────────────────

char **grid;

// ─── Win Detector Globals ────────────────────────────────────────────────────

int winning_column = -1;
int winning_row = -1;
bool winning_ltr_diagonal = false;
bool winning_rtl_diagonal = false;
