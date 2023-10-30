// ННГУ, ИИТММ, Курс "Алгоритмы и структуры данных"
//
// Copyright (c) Сысоев А.В.
//
//

#ifndef __TDynamicMatrix_H__
#define __TDynamicMatrix_H__

#include <iostream>

using namespace std;

const int MAX_VECTOR_SIZE = 100000000;
const int MAX_MATRIX_SIZE = 10000;

// Динамический вектор - 
// шаблонный вектор на динамической памяти
template<typename T>
class TDynamicVector
{
protected:
  size_t sz;
  T* pMem;
public:
    //TDynamicVector() {
       // sz = 0;
        //pMem = nullptr;
    //}
  TDynamicVector(size_t size = 1) : sz(size)
  {
    if (sz <= 0 || sz > MAX_VECTOR_SIZE)
      throw out_of_range("Vector size should be greater than zero or vector size greater than max vector size");
    pMem = new T[sz];
    for (size_t i = 0; i < sz; i++) {
        pMem[i] = 0;
    }
   }
  TDynamicVector(T* arr, size_t s) : sz(s)
  {
    assert(arr != nullptr && "TDynamicVector ctor requires non-nullptr arg");
    pMem = new T[sz];
    std::copy(arr[0], arr[sz-1], pMem);
  }
  TDynamicVector(const TDynamicVector& v)
  {
      sz = v.sz;
      pMem = new T[sz];
      for (int i = 0; i < sz; i++) {
          pMem[i] = v.pMem[i];//?
      }
  }
  //TDynamicVector(TDynamicVector&& v)
  //{}
  ~TDynamicVector()
  {
      delete[]pMem;
  }
  TDynamicVector& operator=(const TDynamicVector& v)
  {
      if (this == &v) {
          return *this;
      }
          if (sz != v.sz) {
              T* p = new T[v.sz];
              delete[]pMem;
              sz = v.sz;
              pMem = p;
          }
          for (int i = 0; i < sz; i++) {
              pMem[i] = v.pMem[i];
          }
          return *this;
  }
  //TDynamicVector& operator=(TDynamicVector&& v) noexcept
  //{
  //}

  size_t size() { return sz; }


  // индексация
  T& operator[](size_t ind)
  {
      if (ind > sz-1)
          throw "index >= size";
      return pMem[ind];
  }
  const T& operator[](size_t ind) const
  {
      if (ind > sz-1)
          throw "index >= size";
      return pMem[ind];
  }
  // индексация с контролем
  //T& at(size_t ind)
  //{
  //}
  //const T& at(size_t ind) const
  //{
  //}

  // сравнение
  bool operator==(const TDynamicVector& v)
  {
      if (sz != v.sz)
          return false;
      else {
          for (int i = 0; i < sz; i++) {
              if (v.pMem[i] != pMem[i])
                  return false;
          }
      }
      return true;
  }
  bool operator!=(const TDynamicVector& v)
  {
      if (v.sz != sz)
          return true;
      else {
          for (int i = 0; i < sz; i++) {
              if (v[i]!=(*this)[i])
                  return true;
          }
      }
      return false;
  }

  // скалярные операции
  TDynamicVector operator+(T val)
  {
      TDynamicVector res(sz);
      for (int i = 0; i < sz; i++) {
          res.pMem[i] = pMem[i] + val;
      }
      return res;
  }
  TDynamicVector operator-(T val)
  {
      TDynamicVector res(sz);
      for (int i = 0; i < sz; i++) {
          res.pMem[i] = pMem[i] - val;
      }
      return res;
  }
  TDynamicVector operator*(T val)
  {
      TDynamicVector res(sz);
      for (int i = 0; i < sz; i++) {
          res.pMem[i] = pMem[i] * val;
      }
      return res;
  }

  // векторные операции
  TDynamicVector operator+(const TDynamicVector& v)
  {
      if (sz != v.sz)
          throw "wrong size!";
      TDynamicVector res(sz);
      for (int i = 0; i < sz; i++) {
          res.pMem[i] = pMem[i] + v.pMem[i];
      }
      return res;
  }
  TDynamicVector operator-(const TDynamicVector& v)
  {
      if (sz != v.sz)
          throw "wrong size!";
      TDynamicVector res(sz);
      for (int i = 0; i < sz; i++) {
          res.pMem[i] = abs(pMem[i] - v.pMem[i]);
      }
      return res;
  }
  T operator*(const TDynamicVector& v) 
  {
      if (sz != v.sz)
          throw "wrong size!";
      T res = 0;
      for (int i = 0; i < sz; i++) {
          res += pMem[i] * v.pMem[i];
      }
      return res;
  }

