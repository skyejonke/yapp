#ifndef ui_h
#define ui_h
#include <ncurses.h>

class ui{
	public:
		ui();
		void start();
	private:
		WINDOW *create_newwin(int height, int width, int starty, int startx);
		void destroy_win(WINDOW *local_win);


};

#endif // ui_h
