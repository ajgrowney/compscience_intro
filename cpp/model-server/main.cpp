#include <iostream>
#include <restbed>
#include "json.h"

using namespace json;
using namespace std;
using namespace restbed;

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

void healthcheck_handler(const shared_ptr< Session > session) 
{
	const auto request = session -> get_request();
	int content_length = request -> get_header("Content-Length", 0);
	session->fetch(content_length, []( const shared_ptr<Session> session, const Bytes & body)
	{
		string response_body = dumps({ {"status", "ok"} });
		string content_length = to_string(response_body.length());
		session->close(OK, response_body, { JSON, { "Content-Length", content_length } });
	});
}

int main(int argc, char* argv[])
{
	Api* a = new Api("0.0.0.0", 8000);
	a->add_http_resource("GET", "/health", healthcheck_handler);
	a->serve();
	return 0;
}
