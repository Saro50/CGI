/*
	upload cgi
	@date 2013/7/22
	@Autor wn

*/
#include <iostream>
#include <stdlib.h>
#include <map>
#include <string>
#include "../includes/Cookie.h"
#include "../includes/HttpHandle.h"

#include <utility>

using namespace std;

const string ENV[ 25 ] = {                 
        "COMSPEC", "DOCUMENT_ROOT", "GATEWAY_INTERFACE",   
        "HTTP_ACCEPT", "HTTP_ACCEPT_ENCODING","HTTP_COOKIE",             
        "HTTP_ACCEPT_LANGUAGE", "HTTP_CONNECTION",         
        "HTTP_HOST", "HTTP_USER_AGENT", "PATH",            
        "QUERY_STRING", "REMOTE_ADDR", "REMOTE_PORT",      
        "REQUEST_METHOD", "REQUEST_URI", "SCRIPT_FILENAME",
        "SCRIPT_NAME", "SERVER_ADDR", "SERVER_ADMIN",      
        "SERVER_NAME","SERVER_PORT","SERVER_PROTOCOL",     
        "SERVER_SIGNATURE","SERVER_SOFTWARE" };  

  

int main (int argc, char *argv[])
{
	si::HttpHandle response("ajax");
  si::Cookie c1("name"),c2("VALE","Name2","VSSSS");
  c1.Name = "Name1";
  c1.Value = "WNasd";
  c1.Path = "/";
  response.addCookie(c1);
  response.addCookie(c2);

	 response.send();
   cout << "<html>\n";
   cout << "<head>\n";
   cout << "<title>title</title>\n";
   cout << "<meta charset='utf-8'>";
   cout << "</head>\n";
   cout << "<body>\n";
   cout << response.getTag();
   cout << "中文测试";
   cout << "<h1>" << "中文测试"<< "</h1>";
   cout << "<table border = \"0\" cellspacing = \"2\">";

   for ( int i = 0; i < 25; i++ )
   {
       cout << "<tr><td>" << ENV[ i ] << "</td><td>";
       // attempt to retrieve value of environment variable
       char *value = getenv( ENV[ i ].c_str() );  
       if ( value != 0 ){
         cout << value;                                 
       }else{
         cout << "Environment variable does not exist.";
       }
       cout << "</td></tr>\n";
   }
   cout << "</table>\n";
   cout << "</body>\n";
   cout << "</html>\n";
   
   return 0;
}