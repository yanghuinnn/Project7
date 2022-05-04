#include <stdio.h>
#include <stdbool.h>

#ifndef __LIST_H__
#define __LIST_H__

#define fail -999999999; 


typedef int* type;

/* 头结点 */
typedef struct head_node {
	int length;	//表长
	int total_element;	//表中数据元素的总数
	type p0;	//表的首元结点（第一个数据元素）的地址
}hn;

/* 创建一个空的顺序表 */
hn* Create_table();

/* 删除顺序表 */
void Delete_table(hn * head_node);

/* 清除顺序表的所有内容 */
hn* Clear_contents(hn * head_node);

/* 判断顺序表是否为空 */
bool Is_empty(hn* head_node);

/* 计算顺序表中数据元素的总量 */
int Calculate_total(hn* head_node);

/* 获取表头数据 */
int Get_first(hn* head_node);

/* 获取表尾数据 */
int Get_end(hn* head_node);

/* 获取某一元素的前驱 */
int Get_front(hn* head_node);

/* 获取某一元素的后继 */
int Get_rear(hn* head_node);

/* 读取某一位置的数据元素的值 */
int Read_values(hn* head_node);

/* 查找表中是否存在某个值，有匹配，则输出该数据元素的位置 */
void Find_value(hn* head_node);

/* 打印顺序表 */
void Print_table(hn* head_node);

/* 插入数据元素 */
hn* Insert_elements(hn* head_node);

/* 删除数据元素 */
hn* Remove_elements(hn* head_node);

/* 修改数据元素 */
hn* Modify_element(hn* head_node);

#endif // !__LIST_H__

