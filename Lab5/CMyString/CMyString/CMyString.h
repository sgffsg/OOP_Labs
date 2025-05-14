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
	
	using iterator = char*;
	using const_iterator = const char*;
	using reverse_iterator = std::reverse_iterator<iterator>;
	using const_reverse_iterator = std::reverse_iterator<const_iterator>;

	iterator begin() noexcept;
	const_iterator begin() const noexcept;
	const_iterator cbegin() const noexcept;

	iterator end() noexcept;
	const_iterator end() const noexcept;
	const_iterator cend() const noexcept;

	reverse_iterator rbegin() noexcept;
	const_reverse_iterator crbegin() const noexcept;

	reverse_iterator rend() noexcept;
	const_reverse_iterator crend() const noexcept;

private:
	size_t m_length;
	size_t m_capacity;
	char* m_symbols;
};

#endif // CMYSTRING_H