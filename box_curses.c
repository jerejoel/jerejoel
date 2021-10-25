#include <ncurses.h>
#include <unistd.h> /* needed for usleep delay*/


#define MIN_X 15
#define MAX_X 30
#define MIN_Y 15
#define MAX_Y 30


void draw_dot(int i, int j);

int main (void)
{
    int i,j;
    char ch;

    initscr ();
    clear ();

    start_color ();
    init_pair (3, COLOR_RED, COLOR_WHITE);
    bkgd (COLOR_PAIR (3));
    curs_set(0);

    noecho ();			/* stop echo of input */

    for (i = MIN_X; i < MAX_X; i++)
    {
        draw_dot(MIN_Y,i);
        draw_dot(MAX_Y,i);
        }
        refresh ();
	sleep(1);

    for (i = MIN_Y; i < MAX_Y; i++)
    {
        draw_dot(i,MIN_X);
        draw_dot(i,MAX_X);
        }

        refresh ();
	sleep(1);

	j=MAX_X;

    for (i = MIN_Y; i < MAX_Y; i++)
    {
        draw_dot(i,j);
        draw_dot(i,i);
	j--;
        }
        refresh();
	sleep(1);

    getch ();
    endwin ();
}



void draw_dot(int x, int y)
{
    int i,j;

        move(x,y);
        printw("*");

}
