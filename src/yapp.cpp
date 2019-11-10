//#include "yapp.hpp"
#include "episode.hpp"
#include <iostream>
#include <string>
#include <vector>
#include "podcast.hpp"
#include "player.hpp"
#include "ui.hpp"
int main(){
//	episode* ep = new episode("https://aphid.fireside.fm/d/1437767933/32f28071-0b08-4ea1-afcc-37af75bd83d6/25727019-3b3a-4e53-978d-0caf09d1e9e6.mp3", "FunCity", 1, 6);
//	ep->download();
//	podc
	std::vector<podcast*> podcasts;
	bool done = false;
	std::string feed;
	int i = 0;
	while(!done){
		std::cout << "Please input a podcast RSS feed, or type \"done\" to end.\n";
		std::cin >> feed;
		if (feed != "done"){
			podcasts.push_back(new podcast(feed));
			std::cout << "Added podcast: " << podcasts[i]->getName() << std::endl;
			i++;
		}
		else{
			done = true;
		}
	}
	std::cout << "Input one of the podcast number"
		<< std::endl;
	for (int i = 0; i < podcasts.size(); i++){
		std::cout << i << ": ";
		std::cout << podcasts[i]->getName()
			<< std::endl;
	}
	int num;
	std::cin >> num;
	done = false;
	while (!done){
		for (int i = 0; i < podcasts[num]->getEpisodeCount();i++){
			//std::cout << i << ": ";
			std::cout << podcasts[num]->getEpisode(i)->getTitle()
				<< std::endl;
		}
		std::cout << "Input an episode number, or input \"done\" to end the session." << std::endl;
		std::string num2;
		std::cin >> num2;
		if (num2 == "done"){
			done = true;
		}
		else{

			podcasts[num]->getEpisode(std::stoi(num2))->download();
			player* play = new player(podcasts[num]->getEpisode(std::stoi(num2)));
		}
	}


	return 0;
}
