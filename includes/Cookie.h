/*
	HTTP Cookies
		@creator: wn
		@date: 2013/7/22
*/
#ifndef _SI_COOKIE_
#define _SI_COOKIE_
#include "si_base.h"
#include <string>

namespace si{
	class Cookie:public si::si_base{
	typedef std::string str;
	public:
		// Cookie(string n ){};
		Cookie(str tag,str N,str V):si::si_base(tag),Name(N),Value(V){};
		Cookie(str tag,str N,str V,str P):si::si_base(tag),Name(N),Value(V),Path(P){};
		Cookie(str tag):si::si_base(tag){};
		str getStr(){
			str result("\nSet-Cookie:");
			result += Name + "=" + Value +";";
			if( Path != "" ){
				result += "path=" + Path + ";";
			}
			if( Expires != "" ){
				result += "expires=" + Expires  + ";";
			}
			if( HttpOnly != "" ){
				result+="httpOnly=true;";
			}
			if( Secure != "" ){
				result += "secure=true;";
			}
			return result;
		}
		str Name;
		str Value;
		str Path;
		str Expires;
		str HttpOnly;
		str Secure;

		~Cookie(){};
	};
}

#endif //_SI_COOKIE_


