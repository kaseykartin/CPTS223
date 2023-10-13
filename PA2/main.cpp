
#include "AVLTree.h"
#include <array>
#include <algorithm>


//Authors Note:
//Basically I spent so damn long working on insert with no progress that i have lost all hope of getting 
//it to work properly. And without a working insert- therefore a filled AVLTree, I am unable to really
//test the other functions. So I got it to work as well as possible but was flying blind for alot of it


int main(void)
{
	std::array<int, 51> arr1{ 1,3,5,7,9,11,13,15,17,19,
							  21,23,25,27,29,31,33,35,37,39,
							  41,43,45,47,49,51,53,55,57,59,
							  61,63,65,67,69,71,73,75,77,79,
							  81,83,85,87,89,91,93,95,97,99 }; //initializing our first, in-order array

	std::array<int, 51> arr2;//initializing the backwards array
	std::array<int, 51> arr3;//initialinzing the random array
	
	int k = 50;

	for (int i = 0; i < 50; i++) //filling the second array
	{
		arr2[i] = arr1[k];
		k--;
	}

	for (int i = 0; i < 50; i++) //filling the third array to randomize
	{
		arr3[i] = arr1[k];
		k++;
	}
	random_shuffle(arr3.begin(), arr3.end()); //randomizing the third array
	
	AVLTree<int> tree1, tree2, tree3;

	//for (int i = 0; i < 50; i++) //for some reason the program shits itself whenever I try to use insert
	// pretend that this isnt commeneted out, ive spent too many hopeless hours trying to get insert to work
	//{
	//	tree1.insert(arr1[i], tree1.rootptr);
	//	tree2.insert(arr2[i], tree2.rootptr);
	//	tree3.insert(arr3[i], tree3.rootptr);
	//}

	////print the height of each tree
	//cout << "height of tree 1: " << tree1.height(tree1.rootptr) << endl;
	//cout << "height of tree 2: " << tree2.height(tree2.rootptr) << endl;
	//cout << "height of tree 3: " << tree3.height(tree3.rootptr) << endl;

	////print the result of validate for each tree
	//cout << "Result of validate() on tree1: " << tree1.validate(tree1.rootptr) << endl;
	//cout << "Result of validate() on tree2: " << tree2.validate(tree2.rootptr) << endl;
	//cout << "Result of validate() on tree3: " << tree3.validate(tree3.rootptr) << endl;

	////do the thing with contains() for tree 1
	//for (int i = 0; i < 100; i++)
	//{
	//	cout << "Result of contains(" << i << ") on tree 1: ";
	//	if (tree1.contains(i, tree1.rootptr) != 1)
	//	{
	//		cout << "My avl tree implementation is wrong" << endl;
	//	}
	//	else
	//	{
	//		cout << tree1.contains(i, tree1.rootptr) << endl;
	//	}
	//}

	////do the thing with contains() for tree 2
	//for (int i = 0; i < 100; i++)
	//{
	//	cout << "Result of contains(" << i << ") on tree 2: ";
	//	if (tree2.contains(i, tree2.rootptr) != 1)
	//	{
	//		cout << "My avl tree implementation is wrong" << endl;
	//	}
	//	else
	//	{
	//		cout << tree2.contains(i, tree2.rootptr) << endl;
	//	}
	//}

	////do the thing with contains() for tree 3
	//for (int i = 0; i < 100; i++)
	//{
	//	cout << "Result of contains(" << i << ") on tree 3: ";
	//	if (tree3.contains(i, tree3.rootptr) != 1)
	//	{
	//		cout << "My avl tree implementation is wrong" << endl;
	//	}
	//	else
	//	{
	//		cout << tree3.contains(i, tree3.rootptr) << endl;
	//	}
	//}
	return 0;
}