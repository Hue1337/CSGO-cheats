#include "ProcMem.h"
#include "csgo.hpp"
#include "iostream"

ProcMem Memory1;
ProcMem* wsk1 = &Memory1;

void RadarHack() {
	char PName[11]{ "csgo.exe" };
	char DLL[20]{ "client.dll" };

	wsk1->Process(PName);
	DWORD PModul{ wsk1->Module(DLL) };

	while (true) {
		for (char i = 0; i < 5; i++) {
			DWORD j{ wsk1->Read<DWORD>(PModul + hazedumper::signatures::dwEntityList + i * VK_SHIFT) };
			wsk1->Write<DWORD>(j + hazedumper::netvars::m_bSpotted, true);
		}
		Sleep(5);
	}
}
