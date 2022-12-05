//this file is generated by program(drogon_ctl) automatically,don't modify it!
#include "about.h"
#include <drogon/utils/OStringStream.h>
#include <string>
#include <map>
#include <vector>
#include <set>
#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <list>
#include <deque>
#include <queue>
using namespace drogon;
std::string about::genText(const DrTemplateData& about_view_data)
{
	drogon::OStringStream about_tmp_stream;
	std::string layoutName{""};
	about_tmp_stream << "<!DOCTYPE html>\n";
	about_tmp_stream << "<html lang=\"en\">\n";
	about_tmp_stream << "<head>\n";
	about_tmp_stream << "    <meta charset=\"UTF-8\">\n";
	about_tmp_stream << "    <meta http-equiv=\"X-UA-Compatible\" content=\"IE=edge\">\n";
	about_tmp_stream << "    <meta name=\"viewport\" content=\"width=device-width, initial-scale=1.0\">\n";
about_tmp_stream<<"\n";
	about_tmp_stream << "    <link rel='stylesheet' href='/dist/about-bundle.css'>\n";
	about_tmp_stream << "    <script defer src='/dist/about-bundle.js'></script>\n";
about_tmp_stream<<"\n";
	about_tmp_stream << "    <title>drogonframework.phaser | about</title>\n";
	about_tmp_stream << "</head>\n";
	about_tmp_stream << "<body>\n";
about_tmp_stream<<"\n";
	about_tmp_stream << "    <div id=\"content\"></div>\n";
	about_tmp_stream << "    \n";
	about_tmp_stream << "</body>\n";
	about_tmp_stream << "</html>\n";
if(layoutName.empty())
{
std::string ret{std::move(about_tmp_stream.str())};
return ret;
}else
{
auto templ = DrTemplateBase::newTemplate(layoutName);
if(!templ) return "";
HttpViewData data = about_view_data;
auto str = std::move(about_tmp_stream.str());
if(!str.empty() && str[str.length()-1] == '\n') str.resize(str.length()-1);
data[""] = std::move(str);
return templ->genText(data);
}
}
