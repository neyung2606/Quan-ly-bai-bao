#include<string>
using namespace std;
class News
{
public:
	string codenews, namenews, namemaga, category, edition, publishing, publishingcom, mainau, sameau;
	int publishingyear;
public:
	News();
	News(string, string, string, string, string, string, string, string, string, int);
	~News();

	void inputData(News&);
	void swap(News&, News&);
};

