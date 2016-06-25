#include "MaxHeap.h"
#include <iostream>
#include <vector>

bool test_max_heap_empty_constructor() {
  bool result = false;
  MaxHeap<int> h;
  if ( h.empty() ) {
    result = true;
  }
  #ifdef NDEBUG
    std::cout << "h = " << h << "\t\t\t\t\t\t\t\t\t";
  #endif
  return result;
}

bool test_max_heap_array_constructor() {
  bool result = false;
  int array_h[10] = { 4, 1, 3, 2, 16, 9, 10, 14, 8, 7 };
  MaxHeap<int> h( array_h, 10 );
  MaxHeap<int> ref;
  ref.maxHeapInsert( 16 );
  ref.maxHeapInsert( 14 );
  ref.maxHeapInsert( 10 );
  ref.maxHeapInsert( 8 );
  ref.maxHeapInsert( 7 );
  ref.maxHeapInsert( 9 );
  ref.maxHeapInsert( 3 );
  ref.maxHeapInsert( 2 );
  ref.maxHeapInsert( 4 );
  ref.maxHeapInsert( 1 );
  if ( h == ref ) {
    result = true;
  }
  #ifdef NDEBUG
    std::cout << "h = " << h << "\t\t\t\t\t";
  #endif
  return result;
}

bool test_max_heap_vector_constructor() {
  bool result = false;
  std::vector<int> vector_h;
  vector_h.push_back( 4 );
  vector_h.push_back( 1 );
  vector_h.push_back( 3 );
  vector_h.push_back( 2 );
  vector_h.push_back( 16 );
  vector_h.push_back( 9 );
  vector_h.push_back( 10 );
  vector_h.push_back( 14 );
  vector_h.push_back( 8 );
  vector_h.push_back( 7 );
  MaxHeap<int> h( vector_h );
  MaxHeap<int> ref;
  ref.maxHeapInsert( 16 );
  ref.maxHeapInsert( 14 );
  ref.maxHeapInsert( 10 );
  ref.maxHeapInsert( 8 );
  ref.maxHeapInsert( 7 );
  ref.maxHeapInsert( 9 );
  ref.maxHeapInsert( 3 );
  ref.maxHeapInsert( 2 );
  ref.maxHeapInsert( 4 );
  ref.maxHeapInsert( 1 );
  if ( h == ref ) {
    result = true;
  }
  #ifdef NDEBUG
    std::cout << "h = " << h << "\t\t\t\t\t";
  #endif
  return result;
}

bool test_max_heap_copy_constructor() {
  bool result = false;
  int array_h[10] = { 4, 1, 3, 2, 16, 9, 10, 14, 8, 7 };
  MaxHeap<int> h( array_h, 10 );
  MaxHeap<int> res( h );
  MaxHeap<int> ref( array_h, 10 );
  h.heapExtractMax();
  if ( res == ref ) {
    result = true;
  }
  #ifdef NDEBUG
    std::cout << "h = " << res << "\t\t\t\t\t";
  #endif
  return result;
}

bool test_max_heap_parent_index() {
  bool result = false;
  int array_h[10] = { 4, 1, 3, 2, 16, 9, 10, 14, 8, 7 };
  MaxHeap<int> h( array_h, 10 );
  size_t index = 2;
  size_t res = h.parentIndex( index );
  size_t ref = 0;
  if ( res == ref ) {
    result = true;
  }
  #ifdef NDEBUG
    std::cout << "h.parentIndex(" << index << ") = " << res << "\t\t\t\t\t\t\t";
  #endif
  return result;
}

bool test_max_heap_parent_index_overflow() {
  bool result = false;
  int array_h[10] = { 4, 1, 3, 2, 16, 9, 10, 14, 8, 7 };
  MaxHeap<int> h( array_h, 10 );
  size_t index = 20;
  size_t res;
  size_t ref = 0;
  try {
    res = h.parentIndex( index );
  }
  catch ( std::overflow_error ) {
    res = 0;
  }
  if ( res == ref ) {
    result = true;
  }
  #ifdef NDEBUG
    std::cout << "h.parentIndex(" << index << ") = " << res << "\t\t\t\t\t\t\t";
  #endif
  return result;
}

