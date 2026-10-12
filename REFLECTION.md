# Reflection
                - copy pasting cause answered these on a google doc first

1. Why does concat only need to work between two lists of the same representation? What would you have to do differently, or what would go wrong, if you tried to make it work between a LinkedList and an ArrayList?

Answer: All these lists have their own way of storing data. A LinkedList list stores data in a node format, while the ArrayList list stores data in an array format; therefore, one list cannot access the data stored in the other list. For my code, dynamic_cast verifies that the other list has the same type as this list.

2. Walk through reverse() on your linked list: name the three pointers you need alive at once, and explain why losing track of any one of them mid-loop corrupts the list.

Answer: My three pointers are previous, current, and next. The current pointer refers to the node I want to modify, previous refers to the location to which its link will be assigned, and next holds the remaining part of the list before the modification. If I lost the next pointer, I would also lose the ability to access the remaining part of the list.

3. addAnywhere and deleteAnywhere both need a bounds check. What’s the valid range for position in each, and what does your implementation do if a caller passes a position outside it?

Answer: In addAnywhere, the possible indices are from 0 to size_, since the insertion is done at the end of the list. In deleteAnywhere, the possible indices are from 0 to size_ - 1, since there should be a value at that index. If the index is not valid, the method simply prints an out-of-bounds message and returns.

4. In LinkedList::concat, why did you need to walk to the end of the list first, when addFront and deleteFront never needed to? What would change about concat’s performance if LinkedList still tracked a tail_ pointer, and what would you have to keep updated elsewhere if you added one back?

Answer: Since addFront and deleteFront deal only with the first node, they may access head_ directly. However, the concat method needs to add the other list behind the last node in this list, so my implementation goes through the list until the end is found. If my class had a tail_ member pointing to the tail node, then concat would run in constant time, but then I'd have to update tail_ in addFront, deleteFront, concat, reverse, and when the list is empty.

5. Pick either addAnywhere or deleteAnywhere in ArrayList and explain, in your own words, what has to shift and in which direction, and why shifting in the wrong direction would overwrite data you still need.

Answer: In my ArrayList::addAnywhere method, the current elements move to the right, from the end to the insertion point. The direction of shifting is done from the end to prevent overwriting data that have not yet been shifted. If the shifting was done from the beginning of the array, then some elements would be overwritten before they were shifted.

6. Point to the exact line in your `main.cpp` where a Reverse card actually changes the direction of play, and explain what would visibly break in the game if that call were missing.

Answer: The line that changes the direction of play is:

players->reverse();

This reverses the order of the players so the turns go in the opposite direction. If I removed this line, the players would stay in the same order, so the Reverse card would not actually change anything in the game.
