#pragma once
#include "CDS_Arr.hpp"

// Constructor
template <class T, int N> CDS_Arr<T, N>::CDS_Arr() : _Size(N) {}

// Getters
template <class T, int N>
constexpr const size_t CDS_Arr<T, N>::GetSize() const {
  return N;
}

template <class T, int N> T *CDS_Arr<T, N>::GetData() { return this->_Arr; }

template <class T, int N> const T *CDS_Arr<T, N>::GetData() const {
  return this->_Arr;
}

// Swap
template <class T, int N>
void CDS_Arr<T, N>::Swap(const size_t &lhs, const size_t &rhs) {
  size_t temp = this->_Arr[lhs];
  this->_Arr[lhs] = this->_Arr[rhs];
  this->_Arr[rhs] = temp;
}

// Fill
template <class T, int N> void CDS_Arr<T, N>::Fill(const T &elem) {
  for (int i = 0; i < _Size; i++) {
    this->_Arr[i] = elem;
  }
}

// Operator Overloads
template <class T, int N> T &CDS_Arr<T, N>::operator[](const size_t index) {
  return this->_Arr[index];
}

template <class T, int N>
const T &CDS_Arr<T, N>::operator[](const size_t index) const {
  return this->_Arr[index];
}

template <class U, int M>
std::ostream &operator<<(std::ostream &stream, const CDS_Arr<U, M> &array) {
  stream << "[";
  for (size_t i = 0; i < array.GetSize(); ++i) {
    stream << array[i];
    if (i != array.GetSize() - 1) {
      stream << ", ";
    }
  }
  stream << "]";
  return stream;
}
