#ifndef episode_h
#define episode_h
#include <string>
class episode;
#include "podcast.hpp"
//#include <boost/network/protocol/http/client.hpp> #include <boost/network/uri.hpp>

class episode{
	public:
		std::string getUrl();
		std::string getPath();
		void setPath(std::string pathIn);
		int getSpot;
		episode(const std::string urlIn, const std::string epTitleIn, const int epNumIn, podcast *podIn);
		void download();
		std::string getTitle();
		std::string epPath;

	private:
		std::string url;
		std::string title;
		int spot;
		int num;
		podcast *pod;
		bool downloaded = false;
};


#endif // episode_h
