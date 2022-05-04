#include <stdio.h>
#include <stdbool.h>

#ifndef __LIST_H__
#define __LIST_H__

#define fail -999999999; 


typedef int* type;

/* ͷ��� */
typedef struct head_node {
	int length;	//��
	int total_element;	//��������Ԫ�ص�����
	type p0;	//�����Ԫ��㣨��һ������Ԫ�أ��ĵ�ַ
}hn;

/* ����һ���յ�˳��� */
hn* Create_table();

/* ɾ��˳��� */
void Delete_table(hn * head_node);

/* ���˳������������ */
hn* Clear_contents(hn * head_node);

/* �ж�˳����Ƿ�Ϊ�� */
bool Is_empty(hn* head_node);

/* ����˳���������Ԫ�ص����� */
int Calculate_total(hn* head_node);

/* ��ȡ��ͷ���� */
int Get_first(hn* head_node);

/* ��ȡ��β���� */
int Get_end(hn* head_node);

/* ��ȡĳһԪ�ص�ǰ�� */
int Get_front(hn* head_node);

/* ��ȡĳһԪ�صĺ�� */
int Get_rear(hn* head_node);

/* ��ȡĳһλ�õ�����Ԫ�ص�ֵ */
int Read_values(hn* head_node);

/* ���ұ����Ƿ����ĳ��ֵ����ƥ�䣬�����������Ԫ�ص�λ�� */
void Find_value(hn* head_node);

/* ��ӡ˳��� */
void Print_table(hn* head_node);

/* ��������Ԫ�� */
hn* Insert_elements(hn* head_node);

/* ɾ������Ԫ�� */
hn* Remove_elements(hn* head_node);

/* �޸�����Ԫ�� */
hn* Modify_element(hn* head_node);

#endif // !__LIST_H__

