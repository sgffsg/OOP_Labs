#include <iostream>
#define CATCH_CONFIG_MAIN
#include "../../../Catch/catch.hpp"
#include "../Lab2_2/ParseURL.h"

SCENARIO("Parse url")
{

	int testPort = 0;
	std::string testHost, testDocument;
	Protocol testProtocol = Protocol::HTTP;
	

	WHEN("Url is invalid")
	{
		THEN("False")
		{
			CHECK_THROWS_WITH(ParseURL("fsfsd", testProtocol, testPort, testHost, testDocument), "Received string is not url");
		}
	}

	WHEN("Host is empty")
	{
		THEN("False")
		{
			CHECK_THROWS_WITH(ParseURL("https://:9000/smt", testProtocol, testPort, testHost, testDocument), "Received string is not url");
		}
	}

	WHEN("Url is valid")
	{
		THEN("Valid host and empty document")
		{
			std::string host;
			std::string document;
			ParseURL("https://www.youtube.com", testProtocol, testPort, host, document);
			CHECK(host == "www.youtube.com");
			CHECK(document.empty());
		}
	}

	WHEN("Port contain symbols")
	{
		THEN("Will throw exception")
		{
			CHECK_THROWS_WITH(ParseURL("http://localhost:9a00", testProtocol, testPort, testHost, testDocument), "Received string is not url");
		}
	}

	WHEN("Port is empty")
	{
		THEN("Will throw exception")
		{
			CHECK_THROWS_WITH(ParseURL("http://localhost:", testProtocol, testPort, testHost, testDocument), "Received string is not url");
		}
	}

	WHEN("Port length more then acceptable value length")
	{
		THEN("False")
		{
			CHECK_THROWS_WITH(ParseURL("https://localhost:653322536/", testProtocol, testPort, testHost, testDocument), "Received string is not url");
		}
	}

	WHEN("Port more then acceptable value")
	{
		THEN("False")
		{
			CHECK_THROWS_WITH(ParseURL("https://localhost:65536/", testProtocol, testPort, testHost, testDocument), "");
		}
	}

	WHEN("Url with port")
	{
		THEN("Valid port")
		{
			int port;
			ParseURL("https://localhost:8000/", testProtocol, port, testHost, testDocument);
			CHECK(port == 8000);
		}
	}

	WHEN("Url with document")
	{
		THEN("Valid document")
		{
			std::string document;
			ParseURL("https://vk.com/feed", testProtocol, testPort, testHost, document);
			CHECK(document == "feed");
		}
	}

	WHEN("Url with port and document")
	{
		THEN("Valid parts")
		{
			int port;
			std::string host;
			std::string document;
			ParseURL("https://localhost:3301/post/1", testProtocol, port, host, document);
			CHECK(port == 3301);
			CHECK(host == "localhost");
			CHECK(document == "post/1");
		}
	}

	WHEN("Invalid protocol")
	{
		THEN("False")
		{
			CHECK_THROWS_WITH(ParseURL("protocol://www.youtube.com", testProtocol, testPort, testHost, testDocument), "Received string is not url");
		}
	}

	WHEN("Between protocol and host invalid symbols")
	{
		THEN("False")
		{
			CHECK_THROWS_WITH(ParseURL("http:dasdadaa/yoir.com", testProtocol, testPort, testHost, testDocument), "Received string is not url");
		}
	}

	WHEN("Https protocol")
	{
		THEN("Valid protocol and port")
		{
			Protocol protocol;
			int port;
			ParseURL("https://www.youtube.com", protocol, port, testHost, testDocument);
			CHECK(protocol == Protocol::HTTPS);
			CHECK(port == 443);
		}
	}

	WHEN("Http protocol")
	{
		THEN("Valid protocol and port")
		{
			Protocol protocol;
			int port;
			ParseURL("http://www.youtube.com", protocol, port, testHost, testDocument);
			CHECK(protocol == Protocol::HTTP);
			CHECK(port == 80);
		}
	}

	WHEN("Ftp protocol")
	{
		THEN("Valid protocol and port")
		{
			Protocol protocol;
			int port;
			ParseURL("ftp://www.youtube.com", protocol, port, testHost, testDocument);
			CHECK(protocol == Protocol::FTP);
			CHECK(port == 21);
		}
	}

	WHEN("Https protocol in different register")
	{
		THEN("Valid protocol and port")
		{
			Protocol protocol;
			int port;
			ParseURL("HtTpS://www.youtube.com", protocol, port, testHost, testDocument);
			CHECK(protocol == Protocol::HTTPS);
			CHECK(port == 443);
		}
	}

	WHEN("Http protocol in different register")
	{
		THEN("Valid protocol and port")
		{
			Protocol protocol;
			int port;
			ParseURL("HtTP://www.youtube.com", protocol, port, testHost, testDocument);
			CHECK(protocol == Protocol::HTTP);
			CHECK(port == 80);
		}
	}

	WHEN("Ftp protocol in different register")
	{
		THEN("Valid protocol and port")
		{
			Protocol protocol;
			int port;
			ParseURL("FtP://www.youtube.com", protocol, port, testHost, testDocument);
			CHECK(protocol == Protocol::FTP);
			CHECK(port == 21);
		}
	}
}