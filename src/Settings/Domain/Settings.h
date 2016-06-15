#pragma once
#include <string>

namespace settings { namespace domain {

class Settings
{
public:
	Settings(const std::string& executablPath, const std::string& backupPath);
	virtual ~Settings();

	std::string getExecutablePath() const;
	std::string getBackupPath() const;

private:
	std::string _executablePath;
	std::string _backupPath;
};

} }