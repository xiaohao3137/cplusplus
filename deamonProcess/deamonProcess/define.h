#pragma once
#include "targetver.h"
#include <Windows.h>
#include <string>
#include <map>
typedef struct  {
	std::string type;
	 int ID;
}StopAction;
struct runItem {
	std::string cmd;
	std::string dir;
	StopAction stop;
};

typedef std::map<std::string, runItem>  MapRun;
typedef std::map<std::string, HANDLE>  MapHandle;

typedef struct {
	HANDLE handle;
	HWND   hwnd;
}ProcessParam,*lProcessParam;
bool CALLBACK YourEnumProc(HWND hWnd, LPARAM lParam)
{
	DWORD dwProcessId;
	GetWindowThreadProcessId(hWnd, &dwProcessId);
	getwindows
	lProcessParam pInfo = (lProcessParam)lParam;

	if (dwProcessId == pInfo->dwProcessId)
	{
		pInfo->hWnd = hWnd;
		return FALSE;
	}
	return TRUE;

}

HWND GetProcessMainWnd(HANDLE dwProcessId)
{
	WNDINFO wi;
	wi.dwProcessId = dwProcessId;
	wi.hWnd = NULL;
	EnumWindows(YourEnumProc, (LPARAM)&wi);
	return wi.hWnd;
}
