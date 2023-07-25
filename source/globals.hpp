#define X_VALUE 'X'
#define O_VALUE 'O'
#define EMPTY_VALUE '-'

#define MIN_NUMBER 1
#define LEFT_PADDING "  "

#define TERM_ITALIC "\x1B[3m"
#define TERM_GREEN "\033[1;32m"
#define TERM_YELLOW "\033[1;33m"
#define TERM_PURPLE "\033[1;35m"
#define TERM_RESET "\033[0m"

extern int dimension;
extern int number_of_players;
extern int game_level;
extern char current_turn;

extern char **grid;

extern int winning_column;
extern int winning_row;
extern bool winning_ltr_diagonal;
extern bool winning_rtl_diagonal;
