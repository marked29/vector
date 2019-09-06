#include <iostream>
#include <vector>



template <typename T>
class dynamic_array
{
private:
	size_t m_capacity;
	size_t m_size;
	T* data;

	bool MemAllocation();

public:
	dynamic_array(const dynamic_array& Obj);

	dynamic_array& operator=(dynamic_array& Obj);

	T& operator[](const size_t Index);

	size_t size() const noexcept;
	void resize(const size_t Size);
	void reserve(const size_t Size);

	void push_back(const T& Value);
	void push_front(const T& Value);
	void emplace(const T& Value, size_t Position);
	
	void erase(const T& Value);

	T& search(const T& Value) const;

	void sort();

	bool operator!();
};

template<typename T>
bool dynamic_array<T>::MemAllocation()
{
	m_data = (T*)realloc(m_data, m_size);
	
}

int main()
{
	
	std::vector<int> as;

	system("pause");
	return 0;
}


