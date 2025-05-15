#include "CStringList.h"

CStringList::CStringList()
{
	m_count = 0;
	m_firstPtr = nullptr;
	m_lastPtr = new Node;
}

CStringList::CStringList(const CStringList& other)
{
	m_count = other.m_count;

	for (const auto& str : other)
	{
		AddStrToEnd(str);
	}
}

CStringList::CStringList(CStringList&& other) noexcept
{
	m_count = 0;
	m_firstPtr = nullptr;
	m_lastPtr = nullptr;
	std::swap(m_count, other.m_count);
	std::swap(m_firstPtr, other.m_firstPtr);
	std::swap(m_lastPtr, other.m_lastPtr);
}

CStringList::~CStringList()
{
	Clear();
}

void CStringList::AddStrToBegin(const std::string& str)
{
	Node* ptr;
	ptr = new Node;
	ptr->str = str;
	if (m_firstPtr == nullptr)
	{
		m_firstPtr = ptr;
		ptr->next = m_lastPtr;
		m_lastPtr->prev = m_firstPtr;
	}
	else
	{
		m_firstPtr->prev = ptr;
		ptr->next = m_firstPtr;
		m_firstPtr = ptr;
	}
	m_count++;
}

void CStringList::AddStrToEnd(const std::string& str)
{
	Node* ptr;
	ptr = new Node;
	ptr->str = str;
	if (m_firstPtr == nullptr)
	{
		m_firstPtr = ptr;
		ptr->next = m_lastPtr;
		m_lastPtr->prev = m_firstPtr;
	}
	else
	{
		Node* prev = m_lastPtr->prev;
		prev->next = ptr;
		ptr->prev = prev;
		ptr->next = m_lastPtr;
		m_lastPtr->prev = ptr;
	}
	m_count++;
}

void CStringList::AddStrToPos(CStringList::CIterator pos, const std::string& str)
{
	if (pos == m_lastPtr)
	{
		AddStrToEnd(str);
		return;
	}
	if (pos == m_firstPtr)
	{
		AddStrToBegin(str);
		return;
	}

	Node* ptr;
	ptr = new Node;
	ptr->str = str;

	Node* prev;
	prev = pos->prev;

	ptr->next = prev->next;
	ptr->prev = prev;
	prev->next = ptr;
	pos->prev = ptr;

	m_count++;
}

void CStringList::RemoveStrInPos(CStringList::CIterator pos)
{
	if (pos == m_lastPtr)
	{
		throw CStringListOutOfRangeError("Position to remove out of range");
	}

	if (pos == m_firstPtr)
	{
		m_firstPtr = pos->next;
	}
	else
	{
		Node* next;
		Node* prev;
		next = pos->next;
		prev = pos->prev;
		next->prev = prev;
		prev->next = next;
	}

	pos->next = nullptr;
	pos->prev = nullptr;

	m_count--;
}

int CStringList::GetCount() const
{
	return m_count;
}

bool CStringList::IsEmpty() const
{
	return (m_count == 0);
}

void CStringList::Clear()
{
	Node* current = m_firstPtr;
	while (current != nullptr)
	{
		Node* next = current->next;
		delete current;
		current = next;
	}
	
	m_firstPtr = nullptr;
	m_lastPtr = nullptr;
	m_count = 0;
}

std::string CStringList::operator[](int index)
{
	return *(begin() + index);
}

#pragma region CIterator
CStringList::CIterator CStringList::begin()
{
	return CIterator(m_firstPtr);
}

CStringList::CIterator CStringList::end()
{
	return CIterator(m_lastPtr);
}

CStringList::CIterator CStringList::begin() const
{
	return CIterator(m_firstPtr);
}

CStringList::CIterator CStringList::end() const
{
	return CIterator(m_lastPtr);
}

CStringList::CIterator::references CStringList::CIterator::operator*()
{
	return m_ptr->str;
}

CStringList::CIterator::pointer CStringList::CIterator::operator->()
{
	return m_ptr;
}

bool CStringList::CIterator::operator==(const CIterator& other)
{
	return (*this->m_ptr == *other.m_ptr);
}

bool CStringList::CIterator::operator!=(const CIterator& other)
{
	return (*this->m_ptr != *other.m_ptr);
}

CStringList::CIterator& CStringList::CIterator::operator++()
{
	if (m_ptr->next == nullptr)
	{
		throw CStringListOutOfRangeError("Can not increament, iterator to last element");
	}
	this->m_ptr = this->m_ptr->next;
	return *this;
}

CStringList::CIterator CStringList::CIterator::operator++(int)
{
	CIterator temp(*this);
	++*this;
	return temp;
}

CStringList::CIterator& CStringList::CIterator::operator+=(int value)
{
	for (int i = 0; i < value; i++)
	{
		++*this;
	}

	return *this;
}

CStringList::CIterator& CStringList::CIterator::operator--()
{
	if (this->m_ptr->prev == nullptr)
	{
		throw CStringListOutOfRangeError("Can not deacreament, iterator to first element");
	}
	this->m_ptr = this->m_ptr->prev;
	return *this;
}

CStringList::CIterator CStringList::CIterator::operator--(int)
{
	CIterator temp(*this);
	--*this;
	return temp;
}

CStringList::CIterator& CStringList::CIterator::operator-=(int value)
{
	for (int i = 0; i < value; i++)
	{
		--*this;
	}

	return *this;
}

CStringList::CIterator CStringList::CIterator::operator+(int value)
{
	CIterator iter(*this);
	return iter += value;
}

CStringList::CIterator CStringList::CIterator::operator-(int value)
{
	CIterator iter(*this);
	return iter -= value;
}
#pragma endregion


#pragma region CRIterator
CStringList::CRIterator CStringList::rbegin()
{
	return CRIterator(m_lastPtr);
}

CStringList::CRIterator CStringList::rend()
{
	return CRIterator(m_firstPtr);
}

CStringList::CRIterator CStringList::rbegin() const
{
	return CRIterator(m_lastPtr);
}

CStringList::CRIterator CStringList::rend() const
{
	return CRIterator(m_firstPtr);
}

std::string CStringList::CRIterator::operator*()
{
	return m_ptr->str;
}

Node* CStringList::CRIterator::operator->()
{
	return m_ptr;
}

bool CStringList::CRIterator::operator==(const CRIterator& other)
{
	return (*this->m_ptr == *other.m_ptr);
}

bool CStringList::CRIterator::operator!=(const CRIterator& other)
{
	return (*this->m_ptr != *other.m_ptr);
}

CStringList::CRIterator& CStringList::CRIterator::operator++()
{
	if (this->m_ptr->prev == nullptr)
	{
		throw CStringListOutOfRangeError("Can not increament, iterator to last element");
	}
	this->m_ptr = this->m_ptr->prev;
	return *this;
}

CStringList::CRIterator CStringList::CRIterator::operator++(int)
{
	CRIterator temp(*this);
	++temp;
	return temp;
}

CStringList::CRIterator& CStringList::CRIterator::operator--()
{
	if (this->m_ptr->next == nullptr)
	{
		throw CStringListOutOfRangeError("Can not deacreament, iterator to first element");
	}
	this->m_ptr = this->m_ptr->next;
	return *this;
}

CStringList::CRIterator CStringList::CRIterator::operator--(int)
{
	CRIterator temp(*this);
	--temp;
	return temp;
}
#pragma endregion