#pragma once
#pragma once
#include "CUrlParsingError.h"

enum class Protocol
{
	HTTP,
	HTTPS
};

std::ostream& operator<<(std::ostream& out, Protocol protocol);

class CHttpUrl
{
public:

	CHttpUrl(std::string const& url);
	CHttpUrl(std::string const& domain, std::string const& document, Protocol protocol = Protocol::HTTP);
	CHttpUrl(std::string const& domain, std::string const& document, Protocol protocol, unsigned short port);

	std::string GetURL() const;
	std::string GetDomain() const;
	std::string GetDocument() const;
	Protocol GetProtocol() const;
	unsigned short GetPort() const;

private:
	Protocol m_protocol;
	std::string m_domain;
	std::string m_document;
	unsigned short m_port;
	bool IsDomainValid(const std::string& domain);
	bool IsDocumentValid(const std::string& document);
	Protocol GetProtocolByString(const std::string& str);
	unsigned short ParsePort(const std::string& portStr);
	static std::string StrToLowerCase(const std::string& str);
};
