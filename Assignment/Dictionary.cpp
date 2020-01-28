#include "pch.h"
#include "Dictionary.h"
#include <math.h>

Dictionary::Dictionary()
{
	int arr[MAX_SIZE];
}


Dictionary::~Dictionary()
{
}

int Dictionary::hash(KeyType key)
{
	int sum = 0;
	int size = (int)key.length();
	for (int i = 0; i < size; i++)
	{
		char c = key[i];
		int ascii;
		if (isupper(c))
			ascii = key[i] - 65;
		else
			ascii = key[i] - 71;
		sum += ascii * (int)pow((double)52, (double)(size - i - 1));
		cout << sum << " ";
	}
	return sum % size;
}

bool Dictionary::add(KeyType newKey, ItemType newItem)
{
	int index = hash(newKey);
	if ()
	{

	}
}

void Dictionary::remove(KeyType key)
{
}

ItemType Dictionary::get(KeyType key)
{
	return ItemType();
}

bool Dictionary::isEmpty()
{
	return size == 0;
}

int Dictionary::getLength()
{
	return size;
}

void Dictionary::print()
{
}
