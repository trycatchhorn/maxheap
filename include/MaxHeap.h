#ifndef MAXHEAP_H
#define MAXHEAP_H

/*
 * The MIT Licese (MIT)
 *
 * Copyright (C) 2016 by Brian Horn, trycatchhorn@gmail.com.
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
*/

#include <algorithm>
#include <iostream>
#include <iterator>
#include <stdexcept>
#include <vector>

enum MaxHeapCreationType {
  ITERATIVE,
  RECURSIVE
};

template<typename T> class MaxHeap;
template<typename T> std::ostream& operator << ( std::ostream& s, const MaxHeap<T>& other );
template<typename T> std::ostream& operator << ( std::ostream& s, std::vector<T> vec );

template<typename T>
class MaxHeap {

 public:

  /**
   * Creates an empty max-heap. The max-heap is backed by a vector, which
   * initially is empty.
   */
  MaxHeap();

  /**
   * Creates a max-heap from a std::vector. The max-heap is constructed from the
   * elements contained in the vector.
   *
   * @param  vec contains the elements from which the max-heap is constructed.
   */
  MaxHeap( std::vector<T> vec, MaxHeapCreationType type = RECURSIVE );

  /**
   * Creates a max-heap from an array. The max-heap is constructed from the
   * elements contained in the array.
   *
   * @param  arr contains the elements from which the max-heap is constructed.
   * @param  size specifies the upper limit in the specified array from where elements are copied.
   */
  MaxHeap( T arr[], size_t size, MaxHeapCreationType type = RECURSIVE );

  /**
   * Creates a copy of the specified max-heap.
   *
   * @param  other a reference to the max-heap from where the copy should be made.
   * @return a copy of the specified max-heap.
   */
  MaxHeap( const MaxHeap<T> &other );

  /**
   * Returns the index of the parent to the element at the specified
   * index in the max-heap.
   *
   * @param   index of element in the max_heap.
   * @return  the index of the parent to the specified element.
   */
  size_t parentIndex( size_t index ) throw( std::overflow_error );

  /**
   * Returns the index of the left child to the element at the specified
   * index in the max-heap.
   *
   * @param   index of element in the max-heap.
   * @return  the index of the left child to the specified element.
   */
  size_t leftChildIndex( size_t index ) throw( std::overflow_error );

  /**
   * Returns the index of the right child to the element at the specified
   * index in the max-heap.
   *
   * @param   index of element in the max-heap.
   * @return  the index of the right child to the specified element.
   */
  size_t rightChildIndex( size_t index ) throw( std::overflow_error );

  /**
   * Returns the parent of the element at the specified
   * index in the max-heap.
   *
   * @param  index of element in the max-heap.
   * @return the parent of the element at the specified index.
   */
  T parent( size_t index );

  /**
   * Returns the left child of the element at the specified
   * index in the max-heap.
   *
   * @param  index of element in the max-heap.
   * @return the left child of the element at the specified index.
   */
  T leftChild( size_t index );

  /**
   * Returns the right child of the element at the specified
   * index in the max-heap.
   *
   * @param  index of element in the max-heap.
   * @return the right child of the element at the specified index.
   */
  T rightChild( size_t index );

  /**
   * Returns the size of the max-heap.
   *
   * @return the size of the max-heap.
   */
  size_t getSize();

  /**
   * Returns if the max-heap is empty.
   *
   * @return true if the max-heap is empty, otherwise false.
   */
  bool empty() const;

  /**
   * Returns the max-heap element at the specified index.
   *
   * @param  index in the max-heap.
   * @return the max-heap element at the specified index.
   */
  T at( size_t index );

  /**
   * Sorts the contents in the max-heap by applying the heap-sort algorithm.
   * NOTE: that to get a sorted copy of an arbitrary max-heap, the following
   * 2 steps are required:
   * 1) Use a vector to contruct a max-heap
   * 2) Apply heapSort() method to the max-heap
   *
   * @return vector<T> vector is a sorted version of the max-heap
   */
  std::vector<T> heapSort();

  /**
   * Returns the element with the maximum key in the max-heap.
   *
   * @return T the element with the maximum key in the max-heap.
   */
  T heapMaximum() throw( std::underflow_error );

  /**
   * Returns the element with the maximum key in the max-heap.
   *
   * NOTE: the element is removed from the max-heap after
   * the operation and the heap maintains its max-heap
   * property.
   *
   * @return T the element with the maximum key in the max-heap.
   */
  T heapExtractMax() throw( std::underflow_error );

  /**
   * Inserts the specified key into the max-heap and
   * maintains the max-heap property.
   *
   * @param key the key to be inserted into the max-heap.
   */
  void maxHeapInsert( const T key );

