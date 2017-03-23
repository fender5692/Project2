/**
* Text User Interface Program
*
* @author Forrest Williams
* @author Conner Shields
*/

#include <cstdlib>
#include <ncurses.h>
#include <iostream>
#include <fstream>
#include <string>
#include <menu.h>
#include <string.h>
#include <panel.h>
using namespace std;

int main()
{	WINDOW *my_win;
	PANEL  *my_panel;
	int lines = 30, cols = 120, y = 2, x = 4, i;

	initscr();
	cbreak();
	noecho();

	/* Create window for the panel */
	my_win = newwin(lines, cols, y, x);


	/* 
	 * Create border around the window
	 */
		box(my_win, 0, 0);

	/* Attach a panel to the window */ 
	my_panel = new_panel(my_win); 	


	/* Update the panel */
	update_panels();

	/* Show it on the screen */
	doupdate();
	
	getch();
	endwin();
}
