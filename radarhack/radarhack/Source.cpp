#include "ProcMem.h"
#include "csgo.hpp"
#include "iostream"
#include "Libraries.h"
#include "thread"

int main() {
	std::thread RADAR(RadarHack);
	RADAR.join();
}
