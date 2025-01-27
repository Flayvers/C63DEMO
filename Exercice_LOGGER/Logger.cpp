#include "Logger.h"
#include <fstream>
#include <iostream>
#include <string>


using namespace std;

LoopEngine::Logger::Logger(const TLevel InLoggingLevel, bool InConsoleTraceActive, bool InFileTraceActive)
{
}

LoopEngine::Logger::~Logger()
{
}

void LoopEngine::Logger::ActivateConsoleTrace(bool InIsActive)
{
	if (_IsConsoleTraceActive != InIsActive)
	{
		_IsConsoleTraceActive = InIsActive;
	}
}

void LoopEngine::Logger::SetLoggingLevel(const TLevel InLoggingLevel)
{
	_LoggingLevel = InLoggingLevel;
}

void LoopEngine::Logger::Log(string msg, const TLevel InLoggingLevel) const
{
	string logMessage = "";

	switch(InLoggingLevel)
	{
	case eINFO:
		logMessage += "Info";
		break;
	case eWARNING:
		logMessage += "Warning";
		break;
	case eDEBUG:
		logMessage += "Debug";
		break;
	case eERROR:
		logMessage += "Error";
		break;
	default:
			break;
	}
		
	logMessage += msg;

	if (_IsFileTraceActive)
	{
		if (TryOpenFile())
		{ 

			TryCloseFile()
		}

	}
	if (_IsConsoleTraceActive)
	{
		cout << logMessage << endl;
	}
}

void LoopEngine::Logger::ActivateFileTrace(bool InIsActive)
{
	if (_IsFileTraceActive != InIsActive)
	{
		_IsFileTraceActive = InIsActive;
	}
	
}

void LoopEngine::Logger::ActivateFileTrace(bool InIsActive, const string& InFileName)
{
	ActivateFileTrace(InIsActive);
	SetFileTraceName(InFileName);
}

void LoopEngine::Logger::SetFileTraceName(const string InFileTraceName)
{
	_TraceFileName = InFileTraceName;
	TryOpenFile();
}

void LoopEngine::Logger::SetAbortLevel(const TLevel InAbortLevel)
{
	_AbortLevel = InAbortLevel;
}

bool LoopEngine::Logger::TryOpenFile()
{
	_ptrFileStream("example.txt");
	if (_ptrFileStream.is_open())
	{
		return true;
	}
	else
	{
		ActivateConsoleTrace(true);
		Log("Unable to open file", eERROR);
	}
	return false;
}

bool LoopEngine::Logger::TryCloseFile()
{

	return false;
}
