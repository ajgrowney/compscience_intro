#include <map>
#include <string>
#include <vector>
using namespace std;
const std::string STRIPCHARS = " \n\r\t\f\v\"";

namespace json {
	string l_strip(string s) {
	        size_t start = s.find_first_not_of(STRIPCHARS);
	        return (start == std::string::npos) ? "" : s.substr(start);
	}
	string r_strip(string s)
	{
	        size_t end = s.find_last_not_of(STRIPCHARS);
	        return (end == std::string::npos) ? "" : s.substr(0, end + 1);
	}
	string quote_strip(string s) {
	        s = l_strip(s);
	        return r_strip(s);
	}
	string quote_wrap(string s) { return '"'+s+'"'; }
	
	string dumps(map<string, string> dict){
	        string result = "{";
	        map<string,string>::iterator it;
	        for(it = dict.begin(); it != dict.end(); it++)
	        {
	                result += quote_wrap(it->first) + ":" + quote_wrap(it->second);
	                result += ",";
	        }
	        result.pop_back();
	        result += "}";
	        return result;
	}

	map< string, string> loads(string s)
	{
	        string pairDelim = ",";
	        string kvpDelim = ":";
	        std::map<string,string> res;
	        // Remove the outer {}
	        s.erase(0,1);
	        s.pop_back();
	        vector<string> pairs;
	        // Split into Pairs
	        int cur_pos = 0;
	        string token;
	        while((cur_pos = s.find(pairDelim)) != string::npos)
	        {
	                token = s.substr(0, cur_pos);
	                pairs.push_back(token);
	                s.erase(0, cur_pos + pairDelim.length());
	        }
	        pairs.push_back(s);
	        // Split pairs into key values
	        for(string& kvp: pairs)
	        {
	                string key = quote_strip(kvp.substr(0, kvp.find(":")));
	                string val = quote_strip(kvp.substr(kvp.find(":")+1, kvp.length()-1));
	                res[key] = val;
	        }
	        return res;
	}
}