bool test_max_heap_left_child_index() {
  bool result = false;
  int array_h[10] = { 4, 1, 3, 2, 16, 9, 10, 14, 8, 7 };
  MaxHeap<int> h( array_h, 10 );
  size_t index = 2;
  size_t res = h.leftChildIndex( index );
  size_t ref = 5;
  if ( res == ref ) {
    result = true;
  }
  #ifdef NDEBUG
    std::cout << "h.leftChildIndex(" << index << ") = " << res << "\t\t\t\t\t\t\t";
  #endif
  return result;
}

bool test_max_heap_right_child_index() {
  bool result = false;
  int array_h[10] = { 4, 1, 3, 2, 16, 9, 10, 14, 8, 7 };
  MaxHeap<int> h( array_h, 10 );
  size_t index = 2;
  size_t res = h.rightChildIndex( index );
  size_t ref = 6;
  if ( res == ref ) {
    result = true;
  }
  #ifdef NDEBUG
    std::cout << "h.rightChildIndex(" << index << ") = " << res << "\t\t\t\t\t\t";
  #endif
  return result;
}

bool test_max_heap_parent() {
  bool result = false;
  int array_h[10] = { 4, 1, 3, 2, 16, 9, 10, 14, 8, 7 };
  MaxHeap<int> h( array_h, 10 );
  size_t index = 2;
  size_t res = h.parent( index );
  size_t ref = 16;
  if ( res == ref ) {
    result = true;
  }
  #ifdef NDEBUG
    std::cout << "h.parent(" << index << ") = " << res << "\t\t\t\t\t\t\t";
  #endif
  return result;
}

bool test_max_heap_left_child() {
  bool result = false;
  int array_h[10] = { 4, 1, 3, 2, 16, 9, 10, 14, 8, 7 };
  MaxHeap<int> h( array_h, 10 );
  size_t index = 2;
  size_t res = h.leftChild( index );
  size_t ref = 9;
  if ( res == ref ) {
    result = true;
  }
  #ifdef NDEBUG
    std::cout << "h.leftChild(" << index << ") = " << res << "\t\t\t\t\t\t\t";
  #endif
  return result;
}

bool test_max_heap_right_child() {
  bool result = false;
  int array_h[10] = { 4, 1, 3, 2, 16, 9, 10, 14, 8, 7 };
  MaxHeap<int> h( array_h, 10 );
  size_t index = 2;
  size_t res = h.rightChild( index );
  size_t ref = 3;
  if ( res == ref ) {
    result = true;
  }
  #ifdef NDEBUG
    std::cout << "h.rightChild(" << index << ") = " << res << "\t\t\t\t\t\t\t";
  #endif
  return result;
}

bool test_max_heap_get_size() {
  bool result = false;
  int array_h[10] = { 4, 1, 3, 2, 16, 9, 10, 14, 8, 7 };
  MaxHeap<int> h( array_h, 10 );
  int heap_size = h.getSize();
  if ( 10 == heap_size ) {
    result = true;
  }
  #ifdef NDEBUG
    std::cout << "h.size() = " << heap_size << "\t\t\t\t\t\t\t\t";
  #endif
  return result;
}

bool test_max_heap_is_leaf() {
  bool result = false;
  int array_h[10] = { 4, 1, 3, 2, 16, 9, 10, 14, 8, 7 };
  MaxHeap<int> h( array_h, 10 );
  bool t1 = h.isLeaf( 0 ) == false;
  bool t2 = h.isLeaf( 1 ) == false;
  bool t3 = h.isLeaf( 2 ) == false;
  bool t4 = h.isLeaf( 3 ) == false;
  bool t5 = h.isLeaf( 4 ) == false;

  bool t6 = h.isLeaf( 5 ) == true;
  bool t7 = h.isLeaf( 6 ) == true;
  bool t8 = h.isLeaf( 7 ) == true;
  bool t9 = h.isLeaf( 8 ) == true;
  bool t10 = h.isLeaf( 9 ) == true;
  bool t = t1 && t2 && t3 && t4 && t5 && t6 && t7 && t8 && t9 && t10;
  if ( t ) {
    result = true;
  }
  #ifdef NDEBUG
    std::cout << "h.isLeaf() = " << t << "\t\t\t\t\t\t\t\t";
  #endif
  return result;
}

