

template <typename T>
linkedList<T>::linkedList()
{
	m_front= nullptr;
	m_size = 0;
}

template <typename T>
linkedList<T>::~linkedList()
{
	while(!isEmpty())
	{
		removeFront();
	}
}

template <typename T>
bool linkedList<T>::isEmpty() const
{
	//returns true if list is empty
	//returns false otherwise
	if(m_size == 0)
	{
		return(true);
	}
	else
	{
		return(false);
	}

}


template <typename T>
int linkedList<T>::size() const
{
	return(m_size);
}

template <typename T>
bool linkedList<T>::search(T value) const
{
	node<T>* tempNode = m_front; //pointer to headnode //pointer to headnode

	//returns true if the value exists in any node
	//returns false otherwise
	if(m_size == 0)
	{
		return(false);
	}
	else
	{
		do
		{
			if(tempNode -> getValue() == value)
			{
				return(true);
			}
			tempNode = tempNode -> getNext();

		}while(tempNode-> getNext() != nullptr);

		if(tempNode -> getValue() == value)
		{
				return(true);
		}
		return(false);
	}
}

template <typename T>
void linkedList<T>::printList() const
{

	node<T>* temp = m_front;

	if(temp == nullptr)
	{
		std::cout << "Nothing here to print. Empty List...";
	}
	else
	{
		while(temp != nullptr)
		{
			std::cout << "Event Info: " << temp->getValue().getYear() << " " <<
			temp->getValue().getMonth() << " " << temp->getValue().getDay() << " " <<
			temp->getValue().getTime() << " " << temp->getValue().getEvent() << " " <<
			temp->getValue().getAttendance() << '\n' << '\n';

			temp = temp->getNext();
		}
	}
}

template <typename T>
void linkedList<T>::addBack(T value)
{
	node<T>* temp = nullptr;

	if(isEmpty())
	{
		m_front = new node<T>(value);
	}
	else
	{
		temp = m_front;
		while(temp->getNext() != nullptr)
		{
			temp = temp->getNext();
		}
		temp->setNext(new node<T>(value));
	}
	m_size++;
}

template <typename T>
void linkedList<T>::addFront(T value)
{
	node<T>* temp = m_front;
	m_front = new node<T>(value);
	m_front->setNext( temp );
	m_size++;
}


template <typename T>
void linkedList<T>::sortList()
{
  node<T>* currentNode = nullptr;
  node<T>* prevNode = nullptr;
  node<T>* temp = nullptr;

	if(size() == 1)
	{
		//no need to sort
	}
	else if(size() == 2)
	{
		currentNode = m_front;
		if (compareDates(currentNode->getValue(), currentNode->getNext()->getValue()) == true)
		{
			addBack(currentNode->getValue());
			removeFront();
		}
	}
	else
	{
		for(int i = 0; i <= size(); i++)
		{
			currentNode = m_front;
			prevNode = m_front;

	    while(currentNode->getNext() != nullptr)
		{
	      if (compareDates(currentNode->getValue(), currentNode->getNext()->getValue()) == true)
			{
	        temp = currentNode->getNext();
	        currentNode->setNext(currentNode->getNext()->getNext());
	        temp->setNext(currentNode);

	        if(currentNode == m_front)
					{
						prevNode = temp;
						m_front = prevNode;
					}
	        else
					{
						prevNode->setNext(temp);
	        	currentNode = temp;
					}
	    	}
	      prevNode = currentNode;
	      currentNode = currentNode->getNext();
	    }
	  }
	}
}

template <typename T>
bool linkedList<T>::compareDates(T value0, T value1)
{
	bool comparer = false;

	if(value0.initial_year < value1.initial_year)
	{
		comparer = true;
		return(comparer);
	}
	if(value0.initial_year == value1.initial_year && value0.initial_month < value1.initial_month)
	{
		comparer = true;
		return(comparer);
	}
	if(value0.initial_year == value1.initial_year && value0.initial_month == value1.initial_month && value0.initial_day < value1.initial_day)
	{
		comparer = true;
		return(comparer);
	}

	return(comparer);
}

template <typename T>
bool linkedList<T>::removeBack()
{
	node<T>* lastNode = nullptr;
	node<T>* secondintoLast = nullptr;
	bool isRemoved = false;

	if(m_size==0)
	{
		isRemoved = false;
	}
	else
	{
		lastNode = m_front;
		secondintoLast = m_front;

		while(lastNode-> getNext() != nullptr)
		{
			lastNode = lastNode -> getNext();
			if(lastNode-> getNext() != nullptr)
			{
				secondintoLast = secondintoLast -> getNext();
			}
		}

		delete(lastNode);
		secondintoLast -> setNext(nullptr);
		lastNode = nullptr;
		m_size--;
		isRemoved = true;

	}

	return(isRemoved);
}

template <typename T>
bool linkedList<T>::removeFront()
{
	node<T>* temp = nullptr;
	bool isRemoved = false;

	if(!isEmpty())
	{
		temp = m_front;
		m_front = temp->getNext();
		delete temp;
		m_size--;
		isRemoved = true;
	}

	return(isRemoved);
}

template <typename T>
std::vector<T> linkedList<T>::toVector() const
{
	std::vector<T> vec;
	node<T>* temp = m_front;

	while( temp != nullptr )
	{
		vec.push_back(temp->getValue());
		temp = temp->getNext();
	}

	return(vec);

}

template<typename T>
bool linkedList<T>::insert(int position, T value)
{

  if(position > m_size || position < 1)
  {
	  return(false);
  }
  else if(position == 1) //If the position is at the front we use addfront instead
  {
    addFront(value);
    return(true);

  }
  else
  {
    node<T>* newNode = new node<T>(value);
    node<T>* temp = m_front;
    int tempPos = 1;

    while(tempPos < (position-1))
    {
		temp = temp->getNext();
		tempPos++;
    }
    newNode->setNext(temp->getNext());
    temp->setNext(newNode);
	m_size++; //Keeps track of the length
    return(true);
  }
}

template<typename T>
T linkedList<T>::getEntry(int position) const
{
	node<T>* temp = m_front;
	int tempPos = 1;
	while(tempPos < position) //Traverses list and gets entry
	{
		temp = temp->getNext();
		tempPos++;
	}
	return temp->getValue();
}
