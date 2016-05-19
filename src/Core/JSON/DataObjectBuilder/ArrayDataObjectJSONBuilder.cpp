#include "ArrayDataObjectJSONBuilder.h"

using core::json::builders::ArrayDataObjectJSONBuilder;

ArrayDataObjectJSONBuilder::ArrayDataObjectJSONBuilder()
{
}


ArrayDataObjectJSONBuilder::~ArrayDataObjectJSONBuilder()
{
}

void ArrayDataObjectJSONBuilder::addChild(std::unique_ptr<IDataObjectJSONBuilder> builder)
{
	if (_childBuilder == nullptr) {
		_childBuilder = std::move(builder);
	}
	else {
		_childBuilder->addChild(std::move(builder));
	}
}

void ArrayDataObjectJSONBuilder::createObject(std::function<void(core::DataObject)> callback)
{
	if (_childBuilder == nullptr) {
		callback(core::DataObject(_vector));
	}
	else {
		_childBuilder->createObject([this](core::DataObject object) {
			_vector.push_back(object);
			_childBuilder = nullptr;
		});
	}
}

void ArrayDataObjectJSONBuilder::addKey(const std::string & key)
{
}
