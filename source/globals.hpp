#define X_VALUE 'X'
#define O_VALUE 'O'
#define EMPTY_VALUE '-'

#define MIN_NUMBER 1

extern int dimension;
extern int number_of_players;
extern int game_level;
extern char current_turn;

extern char **grid;

extern int winning_column;
extern int winning_row;
extern bool winning_ltr_diagonal;
extern bool winning_rtl_diagonal;
