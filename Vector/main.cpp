#include <iostream>
#include <stdio.h> 
#include <stdlib.h> 

//- добавление элемента после последнего;
//-добавление элемента перед первым; 
//-добавление элемента по порядку;
//-удаление элемента с указанной информационной частью;
//-поиск элемента;
//-удаление всех элементов;
//-сортировка элементов;
//-упорядочение текущего элемента(предполагается, что все остальные элементы упорядочены);
//-перегруженный оператор !, определяющий существование элементов в структуре данных;

//-копирование структуры данных с помощью перегруженного оператора присваивания;
//-перегруженный оператор[] при написании класса для работы с массивом;
//-получение количества элементов в массиве;
//-возможность пользователя изменять количество зарезервированной под новые элементы памяти;
//-автоматическое определение количества зарезервированной под новые элементы памяти на основании размера одного элемента.

template <typename T>
class dynamic_array
{
private:
	size_t m_size;
	size_t m_capacity;
	T* m_data;

	void MemAllocation(const size_t ElementsAmount) 
	{
		m_data = static_cast<T*>(realloc(m_data, ElementsAmount * sizeof(T)));
	}

public:
	dynamic_array() : m_size(0), m_capacity(1)
	{
		m_data = static_cast<T*>(malloc(m_capacity * (sizeof(T))));
		if (m_data == NULL)
			std::cout << "Memory was not allocated\n";
	}
	dynamic_array(const size_t Size) : m_size(Size), m_capacity(m_size * 1.5)
	{
		m_data = static_cast<T*>(malloc(m_capacity * sizeof(T)));
		if (m_data == NULL)
		{
			std::cout << "Memory was not allocated\n";
		}

		for (size_t i = 0; i < m_size; i++)
		{
			m_data[i] = 0;
		}

	}
	dynamic_array(const dynamic_array& Obj);
	dynamic_array& operator=(const dynamic_array& Obj);
	~dynamic_array()
	{
		free(m_data);
	}

	T& operator[](const size_t Index) 
	{
		if (Index > m_size - 1)
		{
			throw std::range_error("Out of range");
		}	
		return m_data[Index];
	}

	bool operator!() 
	{
		return m_size == 0 ? true : false;
	}

	size_t size() const noexcept
	{
		return m_size;
	}
	void resize(const size_t NewSize)
	{
		m_size = NewSize;
		m_capacity = NewSize;
		MemAllocation(NewSize);

		for (size_t i = 0; i < m_size; i++)
		{
			m_data[i] = 0;
		}
	}
	void reserve(const size_t Capacity)
	{
		if (Capacity > m_capacity)
		{
			m_capacity = Capacity;
			MemAllocation(m_capacity);
		}
	}

	void push_back(const T Value) noexcept
	{
		if (m_size == m_capacity)
		{
			m_capacity = ceil(m_capacity * 1.5);
			MemAllocation(m_capacity);
		}
		
		m_data[m_size] = Value;
		m_size++;
	}
	void push_front(const T Value) noexcept
	{
		if (m_size == m_capacity)
		{
			m_capacity = ceil(m_capacity * 1.5);
			MemAllocation(m_capacity);
		}
		
		memmove(m_data + 1, m_data, m_size * sizeof(T));
		m_size++;
		m_data[0] = Value;
	}

	void insert(const T Value, size_t Position);
	
	void erase(const T Value);
	void clean() noexcept
	{
		memset(m_data, 0, m_size * sizeof(T));
		m_size = 0;
	}

	T& search(const T Value) const;

	void sort();
	void order_element(const T value);

};

int main()
{


	system("pause");
	return 0;
}


