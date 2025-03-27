#pragma once
#include <iostream>

enum class Protocol
{
	HTTP,
	HTTPS,
	FTP,
};

void ParseURL(const std::string& url, Protocol& protocol, int& port, std::string& host, std::string& document);