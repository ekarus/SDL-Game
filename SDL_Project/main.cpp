#include "CApp.h"
#include "CGame.h"

int main(int argc, char** argv)
{
	CApp::Instance()->onExecute();
	return 0;
}