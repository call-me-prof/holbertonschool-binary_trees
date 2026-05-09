#include "binary_trees.h"

/**
 * tree_height - measures tree height
 * @tree: pointer to root node
 *
 * Return: height
 */
size_t tree_height(const binary_tree_t *tree)
{
	size_t left, right;

	if (tree == NULL)
		return (0);

	left = tree_height(tree->left);
	right = tree_height(tree->right);

	if (left > right)
		return (left + 1);

	return (right + 1);
}

/**
 * binary_tree_is_perfect - checks if a binary tree is perfect
 * @tree: pointer to root node
 *
 * Return: 1 if perfect, 0 otherwise
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	if (tree->left == NULL && tree->right == NULL)
		return (1);

	if (tree->left && tree->right &&
	    tree_height(tree->left) == tree_height(tree->right))
		return (binary_tree_is_perfect(tree->left) &&
			binary_tree_is_perfect(tree->right));

	return (0);
}
