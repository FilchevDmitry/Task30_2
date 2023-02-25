#include <iostream>
#include<cpr/cpr.h>

int main()
{
	cpr::Response r = cpr::Get(cpr::Url("http://httpbin.org/html"),
		cpr::Header({ {"accept:","text/html"} }));
	std::string out;
	if (r.text.find("<h1>") != r.text.size())
	{
		for (int i = r.text.find("<h1>") + 4; i < r.text.find("</h1>"); i++)
		{
			out += r.text[i];
		}
		std::cout << out << std::endl;
	}
	std::cout << "status code " << r.status_code << std::endl;
}
