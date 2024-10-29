#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// �ж�һ�������Ƿ�Ϊ�����ĺ���
bool is_prime(int num) {
  if (num <= 1)
    return false;
  for (int i = 2; i * i <= num; i++) {
    if (num % i == 0)
      return false;
  }
  return true;
}

// ����1���ַ���ת��������
void function1() {
  char str[100];
  char choice;

  // �����ַ���
  printf("������һ���ַ���(���99���ַ�): ");
  scanf("%99s", str); // ������������ַ���Ϊ99

  // ����������в������ַ�
  while (getchar() != '\n')
    ;

  // �������ѡ��
  printf("��ѡ����� (a: Сдת��д, b: ��дתСд, c: ����Ӵ�С, d: "
         "�����С����): ");
  scanf(" %c", &choice);

  int len = strlen(str);

  switch (choice) {
  case 'a':
    for (int i = 0; i < len; i++)
      str[i] = toupper(str[i]);
    printf("ת��Ϊ��д����ַ���: %s\n", str);
    break;

  case 'b':
    for (int i = 0; i < len; i++)
      str[i] = tolower(str[i]);
    printf("ת��ΪСд����ַ���: %s\n", str);
    break;

  case 'c':
    for (int i = 0; i < len - 1; i++) {
      for (int j = i + 1; j < len; j++) {
        if (str[i] < str[j]) {
          char temp = str[i];
          str[i] = str[j];
          str[j] = temp;
        }
      }
    }
    printf("���򣨴Ӵ�С������ַ���: %s\n", str);
    break;

  case 'd':
    for (int i = 0; i < len - 1; i++) {
      for (int j = i + 1; j < len; j++) {
        if (str[i] > str[j]) {
          char temp = str[i];
          str[i] = str[j];
          str[j] = temp;
        }
      }
    }
    printf("���򣨴�С���󣩺���ַ���: %s\n", str);
    break;

  default:
    printf("��Чѡ��,������a, b, c��d��\n");
    break;
  }
}

// ����2�������ж�
void function2() {
  int num;
  char choice;

  printf("������һ��0��1000֮�������: ");
  scanf("%d", &num);

  if (num < 0 || num > 1000) {
    printf("�������ֲ���0��1000��Χ�ڡ�\n");
    return;
  }

  printf("��ѡ����� (a: �������, b: �������, c: ż�����, d: �������): ");
  scanf(" %c", &choice);

  switch (choice) {
  case 'a': {
    if (is_prime(num)) {
      printf("%d ��һ��������\n", num);
    } else {
      int next_prime = num + 1;
      while (!is_prime(next_prime))
        next_prime++;
      printf("%d �����������������һ��������: %d\n", num, next_prime);
    }
    break;
  }

  case 'b':
    printf("%d %s������\n", num, (num % 2 != 0) ? "��" : "����");
    break;

  case 'c':
    printf("%d %sż����\n", num, (num % 2 == 0) ? "��" : "����");
    break;

  case 'd':
    if (num == 520) {
      printf("  **   **  \n");
      printf(" *  * *  * \n");
      printf("*    *    *\n");
      printf(" *       * \n");
      printf("   *   *   \n");
      printf("     *     \n");

    } else {
      printf("��������ֲ���520��\n");
    }
    break;

  default:
    printf("��Чѡ��,������a, b, c��d��\n");
    break;
  }
}

// ����ڵ�ṹ
typedef struct Node {
  int data;
  struct Node *next;
} Node;

// ����һ���½ڵ�
Node *create_node(int data) {
  Node *new_node = (Node *)malloc(sizeof(Node));
  new_node->data = data;
  new_node->next = NULL;
  return new_node;
}

// ����5���ڵ������
Node *create_linked_list() {
  Node *head = NULL;
  Node *current = NULL;
  int data;
  for (int i = 0; i < 5; i++) {
    printf("������ڵ� %d ��ֵ: ", i + 1);
    scanf("%d", &data);
    Node *new_node = create_node(data);
    if (head == NULL) {
      head = new_node;
      current = head;
    } else {
      current->next = new_node;
      current = new_node;
    }
  }
  return head;
}

// ����ڵ�
void insert_node(Node **head) {
  int choice, data;
  printf("������Ҫ����Ľڵ�ֵ: ");
  scanf("%d", &data);
  Node *new_node = create_node(data);

  printf("��ѡ�����λ�� (1: ͷ��, 2: �м�����λ��, 3: β��): ");
  scanf("%d", &choice);

  if (choice == 1) {
    new_node->next = *head;
    *head = new_node;
  } else if (choice == 2) {
    int position;
    printf("������Ҫ�����λ��(��1��ʼ): ");
    scanf("%d", &position);
    Node *temp = *head;
    for (int i = 1; temp != NULL && i < position - 1; i++) {
      temp = temp->next;
    }
    new_node->next = temp->next;
    temp->next = new_node;
  } else if (choice == 3) {
    Node *temp = *head;
    while (temp->next != NULL) {
      temp = temp->next;
    }
    temp->next = new_node;
  }
}

// ɾ���ڵ�
void delete_node(Node **head) {
  int position;
  printf("������Ҫɾ���Ľڵ�λ��(��1��ʼ): ");
  scanf("%d", &position);

  if (position == 1) {
    Node *temp = *head;
    *head = (*head)->next;
    free(temp);
    return;
  }

  Node *temp = *head;
  for (int i = 1; temp != NULL && i < position - 1; i++) {
    temp = temp->next;
  }
  if (temp == NULL || temp->next == NULL)
    return;

  Node *next = temp->next->next;
  free(temp->next);
  temp->next = next;
}

// ������������
void concatenate_lists(Node *old_list, Node *new_list) {
  Node *temp = old_list;
  while (temp->next != NULL) {
    temp = temp->next;
  }
  temp->next = new_list;
}

// �������
void display_list(Node *head) {
  Node *temp = head;
  while (temp != NULL) {
    printf("%d -> ", temp->data);
    temp = temp->next;
  }
  printf("NULL\n");
}

// ����3������
void function3() {
  Node *head = create_linked_list();
  char choice;

  while (true) {
    printf("��ѡ����� (a: ����ڵ�, b: ɾ���ڵ�, c: �½�����������, d: "
           "�������, q: �˳�): ");
    scanf(" %c", &choice);

    if (choice == 'q') {
      break;
    }

    switch (choice) {
    case 'a':
      insert_node(&head);
      break;
    case 'b':
      delete_node(&head);
      break;
    case 'c': {
      Node *new_list = create_linked_list();
      concatenate_lists(head, new_list);
      break;
    }
    case 'd':
      display_list(head);
      break;
    default:
      printf("��Чѡ�������� a, b, c, d �� q��\n");
      break;
    }
  }
}

int main() {
  int choice;

  printf("������һ��1��10֮���������ѡ����: ");
  scanf("%d", &choice);

  switch (choice) {
  case 1:
    function1();
    break;
  case 2:
    function2();
    break;
  case 3:
    function3();
    break;
  default:
    printf("��Ч����,������1��10֮������֡�\n");
    break;
  }

  return 0;
}
