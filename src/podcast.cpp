#include "podcast.hpp"
#include <iostream>
#include <cv.h>
#include <algorithm>
#include "skyelib.hpp"
podcast::podcast(const std::string urlIn){


	std::string cmd = "wget <url> -O /tmp/rss";
	url = urlIn;
	skyelib::replace(cmd,"<url>",url);
	system(cmd.c_str());
	doc.load_file("/tmp/rss");
	if(pugi::xml_text text = doc.child("rss").child("channel").child("title").text()){
		name = text.get();
	}
	std::vector<pugi::xml_node> eps;
	for (pugi::xml_node ep = doc.child("rss").child("channel").child("item"); ep; ep = ep.next_sibling("item")){
		eps.push_back(ep);
	}
	std::reverse(eps.begin(),eps.end());
	for (unsigned int i = 0; i < eps.size()-1; i++){
		std::string epTitle = eps[i].child("title").text().get();
		std::string epUrl = eps[i].child("enclosure").attribute("url").value();
		episodes.push_back(new episode(epUrl, epTitle, i,this));
	}
	cmd = "mkdir ";
	podPath = "data/<title>";
	std::string titleCopy = name;
	skyelib::replace(titleCopy," ","-");
	skyelib::replace(podPath,"<title>",titleCopy);
	system((cmd+podPath).c_str());
	cmd = "mv /tmp/rss data/<title>/rss";
	std::cout << titleCopy << std::endl;
	skyelib::replace(cmd,"<title>",titleCopy);
	skyelib::replace(cmd,"<url>",urlIn);
	std::cout << "HERE " << cmd << std::endl;
	system(cmd.c_str());
}
std::string podcast::getName(){
	return name;
}
std::vector<episode*> podcast::getEpisodes(){
	return episodes;
}
episode* podcast::getEpisode(int numIn){
	return episodes[numIn];
}
std::string podcast::getPath(){
	return podPath;
}