  /**
   * Determines if the element at the specified index is a leaf element
   * in the max-heap.
   *
   * @param  index in the max-heap.
   * @return true if the element at the index is a leaf, false otherwise.
   */
  bool isLeaf( const size_t index ) const;

  /**
   * Determines if this heap satisfies the max-heap property.
   *
   * @return true if the heap satisfies the max-heap property, false otherwise.
   */
  bool isMaxHeap();

  /**
   * Removes, and returns, the element at the specified index from the max-heap
   * while maintaining the max-heap property.
   *
   * NOTE: The element is also removed from the std::vector backing the max-heap.
   *
   * @return The element at the specified index being removed.
   */
  T removeAt( size_t index );

  /**
   * Assignment operator assigns new contents to the max-heap, replacing
   * its current content, and modifying its size accordingly.
   *
   * Copies all elements from 'other' into the max-heap. The container
   * preserves its current allocator, which is used to allocate storage
   * in case of reallocation. Any elements held in the container before
   * the call are either assigned to or destroyed.
   *
   * @param  other the max-heap from where the elements are copied.
   * @return a copy of the specified max-heap.
   */
  MaxHeap<T>& operator = ( MaxHeap<T>& other );

  /**
   * Equal operator determines if the two max-heaps specified
   * are equal.
   *
   * @param  lhs the max-heap at the left-hand side of the equal operator.
   * @param  rhs the max-heap at the right-hand side of the equal operator.
   * @return true if the two specified max-heaps are equal.
   */
  template<typename F>
  friend bool operator == ( const MaxHeap<F>& lhs, const MaxHeap<F>& rhs );

  /**
   * Inequal operator determines if the two max-heaps specified
   * are inequal.
   *
   * @param  lhs the max-heap at the left-hand side of the inequal operator.
   * @param  rhs the max-heap at the right-hand side of the inequal operator.
   * @return true if the two specified max-heaps are inequal.
   */
  template<typename F>
  friend bool operator != ( const MaxHeap<F>& lhs, const MaxHeap<F>& rhs );

  /**
   * Output stream operator for the max-heap
   *
   * @param  s the output stream.
   * @param  other the max-heap at the right-hand side of the output stream operator.
   * @return the output stream for the max-heap.
   */
  friend std::ostream& operator << <T> ( std::ostream& s, const MaxHeap<T>& other );

  /**
   * Output stream operator for the vector backing the max-heap.
   *
   * @param  s the output stream.
   * @param  vec is the vector at the right-hand side of the output stream operator.
   * @return the output stream for the vector.
   */
  friend std::ostream& operator << <T> ( std::ostream& s, std::vector<T> vec );

 private:
  std::vector<T> heap;

  /**
   * Responsible for maintaining the max-heap property of the max-heap.
   * This function assumes that the subtree located at the left
   * and right child satisfies the max-heap property, maxHeapify(index)
   * makes the portion of the heap rooted at index into a max-heap.
   * NOTE: this function uses recursion, when constructing the max-heap.
   *
   * @param   index of element in the max-heap.
  */
  void maxHeapifyRecursive( size_t index );

  /**
   * Responsible for maintaining the max-heap property of the max-heap.
   * This function assumes that the subtree located at the left
   * and right child satisfies the max-heap property, maxHeapify(index)
   * makes the portion of the heap rooted at index into a max-heap.
   * NOTE: this function uses iteration, when constructing the max-heap.
   *
   * @param   index of element in the max-heap.
  */
  void maxHeapifyIterative( size_t index );

  /**
   * Responsible for building the max-heap bottom up. It starts with the
   * lowest non-leaf nodes and calls maxHeapify on them. After calling
   * this function the max-heap satisfies the max-heap property.
   * NOTE: this function uses recursion, when constructing the max-heap.
   */
  void buildMaxHeapRecursive();

  /**
   * Responsible for building the max-heap bottom up. It starts with the
   * lowest non-leaf nodes and calls maxHeapify on them. After calling
   * this function the max-heap satisfies the max-heap property.
   * NOTE: this function uses iteration, when constructing the max-heap.
   */
  void buildMaxHeapIterative();

  /**
   * Inserts new elements into the max-heap by allowing the specified key to
   * propagate up through the max-heap as necessary. The idea is that index will
   * NOT be the final index of the key, but the key will be moved up appropriately
   * when key >= heap.at(index).
   *
   * @param  index at which the heap will initially be overwritten with element key.
   * @param  key value of element to be inserted at the specified index.
   */
  void heapIncreaseKey( int index, T key ) throw( std::invalid_argument );

  /**
   * Swaps the elements in the max-heap specified by the indices.
   *
   * @param  i the first index of the heap element to be swapped.
   * @param  j the second index of the heap element to be swapped.
   */
  void heapSwap( size_t i, size_t j );

