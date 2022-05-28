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
		string response_body = dumps({ {"hello", "world"} });
		string content_length = to_string(response_body.length());
		session->close(OK, response_body, { JSON, { "Content-Length", content_length } });
	});
}

float make_calculation(string operation, float val1, float val2)
{
	if (operation == "add") {
		return Add(val1,val2);
	} else if (operation == "sub") {
		return Subtract(val1, val2);
	} else if (operation == "mult") {
		return Multiply(val1, val2);
	} else if (operation == "div") {
		return Divide(val1, val2);
	} else {
		return 0.0;
	}
}

void calc_handler(const shared_ptr< Session > session) 
{
	const auto request = session -> get_request();
	int request_length = request -> get_header("Content-Length", 0);
	session->fetch(request_length, [&request_length]( const shared_ptr<Session> session, const Bytes & body)
	{
		// Load Request Body
		string req_body(reinterpret_cast<const char*>(body.data()), request_length);
		map<string,string> json_req = loads(req_body);
		
		// Extract Parameters
		string op = json_req["op"];
		float v1 = stof(json_req["v1"]);
		float v2 = stof(json_req["v2"]);
		
		// Make Calculation
		float answer = make_calculation(op, v1, v2);
		
		// Make Response
		string response_body = dumps({ {"answer", to_string(answer)} });
		string response_length = to_string(response_body.length());
		
		// Send Response
		session->close(OK, response_body, { JSON, { "Content-Length", response_length } });
	});
}


int main(int argc, char* argv[])
{
	Api* a = new Api("0.0.0.0", 8000);
	a->add_http_resource("GET", "/hello", hello_handler);
	a->add_http_resource("POST", "/calculation", calc_handler);
	a->serve();
	return 0;
}
