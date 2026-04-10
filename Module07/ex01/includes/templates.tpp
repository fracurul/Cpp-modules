template <typename T, typename F>
void	iter(T* arr, const int size, F func)
{
	for (int i = 0; i < size; i++)
		func(arr[i]);
}

template <typename T, typename F>
void	iter(const T* arr, const int size, F func)
{
	for (int i = 0; i < size; i++)
		func(arr[i]);
}

template <typename T>
void	print(T const& arr)
{
	std::cout << arr << std::endl;
}