bool test_max_heap_is_max_heap() {
  bool result = false;
  int array_h[10] = { 4, 1, 3, 2, 16, 9, 10, 14, 8, 7 };
  MaxHeap<int> h( array_h, 10 );
  if ( h.isMaxHeap() ) {
    result = true;
  }
  #ifdef NDEBUG
    std::cout << "h.isMaxHeap() = " << result << "\t\t\t\t\t\t\t";
  #endif
  return result;
}

bool test_max_heap_is_empty() {
  bool result = false;
  MaxHeap<int> h;
  bool is_empty = h.empty();
  if ( is_empty ) {
    result = true;
  }
  #ifdef NDEBUG
    std::cout << "h.empty() = " << is_empty << "\t\t\t\t\t\t\t\t";
  #endif
  return result;
}

bool test_max_heap_at() {
  bool result = false;
  int array_h[10] = { 4, 1, 3, 2, 16, 9, 10, 14, 8, 7 };
  MaxHeap<int> h( array_h, 10 );
  int h_index = 5;
  int h_element = h.at( h_index );
  if ( 9 == h_element ) {
    result = true;
  }
  #ifdef NDEBUG
    std::cout << "h.at(" << h_index << ") = " << h_element << "\t\t\t\t\t\t\t\t";
  #endif
  return result;
}

bool test_max_heap_assignment_operator() {
  bool result = false;
  MaxHeap<int> h;
  MaxHeap<int> h_copy;
  MaxHeap<int> ref;
  h.maxHeapInsert( 16 );
  h.maxHeapInsert( 14 );
  h.maxHeapInsert( 10 );
  h.maxHeapInsert( 8 );
  h.maxHeapInsert( 7 );
  h.maxHeapInsert( 9 );
  h.maxHeapInsert( 3 );
  h.maxHeapInsert( 2 );
  h.maxHeapInsert( 4 );
  h.maxHeapInsert( 1 );
  ref.maxHeapInsert( 14 );
  ref.maxHeapInsert( 8 );
  ref.maxHeapInsert( 10 );
  ref.maxHeapInsert( 4 );
  ref.maxHeapInsert( 7 );
  ref.maxHeapInsert( 9 );
  ref.maxHeapInsert( 3 );
  ref.maxHeapInsert( 2 );
  ref.maxHeapInsert( 1 );
  h_copy = h;
  h.heapExtractMax();
  if ( h == ref ) {
    result = true;
  }
  #ifdef NDEBUG
    std::cout << "h = " << h << "\t\t\t\t\t";
  #endif
  return result;
}

bool test_max_heap_equal_operator() {
  bool result = false;
  int array_h1[10] = { 4, 1, 3, 2, 16, 9, 10, 14, 8, 7 };
  int array_h2[10] = { 4, 1, 3, 2, 16, 9, 10, 14, 8, 7 };
  MaxHeap<int> h1( array_h1, 10 );
  MaxHeap<int> h2( array_h2, 10 );
  if ( h1 == h2 ) {
    result = true;
  }
  #ifdef NDEBUG
    std::cout << "h1 == h2 = " << result << "\t\t\t\t\t\t\t\t";
  #endif
  return result;
}

bool test_max_heap_not_equal_operator() {
  bool result = false;
  int array_h1[10] = { 4, 1, 3, 2, 16, 9, 10, 14, 8, 7 };
  int array_h2[10] = { 4, 1, 3, 2, 16, 9, 10, 14, 8, 77 };
  MaxHeap<int> h1( array_h1, 10 );
  MaxHeap<int> h2( array_h2, 10 );
  if ( h1 != h2 ) {
    result = true;
  }
  #ifdef NDEBUG
    std::cout << "h1 != h2 = " << result << "\t\t\t\t\t\t\t\t";
  #endif
  return result;
}

