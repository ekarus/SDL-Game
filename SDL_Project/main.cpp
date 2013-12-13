#include "CApp.h"
#include "CGame.h"
#include <iostream>
#include "CLogger.h"

int main(int argc, char** argv)
{
	try
	{
		AppSingleton::Instance()->onExecute();
	}
	catch(const std::exception& exception)
	{
		LOG_ERROR(exception.what());
		assert(false);
	}
	catch(...)
	{
		LOG_ERROR("catch (...)");
		assert(false);
	}
	return 0;
}