#include "podcast.hpp"
#include <iostream>
#include <cv.h>
#include <algorithm>
podcast::podcast(const std::string urlIn){
	//url = urlIn;
	url = "rssDir/action";
	pugi::xml_parse_result result = doc.load_file(url.c_str());
	if(pugi::xml_text text = doc.child("rss").child("channel").child("title").text()){
		name = text.get();
	}
	std::vector<pugi::xml_node> eps;
	for (pugi::xml_node ep = doc.child("rss").child("channel").child("item"); ep; ep = ep.next_sibling("item")){
		eps.push_back(ep);
	}
	std::reverse(eps.begin(),eps.end());
	for (int i = 0; i < eps.size()-1; i++){
		std::string epTitle = eps[i].child("title").text().get();
		std::string epUrl = eps[i].child("enclosure").attribute("url").value();
		episodes.push_back(episode(epUrl, epTitle, i));
	}
}
std::string podcast::getName(){
	return name;
}
std::vector<episode> podcast::getEpisodes(){
	return episodes;
}
