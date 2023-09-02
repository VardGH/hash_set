#include "hash_set.hpp"

namespace container {

hash_set::hash_set()
    : m_buckets(7)
{
}

hash_set::hash_set(int init_size)
    : m_buckets(init_size)
{
}

hash_set::hash_set(const hash_set& other)
    : m_buckets(other.m_buckets)
    , m_const_load_factor(other.m_const_load_factor)
{
}

hash_set& hash_set::operator=(const hash_set& other)
{
    if (this != &other) {
        m_buckets = other.m_buckets;
        m_const_load_factor = other.m_const_load_factor;
    }
    return *this;
}

hash_set::hash_set(hash_set&& other)
    : m_buckets(std::move(other.m_buckets))
    , m_const_load_factor(other.m_const_load_factor)
{
}

hash_set& hash_set::operator=(hash_set&& other)
{
    if (this != &other) {
        m_buckets = std::move(other.m_buckets);
        m_const_load_factor = other.m_const_load_factor;
    }
    return *this;
}

hash_set::~hash_set()
{
    clear();
}

void hash_set::clear()
{
    for (auto& elem : m_buckets) {
        elem.clear();
    }
}

int hash_set::hash_function(int key) const
{
    return key % m_buckets.size();
}

bool hash_set::contains(const int key) const
{
    int index = hash_function(key);
    for (const auto& elem : m_buckets[index]) {
        if (elem == key) {
            return true;
        }
    }
    return false;
}

hash_set::iterator hash_set::find(const int key)
{
    int index = hash_function(key);
    return std::find(m_buckets[index].begin(), m_buckets[index].end(), key);
}

float hash_set::const_load_factor() const
{
    return m_const_load_factor;
}

int hash_set::size() const
{
    int elements = 0;

    for (const auto& bucket : m_buckets) {
        for (const auto& elem : bucket) {
            ++elements;
        }
    }
    return elements;
}


float hash_set::load_factor() const
{
    return static_cast<float>(size()) / m_buckets.size();
}

void hash_set::reserve(int cap)
{
    int bucket_count = std::max(cap, static_cast<int>(cap / m_const_load_factor));
    rehash(bucket_count);
}

void hash_set::rehash(int count)
{
    std::vector<std::forward_list<int>> new_set(count);
    for (const auto& bucket : m_buckets) {
        for (int elem : bucket) {
            int new_index = hash_function(elem) % count;
            new_set[new_index].push_front(elem);
        }
    }
    m_buckets = std::move(new_set);
}

void hash_set::insert(const int key)
{
    update_load_factor();
    int index = hash_function(key);
    if (!contains(key)) {
        m_buckets[index].push_front(key);
    }
}

void hash_set::remove(const int key)
{
    int index = hash_function(key);
    std::forward_list<int>& bucket = m_buckets[index];
    bucket.remove(key);
}

void hash_set::update_load_factor()
{
    if (load_factor() > m_const_load_factor) {
        rehash(m_buckets.size() * 2);
    }
}

void hash_set::print() const
{
    for (std::size_t i = 0; i < m_buckets.size(); ++i) {
        std::cout << "Bucket " << i << ": ";
        for (const auto& elem : m_buckets[i]) {
            std::cout << elem << " ";
        }
        std::cout << std::endl;
    }
}

int hash_set::bucket_count() const
{
    return m_buckets.size();
}

bool hash_set::empty() const
{
    for (const auto& bucket : m_buckets) {
        if (!bucket.empty()) {
            return false;
        }
    }
    return true;
}

int hash_set::bucket_size(size_t index) const
{
    if (index >= m_buckets.size()) {
        return 0; // Invalid bucket index
    }

    size_t count = 0;
    for (const auto& elem : m_buckets[index]) {
        ++count;
    }
    return count;
}

} // namespace container 