#include "ReadInformationOperation.h"

#ifdef WIN32

#include <Windows.h>
#include <aclapi.h>
#include "Shlwapi.h"

using file_system::operations::ReadInformationOperation;

using file_system::Path;

bool ReadInformationOperation::exists(const Path & path) const
{
	return PathFileExists(path.stringValue().c_str());
}

bool ReadInformationOperation::isDirectory(const Path & path) const
{
	if (!this->exists(path))
	{
		return false;
	}
	return PathIsDirectory(path.stringValue().c_str());
}

bool ReadInformationOperation::isFile(const Path & path) const
{
	if (!this->exists(path))
	{
		return false;
	}
	return !PathIsDirectory(path.stringValue().c_str());
}

bool ReadInformationOperation::isExecutable(const Path & path) const
{
	SHFILEINFOA sfi = { 0 };
	DWORD_PTR hr = SHGetFileInfo((LPCTSTR)path.stringValue().c_str(),
		-1,
		&sfi,
		sizeof(sfi),
		SHGFI_EXETYPE);

	return hr != 0;
}

bool ReadInformationOperation::canRead(const Path& path) const {
	PSECURITY_DESCRIPTOR pSD;
	PACL pDACL;
	ULONG result = GetNamedSecurityInfo(
		path.stringValue().c_str(),
		SE_FILE_OBJECT, 
		DACL_SECURITY_INFORMATION, 
		NULL,
		NULL,
		&pDACL,
		NULL,
		&pSD);

	if (result != ERROR_SUCCESS || pDACL == NULL)
	{
		return false;
	}

	ACL_SIZE_INFORMATION aclSize = { 0 };

	if (!GetAclInformation(pDACL, &aclSize, sizeof(aclSize),
		AclSizeInformation)) {
		return NULL;
	}

	for (int i = 0; i < aclSize.AceCount; ++i) {
		ACCESS_ALLOWED_ACE* ace;
		GetAce(pDACL, i, (PVOID*)&ace);

		if (ace->Mask & FILE_GENERIC_READ) {
			return true;
		}
	}

	return false;
}

#endif