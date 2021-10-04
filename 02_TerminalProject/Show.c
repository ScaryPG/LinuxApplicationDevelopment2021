#include <ncurses.h>

int
main(const int argc, const char **argv)
{
    if (argc != 2) {
        return 1;
    }

    FILE *file = fopen(argv[1], "r");
    if (file == NULL) {
        return 1;
    }

    initscr();
    curs_set(0);
    noecho();

    printw("File: %s", argv[1]);
    refresh();

    WINDOW *win = newwin(LINES - 1, COLS, 1, 0);
    keypad(win, TRUE);
    scrollok(win, TRUE);
    wmove(win, 1, 0);

    char *line;
    size_t n;

    for (int i = 0; i < LINES - 3; ++i) {
        if (getline(&line, &n, file) == -1) {
            break;
        }
        wprintw(win, " %s", line);
    }
    box(win, 0, 0);
    wrefresh(win);

    int key;
    while ((key = wgetch(win)) != 27) {
        if (key == 32 && getline(&line, &n, file) != -1) {
            wprintw(win, " %s", line);
            box(win, 0, 0);
            wrefresh(win);
        }
    }

    delwin(win);
    endwin();
    fclose(file);

    return 0;
}
