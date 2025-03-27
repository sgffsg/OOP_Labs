#include "ParseURL.h"
#include <map>
#include <regex>

const std::map<std::string, Protocol> STRING_TO_PROTOCOL{
	{ "http", Protocol::HTTP },
	{ "https", Protocol::HTTPS },
	{ "ftp", Protocol::FTP }
};

const std::map<Protocol, int> DEFAULT_PORT{
	{ Protocol::HTTP, 80 },
	{ Protocol::HTTPS, 443 },
	{ Protocol::FTP, 21 }
};

const int MAX_PORT_VALUE = 65535;

std::string StringToLower(const std::string& str)
{
	std::string lowerStr;
	for (const char& c : str)
	{
		lowerStr += tolower(c);
	}

	return lowerStr;
}

Protocol GetProtocol(const std::string& protocolStr)
{
	return STRING_TO_PROTOCOL.at(StringToLower(protocolStr));
}

int GetPort(const std::string& portStr, const Protocol& protocol)
{
	if (portStr.empty())
	{
		return DEFAULT_PORT.at(protocol);
	}

	int port = std::stoi(portStr.substr(1, portStr.length() - 1));

	if (port > MAX_PORT_VALUE)
	{
		throw std::out_of_range("Some value has exceeded the acceptable range");
	}

	return port;
}

std::string GetDocument(const std::string& document)
{
	return document.empty() ? "" : document.substr(1, document.length() - 1);
}

void ParseURL(const std::string& url, Protocol& protocol, int& port, std::string& host, std::string& document)
{
	const std::regex pattern("^(https|http|ftp)://([\\w-.,]+)(:\\d{1,5})?(/.+)?/?$", std::regex_constants::icase);
	std::smatch match;

	//invalid arg
	if (!std::regex_match(url, match, pattern))
	{
		throw std::invalid_argument("Received string is not url");
	}

	protocol = GetProtocol(match[1].str());
	host = match[2].str();
	port = GetPort(match[3].str(), protocol);
	document = GetDocument(match[4].str());
}
