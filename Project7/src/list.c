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
		free(head_node);
		head_node = NULL;
		return NULL;
	}

	//创建完成
	return head_node;
}

/* 删除顺序表 */
void Delete_table(hn* head_node) {
	//头结点存在，进行删除
	if (head_node != NULL) {
		//释放数组
		if (head_node->p0 != NULL) {
			free(head_node->p0);
		}

		//释放头结点
		free(head_node);
		head_node = NULL;
	}
	
	//删除完成
	return;
}

/* 清除顺序表的所有内容 */
hn* Clear_contents(hn* head_node) {
	//头结点存在
	if (head_node != NULL) {
		//顺序表存在
		if (head_node->p0 != NULL) {
			//释放顺序表内容
			free(head_node->p0);
			head_node->p0 = NULL;
			
			//数据元素总数置为0
			head_node->total_element = 0;
		}
	}

	//清除完成
	return head_node;
}

/* 判断顺序表是否为空 */
bool Is_empty(hn* head_node) {
	//头结点存在
	if (head_node != NULL) {
		//数据元素总数为0，是空表
		if (head_node->total_element == 0) {
			return 0;
		}

		//顺序表不为空
		return 1;
	}
}

/* 计算顺序表中数据元素的总量 */
int Calculate_total(hn* head_node) {
	//头结点存在
	if (head_node != NULL) {
		//返回顺序表中数据元素的总量
		return head_node->total_element;
	}
	else {
		//头结点不存在，没有顺序表，所以没有数据元素
		return -1;
	}
}

/* 获取表头数据 */
int Get_first(hn* head_node) {
	//头结点存在
	if (head_node != NULL) {
		//顺序表存在且数据元素总量大于等于1
		if (head_node->p0 != NULL && head_node->total_element >= 1) {
			//返回表头元素的数据
			return *head_node->p0;
		}
	}
}

/* 获取表尾数据 */
int Get_end(hn* head_node) {
	//头结点存在
	if (head_node != NULL) {
		//表存在且数据元素总量大于等于1
		if (head_node->p0 != NULL && head_node->total_element >= 1) {
			//返回表尾元素的数据
			return *(head_node->p0 + head_node->total_element - 1);
		}
	}		
}

/* 获取某一元素的前驱 */
int Get_front(hn* head_node, int n) {
	//头结点存在且表存在且有数据元素
	if (head_node != NULL && head_node->p0 != NULL && head_node->total_element >= 1) {
		//当n指代的是第一个数据元素，无法获取其前驱
		if (n == 1) {
			return fail;
		}
		else {
			//当n指代的不是第一个数据元素，返回前驱
			return *(head_node->p0 + n - 2);
		}
	}
}

/* 获取某一元素的后继 */
int Get_rear(hn* head_node, int n) {
	//头结点存在且表存在且有数据元素
	if (head_node != NULL && head_node->p0 != NULL && head_node->total_element >= 1) {
		//当n指代的是最后一个数据元素，无法获取其后继
		if (n == head_node->total_element) {
			return fail;
		}
		else {
			//当n指代的不是最后一个数据元素，返回后继
			return *(head_node->p0 + n);
		}
	}
}

/* 读取某一位置的数据元素的值 */
int Read_values(hn* head_node, int n) {
	//头结点存在、表也存在、有数据元素
	if (head_node != NULL && head_node->p0 != NULL && head_node->total_element >= 1) {
		//返回读取到的值
		return *(head_node->p0 + n - 1);
	}
	else {
		//读失败
		return fail;
	}
}

/* 查找表中是否存在某个值，有匹配，则输出该数据元素的位置 */
void Find_value(hn* head_node, int x) {
	//头结点存在、表存在、有数据元素
	if (head_node != NULL && head_node->p0 != NULL && head_node->total_element >= 1) {
		//找出匹配的值
		for (int i = 0; i < head_node->total_element; i++) {
			if (x == *(head_node->p0 + i)) {
				printf("%d ", i);
			}
		}
		putchar('\n');
	}
	else {
		//不能查找
		return;
	}
}

/* 打印顺序表 */
void Print_table(hn* head_node) {
	//头结点存在、表存在、且有数据元素
	if (head_node != NULL && head_node->p0 != NULL && head_node->total_element >= 1) {
		//打印
		for (int i = 0; i < head_node->total_element; i++) {
			printf("%d ", *(head_node->p0 + i));
		}
		putchar('\n');
	}
	else
	{
		return;
	}
}

/* 插入数据元素 */
hn* Insert_elements(hn* head_node, int n, int x) {
	//头结点存在、表存在
	if (head_node != NULL && head_node->p0 != NULL) {
		//插入

	}

}

/* 删除数据元素 */
hn* Remove_elements(hn* head_node, int n) {
	//头结点存在、表存在、有数据元素

}


