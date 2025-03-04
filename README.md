1. Confirm logarithmic insertion and lookup
    Both my find and insert functions can be determined as keeping O(log n) because at every recursive call, the searchable/input data halves each time, thanks to the 
    property BSTs have in which nodes are sorted by some sort of key value. 

2. Avl tree properties 
    Avl trees are able to maintain O(log n) performance due to their balancing property or balancing factor updated in every node. This creates a well balanced tree, making 
    insert/lookup/delete functions more efficient than a tree that more resembles a linked list. 

3. Comparisons
    In what I've observed the avl tree is significantly faster in the insertion time than std::maps are, but can also be significantly slower in finding/search operations. 
    Given the choice, it would depend on if you as a user prioritized one operation over the other to determine what the better data structure for your needs is. 
    It seems like Avl trees are much more efficient if you won't be searching through the data much, and std::maps are more efficient for collections that don't 
    need faster insertion times. 