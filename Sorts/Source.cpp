#include<iostream>
#include "Sorts.h"
#include <ctime>
#include <cstdio>
#include <cstdlib>
#include <Windows.h>
using namespace std;

int main()
{
	Sorts<int> a = Sorts<int>(100, false);
	a.display();
	DWORD start = GetTickCount();
	a.mergeSort();
	DWORD stop = GetTickCount();
	cout << endl << stop-start<<endl;
	a.display();
	cout << endl;
}


