#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

struct Node{
  int data;
  struct Node* left;
  struct Node* right;
};

struct Node* CreateTree(struct Node* root, int data) {
	if (root == NULL) {
		root = (struct Node*)malloc(sizeof(struct Node));
		if (root == NULL) {
			printf("Ошибка выделения памяти.\n");
			exit(0);
		}
		root->left = NULL;
		root->right = NULL;
		root->data = data;
		return root;
	}

	if(data > root->data) {
		root->right = CreateTree(root->right, data);
	} 
	else 
	{
		root->left = CreateTree(root->left, data);
	}
	return root;
}

void print_tree(struct Node* root, int l) {
	if (root == NULL) {
		return;
	}

	print_tree(root->right, l + 1);
	for (int i = 0; i < l; i++) {
		printf(" ");
	}

	printf("%d\n", root->data);
	print_tree(root->left, l + 1);
}

int CountOccurrences(struct Node* root, int target) 
{
	if (root == NULL) 
	{
		return 0;
	}
	if (root->data == target) 
	{
		return 1 + CountOccurrences(root->left, target) + CountOccurrences(root->right, target);
	}
	else if (target < root->data) 
	{
	return CountOccurrences(root->left, target);
	} 
	else 
	{
	return CountOccurrences(root->right, target);
  }
}

int main() 
{
	setlocale(LC_ALL, "RUS");

	int D, start = 1, c = 0, C = 0;
	struct Node* root = NULL;
	int counter[100];
	printf("\t\t\t\t\tВведите -10, чтобы остановить построение дерева\n");

	while(start) 
	{
		printf("Введите число: ");
		scanf("%d", &D);
		if (D == -10) 
		{
			printf("Построение дерева окончено. \n\n");
			start = 0;
		}
		else
		{
			if (D != -10) {
				counter[c] = D;
			}
		  root = CreateTree(root, D);
		}
		c++;
	}
	print_tree(root, 0);

	printf("\nВведите значение для подсчета вхождений: ");
	scanf("%d", &D);

	int count = CountOccurrences(root, D);

	printf("\nЗначение %d встречается %d раз(а) в дереве\n", D, count);

	for (int i = 0; i < c; i++) 
	{
		if (counter[i] == D) 
		{
			C++;
		}
	}
	printf("\nЧисло %d находится на %d уровне\n", D, C);

	return 0;
}