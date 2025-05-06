#ifndef CMYSTRING_H
#define CMYSTRING_H

#include <iostream>

class CMyString
{
public:
	CMyString();
	CMyString(const char* pString);
	CMyString(const char* pString, size_t length);
	CMyString(CMyString const& other);
	CMyString(CMyString&& other) noexcept;
	CMyString(std::string const& stlString);
	~CMyString();

	void Clear();
	size_t GetLength() const;
	size_t GetCapacity() const;
	const char* GetStringData() const;
	CMyString SubString(size_t start, size_t length = SIZE_MAX) const;
	
	

	CMyString& operator=(CMyString const& other);
	CMyString& operator=(CMyString&& other) noexcept;
	CMyString& operator+=(CMyString const& other);

	char& operator[](size_t index);
	const char& operator[](size_t index) const;

	friend CMyString operator+(CMyString const& myStr, CMyString const& str);
	friend CMyString operator+(std::string const& str, CMyString const& myStr);
	friend CMyString operator+(char const* myStr, CMyString const& str);
	friend CMyString operator+(CMyString const& myStr, std::string const& str);
	friend CMyString operator+(CMyString const& myStr, char const* str);

	friend bool operator>(CMyString const& myStr, CMyString const& str);
	friend bool operator<(CMyString const& myStr, CMyString const& str);
	friend bool operator==(CMyString const& myStr, CMyString const& str);
	friend bool operator!=(CMyString const& myStr, CMyString const& str);
	friend bool operator>=(CMyString const& myStr, CMyString const& str);
	friend bool operator<=(CMyString const& myStr, CMyString const& str);

	friend std::ostream& operator<<(std::ostream& stream, CMyString const& myString);
	friend std::istream& operator>>(std::istream& stream, CMyString& myString);
	
	
	

	class iterator
	{
	public:
		iterator(char* point, int pos)
			: m_ptr{ point }
			, m_pos{ pos } {};
		char& operator*() { return *m_ptr; };
		char* operator->() { return m_ptr; };
		iterator& operator++()
		{
			++m_ptr;
			return *this;
		};
		iterator operator++(int)
		{
			iterator temp(*this);
			++temp;
			return temp;
		};
		bool operator==(const iterator& other) { return m_ptr == other.m_ptr; }
		bool operator!=(const iterator& other) { return m_ptr != other.m_ptr; }

	private:
		char* m_ptr;
		int m_pos;
	};

	iterator Begin();
	iterator End();
	iterator CBegin() const;
	iterator CEnd() const;
	
private:
	size_t m_length;
	size_t m_capacity;
	char* m_symbols;
};

#endif // CMYSTRING_H