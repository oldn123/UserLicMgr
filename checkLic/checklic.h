#pragma once



//#ifdef _DLL
#define _DLLEXPORT  _declspec(dllexport) 
//#else
//#define _DLLEXPORT  _declspec(dllimport) 
//#endif

extern "C" int _DLLEXPORT checka();