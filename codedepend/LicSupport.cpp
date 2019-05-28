#include "StdAfx.h"
#include "LicSupport.h"


CLicSupport::CLicSupport(void)
{
}


CLicSupport::~CLicSupport(void)
{
}

bool CLicSupport::decodeMac(char * sOut, const char* sInput, const char * sKey1, const char * sKey2)
{
	return ::MacDecode(sOut, sInput, sKey1, sKey2) == 0;
}

bool CLicSupport::makeLicFile(char * sFile, const char *pKey1, const char *pKey2, const char * macCode, const char* sLicTime, char licType)
{
	return ::makeLicFile(sFile, pKey1, pKey2, macCode, sLicTime, licType) == 0;
}