bool test_max_heap_sort() {
  bool result = false;
  int array_h[10] = { 4, 1, 3, 2, 16, 9, 10, 14, 8, 7 };
  MaxHeap<int> h( array_h, 10 );
  std::vector<int> res = h.heapSort();
  std::vector<int> ref;
  ref.push_back( 16 );
  ref.push_back( 14 );
  ref.push_back( 10 );
  ref.push_back( 9 );
  ref.push_back( 8 );
  ref.push_back( 7 );
  ref.push_back( 4 );
  ref.push_back( 3 );
  ref.push_back( 2 );
  ref.push_back( 1 );
  if ( res == ref ) {
    result = true;
  }
  #ifdef NDEBUG
    std::cout << "ref == res = " << result << "\t\t\t\t\t\t\t\t";
  #endif
  return result;
}

bool test_max_heap_heap_extract_max() {
  bool result = false;
  int res = 0;
  int ref = 16;
  int array_h[10] = { 4, 1, 3, 2, 16, 9, 10, 14, 8, 7 };
  MaxHeap<int> h( array_h, 10 );
  res = h.heapExtractMax();
  if ( res == ref && h.getSize() == 9 ) {
    result = true;
  }
  #ifdef NDEBUG
    std::cout << "h.heapExtractMax = " << res << "\t\t\t\t\t\t\t";
  #endif
  return result;
}

bool test_max_heap_heap_maximum() {
  bool result = false;
  int res = 0;
  int ref = 16;
  int array_h[10] = { 4, 1, 3, 2, 16, 9, 10, 14, 8, 7 };
  MaxHeap<int> h( array_h, 10 );
  res = h.heapMaximum();
  if ( res == ref && h.getSize() == 10 ) {
    result = true;
  }
  #ifdef NDEBUG
    std::cout << "h.heapMaximum = " << res << "\t\t\t\t\t\t\t";
  #endif
  return result;
}

bool test_max_heap_build_max_heap_recursive() {
  bool result = false;
  std::vector<int> vector_h;
  vector_h.push_back( 4 );
  vector_h.push_back( 1 );
  vector_h.push_back( 3 );
  vector_h.push_back( 2 );
  vector_h.push_back( 16 );
  vector_h.push_back( 9 );
  vector_h.push_back( 10 );
  vector_h.push_back( 14 );
  vector_h.push_back( 8 );
  vector_h.push_back( 7 );
  int array_h[10] = { 16, 14, 10, 8, 7, 9, 3, 2, 4, 1 };
  MaxHeap<int> ref( array_h, 10 );
  MaxHeapCreationType type = RECURSIVE;
  MaxHeap<int> res( vector_h, type );
  if ( res == ref ) {
    result = true;
  }
  #ifdef NDEBUG
    std::cout << "h.buildMaxHeapRecursive = " << res << "\t\t";
  #endif
  return result;
}

bool test_max_heap_build_max_heap_iterative() {
  bool result = false;
  std::vector<int> vector_h;
  vector_h.push_back( 4 );
  vector_h.push_back( 1 );
  vector_h.push_back( 3 );
  vector_h.push_back( 2 );
  vector_h.push_back( 16 );
  vector_h.push_back( 9 );
  vector_h.push_back( 10 );
  vector_h.push_back( 14 );
  vector_h.push_back( 8 );
  vector_h.push_back( 7 );
  int array_h[10] = { 16, 14, 10, 8, 7, 9, 3, 2, 4, 1 };
  MaxHeap<int> ref( array_h, 10 );
  MaxHeapCreationType type = ITERATIVE;
  MaxHeap<int> res( vector_h, type );
  if ( res == ref ) {
    result = true;
  }
  #ifdef NDEBUG
    std::cout << "h.buildMaxHeapIterative = " << res << "\t\t";
  #endif
  return result;
}

