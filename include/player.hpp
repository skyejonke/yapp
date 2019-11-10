#ifndef player_h
#define player_h
#include "episode.hpp"
#include <mpv/client.h>
class player{

	public:
		player(episode* ep);
		void toggle();
		void skip(int secs);
	private:
		int spot;

};
#endif
