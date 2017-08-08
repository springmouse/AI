#include "AI_DEMOApp.h"
#include "Information.h"

int main() {
	
	// allocation
	auto app = new AI_DEMOApp();

	// initialise and loop
	app->run("AIE", INFOMATION->ScreenWidth, INFOMATION->ScreenHeight, false);

	// deallocation
	delete app;

	return 0;
}