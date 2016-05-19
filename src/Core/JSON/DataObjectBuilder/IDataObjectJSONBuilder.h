#ifndef IDataObjectJSONBuilder_h
#define IDataObjectJSONBuilder_h

#include "Core/DataObject.h"
#include <memory>
#include <functional>

namespace core { namespace json { namespace builders {

class IDataObjectJSONBuilder {
public:
	virtual ~IDataObjectJSONBuilder(){}
	virtual void addChild(std::unique_ptr<IDataObjectJSONBuilder> builder) = 0;
	virtual void createObject(std::function<void(core::DataObject)> callback) = 0;
	virtual void addKey(const std::string& key) = 0;
};

} } }
#endif /* IDataObjectJSONBuilder_h */
