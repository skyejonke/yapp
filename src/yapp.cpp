//#include "yapp.hpp"
#include "episode.hpp"
#include <iostream>
#include "podcast.hpp"
#include "ui.hpp"
int main(){
//	episode* ep = new episode("https://aphid.fireside.fm/d/1437767933/32f28071-0b08-4ea1-afcc-37af75bd83d6/25727019-3b3a-4e53-978d-0caf09d1e9e6.mp3", "FunCity", 1, 6);
//	ep->download();
	podcast* pod = new podcast("https://www.smashingsecurity.com/rss");
	pod->getEpisode(5)->download();
	std::cout << pod->getEpisodes()[5]->getTitle() << std::endl;
	std::cout << pod->getEpisodes()[5]->getPath() << std::endl;
//	ui* term = new ui();
//	term->start();
//	initscr();
//	endwin();

	return 0;
}
