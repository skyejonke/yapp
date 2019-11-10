#ifndef podcast_h
#define podcast_h
#include <vector>
#include <string>
#include "pugixml.hpp"
class podcast;
#include "episode.hpp"

class podcast{
	public:
		std::string getUrl();
		std::string getName();
		std::vector<episode*> getEpisodes();
		episode* getEpisode(int numIn);
		podcast(const std::string urlIn);
		std::string getPath();
		int getEpisodeCount();


	private:
		std::string url;
		std::string name;
		std::vector<episode*> episodes;
		pugi::xml_document doc;
		std::string podPath;
};

#endif //podcast_h
