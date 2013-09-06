#include "CApp.h"
#include "CGame.h"

int main(int argc, char** argv)
{
	CApp::getInstance()->onExecute();
	return 0;
}