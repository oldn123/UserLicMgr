// dllmain.cpp : Defines the entry point for the DLL application.
#include "stdafx.h"

#include "checklic.h"
//*****************
#define Use_dog
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
				MessageBox(NULL, L"Œ¥ºÏ≤‚µΩº”√‹π∑£°", L"¥ÌŒÛ", MB_ICONERROR);
				_exit(0);
			}
//			memset(g_sSign, 0, 10);
// 			ret = dog_read(hdog, 1, 0, 8, g_sSign);
// 			ret = dog_read(hdog, 2, 0, 4, &g_nNodeSize);	
#else
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