  /**
   * Compares node at index 'index' with the left node and moves
   * the node at index i down the heap by successively exchanging
   * the node with the smaller of its two children. The operation
   * continues until the node reaches a position where it is less
   * than both its children, or, failing that, until it reaches a
   * leaf nodee.
   *
   * @param  index the index of the heap element to be propageated.
   */
  void propagateDown( size_t index );

};

template<typename T>
MaxHeap<T>::MaxHeap() {
}

// Constructor from vector
template<typename T>
MaxHeap<T>::MaxHeap( std::vector<T> v, MaxHeapCreationType type ) {
  heap = v;
  if ( type == ITERATIVE ) {
    buildMaxHeapIterative();
  } else {
    buildMaxHeapRecursive();
  }
}

// Constructor from array
template<typename T>
MaxHeap<T>::MaxHeap( T arr[], size_t size, MaxHeapCreationType type ) {
  std::vector<T> v( arr, arr + size );
  heap = v;
  if ( type == ITERATIVE ) {
    buildMaxHeapIterative();
  } else {
    buildMaxHeapRecursive();
  }
}

// Copy constructor
template<typename T>
MaxHeap<T>::MaxHeap( const MaxHeap<T> &other ) : heap( other.heap ) {
}

template<typename T>
size_t MaxHeap<T>::getSize() {
  return heap.size();
}

template<typename T>
bool MaxHeap<T>::empty() const {
  return heap.empty();
}

template<typename T>
size_t MaxHeap<T>::parentIndex( size_t index ) throw( std::overflow_error ) {
  if ( index > heap.size() ) {
    throw std::overflow_error( "No parent at specified index" );
  }
  return ( index - 1 ) / 2;
}

template<typename T>
size_t MaxHeap<T>::leftChildIndex( size_t index ) throw( std::overflow_error ) {
  if ( index > heap.size() ) {
    throw std::overflow_error( "No left child at specified index" );
  }
  return 2 * index + 1;
}

template<typename T>
size_t MaxHeap<T>::rightChildIndex( size_t index ) throw( std::overflow_error ) {
  if ( index > heap.size() ) {
    throw std::overflow_error( "No right child at specified index" );
  }
  return 2 * index + 2;
}

template<typename T>
T MaxHeap<T>::parent( size_t index ) {
  return at( parentIndex( index ) );
}

template<typename T>
T MaxHeap<T>::leftChild( size_t index ) {
  return at( leftChildIndex( index ) );
}

template<typename T>
T MaxHeap<T>::rightChild( size_t index ) {
  return at( rightChildIndex( index ) );
}

template<typename T>
void MaxHeap<T>::maxHeapifyRecursive( size_t index ) {
  size_t left_child_index = leftChildIndex( index );
  size_t right_child_index = rightChildIndex( index );
  size_t largest;
  size_t heap_size = heap.size();
  if ( left_child_index < heap_size && at( left_child_index ) > at( index ) ) {
    largest = left_child_index;
  } else {
    largest = index;
  }
  if ( right_child_index < heap_size && at( right_child_index ) > at( largest ) ) {
    largest = right_child_index;
  }
  if ( largest != index ) {
    heapSwap( index, largest );
    maxHeapifyRecursive( largest );
  }
}

template<typename T>
void MaxHeap<T>::maxHeapifyIterative( size_t index ) {
  size_t left_child_index = leftChildIndex( index );
  while ( left_child_index < heap.size() ) {
    size_t right_child_index = left_child_index + 1;
    if ( right_child_index == heap.size() ) {
      if ( at( left_child_index ) > at( index ) ) {
        heapSwap( left_child_index, index );
      }
      return;
    }
    size_t choice = right_child_index;
    if ( at( left_child_index ) > at( right_child_index ) ) {
      choice = left_child_index;
    }
    if ( at( choice ) < at( index ) ) {
      return;
    }
    heapSwap( index, choice );
    index = choice;
    left_child_index = 2 * index + 1;
  }
}

template<typename T>
void MaxHeap<T>::buildMaxHeapRecursive() {
  size_t size = heap.size();
  for ( int i = size / 2 - 1; i >= 0; --i ) {
    maxHeapifyRecursive( i );
  }
}

template<typename T>
void MaxHeap<T>::buildMaxHeapIterative() {
  size_t size = heap.size();
  for ( int i = size / 2 - 1; i >= 0; --i ) {
    maxHeapifyIterative( i );
  }
}

template<typename T>
T MaxHeap<T>::at( size_t index ) {
  // Exception will be thrown if index is out of range
  return heap.at( index );
}

template<typename T>
MaxHeap<T>& MaxHeap<T>::operator = ( MaxHeap<T>& h ) {
  heap = h.heap;
  return h;
}

