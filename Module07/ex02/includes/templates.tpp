template <typename T>
Array<T>::Array() : _data(NULL), _size(0) {}

template <typename T>
Array<T>::Array(unsigned int n) : _size(n)
{
	if (n > 0)
		_data = new T[n]();
	else
		_data = NULL;
}

template <typename T>
Array<T>::Array(const Array& copy) : _size(copy._size)
{
	if (_size > 0)
	{
		_data = new T[_size];
		for (unsigned int i = 0; i < _size; i++)
			_data[i] = copy._data[i];
	}
	else
		_data = NULL;
}

template <typename T>
Array<T>&	Array<T>::operator=(const Array& copy)
{
	if (this != &copy)
	{
		delete[] _data;
		_size = copy._size;
		if (_size > 0)
		{
			_data = new T[_size];
			for (unsigned int i = 0; i < _size; i++)
				_data[i] = copy._data[i];
		}
		else
			_data = NULL;
	}
	return (*this);
}

template <typename T>
Array<T>::~Array() { delete[] _data; }

template <typename T>
T&	Array<T>::operator[](unsigned int i)
{
	if (i >= _size)
		throw std::out_of_range("Position out of range");
	return (_data[i]);
}

template <typename T>
const T&	Array<T>::operator[](unsigned int i) const
{
	if (i >= _size)
		throw std::out_of_range("Position out of range");
	return (_data[i]);
}

template <typename T>
unsigned int	Array<T>::size() const
{
	return (_size);
}
