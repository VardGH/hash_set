#ifndef HASH_SET
#define HASH_SET

#include <vector>
#include <forward_list>
#include <algorithm>
#include <iterator> 
#include <iostream>

namespace container {

class hash_set
{
public:
    using iterator = std::forward_list<int>::iterator;

    // Constructors and destructor
    hash_set(); // Default constructor
    explicit hash_set(int init_size); // Constructor with initial size
    hash_set(const hash_set& other); // Copy constructor
    hash_set& operator=(const hash_set& other); // Copy assignment operator
    hash_set(hash_set&& other); // Move constructor
    hash_set& operator=(hash_set&& other); // Move assignment operator
    ~hash_set(); // Destructor

    // Element manipulation
    void insert(const int key); // Insert an element
    void remove(const int key); // Remove an element
    bool contains(const int key) const; // Check if an element exists
    iterator find(const int key); // Find an element by key

    // Bucket interface
    int bucket_count() const; // Get the total number of buckets
    int bucket_size(size_t index) const; // Get the size of a specific bucket

    // Hash policy
    float const_load_factor() const; // Get the constant load factor
    float load_factor() const; // Calculate the current load factor
    void reserve(int count); // Reserve buckets based on a count

    // Information about the hash set
    bool empty() const; // Check if the hash set is empty
    void clear(); // Clear all elements
    void print() const; // Print the contents of the hash set
    int size() const; // Get the number of elements

private:
    int hash_function(int key) const; // Compute the hash value for a key
    void update_load_factor(); // Helper function for load factor updates
    void rehash(int count); // Rehash the hash set with a new count

private:
    std::vector<std::forward_list<int>> m_buckets; // Storage for elements
    float m_const_load_factor = 0.7; // Constant load factor
};

} // namespace container

#endif // HASH_SET