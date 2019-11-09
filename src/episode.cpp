#include "episode.hpp"
#include <cv.h>


episode::episode(const std::string urlIn, const std::string epTitleIn, const int epNumIn){
	url = urlIn;
	title = epTitleIn;
	num = epNumIn;
}

void episode::download(){
	std::string command = "wget ";
	system((command + url).c_str());
}

std::string episode::getTitle(){
	return title;
}
