#ifndef ApplicationParametersReader_hpp
#define ApplicationParametersReader_hpp

#include <stdio.h>
#include <functional>

namespace application { namespace parameters {

	class ApplicationParametersReader {
	public:
		void start(char* argv[]) const;
		
		void setOnExecutablePath(std::function<void (const std::string&)> func);
		
	private:
		std::function<void (const std::string&)> _onExecutablePath;
	};
	
} }

#endif /* ApplicationParametersReader_hpp */