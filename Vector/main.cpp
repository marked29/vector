#include <iostream>
#include <vector>

//- ���������� �������� ����� ����������;
//-���������� �������� ����� ������; 
//-���������� �������� �� �������;
//-�������� �������� � ��������� �������������� ������;
//-����� ��������;
//-�������� ���� ���������;
//-���������� ���������;
//-������������ �������� ��������(��������������, ��� ��� ��������� �������� �����������);
//-������������� �������� !, ������������ ������������� ��������� � ��������� ������;

//-����������� ��������� ������ � ������� �������������� ��������� ������������;
//-������������� ��������[] ��� ��������� ������ ��� ������ � ��������;
//-��������� ���������� ��������� � �������;
//-����������� ������������ �������� ���������� ����������������� ��� ����� �������� ������;
//-�������������� ����������� ���������� ����������������� ��� ����� �������� ������ �� ��������� ������� ������ ��������.

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


