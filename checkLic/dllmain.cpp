// dllmain.cpp : Defines the entry point for the DLL application.
#include "stdafx.h"
#include "stdio.h"
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
				//MessageBox(NULL, L"未检测到加密狗！", L"错误", MB_ICONERROR);
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

//			memset(g_sSign, 0, 10);
// 			ret = dog_read(hdog, 1, 0, 8, g_sSign);
// 			ret = dog_read(hdog, 2, 0, 4, &g_nNodeSize);	
#else
			

			char sMacMe[100] = {0};
			char sIp[100] = {0};
			getLocalInfo(sMacMe, sIp);
		

			char * sModulePath = _GetModulePath(hModule);
			char sLicFile[260] = {0};
			strcpy(sLicFile, sModulePath);
			strcat(sLicFile, "license");
			char sTime[100];
			char sEncodes[1024];
			FILE * fp = fopen(sLicFile, "rb");
			if (fp)
			{
				fseek(fp, 0, SEEK_END);
				long llen = ftell(fp);
				char * sfileData = new char[llen];
				fseek(fp, 0, SEEK_SET);
				fread(sfileData, 1, llen, fp);
				fclose(fp);

				char * sFind = sfileData;
				
				memset(sTime, 0, 100);
				memset(sEncodes, 0, 1024);
				do 
				{
					char * sf1 = strstr(sFind, "\r\n");
					if (!sf1)
					{
						sf1 = strstr(sFind, "\n\r");
					}
					if (sf1)
					{
						int ncnt = sf1 - sFind;
						memcpy(sTime, sFind, ncnt);
						sFind += (ncnt + 2);		
						sf1 = strstr(sFind, "\r\n");
						if (sf1)
						{
							ncnt = sf1 - sFind;
							sFind += (ncnt + 2);
							memcpy(sEncodes, sFind, ncnt);
							sf1 = strstr(sFind, "\r\n");
							if (sf1)
							{
							}
						}
						else
						{
							ncnt = llen - ncnt - 3;
							memcpy(sEncodes, sFind, ncnt);
						}
					}
				} while (0);
				
				delete [] sfileData;
			}

			char sOut[1000];
			char sOut1[1000];
			decodeData(sOut, sEncodes, "~!@#$%^&");

			decodeData(sOut1, sOut, ")(*&^%$#");

			char sMac[12];
			memcpy(sMac, sOut1, 12);
			
			BYTE byteCode = 0;
			memcpy(&byteCode, &sOut1[12], 1);

			char sTimeDecode[20];
			memcpy(sTimeDecode, &sOut1[13], 19);

			for (int i =0; i < 12; i++)
			{
				if (sMac[i] != sMacMe[i])
				{
					_exit(0);
				}
			}

			if (byteCode == 't')
			{
				time_t tm1 = StringToDatetime(sTimeDecode);
				time_t t = time(NULL); //获取目前秒时间  
			
				if (tm1 < t)
				{
					//outtimes
					_exit(0);
				}
			}
			else
			if (byteCode != 'l')
			{
				_exit(0);
			}
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