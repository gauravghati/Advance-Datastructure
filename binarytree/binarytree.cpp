/*
=========================================================================
Assignment : Implementation of Priority Queue
Name : Gaurav Ghati
class : SE 10
Batch : F 10

Problem Statement:
	Create Binary Tree (BT) and perform following operations:
		a. Insert
		b. Display
		c. Depth of a tree
		d. Display leaf-nodes
		e. Create a copy of a tree
=========================================================================
*/

#include <iostream>
#include "BTree.cpp"

using namespace std;

void menu(){
	cout << "\n<------ OPERATIONS ------->";
	cout << "\n1) Create The Tree";
	cout << "\n2) Insert a single Node";
	cout << "\n3) Display the Tree Structure";
	cout << "\n4) Display leaf Node of the Tree";
	cout << "\n5) Create a copy of the tree";
	cout << "\n6) Depth of the Tree";
	cout << "\n7) Exit";
	cout << "\nEnter Choice: ";
}

int main() {
	
	BTree<int> p, copied;
	int ch, val;
	bool enter = true;
	
	while(enter){
		menu();
		cin >> ch;
		switch(ch){
			case 1:
				p.create();
				break;
			case 2: 
				cout << "Enter Value to be inserted";
				cin >> val;
				p.insert(val);
				break;
			case 3: 
				p.displaytree();
				break;
			case 4: 
				p.disleafs();
				break;
			case 5: 
				copied = p;
				cout << "\nSTRUCTURE OF COPIED TREE\n";
				copied.displaytree();
				break;
			case 6: 
				cout << "\nDepth of THe created Tree is: " << p.depth();
				break;		
			case 7: 
				enter = false;
				break;			
			default: 
				cout << "Enter Valid choice: ";
		}
	}	
	return 0;
}

/*

<------ OPERATIONS ------->
1) Create The Tree
2) Insert a single Node
3) Display the Tree Structure
4) Display leaf Node of the Tree
5) Create a copy of the tree
6) Depth of the Tree
7) Exit
Enter Choice: 1

Enter Number of Elements: 7
ENter the Value to be Inserted: 34
ENter the Value to be Inserted: 45

Enter L/R for Left Insert or Right Insert of 34: l
ENter the Value to be Inserted: 66

Enter L/R for Left Insert or Right Insert of 34: l

Enter L/R for Left Insert or Right Insert of 45: l
ENter the Value to be Inserted: 55

Enter L/R for Left Insert or Right Insert of 34: l

Enter L/R for Left Insert or Right Insert of 45: r
ENter the Value to be Inserted: 89

Enter L/R for Left Insert or Right Insert of 34: r
ENter the Value to be Inserted: 23

Enter L/R for Left Insert or Right Insert of 34: r

Enter L/R for Left Insert or Right Insert of 89: r
ENter the Value to be Inserted: 67

Enter L/R for Left Insert or Right Insert of 34: l

Enter L/R for Left Insert or Right Insert of 45: r

Enter L/R for Left Insert or Right Insert of 55: r

<------ OPERATIONS ------->
1) Create The Tree
2) Insert a single Node
3) Display the Tree Structure
4) Display leaf Node of the Tree
5) Create a copy of the tree
6) Depth of the Tree
7) Exit
Enter Choice: 2
Enter Value to be inserted: 87

Enter L/R for Left Insert or Right Insert of 34: r

Enter L/R for Left Insert or Right Insert of 89: l

<------ OPERATIONS ------->
1) Create The Tree
2) Insert a single Node
3) Display the Tree Structure
4) Display leaf Node of the Tree
5) Create a copy of the tree
6) Depth of the Tree
7) Exit
Enter Choice: 3
<-------------TREE STRUCTURE------------->
                    23

          89

                    87

34

                              67

                    55

          45

                    66

<------ OPERATIONS ------->
1) Create The Tree
2) Insert a single Node
3) Display the Tree Structure
4) Display leaf Node of the Tree
5) Create a copy of the tree
6) Depth of the Tree
7) Exit
Enter Choice: 4

1) Inorder Display: 
2) Preorder Display: 
3) Postorder Display: 
 Enter Choice: 1
 66 45 55 67 34 87 89 23

<------ OPERATIONS ------->
1) Create The Tree
2) Insert a single Node
3) Display the Tree Structure
4) Display leaf Node of the Tree
5) Create a copy of the tree
6) Depth of the Tree
7) Exit
Enter Choice: 4

1) Inorder Display: 
2) Preorder Display: 
3) Postorder Display: 
 Enter Choice: 2
 34 45 66 55 67 89 87 23

<------ OPERATIONS ------->
1) Create The Tree
2) Insert a single Node
3) Display the Tree Structure
4) Display leaf Node of the Tree
5) Create a copy of the tree
6) Depth of the Tree
7) Exit
Enter Choice: 4

1) Inorder Display: 
2) Preorder Display: 
3) Postorder Display: 
 Enter Choice: 3
 66 67 55 45 87 23 89 34

<------ OPERATIONS ------->
1) Create The Tree
2) Insert a single Node
3) Display the Tree Structure
4) Display leaf Node of the Tree
5) Create a copy of the tree
6) Depth of the Tree
7) Exit
Enter Choice: 5

STRUCTURE OF COPIED TREE
<-------------TREE STRUCTURE------------->
                    23

          89

                    87

34

                              67

                    55

          45

                    66

<------ OPERATIONS ------->
1) Create The Tree
2) Insert a single Node
3) Display the Tree Structure
4) Display leaf Node of the Tree
5) Create a copy of the tree
6) Depth of the Tree
7) Exit
Enter Choice: 6
Depth of THe created Tree is: 4

<------ OPERATIONS ------->
1) Create The Tree
2) Insert a single Node
3) Display the Tree Structure
4) Display leaf Node of the Tree
5) Create a copy of the tree
6) Depth of the Tree
7) Exit
Enter Choice: 7



*/