#include "ProcMem.h"
#include "csgo.hpp"
#include "iostream"

ProcMem Memory1;
ProcMem* wsk = &Memory1;

void BunnyHop(){
	char PName[11]{ "csgo.exe" };
	char DLL[20]{ "client.dll" };

	wsk->Process(PName);
	DWORD PModule{ wsk->Module(DLL) };

	while (true){
		if (GetAsyncKeyState(0x20)){
			DWORD id1{ wsk->Read<DWORD>(DWORD(PModule) + DWORD(hazedumper::signatures::dwLocalPlayer)) };
			DWORD FLAG{ wsk->Read<DWORD>(id1 + hazedumper::netvars::m_fFlags) };

			if (static_cast<int>(FLAG) == 257){
				wsk->Write(PModule + hazedumper::signatures::dwForceJump, 6);
			}
		}
		Sleep(5);
	}
}