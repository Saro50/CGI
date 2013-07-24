/*
	project si_base
		@autor: wn
		@date: 2013/7/22
*/
#ifndef _SI_BASE_
#define _SI_BASE_
#include <string>
typedef std::string str;
namespace si{
	class si_base
	{
	public:
		si_base(str n):tag(n){};
		str getTag()const{
			return tag;
		}
		virtual ~si_base(){};
	private:
		str tag;
		/* data */
	};
}

#endif //_SI_BASE_