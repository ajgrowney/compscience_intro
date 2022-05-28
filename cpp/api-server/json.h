#ifndef JSON_H
#define JSON_H

#include <string>
#include <map>
using namespace std;
namespace json {
	string l_strip(string s);
	string r_strip(string s);
	string quote_wrap(string s);
	string dumps(map<string, string> dict);
	map< string, string> loads(string s);
}
#endif
