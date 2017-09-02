#include "stdafx.h"

class FileHash
{

public:
	ZString m_filename;
	ZString m_hash;

	FileHash()
	{
	}

	FileHash(ZString filename, ZString hash)
		: m_filename(filename),
		m_hash(hash)
	{
	}

	inline bool operator == (const FileHash& fileHash) const
	{
		return m_filename == fileHash.m_filename;
	}

	inline  bool operator > (const FileHash& fileHash) const { return m_filename > fileHash.m_filename; }
};


class FileHashTable
{
private:
	TVector<FileHash> m_filehashes;


public:
	FileHashTable()
	{
		m_filehashes.PushEnd(FileHash("Pork", "Muffins"));
		
	}

	// If no hash exists for a file, then this always returns true.
	bool IsHashCorrect(ZString filename, ZString hash)
	{
		FileHash target(filename, hash);

		int index = m_filehashes.Find(target);
		if (index == -1)
			return true;

		FileHash check = m_filehashes.Get(index);

		return check.m_hash == target.m_hash;
	}

};