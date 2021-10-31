#ifndef ARRAYINT_H
#define ARRAYINT_H

#include <cassert>

class ArrayInt
{
private:
    int m_length;
    int* m_data;

public:
    ArrayInt() :
        m_length(0), m_data(nullptr)
    {
    }

    ArrayInt(int length) :
        m_length(length)
    {
        assert(length >= 0);
        if (length > 0)
            m_data = new int[length];
        else
            m_data = nullptr;
    }

    ~ArrayInt()
    {
        delete[] m_data;
    }

    void erase()
    {
        delete[] m_data;
        m_data = nullptr;
        m_length = 0;
    }

    int& operator[](int index)
    {
        assert(index >= 0 && index < m_length);
        return m_data[index];
    }

    void resize(int newLength)
    {     
        if (newLength == m_length)
            return;

        if (newLength <= 0)
        {
            erase();
            return;
        }

        int* data = new int[newLength];

        if (m_length > 0)
        {
            int elementsToCopy = (newLength > m_length) ? m_length : newLength;

        for (int index = 0; index < elementsToCopy; ++index)
                data[index] = m_data[index];
        }

        delete[] m_data;

        m_data = data;
        m_length = newLength;
    }

    void insertBefore(int value, int index)
    {
 
        assert(index >= 0 && index <= m_length);

        int* data = new int[m_length + 1];

        for (int before = 0; before < index; ++before)
            data[before] = m_data[before];

        data[index] = value;

        for (int after = index; after < m_length; ++after)
            data[after + 1] = m_data[after];

        delete[] m_data;
        m_data = data;
        ++m_length;
    }

  
    void insertAtBeginning(int value) { insertBefore(value, 0); }
    void insertAtEnd(int value) { insertBefore(value, m_length); }
    void sort() {
        for (int iteration = 0; iteration < m_length - 1; ++iteration)
        {
            // Перебираем каждый элемент массива до последнего элемента (не включительно).
            // Последний элемент не имеет пары для сравнения
            for (int currentIndex = 0; currentIndex < m_length - 1; ++currentIndex)
            {
                // Если текущий элемент больше элемента, следующего за ним, то меняем их местами
                if (m_data[currentIndex] > m_data[currentIndex + 1])
                    std::swap(m_data[currentIndex], m_data[currentIndex + 1]);
            }
        }
    }
    int getLength() { return m_length; }
    void print() {
        for (int i = 0; i < getLength(); i++)
            std::cout << m_data[i] << " ";
        std::cout << std::endl;
    }
};

#endif