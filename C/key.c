#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 判断一个数字是否为素数的函数
bool is_prime(int num) {
  if (num <= 1)
    return false;
  for (int i = 2; i * i <= num; i++) {
    if (num % i == 0)
      return false;
  }
  return true;
}

// 功能1：字符串转换和排序
void function1() {
  char str[100];
  char choice;

  // 输入字符串
  printf("请输入一个字符串(最多99个字符): ");
  scanf("%99s", str); // 限制最大输入字符数为99

  // 清除缓冲区中残留的字符
  while (getchar() != '\n')
    ;

  // 输入操作选择
  printf("请选择操作 (a: 小写转大写, b: 大写转小写, c: 排序从大到小, d: "
         "排序从小到大): ");
  scanf(" %c", &choice);

  int len = strlen(str);

  switch (choice) {
  case 'a':
    for (int i = 0; i < len; i++)
      str[i] = toupper(str[i]);
    printf("转换为大写后的字符串: %s\n", str);
    break;

  case 'b':
    for (int i = 0; i < len; i++)
      str[i] = tolower(str[i]);
    printf("转换为小写后的字符串: %s\n", str);
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
    printf("排序（从大到小）后的字符串: %s\n", str);
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
    printf("排序（从小到大）后的字符串: %s\n", str);
    break;

  default:
    printf("无效选择,请输入a, b, c或d。\n");
    break;
  }
}

// 功能2：条件判断
void function2() {
  int num;
  char choice;

  printf("请输入一个0到1000之间的数字: ");
  scanf("%d", &num);

  if (num < 0 || num > 1000) {
    printf("输入数字不在0到1000范围内。\n");
    return;
  }

  printf("请选择操作 (a: 素数检测, b: 奇数检测, c: 偶数检测, d: 特殊输出): ");
  scanf(" %c", &choice);

  switch (choice) {
  case 'a': {
    if (is_prime(num)) {
      printf("%d 是一个素数。\n", num);
    } else {
      int next_prime = num + 1;
      while (!is_prime(next_prime))
        next_prime++;
      printf("%d 不是素数，最近的下一个素数是: %d\n", num, next_prime);
    }
    break;
  }

  case 'b':
    printf("%d %s奇数。\n", num, (num % 2 != 0) ? "是" : "不是");
    break;

  case 'c':
    printf("%d %s偶数。\n", num, (num % 2 == 0) ? "是" : "不是");
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
      printf("输入的数字不是520。\n");
    }
    break;

  default:
    printf("无效选择,请输入a, b, c或d。\n");
    break;
  }
}

// 链表节点结构
typedef struct Node {
  int data;
  struct Node *next;
} Node;

// 创建一个新节点
Node *create_node(int data) {
  Node *new_node = (Node *)malloc(sizeof(Node));
  new_node->data = data;
  new_node->next = NULL;
  return new_node;
}

// 创建5个节点的链表
Node *create_linked_list() {
  Node *head = NULL;
  Node *current = NULL;
  int data;
  for (int i = 0; i < 5; i++) {
    printf("请输入节点 %d 的值: ", i + 1);
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

// 插入节点
void insert_node(Node **head) {
  int choice, data;
  printf("请输入要插入的节点值: ");
  scanf("%d", &data);
  Node *new_node = create_node(data);

  printf("请选择插入位置 (1: 头部, 2: 中间任意位置, 3: 尾部): ");
  scanf("%d", &choice);

  if (choice == 1) {
    new_node->next = *head;
    *head = new_node;
  } else if (choice == 2) {
    int position;
    printf("请输入要插入的位置(从1开始): ");
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

// 删除节点
void delete_node(Node **head) {
  int position;
  printf("请输入要删除的节点位置(从1开始): ");
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

// 连接两个链表
void concatenate_lists(Node *old_list, Node *new_list) {
  Node *temp = old_list;
  while (temp->next != NULL) {
    temp = temp->next;
  }
  temp->next = new_list;
}

// 输出链表
void display_list(Node *head) {
  Node *temp = head;
  while (temp != NULL) {
    printf("%d -> ", temp->data);
    temp = temp->next;
  }
  printf("NULL\n");
}

// 功能3主函数
void function3() {
  Node *head = create_linked_list();
  char choice;

  while (true) {
    printf("请选择操作 (a: 插入节点, b: 删除节点, c: 新建并连接链表, d: "
           "输出链表, q: 退出): ");
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
      printf("无效选择，请输入 a, b, c, d 或 q。\n");
      break;
    }
  }
}

int main() {
  int choice;

  printf("请输入一个1到10之间的数字来选择功能: ");
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
    printf("无效输入,请输入1到10之间的数字。\n");
    break;
  }

  return 0;
}
