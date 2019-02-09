// NetworkCheck.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include "netlistmgr.h"
#include "atlbase.h"
#include "atlcom.h"

int main()
{
	NLM_CONNECTIVITY ConnState = NLM_CONNECTIVITY_DISCONNECTED;
	CComPtr<INetworkListManager> pNLM;
	int Ret;

	std::cout << "connectivity Check";

	HRESULT hrCoinit = CoInitializeEx(NULL, COINIT_MULTITHREADED);
	HRESULT hr = CoCreateInstance(CLSID_NetworkListManager, NULL,
		CLSCTX_ALL, __uuidof(INetworkListManager), (LPVOID*)&pNLM);
	
	if (hr == S_OK)
	{
		hr = pNLM->GetConnectivity(&ConnState);
	}
	
	Ret = (int) ConnState;	
	if (ConnState & (NLM_CONNECTIVITY_IPV6_INTERNET | NLM_CONNECTIVITY_IPV4_INTERNET))
	{
		Ret = 0xFFFF;
		std::cout << "\nInternet Connected";
	}
	else
	{
		std::cout << "No Internet";
	}
	
	return Ret;
}

