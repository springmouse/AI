#include "AI_DEMOApp.h"

int main() {
	
	// allocation
	auto app = new AI_DEMOApp();

	// initialise and loop
	app->run("AIE", 1280, 720, false);

	// deallocation
	delete app;

	return 0;
}