#include <stdio.h>

#ifndef __LIST_H__
#define __LIST_H__

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


/* �ж�˳����Ƿ�Ϊ�� */


/* ����˳���������Ԫ�ص����� */


/* ��ͷ */


/* ��β */


/* ǰ�� */


/* ��� */


/* ��ȡĳһλ�õ�����Ԫ�ص�ֵ */


/* ���ұ����Ƿ����ĳ��ֵ����ƥ�䣬�����������Ԫ�ص�λ�� */


/* ��ӡ˳��� */


/* ��������Ԫ�� */


/* ɾ������Ԫ�� */



#endif // !__LIST_H__

