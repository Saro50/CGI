/*
	html helper
		@autor: wn
		@date: 2013/7/22
*/
#ifndef _SI_HTMLHELPER_
#define _SI_HTMLHELPER_
#include "si_base.h"
#include "iostream"
#include "string"

typedef std::string str;

namespace si{
	class HtmlHelper:si::si_base
	{
	public:
		HtmlHelper(str& n):si::si_base(n){};
		void printTag(str&,str&);
		~HtmlHelper(){};
	private:
	};

}
#endif //_SI_HTMLHELPER_