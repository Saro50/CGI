/*
	upload cgi
	@date 2013/7/22
	@Autor wn

*/
#include <iostream>
#include <stdlib.h>
#include <map>
#include <fstream>
#include <string>
#include <ctime>
#include "../includes/Cookie.h"
#include "../includes/HttpHandle.h"
#include "../includes/HtmlHelper.h"

#include <utility>

using namespace std;

// const int EVN_COUNTER(28);
const string ENV[] = {  
        "upload_file",               
        "COMSPEC", "DOCUMENT_ROOT", "GATEWAY_INTERFACE",  
        "HTTP_ACCEPT", "HTTP_ACCEPT_ENCODING","HTTP_COOKIE",             
        "HTTP_ACCEPT_LANGUAGE", "HTTP_CONNECTION",         
        "HTTP_HOST", "HTTP_USER_AGENT", "PATH",            
        "QUERY_STRING", "REMOTE_ADDR", "REMOTE_PORT",      
        "REQUEST_METHOD", "REQUEST_URI", "SCRIPT_FILENAME",
        "SCRIPT_NAME", "SERVER_ADDR", "SERVER_ADMIN",      
        "SERVER_NAME","SERVER_PORT","SERVER_PROTOCOL", 
        "CONTENT_TYPE",
        "CONTENT_LENGTH",    
        "SERVER_SIGNATURE","SERVER_SOFTWARE" };  

const int EVN_COUNTER = sizeof(ENV)/sizeof(string);

#define BUFFSIZE 16*1024 

char szBuff[BUFFSIZE];

int main (int argc, char *argv[])
{
  /* 
    @convert upload file to Binary 

      _setmode(_fileno(stdin), _O_BINARY);
  
    @read from stream

      std::cin.read(buf, len);

    @convert file mode to text

      _setmode(_fileno(stdin), _O_TEXT);


    @CONTENT_LENGTH只对application/x-www-form-urlencoded类型数据起作用，如果要读上传的文件数据应该是

      string buf;
      cin.unsetf( ios::skipws );
      while ( cin )
      {
      cin >> c;
      buf += c;
      }
      
    */

	si::HttpHandle response("ajax");
  si::Cookie c1("name"),c2("VALE","Name2","VSSSS");
  time_t currentTime;
  time(&currentTime);

  c1.Name = "Name1";
  c1.Value = "WNasd";
  c1.Path = "/";
  response.addCookie(c1);
  response.addCookie(c2);
	response.send();
   /*
     @atoi convert char into int ;
   */
   int contentLength = atoi( getenv( "CONTENT_LENGTH" ) );
   char postString[4096] = "";

   // string buf;
    // _setmode( _fileno( stdin ), _O_BINARY ); 

    // std::cin.read(buf, contentLength);

     // if(fgets(szBuff, sizeof(szBuff), std::cin ){
     //  cout << szBuff
     // }

    string buf;

    string tmp;

    // cin.unsetf( ios::skipws );
    while ( cin )
    {
      std::cin >> tmp;
      buf += tmp;
    }

    // _setmode(_fileno(stdin), _O_TEXT);
     std::cin.read( postString , contentLength);
   // std::cin.fread();
   std::string dataString(postString);
   std::string getNowTime = asctime( localtime( &currentTime ) );
   cout << "<html>\n";
   cout << "<head>\n";
   cout << "<title>title</title>\n";
   cout << "<meta charset='utf-8'>";
   cout << "</head>\n";
   cout << "<body>\n";
   cout << response.getTag();
   cout << "中文测试";
   cout << "<h1>" << "中文测试"<< "</h1>";
   cout <<"<h2 >" << postString <<"</h2>";
   cout << "<h3>" << getNowTime << "</h3>";
   cout << "<h4 style='background:#f1f1f1;border:1px solid #ccc;' >" << buf << "</h4>";
   cout << "<table border = \"0\" cellspacing = \"2\">";
//eest for check outconst int EVN_COUNTER(EVN_COUNTER);
   for ( int i = 0; i < EVN_COUNTER; i++ )
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
