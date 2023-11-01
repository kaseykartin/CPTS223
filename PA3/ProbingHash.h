#ifndef __PROBING_HASH_H
#define __PROBING_HASH_H

#include <vector>
#include <stdexcept>

#include "Hash.h"

using std::vector;
using std::pair;

// Can be used for tracking lazy deletion for each element in your table
enum EntryState {
    EMPTY = 0,
    VALID = 1,
    DELETED = 2
};

template<typename K, typename V>
class ProbingHash : public Hash<K, V> { // derived from Hash
private:
    vector<pair<pair<K, V>, EntryState>> m_table;
    int count;

public:
    ProbingHash(int n = 11);

    ~ProbingHash();

    int size();

    V operator[](const K& key);

    bool insert(const std::pair<K, V>& pair);

    void erase(const K& key);

    void clear();

    int bucket_count();

    float load_factor();

private:
    int findNextPrime(int n);

    int isPrime(int n);

    int hash(const K& key);

    void initializeTable(int n); //using seperate function for constructor cause i kept getting weird error, not sure why this fixed it tbh

    void rehash(void);
};


/////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////PUBLIC FUNCTIONS/////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////

template<typename K, typename V>
ProbingHash<K, V>::ProbingHash(int n)
{
    this->initializeTable(n);
}

template<typename K, typename V>
ProbingHash<K, V>::~ProbingHash()
{
    this->initializeTable(0);
}

template<typename K, typename V>
int ProbingHash<K, V>::size()
{
    return this->count;
}

template<typename K, typename V>
V ProbingHash<K, V>::operator[](const K& key)
{
    int keyIndex = hash(key), size = this->m_table.size();

    for (int i = 0; i < size; i++)
    {
        if ((this->m_table[keyIndex].first.first == key) && (this->m_table[keyIndex].second == VALID))
        {
            return this->m_table[keyIndex].first.second;
        }
        
        keyIndex = (keyIndex + 1) % keyIndex;

    }

    return -1;
}

template<typename K, typename V>
bool ProbingHash<K, V>::insert(const std::pair<K, V>& pair)
{
    //get hash for key
    int keyIndex = hash(pair.first);

    //find next open spot in table
    while (m_table[keyIndex].second == EMPTY && m_table[keyIndex].first != pair)
    {
        keyIndex++;
        keyIndex %= this->count;
    }

    //add one to count if item is added
    if (m_table[keyIndex].second != VALID)
    {
        count++;
    }

    m_table[keyIndex].first = pair;
    m_table[keyIndex].second = VALID;

    //rehash if necessary
    if (this->load_factor() > 0.75)
    {
        this->rehash();
    }

    return true;
}

template<typename K, typename V>
void ProbingHash<K, V>::erase(const K& key)
{
    //get hash for key
    int keyIndex = hash(key), count = 0;

    while (count < m_table.size())
    {
        if (m_table[keyIndex].first.first == key)
        {
            this->m_table[keyIndex].second = DELETED;
            this->count -= 1;
            return;
        }
        keyIndex = (keyIndex + 1) % m_table.size();
        count++;
    }

}

template<typename K, typename V>
void ProbingHash<K, V>::clear()
{
    this->initializeTable(0);
}

template<typename K, typename V>
int ProbingHash<K, V>::bucket_count()
{
    return this->m_table.size();
}

template<typename K, typename V>
float ProbingHash<K, V>::load_factor()
{
    return (float)count / (float)m_table.size();
}



/////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////PRIVATE FUNCTIONS/////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////
template<typename K, typename V>
int ProbingHash<K, V>::findNextPrime(int n)
{
    while (!isPrime(n))
    {
        n++;
    }
    return n;
}

template<typename K, typename V>
int ProbingHash<K, V>::isPrime(int n)
{
    for (int i = 2; i <= sqrt(n); i++)
    {
        if (n % i == 0)
        {
            return false;
        }
    }

    return true;
}

template<typename K, typename V>
int ProbingHash<K, V>::hash(const K& key)
{
    return key % this->m_table.size();
}

template<typename K, typename V>
void ProbingHash<K, V>::initializeTable(int n)
{
    this->m_table.clear(); //clear the table
    this->count = 0;       //clear the count
    this->m_table.resize(n); //resize to specified prime
}

template<typename K, typename V>
void ProbingHash<K, V>::rehash(void)
{
    int size = this->m_table.size();
    vector<pair<K, V>> items;

    for (int i = 0; i < size; ++i)
    {
        if (this->m_table[i].second == VALID)
        {
            items.push_back(this->m_table[i].first);
        }
    }

    initializeTable(findNextPrime(size * 2));

    size = items.size();

    for (int i = 0; i < size; ++i)
    {
        insert(items[i]);
    }
}

#endif //__PROBING_HASH_H
