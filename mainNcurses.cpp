#include <ncurses.h>

int main() {
    // 1. Initialize ncurses and configure terminal behavior
    initscr();              // Start ncurses mode
    cbreak();               // Read keypresses immediately without waiting for Enter
    noecho();               // Don't automatically print typed keys to the screen
    keypad(stdscr, TRUE);   // Enable special keys (like arrow keys)
    curs_set(0);            // Hide the blinking cursor

    int y = 5, x = 10;      // Starting position (row, column)
    int ch = 0;

    // 2. Main loop: redraw the screen on every keypress until 'q' is pressed
    while (ch != 'q') {
        clear();            // Clear the virtual screen buffer
        mvprintw(0, 0, "Use arrow keys to move '@'. Press 'q' to quit.");
        mvaddch(y, x, '@'); // Move to (y, x) and draw '@'
        refresh();          // Push the buffer updates to your actual terminal

        ch = getch();       // Wait for user input
        if (ch == KEY_UP && y > 1) y--;
        else if (ch == KEY_DOWN && y < LINES - 1) y++;
        else if (ch == KEY_LEFT && x > 0) x--;
        else if (ch == KEY_RIGHT && x < COLS - 1) x++;
    }

    // 3. Restore normal terminal settings before exiting
    endwin();
    return 0;
}