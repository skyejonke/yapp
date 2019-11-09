#ifndef podcast_h
#define podcast_h
#include "episode.hpp"
#include <vector>
#include <string>
#include "pugixml.hpp"

class podcast{
	public:
		std::string getUrl();
		std::string getName();
		std::vector<episode> getEpisodes();
		podcast(const std::string urlIn);


	private:
		std::string url;
		std::string name;
		std::vector<episode> episodes;
		pugi::xml_document doc;
};

#endif //podcast_h
