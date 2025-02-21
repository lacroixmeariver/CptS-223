#include <iostream>
#include "BST.h" 
/*
Question portion:
Part A:
	1. A move constructor is a class function that allows for the transfering of elements/object data from one object to another of the same type - leaves the object
	that the data is moved from in a state of emptiness/void of values. 
	2. A move assignment operator overloads an operator to accept data that is stored somewhere in memory (referred to as an rvalue or sometimes a temporary value), 
	and defines how a certain user defined object's resources are distributed to the intended destination. 

Part B:
	1. BST::empty() has a worst case time complexity of O(1). Since there isn't iteration or processes to go through, just a simple check at the root of 
	a tree and a boolean value is returned. 

	2. BST::add() has a worst case time complexity of O(n). Since this is not a self-balancing tree (no balance factor), the worst insertion 
	(meaning a very unbalanced or degenerate tree) has to travel down n nodes - in which n represents the max height of a tree. 

	3. BST::makeEmpty() has a worst case time complexity of O(n). In post-order traversal, the recurrence relation is 2T(n) = T(n/2) + O(1), and because the entire tree
	is 2^k nodes in total (at least in a BST), each call down each subtree divides the size by half. When the relation is expanded, it simplifies to O(n) by way of n equaling
	2^k, it's inverse being k = log_2(n). Since linear functions grow at a faster speed than logarithmic ones do, complexity boils down to O(n).

	4. BST::printLevelOrder() has a worst case time complexity of O(n). Similarly to post-order traversal, each node is only visited once. Most operations done within that 
	function + it's helpers operate at O(1) (push, pop, etc.), and since we ignore everything but the highest order growth rate, it comes down to O(n).

	5. BST::cloneTree() has a worst case time complexity of O(n). Similar to a couple of BST operations, each node is only visited once, and the collection size is constantly
	halved every recursive call to the left and right subtrees. All other operations are at O(n), since it's just transfering information over. 

*/
int main(){


	/* MA TODO: Implement */
	/* Create a BST string tree (bst_test) ; add the following string values to the bst_test in order: "C", "p", "t", "s", "2", "3" , "B", "S", "T"*/
	BST<string> bst_test;
	vector<string> bstTestString = {"C", "p", "t", "s", "2", "3" , "B", "S", "T"};
	for (int i = 0; i < bstTestString.size(); i++)
	{
		bst_test.add(bstTestString[i]); // populating the tree with a loop + vector
	}

	/* MA TODO: Implement */
	// Test1: Test printLevelOrder()
	/* Print the tree you created using
	    a. In-order print
	    a. Level-order print
	    a. Post-order print
	    a. Pre-order print */
	cout << "********** Test 1 **********" << endl;
	cout << "In order: " << endl;
	bst_test.printInOrder(); cout << endl;
	cout << "Level order: " << endl;
	bst_test.printLevelOrder(); cout << endl;
	cout << "Post order: " << endl;
	bst_test.printPostOrder(); cout << endl;
	cout << "Pre order: " << endl;
	bst_test.printPreOrder(); cout << endl;
	cout << endl;


	/* MA TODO: Implement */
	// Test2: Test copy constructor -1
	/* Create a new BST tree (bst_copy1) ; initialize bst_copy1 with 'bst_test's data, using the copy constructor */
	/* Test condition: Check if the size of bst_copy1 is same as bst_test; and  bst_copy1 contains the values "B", "S", "T" 
	    * if so, print the mesaage: "Copy constructor test-1 passed!"";
		* else *print the message: "Copy constructor test-1 failed!"" and print both bst_test and bst_copy1 using level order print.*/
	cout << "********** Test 2 **********" << endl;
	BST<string> bst_copy1;
	bst_copy1 = bst_test; 
	if (bst_test.size() == bst_copy1.size())
	{
		cout << "Copy constructor test-1 passed!" << endl;
	}
	else
	{
		cout << "Copy constructor test-1 failed!" << endl;
	}
	cout << "Level order bst_test: " << endl;
	bst_test.printLevelOrder(); 
	cout << endl;
	cout << "Level order bst_copy1: " << endl;
	bst_copy1.printLevelOrder();
	cout << endl << endl;

	


	/* MA TODO: Implement */
	// Test3: Test copy constructor - 2
	/* Update one of the strings in bst_copy1 tree using the following statement:  */
	   // bst_copy1.getNode("B")->setValue("A");
	/* Assuming copy constructor does a deep copy, the above statement should update bst_copy1 only, and not bst_test. */
	/* Test condition: 
	    * if bst_test contains "B" and it doesn't contain "A", test passes. Print the message: "Copy constructor test-2 passed!"";
		* else *print the message: "Copy constructor test-2 failed!"" and print bst_test using level order print.*/

	cout << "********** Test 3 **********" << endl;
	
	bst_copy1.getNode("B")->setValue("A");
	if (!bst_test.contains("A")) 
	{
		cout << "Copy constructor test-2 passed!" << endl;
	}
	else
	{
		cout << "Copy constructor test-2 failed!" << endl;
	}
	bst_test.printLevelOrder(); 
	cout << endl;
	bst_copy1.printLevelOrder(); 
	cout << endl << endl;


	/* MA TODO: Implement */
	// Test4: Test copy assignment
	/* Create a new BST tree (bst_copy2) ; initialize bst_copy2 with 'bst_test's data, using the copy assignment operator. */
	/* Test condition: Check if the size of bst_copy2 is same as bst_test and  bst_copy2 contains the values "B", "S", "T" 
	    * if so, print the mesaage: "Copy assignment operator test passed!"";
		* else *print the message: "Copy assignment operator test failed!"" and print both bst_test and bst_copy2 using level order print.*/
	
	cout << "********** Test 4 **********" << endl;
	BST<string> bst_copy2; 
	bst_copy2 = bst_test;
	if (bst_copy2.size() == bst_test.size())
	{
		cout << "Copy assignment operator test passed!" << endl;
	}
	else
	{
		cout << "Copy assignment operator test failed!" << endl;
	}
	bst_test.printLevelOrder(); 
	cout << endl;
	bst_copy2.printLevelOrder(); 
	cout << endl << endl;


	/* MA TODO: Implement */
	// Test5: Test move constructor
	/* Create a new BST tree (bst_move1) ; initialize bst_move1 with 'bst_test's data, using the move constructor */
	/* Test condition: Check if the size of bst_move1 is 9 and  bst_move1 contains the values "B", "S", "T", and bst_test is empty (use the empty() function of BST to check if bst_test is empty.).  
	    * if so, print the mesaage: "Move constructor test passed!"";
		* else *print the message: "Move constructor test failed!"" and print bst_move1 using level order print.*/

	cout << "********** Test 5 **********" << endl;
	BST<string> bst_move1(std::move(bst_test)); //.bst_move1.debug_on();
	//bst_move1 = std::move(bst_test);
	
	
	if (bst_move1.size() == 9 && bst_test.empty())
	{
		cout << "Move constructor test passed!" << endl;
	}
	else
	{
		cout << "Move constructor test failed!" << endl;
	}
	bst_test.printLevelOrder(); 
	cout << endl;
	bst_move1.printLevelOrder(); 
	cout << endl;
	cout << endl;


	/* MA TODO: Implement */
	// Test6: Test move assignment 
	/* Create a new BST tree (bst_move2) ; initialize bst_move2 with rvalue BST<string>({"B","S","T"}), using the move assignment operator */
	/* Test condition: Check if the size of bst_move2 is 3 and  bst_move2 contains the values "B", "S", "T". 
	    * if so, print the message: "Move assignment operator test passed!"";
		* else *print the message: "Move assignment operator test failed!"" and print  bst_move2  using level order print.*/
	cout << "********** Test 6 **********" << endl;
	BST<string> inputRVAL({"B","S","T"}); 
	BST<string> bst_move2(inputRVAL);

	if (bst_move2.size() == 3 && bst_move2.contains("B") && bst_move2.contains("S") && bst_move2.contains("T"))
	{
		cout << "Move assignment operator test passed!" << endl;
	}
	else
	{
		cout << "Move assignment operator test failed!" << endl;
	}

	bst_test.printLevelOrder(); cout << endl;
	bst_move2.printLevelOrder(); 
	cout << endl;


	return 0;
}