// dllmain.cpp : Defines the entry point for the DLL application.
#include "stdafx.h"

#include <IPHlpApi.h>  
#include <stdio.h>
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





bool getAdapterState(DWORD index)
{
	MIB_IFROW Info;    // 存放获取到的Adapter参数
	memset(&Info, 0, sizeof(MIB_IFROW));
	Info.dwIndex = index; // dwIndex是需要获取的Adapter的索引，可以通过GetAdaptersInfo和其他相关函数获取
	if (GetIfEntry(&Info) != NOERROR)
	{
		return false;
	}
	if (Info.dwOperStatus == IF_OPER_STATUS_NON_OPERATIONAL
		|| Info.dwOperStatus == IF_OPER_STATUS_UNREACHABLE
		|| Info.dwOperStatus == IF_OPER_STATUS_DISCONNECTED

		|| Info.dwOperStatus == IF_OPER_STATUS_CONNECTING)
		return false;
	else if (Info.dwOperStatus == IF_OPER_STATUS_OPERATIONAL

		|| Info.dwOperStatus == IF_OPER_STATUS_CONNECTED)
		return true;

	return false;
}

int getLocalInfo(char * mac, char * ipMe)
{
	IP_ADAPTER_INFO IOInfo[20];
	PIP_ADAPTER_INFO pIOInfo = NULL;
	DWORD Result = 0;
	unsigned long nLen = sizeof(IOInfo);

	Result = GetAdaptersInfo(IOInfo, &nLen);
	pIOInfo = &IOInfo[0];
	bool bGetOK = false;
	while (pIOInfo)
	{
		IP_ADDR_STRING *pIpAddrString = &(pIOInfo->IpAddressList);
		if (bGetOK || !getAdapterState(pIOInfo->Index))
		{
			//网络未连接
			pIOInfo = pIOInfo->Next;
			continue;
		}

		{	
			if (/*strstr(pIOInfo->Description, "PCI")>0 &&*/ pIOInfo->Type == MIB_IF_TYPE_ETHERNET) //有线网可用时直接返回
			{
				bGetOK = true;
			}	
			else if (pIOInfo->Type == 71)	//无线网络
			{
				bGetOK = true;
			}

			if (bGetOK)
			{
				//仅考虑有线网络与无线网络
				strcpy(ipMe, pIpAddrString->IpAddress.String);
				sprintf(mac, "%2x:%2x:%2x:%2x:%2x:%2x", pIOInfo->Address[0], pIOInfo->Address[1], pIOInfo->Address[2],
					pIOInfo->Address[3], pIOInfo->Address[4], pIOInfo->Address[5]);
			}
		}

		pIOInfo = pIOInfo->Next;
	}

	return 0;
}



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
			

			char sMac[100] = {0};
			char sIp[100] = {0};
			getLocalInfo(sMac, sIp);
			MessageBoxA(0, sMac, sIp, 0);
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