#include "ConcreteCustomFileSettingsDAO.h"
#include "RapidJSON/document.h"
#include "RapidJSON/filereadstream.h"
#include "Settings/Builders/CustomFileSettingsBuilder.h"

using settings::dataaccess::ConcreteCustomFileSettingsDAO;
using settings::domain::CustomFileSettings;

using std::string;

using rapidjson::Document;

ConcreteCustomFileSettingsDAO::ConcreteCustomFileSettingsDAO(const string& filePath, std::unique_ptr<settings::builders::CustomFileSettingsBuilder> builder)
: _filePath(filePath), _builder(std::move(builder))
{
}


ConcreteCustomFileSettingsDAO::~ConcreteCustomFileSettingsDAO()
{
}

CustomFileSettings ConcreteCustomFileSettingsDAO::get()
{
	FILE* fp = fopen(_filePath.c_str(), "rb");
	char readBuffer[65536];

	rapidjson::FileReadStream fileStream(fp, readBuffer, sizeof(readBuffer));

	Document document;
	document.ParseStream(fileStream);

	_builder->setBackupFolderPath(document["backupFolder"].GetString());
	
	fclose(fp);

	return _builder->build();
}
