# Reflection

## 1. Why does LinkedList::deleteFront() use two delete calls?

The first delete call removes the data object stored inside the node. The second delete call removes the node itself. The data object was created with new int(...) or new Data(...) in main.cpp, while the node was created with new Node<T>(value) inside LinkedList::addFront().

## 2. Why does ArrayList need a destructor after changing from T to T*?

When ArrayList stored values directly, deleting the array elements was not necessary. After changing the array to store pointers, each pointer points to an object created on the heap. The destructor is necessary to delete every object still stored in the array. Without the destructor, the program would usually compile, but the allocated memory would leak.

## 3. How are addFront() and search() different with ownership?

addFront() takes ownership of the pointer it receives. The list is responsible for deleting that object later. search() only temporarily looks at the pointer and compares its value. It does not own the pointer and must never delete it.

## 4. What two mechanisms allow ArrayList and LinkedList to be swapped?

Inheritance and virtual functions make the swap possible. Both classes inherit from the same List<T> interface and implement the same virtual methods. The makeList() function returns a List<T> pointer, so main.cpp does not need to know which implementation is being used.

## 5. Explain one important keyword from the project.

The override keyword tells the compiler that a derived-class method is meant to replace a virtual method from the base class. 