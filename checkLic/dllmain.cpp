// dllmain.cpp : Defines the entry point for the DLL application.
#include "stdafx.h"
#include "stdio.h"
#define _CHECKLIC_MODE
#include "..\..\softlic\source\api.h"
#include <time.h> 
#include <process.h>
using namespace std;
#pragma comment(lib, "IPHlpApi.Lib")  

#include "checklic.h"
//*****************
//#define Use_dog
//*****************
#ifdef Use_dog
#include "..\..\dog\dog_api.h"
#include "..\..\dog\dog_api_cpp.h"
#include "..\..\dog\vendor_code.h"
#pragma comment(lib, "..\\..\\dog\\lib\\libdog_windows_3155421.lib")

dog_handle_t hdog = 0;
#endif





BOOL APIENTRY DllMain( HMODULE hModule,
                       DWORD  ul_reason_for_call,
                       LPVOID lpReserved
					 )
{
	switch (ul_reason_for_call)
	{
	case DLL_PROCESS_ATTACH:
		{
#ifdef Use_dog	
			dog_status_t ret = dog_login(200, vendorCode, &hdog);
			if (ret != DOG_STATUS_OK)
			{
				//MessageBox(NULL, L"Î´¼ì²âµ½¼ÓÃÜ¹·£¡", L"´íÎó", MB_ICONERROR);
				_exit(0);
			}

			char sPath[250] = {0};
			GetModuleFileNameA(hModule, sPath, 250);
			for (int i = strlen(sPath); i > 0; i--)
			{
				if (sPath[i] == '\\' ||
					sPath[i] == '/')
				{
					sPath[i + 1] = 0;
					break;
				}
			}
#else		
			char * sModulePath = _GetModulePath(hModule);
			char sLicFile[260] = {0};
			strcpy(sLicFile, sModulePath);
			strcat(sLicFile, "license");
			checkLicFile(sLicFile, "~!@#$%^&", ")(*&^%$#");
#endif
		}
	case DLL_THREAD_ATTACH:
	case DLL_THREAD_DETACH:
	case DLL_PROCESS_DETACH:
		break;
	}
	return TRUE;
}

extern "C"{
	int _DLLEXPORT checka()
	{
		return 0;
	}
}