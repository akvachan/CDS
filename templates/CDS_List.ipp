#pragma once
#include "CDS_List.hpp"
#include <cassert>
#include <iostream>
#include <utility>

#define assertm(exp, msg) assert(((void)msg, exp))

// Constructors
template <class T>
CDS_List<T>::CDS_List() : _Size(0), _Capacity(_Init::_INITIAL) {
  this->Reallocate(_Init::_INITIAL);
}

// Destructor
template <class T> CDS_List<T>::~CDS_List() {
  this->Clear();
  if (this->GetData())
    ::operator delete(_List, this->GetCapacity() * sizeof(T));
}

// Getters
template <class T> const size_t CDS_List<T>::GetSize() const {
  return this->_Size;
}

template <class T> T *CDS_List<T>::GetData() { return this->_List; }

template <class T> const T *CDS_List<T>::GetData() const { return this->_List; }

template <class T> const size_t CDS_List<T>::GetCapacity() const {
  return this->_Capacity;
}

template <class T> T &CDS_List<T>::GetElement(const size_t index) const {
  assertm(index < this->GetSize(), "Index out of bounds");
  return this->_List[index];
}

// Setters
template <class T> void CDS_List<T>::SetCapacity(const size_t cap) {
  this->_Capacity = cap;
}

template <class T> void CDS_List<T>::SetSize(const size_t size) {
  this->_Size = size;
}

template <class T> void CDS_List<T>::SetData(T *data) { this->_List = data; }

template <class T>
void CDS_List<T>::SetElement(const size_t index, const T &elem) {
  this->_List[index] = elem;
}

template <class T> void CDS_List<T>::Reallocate(const size_t newCap) {
  T *newList = (T *)::operator new(newCap * sizeof(T));
  // if new capacity is smaller than current capacity (downsizing) then take new
  // capacity as upper limit, else take size.
  size_t lim = ((this->GetCapacity() > newCap) ? newCap : this->GetSize());

  for (size_t i = 0; i < lim; i++) {
    // move of elements into uninitialized memory (very weird!)
    new (newList + i) T(std::move(this->GetElement(i)));
  }

  for (int i = 0; i < this->GetSize(); i++) {
    this->GetElement(i).~T();
  }

  if (this->GetData())
    ::operator delete(_List, this->GetCapacity() * sizeof(T));

  this->SetData(newList);
  this->SetCapacity(newCap);
}

// Fill
template <class T> void CDS_List<T>::Fill(const T &elem) {
  for (int i = 0; i < _Size; i++) {
    this->SetElement(i, elem);
  }
}

// Swap
template <class T>
void CDS_List<T>::Swap(const size_t &lhs, const size_t &rhs) {
  T temp = std::move(this->GetElement(lhs)); // Move element at lhs to temp
  this->SetElement(lhs, std::move(this->GetElement(rhs))); // Move rhs to lhs
  this->SetElement(rhs, std::move(temp)); // Move temp (original lhs) to rhs
}

// Append
template <class T> const T &CDS_List<T>::Append(const T &elem) {
  if (this->GetSize() >= this->GetCapacity()) {
    this->Reallocate(this->GetCapacity() * 2);
  }
  this->SetElement(this->GetSize(), elem);
  this->SetSize(this->GetSize() + 1);

  return this->GetElement(this->GetSize() - 1);
}

// Append (Temporary elem)
template <class T> const T &CDS_List<T>::Append(T &&elem) {
  if (this->GetSize() >= this->GetCapacity()) {
    this->Reallocate(this->GetCapacity() * 2);
  }
  new (this->GetData() + this->GetSize()) T(std::move(elem));
  this->SetSize(this->GetSize() + 1);

  return this->GetElement(this->GetSize() - 1);
}

// Emplace
template <class T>
template <class... Args>
T &CDS_List<T>::Emplace(Args &&...args) {
  if (this->GetSize() >= this->GetCapacity()) {
    this->Reallocate(this->GetCapacity() * 2);
  }
  new (&this->GetElement(this->GetSize())) T(std::forward<Args>(args)...);
  this->SetSize(this->GetSize() + 1);

  return this->GetElement(this->GetSize() - 1);
}

// Pop
template <class T> T CDS_List<T>::Pop() {
  assertm(this->GetSize() > 0, "List is empty");
  T outElem = std::move(GetElement(this->GetSize() - 1));
  this->SetSize(this->GetSize() - 1);

  return outElem;
}

// Clear
template <class T> void CDS_List<T>::Clear() {
  for (int i = 0; i < this->GetSize(); i++) {
    this->GetElement(i).~T();
  }
  this->SetSize(0);
}

// Insert
template <class T> void CDS_List<T>::Insert(const size_t index, const T &elem) {
  std::logic_error("Function not yet implemented!");
}

// Remove
template <class T> void CDS_List<T>::Remove(const size_t index) {
  std::logic_error("Function not yet implemented!");
}

// Operator Overloads
template <class T> T &CDS_List<T>::operator[](const size_t index) {
  return this->GetElement(index);
}

template <class T> const T &CDS_List<T>::operator[](const size_t index) const {
  return this->GetElement(index);
}

template <class U>
std::ostream &operator<<(std::ostream &stream, const CDS_List<U> &array) {
  stream << "[";
  for (size_t i = 0; i < array.GetSize(); ++i) {
    stream << array.GetElement(i);
    if (i != array.GetSize() - 1) {
      stream << ", ";
    }
  }
  stream << "]";
  return stream;
}

// Iterator Constructor
template <class T>
CDS_List<T>::iterator::iterator(pointer inPointer) : _pointer(inPointer) {}

// Iterator Overloads
template <class T>
typename CDS_List<T>::iterator::reference
CDS_List<T>::iterator::operator*() const {
  return *this->_pointer;
}

template <class T>
typename CDS_List<T>::iterator::pointer CDS_List<T>::iterator::operator->() {
  return this->_pointer;
}

template <class T>
typename CDS_List<T>::iterator &CDS_List<T>::iterator::operator++() {
  ++_pointer;
  return *this;
}

template <class T>
typename CDS_List<T>::iterator CDS_List<T>::iterator::operator++(int) {
  iterator temp = *this;
  ++_pointer;
  return temp;
}

template <class T>
typename CDS_List<T>::iterator &CDS_List<T>::iterator::operator--() {
  --_pointer;
  return *this;
}

template <class T>
typename CDS_List<T>::iterator CDS_List<T>::iterator::operator--(int) {
  iterator temp = *this;
  --_pointer;
  return temp;
}

template <class T>
bool CDS_List<T>::iterator::operator==(const CDS_List<T>::iterator &other) const {
  return this->_pointer == other._pointer;
}

template <class T>
bool CDS_List<T>::iterator::operator!=(const CDS_List<T>::iterator &other) const {
  return this->_pointer != other._pointer;
}

template <class T> typename CDS_List<T>::iterator CDS_List<T>::end() {
  return iterator(this->GetData() + this->GetSize());
}

template <class T> typename CDS_List<T>::iterator CDS_List<T>::begin() {
  return iterator(this->GetData());
}
