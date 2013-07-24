#include "HttpHandle.h"

// namespace si{
// 	class HttpHandle:public si::si_base
// 	{
		
// 	public:
// 		HttpHandle(str n):si::si_base(n){
// 			header = "Date:;\nContent-type:text/html;";
// 		};
// 		void send(){
// 			C c1("login","wn","test");
// 			str result("Date:;");
// 			result += "\nContent-type:text/html;\ncharset:UTF-8";

// 			c_mapper::iterator mp_it = c_container.begin();
// 			while( mp_it != c_container.end() ){
// 				result += mp_it->second;
// 				mp_it++;
// 			}
// 			std::cout<<"Date:;"
// 				<<"\nContent-type:text/html;"
// 				<<"\nCITY-POWER:SI;"
// 				<< c1.setCookie()
// 				<<"\ncharset:UTF-8\n"<<std::endl;
// 		}
// 		void delCookie();
// 		void addCookie();
// 		void clearCookie();
// 		~HttpHandle(){};
// 	private:
// 		static const str ENV[ 24 ];
// 		str header;
// 		c_mapper c_container;
// 		};
// }
typedef std::map< std::string , std::string > c_mapper;
typedef std::string str;
typedef si::Cookie C;

const str si::HttpHandle::ENV[ 24 ] = {                 
		        "COMSPEC", "DOCUMENT_ROOT", "GATEWAY_INTERFACE",   
		        "HTTP_ACCEPT", "HTTP_ACCEPT_ENCODING",             
		        "HTTP_ACCEPT_LANGUAGE", "HTTP_CONNECTION",         
		        "HTTP_HOST", "HTTP_USER_AGENT", "PATH",            
		        "QUERY_STRING", "REMOTE_ADDR", "REMOTE_PORT",      
		        "REQUEST_METHOD", "REQUEST_URI", "SCRIPT_FILENAME",
		        "SCRIPT_NAME", "SERVER_ADDR", "SERVER_ADMIN",      
		        "SERVER_NAME","SERVER_PORT","SERVER_PROTOCOL",     
		        "SERVER_SIGNATURE","SERVER_SOFTWARE" };


void si::HttpHandle::send(){
			C c1("login","wn","test");
			str result("Date:;");

			result +=  "\nContent-type:text/html;\ncharset:UTF-8;";

			c_mapper::iterator mp_it = c_container.begin();
			while( mp_it != c_container.end() ){
				result += mp_it->second;
				mp_it++;
			}
			result += "\n\n";
			// std::cout<<"Date:;"
			// 	<<"\nContent-type:text/html;"
			// 	<<"\nCITY-POWER:SI;"
			// 	<< c1.getStr()
			// 	<<"\ncharset:UTF-8\n\n"
			// 	<< result
			// 	<< std::endl;
			std::cout << result << std::endl;
}

void si::HttpHandle::delCookie(str& keyName){
	 if(c_container.count(keyName))
	 		c_container.erase(keyName);
}

c_mapper::iterator si::HttpHandle::addCookie(C c){
		c_container[c.Name] = c.getStr();
		return c_container.find(c.Name);
	// c_container.insert(make_pair(C.Name,C.getStr() ));
}
c_mapper::iterator si::HttpHandle::getCookie(str& name){
	return c_container.find(name);
}