  friend void swap(TDynamicVector& lhs, TDynamicVector& rhs) 
  {
    std::swap(lhs.sz, rhs.sz);
    std::swap(lhs.pMem, rhs.pMem);
  }

  // ввод/вывод
  friend istream& operator>>(istream& istr, TDynamicVector& v)
  {
    for (size_t i = 0; i < v.sz; i++)
      istr >> v.pMem[i]; // требуется оператор>> для типа T
    return istr;
  }
  friend ostream& operator<<(ostream& ostr, const TDynamicVector& v)
  {
    for (size_t i = 0; i < v.sz; i++)
      ostr << v.pMem[i] << ' '; // требуется оператор<< для типа T
    return ostr;
  }
};


// Динамическая матрица - 
// шаблонная матрица на динамической памяти
template<typename T>
class TDynamicMatrix : public TDynamicVector<TDynamicVector<T>>
{
  using TDynamicVector<TDynamicVector<T>>::pMem;
  using TDynamicVector<TDynamicVector<T>>::sz;
public:
  TDynamicMatrix(size_t s = 1) : TDynamicVector<TDynamicVector<T>>(s)
  {
      if (sz > MAX_MATRIX_SIZE || sz < 0) {
          throw("wrong size!");
      }
      for (size_t i = 0; i < sz; i++) {
          pMem[i] = TDynamicVector<T>(sz);
      }
  }

  using TDynamicVector<TDynamicVector<T>>::operator[];

  size_t size() {
      return sz;
  }

  // сравнение
  bool operator==(const TDynamicMatrix& m)
  {
      if (sz != m.sz)
          return false;
      for (int i = 0; i < sz; i++) {
          if(m[i]!=(*this)[i])
                  return false;
      }
      return true;
  }

  bool operator!=(const TDynamicMatrix& m) {
      if (m.sz != sz) {
          return true;
      }
      for (int i = 0; i < sz; i++) {
              if (pMem[i] != m.pMem[i]) {
                  return true;
          }
      }
      return false;
  }

  /*TDynamicMatrix operator=(const TDynamicMatrix& m) {
      if (this == &m)
          return *this;
      if (sz != m.sz) {
          sz = m.sz;
          delete[]pMem;
      }
      return *this;
  }*/


  // матрично-скалярные операции
  TDynamicMatrix operator*(const T& val)
  {
      TDynamicMatrix res(sz);
      for (int i = 0; i < sz; i++) {
              res[i] = pMem[i] * val;
      }
      return res;
  }

  // матрично-векторные операции
  TDynamicVector<T> operator*(const TDynamicVector<T>& v)
  {
      if (sz != v.sz)
          throw "wrong sizes!";
      TDynamicVector res(sz);
      for (int i = 0; i < sz; i++) {
          for (int j = 0; j < sz; j++) {
              res[i] += pMem[i][j] * v.pMem[j];
          }
      }
      return res;
  }

  // матрично-матричные операции
  TDynamicMatrix operator+(const TDynamicMatrix& m)
  {
      if (sz != m.sz)
          throw "wrong sizes!";
      TDynamicMatrix res(sz);
      for (int i = 0; i < sz; i++) {
              res.pMem[i] = pMem[i] + m.pMem[i];
      }
      return res;
  }
  TDynamicMatrix operator-(const TDynamicMatrix& m)
  {
      if (sz != m.sz)
          throw "wrong sizes!";
      TDynamicMatrix res(sz);
      for (int i = 0; i < sz; i++) {
              res.pMem[i]= pMem[i] - m.pMem[i];
      }
      return res;
  }
  TDynamicMatrix operator*(const TDynamicMatrix& m)
  {
      if (sz != m.sz)
          throw "wrong sizes!";
      TDynamicMatrix res(sz);
      for (int i = 0; i < sz; i++) {
          for (int j = 0; j < sz; j++) {
              for (int k = 0; k < sz; k++) {
                  res[i][j] += pMem[i][k] * m.pMem[k][j];
              }
          }
      }
      return res;
  }

  // ввод/вывод
  friend istream& operator>>(istream& istr, TDynamicMatrix& v)
  {
      for (int i = 0; i < v.sz; i++) {
              istr >> v.pMem[i];
      }
      return istr;
  }
  friend ostream& operator<<(ostream& ostr, const TDynamicMatrix& v)
  {
      for (int i = 0; i < v.sz; i++) {
              ostr << v.pMem[i]<<" ";
      }
      return ostr;
  }
};

#endif