template<typename T>
std::vector<T> MaxHeap<T>::heapSort() {
  std::vector<T> result;
  MaxHeap<T> heapCopy = *this;
  for ( typename std::vector<T>::reverse_iterator it = heap.rbegin(); it != heap.rend(); ++it ) {
    std::swap( heap.front(), *it );
    result.push_back( heap.back() );
    heap.pop_back();
    maxHeapifyRecursive( 0 );
  }
  *this = heapCopy;
  return result;
}

template<typename T>
T MaxHeap<T>::heapMaximum() throw( std::underflow_error ) {
  if ( empty() ) {
    throw std::underflow_error( "MaxHeap is empty!" );
  }
  return at( 0 );
}

template<typename T>
T MaxHeap<T>::heapExtractMax() throw( std::underflow_error ) {
  size_t size = heap.size();
  if ( empty() ) {
    throw std::underflow_error( "MaxHeap is empty!" );
  }

  T result;
  heapSwap( 0, size - 1 );
  result = heap.back();
  heap.pop_back();
  maxHeapifyRecursive( 0 );
  return result;
}

template<typename T>
void MaxHeap<T>::heapIncreaseKey( int index, T key ) throw( std::invalid_argument ) {
  if ( key < at( index ) ) {
    throw std::invalid_argument( "New key is smaller than current key!" );
  }
  heap.at( index ) = key;
  while ( index > 0 && at( parentIndex( index ) ) < at( index ) ) {
    heapSwap( index, parentIndex( index ) );
    index = parentIndex( index );
  }
}

template<typename T>
void MaxHeap<T>::heapSwap( size_t i, size_t j ) {
  if ( i < getSize() && j < getSize() ) {
    std::swap( heap.at( i ), heap.at( j ) );
  }
}

template<typename T>
void MaxHeap<T>::propagateDown( size_t index ) {
  size_t n;
  size_t j;
  while ( !isLeaf( index ) ) {
    n = getSize();
    j = leftChildIndex( index );
    if ( ( j < ( n - 1 ) ) && ( at( j ) < at( j + 1 ) ) ){
      j++;
    }
    if ( at( index ) >= at( j ) ) {
      return;
    }
    heapSwap( index, j );
    index = j;
  }
}

template<typename T>
void MaxHeap<T>::maxHeapInsert( T key ) {
  heap.push_back( key );
  MaxHeap<T>::heapIncreaseKey( heap.size() - 1, key );
}

template<typename T>
bool MaxHeap<T>::isLeaf( const size_t index ) const {
  return ( ( index < heap.size() ) && ( index >= heap.size() / 2 ) );
}

template<typename T>
bool MaxHeap<T>::isMaxHeap() {
  size_t number_of_elements;
  size_t left_child_index;
  size_t right_child_index;
  number_of_elements = getSize();
  for ( size_t i = 0; i < number_of_elements; i++ ) {
    left_child_index = leftChildIndex( i );
    right_child_index = rightChildIndex( i );
    if ( ( left_child_index < number_of_elements ) && ( at( left_child_index ) > at( i ) ) ) {
      return false;
    }
    if ( ( right_child_index < number_of_elements ) && ( at( right_child_index ) > at( i ) ) ) {
      return false;
    }
  }
  return true;
}

template<typename T>
T MaxHeap<T>::removeAt( size_t index ) {
  size_t result;
  size_t n;
  n = getSize();
  if ( index == ( n - 1 ) ) {
    n--;
  } else {
    heapSwap( index, --n );
    while ( ( index > 0 ) && ( at( index ) > at( parentIndex( index ) ) ) ) {
      heapSwap( index, parentIndex( index ) );
      index = parentIndex( index );
    }
    if ( n != 0 ) {
      propagateDown( index );
    }
  }
  result = at( n );
  heap.erase( std::remove( heap.begin(), heap.end(), result ), heap.end() );
  return result;
}

template<typename F>
bool operator == ( const MaxHeap<F>& lhs, const MaxHeap<F>& rhs ) {
  return lhs.heap == rhs.heap;
}

template<typename F>
bool operator != ( const MaxHeap<F>& lhs, const MaxHeap<F>& rhs ) {
  return !( lhs.heap == rhs.heap );
}

template<typename T>
std::ostream& operator << ( std::ostream& s, const MaxHeap<T>& other ) {

  s << "<";
  if ( other.empty() ) {
    s << ">";
    return s;
  }
  size_t i;
  for ( i = 0; i < other.heap.size() - 1; i++ ) {
    s << other.heap[i] << ", ";
  }
  s << other.heap[other.heap.size() - 1] << ">";
  return s;
}

template<typename T>
std::ostream & operator << ( std::ostream & s, std::vector<T> vec ) {
  s << "{ ";
  std::copy( vec.begin(), vec.end() - 1, std::ostream_iterator<T>( s, ", " ) );
  std::copy( vec.end() - 1, vec.end(), std::ostream_iterator<T>( s, " " ) );
  s << "}";
  return s;
}

#endif
