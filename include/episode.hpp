#ifndef episode_h
#define episode_h
#include <string>
//#include <boost/network/protocol/http/client.hpp> #include <boost/network/uri.hpp>

class episode{
	public:
		std::string getUrl;
		std::string getPath;
		int getSpot;
		episode(const std::string urlIn, const std::string epTitleIn, const int epNumIn);
		void download();
		std::string getTitle();

	private:
		std::string url;
		std::string path;
		std::string title;
		int spot;
		int num;
};


#endif // episode_h
