#ifndef __MEMORY_H__
#define __MEMORY_H__

#include <windows.h>
#include <stdio.h>
#include <list>

#include "process.h"
#include "threads.h"
#include "utils.h"

#define WRITABLE (PAGE_READWRITE | PAGE_WRITECOPY | PAGE_EXECUTE_READWRITE | PAGE_EXECUTE_WRITECOPY)

typedef enum _MEMORY_INFORMATION_CLASS {
    MemoryBasicInformation
} MEMORY_INFORMATION_CLASS, *PMEMORY_INFORMATION_CLASS;

BOOL ReadMemory(HANDLE hProcess, PVOID64 lpBaseAddress, LPVOID lpBuffer, SIZE_T nSize);
BOOL ReadMemory(HANDLE hProcess, LPCVOID lpBaseAddress, LPVOID lpBuffer, SIZE_T nSize);

BOOL ReadMemory(DWORD dwPid, PVOID64 lpBaseAddress, LPVOID lpBuffer, SIZE_T nSize);
BOOL ReadMemory(DWORD dwPid, LPCVOID lpBaseAddress, LPVOID lpBuffer, SIZE_T nSize);

std::list<MEMORY_BASIC_INFORMATION32> GetMemoryInformation32(DWORD dwPID);
std::list<MEMORY_BASIC_INFORMATION64> GetMemoryInformation64(DWORD dwPID);

/*BOOL ReadMemory(HANDLE hProcess, PVOID64 lpBaseAddress, LPVOID lpBuffer, SIZE_T nSize);
BOOL ReadMemory(DWORD dwPid, PVOID64 lpBaseAddress, LPVOID lpBuffer, SIZE_T nSize);
BOOL WriteMemory(HANDLE hProcess, PVOID64 lpBaseAddress, LPVOID lpBuffer, SIZE_T nSize);
BOOL WriteMemory(DWORD dwPid, PVOID64 lpBaseAddress, LPVOID lpBuffer, SIZE_T nSize);
std::list<MEMORY_BASIC_INFORMATION> GetMemoryInformation(DWORD dwPID);*/

//std::list<LPCVOID> ScanPattern(LPCVOID lpPattern, SIZE_T nSize, DWORD dwPid);

#endif // __MEMORY_H__

