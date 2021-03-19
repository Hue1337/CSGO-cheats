#include "ProcMem.h"
#include "csgo.hpp"
#include "iostream"
#include "Libraries.h"
#include "thread"

int main(){
	std::thread BUNNY(BunnyHop);
	BUNNY.join();
}