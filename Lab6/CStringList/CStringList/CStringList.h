#pragma once
#include <iostream>
#include "CStringListOutOfRangeError.h"

struct Node
{
	std::string str;
	Node* next = nullptr;
	Node* prev = nullptr;
	bool operator==(const Node& other) { return (str == other.str && next == other.next && prev == other.prev); };
	bool operator!=(const Node& other) { return (str != other.str || next != other.next || prev != other.prev); };
};

class CStringList
{
public:
	class CIterator : public std::iterator<std::bidirectional_iterator_tag, Node>
	{
	public:
		typedef std::string& references;
		typedef Node* pointer;

		CIterator()
			: m_ptr(nullptr)
		{
		};

		CIterator(Node* ptr)
			: m_ptr{ ptr }
		{
		}

		~CIterator()
		{
			m_ptr = nullptr;
		}

		references operator*();
		pointer operator->();
		bool operator==(const CIterator& other);
		bool operator!=(const CIterator& other);
		CIterator& operator++();
		CIterator operator++(int);
		CIterator& operator+=(int value);
		CIterator& operator--();
		CIterator operator--(int);
		CIterator& operator-=(int value);
		CIterator operator+(int value);
		CIterator operator-(int value);

	private:
		Node* m_ptr;
	};

	class CRIterator : public std::reverse_iterator<CStringList::CIterator>
	{
	public:
		CRIterator()
			: m_ptr(nullptr)
		{
		};

		CRIterator(Node* ptr)
			: m_ptr(ptr)
		{
		}

		~CRIterator()
		{
			m_ptr = nullptr;
		}

		std::string operator*();
		Node* operator->();
		
		bool operator==(const CRIterator& other);
		bool operator!=(const CRIterator& other);
		
		CRIterator& operator++();
		CRIterator operator++(int);
		CRIterator& operator--();
		CRIterator operator--(int);

	private:
		Node* m_ptr;
	};

	CStringList();
	CStringList(const CStringList& other);
	CStringList(CStringList&& other) noexcept;
	~CStringList();

	void AddStrToBegin(const std::string& str);
	void AddStrToEnd(const std::string& str);
	void AddStrToPos(CStringList::CIterator pos, const std::string& str);
	void RemoveStrInPos(CStringList::CIterator pos);
	int GetCount() const;
	bool IsEmpty() const; 
	void Clear();

	std::string operator[](int index);

	CIterator begin();
	CIterator end();
	CIterator begin() const;
	CIterator end() const;
	
	CRIterator rbegin();
	CRIterator rend();
	CRIterator rbegin() const;
	CRIterator rend() const;

private:
	int m_count;
	Node* m_firstPtr;
	Node* m_lastPtr;
};
