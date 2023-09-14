// zavd_82.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;
#define Space 10

class TreeNode {
public:

	int value;
	TreeNode* left;
	TreeNode* right;

	TreeNode(int val) {
		left = nullptr;
		right = nullptr;
		value = val;
	}
};

void displayTree(TreeNode* root, int space) {

	if (root == nullptr)
	{
		return;
	}
	space += Space;

	displayTree(root->right, space);
	cout << endl;
	for (int i = Space; i < space; i++)
	{
		cout << " ";
	}
	cout << root->value;

	displayTree(root->left, space);
}

void addNode(TreeNode* root, int val) {
	if (root == nullptr)
	{
		return;
	}
	if (val > root->value && root->right == nullptr)
	{
		root->right = new TreeNode(val);
		return;

	}
	if (val < root->value && root->left == nullptr)
	{
		root->left = new TreeNode(val);
		return;

	}
	if (val > root->value)
	{
		root = root->right;
	}
	else {
		root = root->left;
	}
	addNode(root, val);
}

bool binarySearch(TreeNode* root, int val) {
	if (root == nullptr)
	{
		return false;
	}
	if (val == root->value)
	{
		return true;
	}
	else
	{
		if (val > root->value)
		{
			root = root->right;
		}
		else
		{
			root = root->left;
		}
	}

	binarySearch(root, val);
}

int countTwoElements(TreeNode* root, int& count) {

	if (root == nullptr)
	{
		return 0;
	}
	if (root->left != nullptr && root->right != nullptr)
	{
		count++;
	}

	countTwoElements(root->right, count);
	countTwoElements(root->left, count);

	return count;
}

int sumValues(TreeNode* root, int& totalValue) {
	if (root == nullptr) {
		return totalValue;
	}
	totalValue += root->value;

	totalValue = sumValues(root->left, totalValue);
	totalValue = sumValues(root->right, totalValue);

	return totalValue;
}

int maxTreeDepth(TreeNode* root) {
	if (root == nullptr) {
		return 0;
	}

	int leftDepth = maxTreeDepth(root->left);
	int rightDepth = maxTreeDepth(root->right);

	return 1 + max(leftDepth, rightDepth);
}

int main()
{
	TreeNode* rootNode = new TreeNode(10);

	addNode(rootNode, 22);
	addNode(rootNode, 13);
	addNode(rootNode, 30);
	addNode(rootNode, 25);
	addNode(rootNode, 15);
	addNode(rootNode, 9);
	addNode(rootNode, 35);


	int choice;
	do
	{
		cout << "\nMenu\n";
		cout << "1. Display Tree\n";
		cout << "2. Search Number\n";
		cout << "3. Count Elements with Two Children\n";
		cout << "4. Sum of All Elements\n";
		cout << "5. Maximum Depth of Tree\n";
		cout << "6. Exit\n";
		cout << "Enter your choice: ";
		cin >> choice;

		switch (choice)
		{
		case 1:
			displayTree(rootNode, 10);
			break;

		case 2:
			int searchVal;
			cout << "Enter number to search: ";
			cin >> searchVal;
			if (binarySearch(rootNode, searchVal) == true)
			{
				cout << "Number " << searchVal << " is present" << endl;
			}
			else
			{
				cout << "Number " << searchVal << " is missing" << endl;
			}
			break;

		case 3:
			int counter;
			counter = 0;
			cout << "\nNumbers of elements that have two child elements: ";
			cout << countTwoElements(rootNode, counter) << endl;
			break;

		case 4:
			int totalSum;
			totalSum = 0;
			cout << "\nThe sum of all elements is "
				<< sumValues(rootNode, totalSum) << endl;
			break;

		case 5:
			int treeDepth;
			treeDepth = maxTreeDepth(rootNode);
			cout << "\nMaximum depth of the binary tree: " << treeDepth << endl;
			break;

		case 6:
			exit(0);

		default:
			cout << "Invalid choice" << endl;
		}
	} while (choice != 6);
}