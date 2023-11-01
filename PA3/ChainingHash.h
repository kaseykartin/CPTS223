/*
 *  Separate chaining hashtable
 */

#ifndef __CHAINING_HASH_H
#define __CHAINING_HASH_H

 // Standard library includes
#include <iostream>
#include <vector>
#include <list>
#include <stdexcept>


// Custom project includes
#include "Hash.h"

// Namespaces to include
using std::vector;
using std::list;
using std::pair;

using std::cout;
using std::endl;

//
// Separate chaining based hash table - derived from Hash
//
template<typename K, typename V>
class ChainingHash : public Hash<K, V> {
private:
    vector<list<pair<K, V>>> m_table; //our hash table
    int count = 0;


public:

    ChainingHash(int n = 11);

    ~ChainingHash();

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

    void initializeTable(int n); //using function for constructor to get around weird error

    void rehash(void);

};

/////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////PUBLIC FUNCTIONS/////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////

template<typename K, typename V>
ChainingHash<K, V>::ChainingHash(int n)
{
    this->initializeTable(n);
}

template<typename K, typename V>
ChainingHash<K, V>::~ChainingHash()
{
    this->initializeTable(0);
}

template<typename K, typename V>
int ChainingHash<K, V>::size()
{
    return this->count;
}

template<typename K, typename V>
V ChainingHash<K, V>::operator[](const K& key)
{
    int key_index = hash(key);
    list<pair<K, V>> bucket = m_table.at(key_index);
    
    for (pair<K, V> pair : bucket)
    {
        if (pair.first == key) {
            return pair.second;
        }
    }

    //key not found
    return -1;
}

template<typename K, typename V>
bool ChainingHash<K, V>::insert(const std::pair<K, V>& pair)
{
    if (this->load_factor() > 0.75)
    {
        this->rehash();
    }

    this->m_table[this->hash(pair.first)].push_back(pair);
    this->count += 1;
    
    return true;
}

template<typename K, typename V>
void ChainingHash<K, V>::erase(const K& key)
{
    //get hash for key
    int key_index = hash(key);
    for (pair<K, V> pair : m_table[key_index])
    {
        //if key is found, remove pair from list
        if (pair.first == key)
        {
            this->m_table[key_index].clear();
            this->count -= 1;
            return;
        }
    }
}

template<typename K, typename V>
void ChainingHash<K, V>::clear()
{
    this->initializeTable(11); //simply create a new table of size 11
}

template<typename K, typename V>
int ChainingHash<K, V>::bucket_count()
{
    return this->m_table.size();
}

template<typename K, typename V>
float ChainingHash<K, V>::load_factor()
{
    return (float)count / (float)m_table.size();
}


/////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////PRIVATE FUNCTIONS/////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////

template<typename K, typename V>
int ChainingHash<K, V>::hash(const K& key)
{
    return key % this->m_table.size();
}

template<typename K, typename V>
void ChainingHash<K, V>::initializeTable(int n)
{
    this->m_table.clear(); //clear the table
    this->count = 0;       //clear the count
    this->m_table.resize(n); //resize to specified prime
}

template<typename K, typename V>
int ChainingHash<K, V>::findNextPrime(int n)
{
    while (!isPrime(n))
    {
        n++;
    }
    return n;
}

template<typename K, typename V>
int ChainingHash<K, V>::isPrime(int n)
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
void ChainingHash<K, V>::rehash(void)
{
    ChainingHash<K,V> newTable(count * 2);

    for (auto it : this->m_table)
    {
        for (auto it2 : it)
        {
            newTable.insert(it2);
        }
    }

    //replace the old table with the newly created one
    this->m_table = newTable.m_table;
    this->count = newTable.bucket_count();
}


#endif //__CHAINING_HASH_H