bool test_max_heap_insert() {
  bool result = false;
  MaxHeap<int> res;
  res.maxHeapInsert( 16 );
  res.maxHeapInsert( 14 );
  res.maxHeapInsert( 10 );
  res.maxHeapInsert( 8 );
  res.maxHeapInsert( 7 );
  res.maxHeapInsert( 9 );
  res.maxHeapInsert( 3 );
  res.maxHeapInsert( 2 );
  res.maxHeapInsert( 4 );
  res.maxHeapInsert( 1 );
  int array_h[10] = { 16, 14, 10, 8, 7, 9, 3, 2, 4, 1 };
  MaxHeap<int> ref( array_h, 10 );
  if ( res == ref ) {
    result = true;
  }
  #ifdef NDEBUG
    std::cout << "h.insert = " << res << "\t\t\t\t";
  #endif
  return result;
}

bool test_max_heap_remove_at() {
  bool result = false;
  int array_org[10] = { 4, 1, 3, 2, 16, 9, 10, 14, 8, 7 };
  MaxHeap<int> h_org( array_org, 10 );
  int array_ref[9] = { 16, 8, 10, 4, 7, 9, 3, 2, 1 };
  MaxHeap<int> h_ref( array_ref, 9 );
  size_t remove_index = 1;
  size_t remove_element_ref = 14;
  size_t remove_element_res;
  remove_element_res = h_org.removeAt( remove_index );
  bool t1 = remove_element_ref == remove_element_res;
  bool t2 = h_org.getSize() == h_ref.getSize();
  bool t3 = h_org == h_ref;
  bool t = t1 && t2 && t3;
  if ( t ) {
    result = true;
  }
  #ifdef NDEBUG
    std::cout << "h.removeAt(" << remove_index << ") = " << remove_element_res << "\t\t\t\t\t\t\t";
  #endif
  return result;
}

