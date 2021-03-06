#pragma once
#include <vector>

#include "AppLauncher/Domain/FileToRestore.h"

namespace settings {
	namespace repositories {
		class SettingsRepository;
	}
}
namespace launcher {
	namespace domain {
		class BackupFolder;
	}
}

namespace launcher { namespace repositories {

class FileToRestoreRepository
{
public:
	FileToRestoreRepository(settings::repositories::SettingsRepository& settingsRepository);
	virtual ~FileToRestoreRepository();

	std::vector<launcher::domain::FileToRestore> get(const launcher::domain::BackupFolder& backupFolder);

private:
	settings::repositories::SettingsRepository& _settingsRepository;
};

} }