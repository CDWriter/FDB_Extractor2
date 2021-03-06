#pragma once

#include "FDBFile.h"
#include "FDBFieldManager.h"


class FDBFileStringDB : public  FDBFile
{
    private:
		#pragma warning( disable : 4200 )
		struct s_entry
		{
			const char key[64];
			uint32_t  v_len;
			const char value[];
		};
		#pragma warning( default: 4200 )

    public:
        FDBFileStringDB(const FDBPackage::file_info& s_info, uint8_t* data );

        bool WriteINI(const char*);
        bool WriteSQLITE(const char* filename);
        bool WriteMySQL(const char* filename);
        FDBPackage::e_export_format DefaultFormat()    { return FDBPackage::EX_INI; };
        bool ExportFormatIsValid(FDBPackage::e_export_format e)    { return (e==FDBPackage::EX_INI)||(e==FDBPackage::EX_SQLITE)||(e==FDBPackage::EX_MYSQL)||(FDBFile::ExportFormatIsValid(e)); };
};

