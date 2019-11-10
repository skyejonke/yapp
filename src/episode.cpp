#include "episode.hpp"
#include <cv.h>
#include "skyelib.hpp"
#include <iostream>

episode::episode(const std::string urlIn, const std::string epTitleIn, const int epNumIn, podcast *podIn){
	url = urlIn;
	title = epTitleIn;
	num = epNumIn;
	pod = podIn;
	spot = 0;
	//epPath = "ERROR";
}

void episode::download(){
	std::string cmd = "wget <url> -O <pod>/<num>.mp3";
	skyelib::replace(cmd,"<url>",url);
	skyelib::replace(cmd,"<pod>",pod->getPath());
	skyelib::replace(cmd,"<num>",std::to_string(num));
	std::string path = "<pod>/<num>.mp3";
	skyelib::replace(path,"<pod>",pod->getPath());
	skyelib::replace(path,"<num>",std::to_string(num));
	setPath(path);
	//system(cmd.c_str());
	downloaded=true;
}

std::string episode::getTitle(){
	return title;
}
std::string episode::getPath(){
	return epPath;
}
void episode::setPath(std::string pathIn){
	epPath = pathIn;
}
int64_t* episode::getSpot(){
	return spot;
}
void episode::setSpot(int64_t *spotIn){
	spot = spotIn;
}
