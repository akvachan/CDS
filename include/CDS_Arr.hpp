#pragma once
#include <iostream>

/**
 * @file CDS_Arr.h
 * @brief Header file for the CDS_Arr template class.
 */

/**
  @class CDS_Arr
 * @brief A simple template class for a fixed-size array with additional
 * functionality.
 *
 * This class provides a fixed-size array with functionalities such as
 * element access, swapping elements, filling the array with values,
 * and outputting the array to an output stream.
 *
 * @tparam T The type of elements stored in the array.
 * @tparam N The size of the array.
 */
template <class T, int N> class CDS_Arr {
public:
  /**
   * @brief Constructs a CDS_Arr object.
   */
  CDS_Arr();

  /**
   * @brief Gets the size of the array.
   *
   * @return The size of the array as a constant size_t value.
   */
  constexpr const size_t GetSize() const;

  /**
   * @brief Gets a pointer to the array data.
   *
   * @return A pointer to the array data.
   */
  T *GetData();

  /**
   * @brief Gets a constant pointer to the array data.
   *
   * @return A constant pointer to the array data.
   */
  const T *GetData() const;

  /**
   * @brief Swaps two elements in the array.
   *
   * @param lhs The index of the first element to swap.
   * @param rhs The index of the second element to swap.
   */
  void Swap(const size_t &lhs, const size_t &rhs);

  /**
   * @brief Fills the array with values of type T.
   * @param elem The value of type T.
   */
  void Fill(const T &elem);

  /**
   * @brief Accesses an element in the array.
   *
   * @param index The index of the element to access.
   * @return A reference to the element at the specified index.
   */
  T &operator[](const size_t index);

  /**
   * @brief Accesses a constant element in the array.
   *
   * @param index The index of the element to access.
   * @return A constant reference to the element at the specified index.
   */
  const T &operator[](const size_t index) const;

  /**
   * @brief Overloads the stream insertion operator to output the array.
   *
   * @tparam U The type of elements stored in the array.
   * @tparam M The size of the array.
   * @param stream The output stream.
   * @param array The CDS_Arr object to output.
   * @return The output stream.
   */
  template <class U, int M>
  friend std::ostream &operator<<(std::ostream &stream,
                                  const CDS_Arr<U, M> &array);

private:
  T _Arr[N];    /**< The fixed-size array. */
  size_t _Size; /**< The size of the array. */
};

#include "CDS_Arr.ipp"
