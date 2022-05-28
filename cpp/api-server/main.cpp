#include <iostream>
#include <restbed>
#include "mathLib.h"
#include "json.h"

using namespace json;
using namespace std;
using namespace restbed;
using namespace MathLibrary::Arithmetic;

#define JSON { "Content-Type", "application/json" }

template <typename T>
void print(T s) { cout << s << endl; }

class Api {
	public:
		Api(string host, int port) {
			_settings = make_shared<Settings>();
			_settings->set_port(port);
			_settings->set_bind_address(host);
			_settings->set_default_header("Connection","close");
		}

		void serve() {
			for(shared_ptr<Resource>& r: _resources) {
				server.publish(r);
			}
			server.start(_settings);
		}

		void add_http_resource(string method, string path, void (*func) (const shared_ptr<Session>))
		{
			shared_ptr<Resource> res = make_shared<Resource>();
			res->set_path(path);
			res->set_method_handler(method, func);
			_resources.push_back(res);
			return;
		}
		~Api() {}
	private:
		shared_ptr<Settings> _settings;
		vector<shared_ptr<Resource>> _resources;
		Service server;
		
};

void hello_handler(const shared_ptr< Session > session) 
{
	const auto request = session -> get_request();
	int content_length = request -> get_header("Content-Length", 0);
	session->fetch(content_length, []( const shared_ptr<Session> session, const Bytes & body)
	{
		print(body.data());
		map<string,string> res { {"hello", "world"} };
		string response_body = dumps(res);
		string content_length = to_string(response_body.length());
		session->close(OK, dumps(res), { JSON, { "Content-Length", content_length } });
	});
}
float make_calculation(string operation, float val1, float val2)
{
	if (operation == "add")
	{
		return Add(val1,val2);
	}
	else
	{
		return 0.0;
	}
}

void equation_handler(const shared_ptr< Session > session) 
{
	const auto request = session -> get_request();
	int content_length = request -> get_header("Content-Length", 0);
	session->fetch(content_length, [&content_length]( const shared_ptr<Session> session, const Bytes & body)
	{
		string req_body(reinterpret_cast<const char*>(body.data()), content_length);
		map<string,string> json_req = loads(req_body);
		string op = json_req["op"];
		string v1 = json_req["v1"];
		string v2 = json_req["v2"];
		float answer = make_calculation(op, stof(v1), stof(v2));
		map<string,string> res { {"answer", to_string(answer)} };
		string response_body = dumps(res);
		string response_length = to_string(response_body.length());
		session->close(OK, dumps(res), { JSON, { "Content-Length", response_length } });
	});
}


int main(int argc, char* argv[])
{
	Api* a = new Api("0.0.0.0", 8000);
	a->add_http_resource("GET", "/hello", hello_handler);
	a->add_http_resource("POST", "/equation", equation_handler);
	a->serve();
	return 0;
}
