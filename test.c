#include<stdio.h>
#include<stdlib.h>
struct test {
		int val;
		struct test *next;
	};
void printftest(struct test *head) {
	struct test *p = head;
	while (p != NULL) {
		printf("%d\n", p->val);
		p = p->next;
	}
}
void tailtest(struct test **head, int num) {
	struct test *newnode = malloc(sizeof(struct test));
	newnode->val = num;
	newnode->next = NULL;
	if (*head == NULL) {
		*head = newnode;
		return;
	}
	struct test *p = *head;
	while (p->next != NULL) {
		p = p->next;
	}
	p->next = newnode;
}
void headtest(struct test **head, int num) {
	struct test *newnode = malloc(sizeof(struct test));
	newnode->val = num;
	newnode->next = *head;
	*head = newnode;
}
void deletetest(struct test **head, int num) {
	struct test *p = *head;
	while (*head != NULL && p->val == num) {
		*head = p->next;
		free(p);
		p = *head;
	}
	p = *head;
	while (p != NULL && p->next != NULL) {
		if (p->next->val == num) {
			p->next = p->next->next;
			free(p->next);
		} else {
			p = p->next;
		}
	}
}
struct test* findtest(struct test *head, int num) {
	struct test *p = head;
	while (p != NULL) {
		if (p->val == num) {
			return p;
		}
		p = p->next;
	}
	return NULL;
}
void changetest(struct test *head, int old, int new) {
	struct test *p = findtest(head, old);
	if (p == NULL) {
		return;
	}
	p->val = new;
	return;
}
int main() {
	struct test *head = NULL;
	headtest(&head, 44);
	tailtest(&head, 11);
	tailtest(&head, 11);
	tailtest(&head, 22);
	tailtest(&head, 33);
	headtest(&head, 55);
	headtest(&head, 55);
	printftest(head);
	deletetest(&head, 55);
	printftest(head);
	struct test *res = findtest(head, 33);
	if (res != NULL) {
		printf("找到了%d\n", res->val);
	} else {
		printf("no\n");
	}
	res = findtest(head, 32);
	if (res != NULL) {
		printf("找到了%d\n", res->val);
	} else {
		printf("no\n");
	}
	changetest(head, 33 , 88);
	printftest(head);
	return 0;
}