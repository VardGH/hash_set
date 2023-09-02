# hash_set

container::hash_set is a C++ implementation of a hash set data structure. It provides a dynamic set that allows efficient insertion, removal, and retrieval of elements based on their keys.

## Table of Contents

- [Features](#features)
- [Functions](#functions)

## Features

- Dynamic resizing of the underlying hash table to maintain efficient performance.
- Support for constant load factor management.
- Iteration and querying of elements.
- Easy-to-use interface for inserting, removing, and checking element existence.

## Functions

- **`hash_set()`**
  - Initializes an empty hash set with a default number of buckets.

- **`explicit hash_set(int init_size)`**
  - Initializes an empty hash set with a specified number of buckets (`init_size`).

- **`hash_set(const hash_set& other)`**
  - Creates a new hash set as a copy of another hash set (`other`).

- **`hash_set& operator=(const hash_set& other)`**
  - Assigns the content of another hash set (`other`) to the current hash set.

- **`hash_set(hash_set&& other)`**
  - Creates a new hash set by moving the content of another hash set (`other`).

- **`hash_set& operator=(hash_set&& other)`**
  - Assigns the content of another hash set (`other`) to the current hash set.

- **`~hash_set()`**
  - Cleans up the resources used by the hash set.

- **`void insert(const int key)`**
  - Inserts an element with the specified key into the hash set.

- **`void remove(const int key)`**
  - Removes an element with the specified key from the hash set.

- **`bool contains(const int key) const`**
  - Checks if the hash set contains an element with the specified key.

- **`iterator find(const int key)`**
  - Searches for an element with the specified key and returns an iterator to it (if found).

- **`int bucket_count() const`**
  - Gets the total number of buckets in the hash set.

- **`int bucket_size(size_t index) const`**
  - Gets the size (number of elements) of a specific bucket in the hash set.

- **`float const_load_factor() const`**
  - Gets the constant load factor used in the hash set.

- **`float load_factor() const`**
  - Calculates and returns the current load factor of the hash set.

- **`void reserve(int count)`**
  - Reserves a specified number of buckets based on a count.

- **`bool empty() const`**
  - Checks if the hash set is empty.

- **`void clear()`**
  - Clears all elements from the hash set.

- **`void print() const`**
  - Prints the contents of the hash set to the console.

- **`int size() const`**
  - Gets the number of elements in the hash set.
