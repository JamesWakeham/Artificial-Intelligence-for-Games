#include "Application2D.h"
#include "Graph.h"
#include <iostream>

int main() {


	BaseApplication* app = new Application2D();
	if (app->startup())
		app->run();
	app->shutdown();

	return 0;
}