#include <string>
#include <sstream>

namespace StringHelper
{
	namespace Detail
	{
		class String
		{
		public:

			template<typename T>
			static std::string ToString(T t)
			{
				std::stringstream stream;
				stream << t;
				return stream.str();
			}
		};
	}

	typedef Detail::String String;
}
