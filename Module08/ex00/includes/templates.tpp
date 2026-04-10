template <typename T>
typename T::iterator	easyfind(T& arr, int n)
{
	typename T::iterator	itContainer;
	itContainer = std::find(arr.begin(), arr.end(), n);

	if (itContainer != arr.end())
	{
		std::cout << "number found at position: " << std::distance(arr.begin(), itContainer) << std::endl;
		return (itContainer);
	}
	throw std::out_of_range("Number not found");
}