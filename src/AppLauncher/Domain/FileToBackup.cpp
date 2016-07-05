#include "FileToBackup.h"

#include "AppLauncher/Domain/BackupFolder.h"
#include "AppLauncher/Exceptions/FileToBackupExceptions.h"

using launcher::domain::FileToBackup;

using file_system::Path;

using launcher::domain::BackupFolder;

FileToBackup::FileToBackup(const Path& path)
	: _path(path)
{
	if (!_path.exists())
	{
		throw launcher::exceptions::FileToBackupNotNotfoundException(path);
	}

	if (!_path.isFile())
	{
		throw launcher::exceptions::FileToBackupNotAFileException(path);
	}

	if (!_path.canRead())
	{
		throw launcher::exceptions::FileToBackupInvalidPermissionException(path);
	}
}


FileToBackup::~FileToBackup()
{
}

file_system::Path launcher::domain::FileToBackup::getPath() const
{
	return _path;
}

void FileToBackup::copyTo(const BackupFolder & folder) const
{
	// TODO
}