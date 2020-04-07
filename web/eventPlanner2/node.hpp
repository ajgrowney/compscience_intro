template <typename T>
node<T>::node(T value) : m_value(value), m_next(nullptr)
{
	m_next = nullptr;
}

template <typename T>
T node<T>::getValue() const
{
	return(m_value);
}

template <typename T>
void node<T>::setValue(T value)
{
	m_value = value;
}

template <typename T>
node<T>* node<T>::getNext() const
{
	return(m_next);
}

template <typename T>
void node<T>::setNext(node<T>* next)
{
	m_next = next;
}
