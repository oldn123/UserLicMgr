#pragma once

#ifdef CODEDEPEND_EXPORTS
#define _DLLEXPORT  _declspec(dllexport) 
#else
#define _DLLEXPORT  _declspec(dllimport) 
#endif

class _DLLEXPORT CLicSupport
{
public:
	CLicSupport(void);
	~CLicSupport(void);

	static char cTrial_check_ip_time;
	static char cTrial_check_time;
	static char cLegal_check_ip;
	
public:
	static bool decodeMac(char * sOut, const char* sInput, const char * sKey1, const char * sKey2);

	static bool makeLicFile(char * sFile, const char *pKey1, const char *pKey2, const char * macCode, const char* sLicTime, char licType);
};

