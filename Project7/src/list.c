#include "../include/list.h"
#include <stdlib.h>

#define ADD 50

int location, data;

/* 创建一个空的顺序表 */
hn* Create_table() {
	//创建头结点
	hn * head_node = (hn *)malloc(sizeof(hn));
	if (head_node == NULL) {
		return NULL;
	}
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
		printf("%d\n", head_node->total_element);
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
			printf("%d\n", *head_node->p0);
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
			printf("%d\n", *(head_node->p0 + head_node->total_element - 1));
			return *(head_node->p0 + head_node->total_element - 1);
		}
	}		
}

/* 获取某一元素的前驱 */
int Get_front(hn* head_node) {
	printf("输入元素位置，以获取前驱：");
	scanf_s("%d", &location);
	//头结点存在且表存在且有数据元素
	if (head_node != NULL && head_node->p0 != NULL && head_node->total_element >= 1) {
		//当n指代的是第一个数据元素，无法获取其前驱
		if (location == 1) {
			return fail;
		}
		else {
			//当n指代的不是第一个数据元素，返回前驱
			printf("%d\n", *(head_node->p0 + location - 2));
			return *(head_node->p0 + location - 2);
		}
	}
}

/* 获取某一元素的后继 */
int Get_rear(hn* head_node) {
	printf("输入元素位置，以获取后继：");
	scanf_s("%d", &location);
	//头结点存在且表存在且有数据元素
	if (head_node != NULL && head_node->p0 != NULL && head_node->total_element >= 1) {
		//当n指代的是最后一个数据元素，无法获取其后继
		if (location == head_node->total_element) {
			return fail;
		}
		else {
			//当n指代的不是最后一个数据元素，返回后继
			printf("%d\n", *(head_node->p0 + location));
			return *(head_node->p0 + location);
		}
	}
}

/* 读取某一位置的数据元素的值 */
int Read_values(hn* head_node) {
	printf("输入读取位置：");
	scanf_s("%d", &location);
	//头结点存在、表也存在、有数据元素
	if (head_node != NULL && head_node->p0 != NULL && head_node->total_element >= 1) {
		//返回读取到的值
		printf("%d\n", *(head_node->p0 + location - 1));
		return *(head_node->p0 + location - 1);
	}
	else {
		//读失败
		return fail;
	}
}

/* 查找表中是否存在某个值，有匹配，则输出该数据元素的位置 */
void Find_value(hn* head_node) {
	printf("输入查找值：");
	scanf_s("%d", &data);
	//头结点存在、表存在、有数据元素
	if (head_node != NULL && head_node->p0 != NULL && head_node->total_element >= 1) {
		//找出匹配的值
		for (int i = 0; i < head_node->total_element; i++) {
			if (data == *(head_node->p0 + i)) {
				printf("%d ", i + 1);
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
hn* Insert_elements(hn* head_node) {
	printf("请输出插入位置以及数据，使用逗号分隔：");
	scanf_s("%d,%d", &location, &data);
	//头结点存在、表存在、要插入的位置合理，才能插入
	if (head_node != NULL && head_node->p0 != NULL && location >= 1 && location <= (head_node->total_element + 1)) {
		int i;
		//表没满
		if (head_node->total_element < head_node->length) {
			//头部插入
			if (location == 1) {
				//从最后开始，先把所有元素往后移一位
				for (i = head_node->total_element - 1; i >= 0; i--) {
					*(head_node->p0 + i + 1) = *(head_node->p0 + i);
				}
				//将值x赋给首元素
				*(head_node->p0) = data;
			}
			else if (location == head_node->total_element) {	//尾部插入
				//直接赋值
				*(head_node->p0 + head_node->total_element) = data;
			}
			else {	//中间插入
				//从最后一个元素开始，直到被插入位置的元素，将它们依次向后移动一位
				for (i = head_node->total_element - 1; i >= location - 1; i--) {
					*(head_node->p0 + i + 1) = *(head_node->p0 + i);
				}
				//在n处插入x
				*(head_node->p0 + location - 1) = data;
			}
		}
		else {	//表满了
			//扩增表
			type new_p = (type)malloc(sizeof(type) * (head_node->length + ADD));
			if (new_p == NULL) {
				return NULL;
			}
			//在首
			if (location == 1) {
				//先将x赋给新表的首元素
				*new_p = data;
				//再将旧表的数据从头开始依次拷贝到新表里
				for (i = 0; i < head_node->total_element; i++) {
					*(new_p + i + 1) = *(head_node->p0 + i);
				}
			}
			else if (location == head_node->total_element) {	//在尾
				//将旧表的数据从头开始依次拷贝到新表里
				for (i = 0; i < head_node->total_element; i++) {
					*(new_p + i) = *(head_node->p0 + i);
				}
				//将x赋给新表的尾元素
				*(new_p + head_node->total_element) = data;
			}
			else {	//在中间
				//先拷贝要插入位前的所有元素
				for (i = 0; i < location - 1; i++) {
					*(new_p + i) = *(head_node->p0 + i);
				}
				//赋值x到插入位
				*(new_p + i) = data;
				//再拷贝插入位后的元素
				for (; i < head_node->total_element; i++) {
					*(new_p + i + 1) = *(head_node->p0 + i);
				}
			}

			//把旧表释放
			free(head_node->p0);

			//把new_p赋给head_node->p0
			head_node->p0 = new_p;

			//表长要变
			head_node->length += ADD;
		}
		
		//表中数据元素总量要变
		head_node->total_element++;
	}
	else {	//不能插入

	}
	
	//插入完成
	return head_node;

}

/* 删除数据元素 */
hn* Remove_elements(hn* head_node) {
	printf("输入删除位：");
	scanf_s("%d", &location);
	//头结点存在、表存在、有数据元素、删除位置合理，则删除
	if (head_node != NULL && head_node->p0 != NULL && head_node->total_element >= 1 && location >= 1 && location <= head_node->total_element) {
		int i;
		//删除头
		if (location == 1) {
			//直接从第二个元素开始往前覆盖
			for (i = 1; i < head_node->total_element; i++) {
				*(head_node->p0 + i - 1) = *(head_node->p0 + i);
			}
		}
		else if (location == head_node->total_element) {	//删除尾
			//删除尾部不需要做任何操作，总元素数量减1，就相当于把最后一个元素给删除了，在我们的理解中，
			//total_element包含的才是有效的值，在这之外的虽然可以访问，我们认为是无效的访问。
		}
		else {	//删除中间
			//从删除位的后一位开始往前移动一位
			for (i = location; i < head_node->total_element; i++) {
				*(head_node->p0 + i - 1) = *(head_node->p0 + i);
			}
		}
		
		//总元素数量减1
		head_node->total_element--;
	}
	else {	//不能删除

	}

	//删除结束
	return head_node;
}

/* 修改数据元素 */
hn* Modify_element(hn* head_node) {
	printf("输入修改位置及修改值，使用逗号分隔：");
	scanf_s("%d,%d", &location, &data);
	//头结点存在、表存在、有数据元素、修改位置合理，则修改
	if (head_node != NULL && head_node->p0 != NULL && head_node->total_element >= 1 && location >= 1 && location <= head_node->total_element) {
		//修改值
		*(head_node->p0 + location - 1) = data;
	}

	//修改完成
	return head_node;
}