int main( int argc, const char * argv[] ) {
  if ( test_max_heap_empty_constructor() ) {
    std::cout << "test_max_heap_empty_constructor -> OK" << std::endl;
  } else {
    std::cout << "test_max_heap_empty_constructor -> FAIL" << std::endl;
  }
  if ( test_max_heap_array_constructor() ) {
    std::cout << "test_max_heap_array_constructor -> OK" << std::endl;
  } else {
    std::cout << "test_max_heap_array_constructor -> FAIL" << std::endl;
  }
  if ( test_max_heap_vector_constructor() ) {
    std::cout << "test_max_heap_vector_constructor -> OK" << std::endl;
  } else {
    std::cout << "test_max_heap_vector_constructor -> FAIL" << std::endl;
  }
  if ( test_max_heap_copy_constructor() ) {
    std::cout << "test_max_heap_copy_constructor -> OK" << std::endl;
  } else {
    std::cout << "test_max_heap_copy_constructor -> FAIL" << std::endl;
  }
  if ( test_max_heap_parent_index() ) {
    std::cout << "test_max_heap_parent_index -> OK" << std::endl;
  } else {
    std::cout << "test_max_heap_parent_index -> FAIL" << std::endl;
  }
  if ( test_max_heap_parent_index_overflow() ) {
    std::cout << "test_max_heap_parent_index_overflow -> OK" << std::endl;
  } else {
    std::cout << "test_max_heap_parent_index_overflow -> FAIL" << std::endl;
  }
  if ( test_max_heap_left_child_index() ) {
    std::cout << "test_max_heap_left_child_index -> OK" << std::endl;
  } else {
    std::cout << "test_max_heap_left_child_index -> FAIL" << std::endl;
  }
  if ( test_max_heap_right_child_index() ) {
    std::cout << "test_max_heap_right_child_index -> OK" << std::endl;
  } else {
    std::cout << "test_max_heap_right_child_index -> FAIL" << std::endl;
  }
  if ( test_max_heap_parent() ) {
    std::cout << "test_max_heap_parent() -> OK" << std::endl;
  } else {
    std::cout << "test_max_heap_parent() -> FAIL" << std::endl;
  }
  if ( test_max_heap_left_child() ) {
    std::cout << "test_max_heap_left_child() -> OK" << std::endl;
  } else {
    std::cout << "test_max_heap_left_child() -> FAIL" << std::endl;
  }
  if ( test_max_heap_right_child() ) {
    std::cout << "test_max_heap_right_child() -> OK" << std::endl;
  } else {
    std::cout << "test_max_heap_right_child() -> FAIL" << std::endl;
  }
  if ( test_max_heap_get_size() ) {
    std::cout << "test_max_heap_get_size -> OK" << std::endl;
  } else {
    std::cout << "test_max_heap_get_size -> FAIL" << std::endl;
  }
  if ( test_max_heap_is_leaf() ) {
    std::cout << "test_max_heap_is_leaf -> OK" << std::endl;
  } else {
    std::cout << "test_max_heap_is_leaf -> FAIL" << std::endl;
  }
  if ( test_max_heap_is_max_heap() ) {
    std::cout << "test_max_heap_is_max_heap -> OK" << std::endl;
  } else {
    std::cout << "test_max_heap_is_max_heap -> FAIL" << std::endl;
  }
  if ( test_max_heap_is_empty() ) {
    std::cout << "test_max_heap_is_empty -> OK" << std::endl;
  } else {
    std::cout << "test_max_heap_is_empty -> FAIL" << std::endl;
  }
  if ( test_max_heap_at() ) {
    std::cout << "test_max_heap_at -> OK" << std::endl;
  } else {
    std::cout << "test_max_heap_at -> FAIL" << std::endl;
  }
  if ( test_max_heap_assignment_operator() ) {
    std::cout << "test_max_heap_assignment_operator -> OK" << std::endl;
  } else {
    std::cout << "test_max_heap_assignament_operator -> FAIL" << std::endl;
  }
  if ( test_max_heap_equal_operator() ) {
    std::cout << "test_max_heap_equal_operator -> OK" << std::endl;
  } else {
    std::cout << "test_max_heap_equal_operator -> FAIL" << std::endl;
  }
  if ( test_max_heap_not_equal_operator() ) {
    std::cout << "test_max_heap_not_equal_operator -> OK" << std::endl;
  } else {
    std::cout << "test_max_heap_not_equal_operator -> FAIL" << std::endl;
  }
  if ( test_max_heap_sort() ) {
    std::cout << "test_max_heap_sort -> OK" << std::endl;
  } else {
    std::cout << "test_max_heap_sort -> FAIL" << std::endl;
  }
  if ( test_max_heap_heap_extract_max() ) {
    std::cout << "test_max_heap_heap_extract_max -> OK" << std::endl;
  } else {
    std::cout << "test_max_heap_heap_extract_max -> FAIL" << std::endl;
  }
  if ( test_max_heap_heap_maximum() ) {
    std::cout << "test_max_heap_heap_maximum -> OK" << std::endl;
  } else {
    std::cout << "test_max_heap_heap_maximum -> FAIL" << std::endl;
  }
  if ( test_max_heap_build_max_heap_recursive() ) {
    std::cout << "test_max_heap_build_max_heap_recursive -> OK" << std::endl;
  } else {
    std::cout << "test_max_heap_build_max_heap_recursive -> FAIL" << std::endl;
  }
  if ( test_max_heap_build_max_heap_iterative() ) {
    std::cout << "test_max_heap_build_max_heap_iterative -> OK" << std::endl;
  } else {
    std::cout << "test_max_heap_build_max_heap_iterative -> FAIL" << std::endl;
  }
  if ( test_max_heap_insert() ) {
    std::cout << "test_max_heap_insert -> OK" << std::endl;
  } else {
    std::cout << "test_max_heap_insert -> FAIL" << std::endl;
  }
  if ( test_max_heap_remove_at() ) {
    std::cout << "test_max_heap_remove_at -> OK" << std::endl;
  } else {
    std::cout << "test_max_heap_remove_at -> FAIL" << std::endl;
  }
  return 0;
}
