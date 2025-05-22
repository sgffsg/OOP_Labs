#pragma once
#include <iostream>

template <typename T>
class CMyArray
{
public:
	CMyArray()
		: m_count{ 0 }
		, m_capacity{ 2 }
	{
		m_data = new T[m_capacity]();
		m_data[m_count] = T();
	};
	CMyArray(const CMyArray& other)
	{
		m_capacity = other.m_capacity;
		m_count = other.m_count;
		m_data = new T[m_capacity];
		for (size_t i = 0; i < m_capacity; i++)
		{
			m_data[i] = other.m_data[i];
		}
	};
	CMyArray(CMyArray&& other) noexcept
	{
		m_data = new T[m_capacity];
		std::swap(m_capacity, other.m_capacity);
		std::swap(m_count, other.m_count);
		std::swap(m_data, other.m_data);
	};
	~CMyArray()
	{
		delete[] m_data;
	};

	

	void AddToBack(const T& value)
	{
		if (m_count + 1 == m_capacity)
		{
			Resize(m_capacity * 2);
		}
		m_data[m_count] = value;
		m_count++;
	};
	size_t GetCount() const
	{
		return m_count;
	};
	size_t GetCapacity() const
	{
		return m_capacity;
	};
	void Resize(size_t newCapacity)
	{
		if (newCapacity < m_count)
		{
			throw std::invalid_argument("New capacity less then currnet size");
		}
		T* newData = new T[newCapacity];
		for (size_t i = 0; i < newCapacity; i++)
		{
			newData[i] = (i < m_count) ? m_data[i] : T();
		}
		delete[] m_data;
		m_data = newData;
		m_capacity = newCapacity;
	};
	void Clear()
	{
		m_capacity = 1;
		m_count = 0;
		delete[] m_data;
		m_data = new T[m_capacity];
	};
	T& operator[](size_t index)
	{
		if (index >= m_capacity)
		{
			throw std::out_of_range("Index more then capacity");
		}
		return m_data[index];
	};
	const T& operator[](size_t index) const
	{
		if (index >= m_capacity)
		{
			throw std::out_of_range("Index more then capacity");
		}
		return m_data[index];
	};

	T* begin()
	{
		return m_data;
	}

	T* end()
	{
		return m_data + m_count;
	}

	const T* begin() const
	{
		return m_data;
	}

	const T* end() const
	{
		return m_data + m_count;
	}

	std::reverse_iterator<T*> rbegin()
	{
		return std::reverse_iterator<T*>(end());
	}

	std::reverse_iterator<T*> rend()
	{
		return std::reverse_iterator<T*>(begin());
	}

	std::reverse_iterator<const T*> rbegin() const
	{
		return std::reverse_iterator<const T*>(end());
	}

	std::reverse_iterator<const T*> rend() const
	{
		return std::reverse_iterator<const T*>(begin());
	}

	CMyArray& operator=(const CMyArray& other)
	{
		if (std::addressof(other) == this)
		{
			return *this;
		}
		m_count = other.m_count;
		m_capacity = other.m_capacity;
		m_data = new T[m_capacity];
		for (size_t i = 0; i < m_capacity; i++)
		{
			m_data[i] = other.m_data[i];
		}
		return *this;
	}

	CMyArray& operator=(CMyArray&& other) noexcept
	{
		if (std::addressof(other) == this)
		{
			return *this;
		}
		delete[] m_data;
		m_data = nullptr;
		m_capacity = 2;
		m_count = 0;
		std::swap(m_data, other.m_data);
		std::swap(m_capacity, other.m_capacity);
		std::swap(m_count, other.m_count);
		return *this;
	}

private:
	size_t m_count;
	size_t m_capacity;
	T* m_data;
};
