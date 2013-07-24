/*
	HTTP handle
		@creator: wn
		@date: 2013/7/22
*/
#ifndef _SI_HTTPHANDLE_
#define _SI_HTTPHANDLE_
#include <string>
#include <iostream>
#include <map>
#include <stdlib.h>
#include "si_base.h"
#include "Cookie.h"

typedef std::string str;
typedef std::map< str,str > c_mapper;
typedef si::Cookie C;

namespace si{
	class HttpHandle:public si::si_base
	{
	public:
		HttpHandle(str n):si::si_base(n){
			date = "Date:;\nContent-type:text/html;";
		};
		enum status { Nomal };
		void send();
		void delCookie(str&);
		c_mapper::iterator addCookie(C);
		c_mapper::iterator getCookie(str&);
		void clearCookie();
		~HttpHandle(){};
	private:
		static const str ENV[ 24 ];
		str date;
		str contentType;
		c_mapper c_container;
		};
}


// const string ENV[ 24 ] = {                 
//         "COMSPEC", "DOCUMENT_ROOT", "GATEWAY_INTERFACE",   
//         "HTTP_ACCEPT", "HTTP_ACCEPT_ENCODING",             
//         "HTTP_ACCEPT_LANGUAGE", "HTTP_CONNECTION",         
//         "HTTP_HOST", "HTTP_USER_AGENT", "PATH",            
//         "QUERY_STRING", "REMOTE_ADDR", "REMOTE_PORT",      
//         "REQUEST_METHOD", "REQUEST_URI", "SCRIPT_FILENAME",
//         "SCRIPT_NAME", "SERVER_ADDR", "SERVER_ADMIN",      
//         "SERVER_NAME","SERVER_PORT","SERVER_PROTOCOL",     
//         "SERVER_SIGNATURE","SERVER_SOFTWARE" };  

// const str _ENV[ 29 ] = {                 
//         "HTTP_REFERER","PATH_INFO",
//         "HTTP_ACCEPT", "HTTP_ACCEPT_ENCODING",             
//         "HTTP_ACCEPT_LANGUAGE", "HTTP_CONNECTION",         
//         "HTTP_HOST", "HTTP_USER_AGENT",
//  		 "COMSPEC", "DOCUMENT_ROOT", "GATEWAY_INTERFACE",
//         "CONTENT_LENGTH","CONTENT_TYPE","HTTP_COOKIE",
//          "PATH",            
//         "QUERY_STRING", "REMOTE_ADDR", "REMOTE_PORT",      
//         "REQUEST_METHOD", "REQUEST_URI", "SCRIPT_FILENAME",
//         "SCRIPT_NAME", "SERVER_ADDR", "SERVER_ADMIN",      
//         "SERVER_NAME","SERVER_PORT","SERVER_PROTOCOL",     
//         "SERVER_SIGNATURE","SERVER_SOFTWARE" 
//     }; 



#endif //_SI_HTTPHANDLE_		