#include "../include/list.h"

/* ����һ���յ�˳��� */
hn* Create_table() {
	//����ͷ���
	hn * head_node = (hn *)malloc(sizeof(hn));
	head_node->length = 0;
	head_node->total_element = 0;
	head_node->p0 = NULL;

	//�û������
	printf("�������");
	scanf_s("%d", &(head_node->length));

	//����ռ�
	head_node->p0 =	(type)malloc(sizeof(type) * head_node->length);
	
	//����ʧ�ܣ�Ҫ�ͷ�ͷ���Ŀռ䣩
	if (head_node->p0 == NULL) {
		return NULL;
	}
	free(head_node);

	//�������
	return head_node;
}

/* ɾ��˳��� */
void Delete_table(hn* head_node) {































}