#include<stdio.h>
#include<Windows.h>

WINAPI subMain(LPVOID lpThreadParameter)	// dong nay bat buoc
{
	while (TRUE)
	{
		printf("[%s] Xin chao\n", __func__);
		Sleep(2000);
	}
}

void main()
{
	CreateThread(NULL, 128, subMain, NULL, 0, NULL);
	while (TRUE)
	{
		printf("[%s] Say hello\n", __func__);
		Sleep(1000);
	}
}
