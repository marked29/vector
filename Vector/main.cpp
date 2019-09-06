#include <iostream>
#include <vector>

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
	size_t m_capacity;
	size_t m_size;
	T* data;

	bool MemAllocation();

public:
	dynamic_array();
	dynamic_array(const size_t Size);
	dynamic_array(const dynamic_array& Obj);
	dynamic_array& operator=(const dynamic_array& Obj);
	~dynamic_array();

	T& operator[](const size_t Index);
	bool operator!();

	size_t size() const noexcept;
	void resize(const size_t Size);
	void reserve(const size_t Size);

	void push_back(const T Value);
	void push_front(const T Value);
	void emplace(const T Value, size_t Position);
	
	void erase(const T Value);
	void clean();

	T& search(const T Value) const;

	void sort();
	void order_element(const T value);

};

int main()
{


	system("pause");
	return 0;
}


