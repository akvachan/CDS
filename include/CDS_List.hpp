/**
 * @file CDS_List.hpp
 * @brief A templated dynamic list class for managing an array of elements.
 *
 * This file contains the definition of the CDS_List class template,
 * which provides basic operations such as appending, removing, and accessing
 * elements.
 */

#pragma once
#include <iostream>
namespace _Init {

/**
 * @brief Namespace for initialization constants.
 */
constexpr const size_t _INITIAL = 1; ///< Initial capacity for the list.
} // namespace _Init

/**
 * @brief Templated dynamic list class.
 *
 * This class implements a dynamic list (array-like structure) that supports
 * operations such as adding, removing, and accessing elements. It automatically
 * reallocates memory when the capacity is exceeded.
 *
 * @tparam T The type of elements stored in the list.
 */
template <class T> class CDS_List {
public:
  class iterator {

  public:
    using iterator_category = std::forward_iterator_tag;
    using difference_type = std::ptrdiff_t;
    using value_type = T;
    using pointer = T *;
    using reference = T &;

    iterator(pointer inPointer);

    reference operator*() const;
    pointer operator->();
    iterator &operator++();
    iterator operator++(int);
    iterator &operator--();
    iterator operator--(int);

    bool operator==(const iterator &other) const;
    bool operator!=(const iterator &other) const;

  private:
    pointer _pointer;
  };

  // Constructors and Destructor

  /**
   * @brief Default constructor.
   *
   * Initializes the list with a default capacity.
   */
  CDS_List();

  /**
   * @brief Destructor.
   *
   * Frees any dynamically allocated memory.
   */
  ~CDS_List();

  // Getters

  /**
   * @brief Get a pointer to the internal data array.
   *
   * @return A pointer to the array of elements.
   */
  T *GetData();

  /**
   * @brief Get a const reference to the element at the given index.
   *
   * @param index The index of the element to retrieve.
   * @return A const reference to the element.
   */
  T &GetElement(const size_t index) const;

  /**
   * @brief Get the current size of the list.
   *
   * @return The number of elements in the list.
   */
  const size_t GetSize() const;

  /**
   * @brief Get a const pointer to the internal data array.
   *
   * @return A const pointer to the array of elements.
   */
  const T *GetData() const;

  /**
   * @brief Get the current capacity of the list.
   *
   * @return The maximum number of elements the list can hold without
   * reallocation.
   */
  const size_t GetCapacity() const;

  // Modifiers

  /**
   * @brief Remove and return the last element from the list.
   *
   * @return The last element in the list.
   */
  T Pop();

  /**
   * @brief Append an element to the end of the list.
   *
   * Reallocates the internal array if the capacity is exceeded.
   *
   * @param elem The element to append.
   * @return A const reference to the appended element.
   */
  const T &Append(const T &elem);

  /**
   * @brief Append a temporary element to the end of the list.
   *
   * Reallocates the internal array if the capacity is exceeded.
   *
   * @param elem The temporary element to append.
   * @return A const reference to the appended element.
   */
  const T &Append(T &&elem);

  /**
   * @brief Construct and append an element in place.
   *
   * Constructs an element directly in the list without copying or moving it.
   *
   * @tparam Args The types of the constructor arguments.
   * @param args The constructor arguments.
   * @return A reference to the newly emplaced element.
   */
  template <class... Args> T &Emplace(Args &&...args);

  /**
   * @brief Fill the list with the specified element.
   *
   * @param elem The element to fill the list with.
   */
  void Fill(const T &elem);

  /**
   * @brief Swap two elements in the list by their indices.
   *
   * @param lhs The index of the first element.
   * @param rhs The index of the second element.
   */
  void Swap(const size_t &lhs, const size_t &rhs);

  /**
   * @brief Insert an element at a specified index.
   *
   * @param index The index at which to insert the element.
   * @param elem The element to insert.
   */
  void Insert(const size_t index, const T &elem);

  /**
   * @brief Remove an element at a specified index.
   *
   * @param index The index of the element to remove.
   */
  void Remove(const size_t index);

  /**
   * @brief Clear the list, removing all elements.
   */
  void Clear();

  // Operator Overloads

  /**
   * @brief Access an element by its index.
   *
   * @param index The index of the element to access.
   * @return A reference to the element.
   */
  T &operator[](const size_t index);

  /**
   * @brief Access an element by its index (const version).
   *
   * @param index The index of the element to access.
   * @return A const reference to the element.
   */
  const T &operator[](const size_t index) const;

  /**
   * @brief Output stream operator overload.
   *
   * Allows printing the list to an output stream.
   *
   * @tparam U The type of elements in the list.
   * @param stream The output stream.
   * @param array The list to print.
   * @return A reference to the output stream.
   */
  template <class U>
  friend std::ostream &operator<<(std::ostream &stream,
                                  const CDS_List<U> &array);

  iterator end();
  iterator begin();

private:
  size_t _Size;       ///< The current number of elements in the list.
  size_t _Capacity;   ///< The maximum number of elements the list can hold.
  T *_List = nullptr; ///< Pointer to the dynamically allocated array.

  // Setters

  /**
   * @brief Set the capacity of the list.
   *
   * @param cap The new capacity.
   */
  void SetCapacity(const size_t cap);

  /**
   * @brief Set the size of the list.
   *
   * @param size The new size.
   */
  void SetSize(const size_t size);

  /**
   * @brief Set the internal data array.
   *
   * @param data Pointer to the new data array.
   */
  void SetData(T *data);

  /**
   * @brief Set the element at a specified index.
   *
   * @param index The index of the element.
   * @param elem The element to set.
   */
  void SetElement(const size_t index, const T &elem);

  /**
   * @brief Reallocate the internal data array to a new capacity.
   *
   * @param mem The new capacity.
   */
  void Reallocate(size_t mem);
};

#include "CDS_List.ipp"
