#include "StdAfx.h"
#include "LicSupport.h"


char CLicSupport::cTrial_check_ip_time = Trial_check_ip_time;
char CLicSupport::cTrial_check_time = Trial_check_time;
char CLicSupport::cLegal_check_ip = Legal_check_ip;

char* CLicSupport::sKey1 = GetDefaultKey(0);
char* CLicSupport::sKey2 = GetDefaultKey(1);

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

bool CLicSupport::makeLicFile(char * sFile, const char * sSoftId, const char *pKey1, const char *pKey2, const char * macCode, const char* sLicTime, char licType)
{
	return ::makeLicFile(sFile, sSoftId, pKey1, pKey2, macCode, sLicTime, licType) == 0;
}