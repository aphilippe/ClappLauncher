#ifndef Path_hpp
#define Path_hpp

#include <stdio.h>
#include <string>

namespace clt { namespace filesystem { namespace entities {

class Path {
public:
	Path(const std::string & value);
	std::string getValue() const;

	Path getParent() const;
	
private:
	std::string _value;
};

} } }
#endif /* Path_hpp */