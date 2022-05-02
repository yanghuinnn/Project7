#include "../include/list.h"

/* 创建一个空的顺序表 */
hn* Create_table() {
	//创建头结点
	hn * head_node = (hn *)malloc(sizeof(hn));
	head_node->length = 0;
	head_node->total_element = 0;
	head_node->p0 = NULL;

	//用户输入表长
	printf("输入表长：");
	scanf_s("%d", &(head_node->length));

	//申请空间
	head_node->p0 =	(type)malloc(sizeof(type) * head_node->length);
	
	//申请失败（要释放头结点的空间）
	if (head_node->p0 == NULL) {
		return NULL;
	}
	free(head_node);

	//创建完成
	return head_node;
}

/* 删除顺序表 */
void Delete_table(hn* head_node) {































}