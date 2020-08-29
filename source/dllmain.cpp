// dllmain.cpp : Defines the entry point for the DLL application.
#include "pch.h"
#include "MemoryMgr.h"

enum eGame {
	WARSZAWKA = 1,
	SYRENKA
};

using namespace Memory::VP;

eGame GetGame()
{
	if (strcmp((char*)0x5468F4, "Warszawka Racer") == 0)
		return WARSZAWKA;
	else if (strcmp((char*)0x4CAB2C, "Syrenka Racer") == 0)
		return SYRENKA;
}


void Init()
{
	switch (GetGame())
	{
	case WARSZAWKA:
		Patch<double>(0x5459B0, (double)1);
		Patch<float>(0x5458C4, 0.0005559999845f);
		Patch<float>(0x5459B8, 0.004333333578f);
		break;
	case SYRENKA:
		Patch<double>(0x4C7140, (double)1);
		Patch<float>(0x4CE9F4, 0.0005559999845f);
		Patch<float>(0x4C7674, 0.002566f);
		break;
	default:
		break;
	}
}

extern "C"
{
	__declspec(dllexport) void InitializeASI()
	{
		Init();
	}
}