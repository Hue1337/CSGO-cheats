#include "ProcMem.h"
#include "csgo.hpp"
#include "iostream"

ProcMem Memory2;
ProcMem* wsk2 = &Memory2;

void WH()
{
	char PName[11]{ "csgo.exe" };
	char DLL[20]{ "client.dll" };

	wsk2->Process(PName);
	DWORD PM{ wsk2->Module(DLL) };

	DWORD lPlayer{ wsk2->Read<DWORD>(PM + hazedumper::signatures::dwGlowObjectManager) };

	while (true)
	{
		DWORD OPlayer{ wsk2->Read<DWORD>(PM + hazedumper::signatures::dwLocalPlayer) };
		int MTeam{ wsk2->Read<int>(OPlayer + hazedumper::netvars::m_iTeamNum) };


		for (int i = 0; i < 10; i++)
		{
			DWORD EPlayer{ wsk2->Read<DWORD>(PM + hazedumper::signatures::dwEntityList + i * VK_SHIFT) };

			int DLght{ wsk2->Read<int>(EPlayer + hazedumper::netvars::m_iGlowIndex) };
			int ETeam{ wsk2->Read<int>(EPlayer + hazedumper::netvars::m_iTeamNum) };

			if (ETeam != MTeam)
			{
				wsk2->Write<float>(lPlayer + (DLght * 0x38) + 0x8, 1);
				wsk2->Write<float>(lPlayer + (DLght * 0x38) + 0x10, 0.5);
			}
			else
			{
				wsk2->Write<float>(lPlayer + (DLght * 0x38) + 0x4, 1);
				wsk2->Write<float>(lPlayer + (DLght * 0x38) + 0x10, 0.5);
			}
			wsk2->Write<bool>(lPlayer + (DLght * 0x38) + 0x24, true);
			wsk2->Write<bool>(lPlayer + (DLght * 0x38) + 0x25, false);
		}

	}
}