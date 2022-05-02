#include <stdio.h>

#ifndef __LIST_H__
#define __LIST_H__

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


/* 判断顺序表是否为空 */


/* 计算顺序表中数据元素的总量 */


/* 表头 */


/* 表尾 */


/* 前驱 */


/* 后继 */


/* 读取某一位置的数据元素的值 */


/* 查找表中是否存在某个值，有匹配，则输出该数据元素的位置 */


/* 打印顺序表 */


/* 插入数据元素 */


/* 删除数据元素 */



#endif // !__LIST_H__

