#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};
// ������������ ���������� ������
struct Node* CreateTree(struct Node* root, int data) 
{
    if (root == NULL) // ���� ������ ������ 
    {
        root = (struct Node*)malloc(sizeof(struct Node)); // ���������� � ������
        if (root == NULL) // ���� �� ������� ��������� ������
        {
            printf("������ ��������� ������");
            exit(0); // ���������� ������ 
        }
        root->left = NULL;
        root->right = NULL;
        root->data = data;
        return root;
    }
    if (data < root->data) // ���� ������� ������� ������ �������� ����
    {
        root->left = CreateTree(root->left, data); // �� ����� ���������
    }
    else if (data > root->data) // // ���� ������� ������� ������ �������� ����
    {
        root->right = CreateTree(root->right, data); // �� ������ ���������
    } // ���������� ������������� ��������, ������� = ���� 

    return root;
}

int CountOccurrences(struct Node* root, int target) {
    if (root == NULL)
        return 0;

    if (root->data == target)
        return 1 + CountOccurrences(root->left, target) + CountOccurrences(root->right, target);
    else if (target < root->data)
        return CountOccurrences(root->left, target);
    else
        return CountOccurrences(root->right, target);
}

void print_tree(struct Node* r, int l) {
    if (r == NULL)
        return;

    print_tree(r->right, l + 1);
    for (int i = 0; i < l; i++) {
        printf(" ");
    }
    printf("%d\n", r->data);
    print_tree(r->left, l + 1);
}

int main() {
    setlocale(LC_ALL, "RUS");
    int end, start = 1;

    struct Node* root = NULL;

    printf("\t\t\t\t������� -10, ����� ���������� ���������� ������: \n");
    while (start) {
        printf("������� �����: ");
        scanf("%d", &end);
        if (end == -10) {
            printf("���������� ������ ��������\n\n");
            start = 0;
        }
        else {
            root = CreateTree(root, end);
        }
    }

    print_tree(root, 0);

    return 0;
}
