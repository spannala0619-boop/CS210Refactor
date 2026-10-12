# Reflection

 1. In LinkedList::deleteFront(), why does it take two separate delete calls instead of one? Name exactly what each one frees, and name the two new calls back in the program responsible for putting them on the heap in the first place.

Answer: The first delete lets go of the data stored inside the node, in this case it could be int or player. The second delete lets go of the node object itself. The data is put into heap by calls like new int(10) or new player(), and the node is put on heap by new Node<T>(value) which is inside addFront method.

2. ArrayList never had a destructor before today. Explain, in your own words, why switching from T data[CAPACITY] to T* data_[CAPACITY] is what made a destructor necessary, and what would happen if you forgot to write one. Would you get a compiler error? Why or why not?

Answer: When the arraay had stored actual T values, the objects had automatically been cleaned up when the arraay was out of scope. The destructor has to delete these objects manually because since we changed it to an array of pointers, each element would point to something new. If destructor was not there, program would compile but it would lead to a memory leak.

 3. search() and addFront() both take a T*, but they treat that pointer completely differently. Explain the difference in terms of ownership: which one is allowed to delete what you handed it, and which one is never allowed to?

Answer: addFront() has ownership because the list stores it and deletes it later. It is why destructors and delete functions free the data. Search only looks at value and does not take ownership

4. You swapped LinkedList<T> for ArrayList<T> inside makeList() and reran main.cpp without changing a single line there. What two mechanisms, by name, made that possible?

Answer: Inheritence allowed both lists to use through common list type.

5. Pick one keyword from the Key Terms glossary that you either had to add today or would not have thought to add on your own. Describe, in your own words and without copying the guide’s wording, the smallest example you can think of where leaving it out would cause a real problem.

Answer: I chose const. Search() is marked with const as search would not change list. If I were to leave out const, it would not compile as the function would not match the base class.