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
		free(head_node);
		head_node = NULL;
		return NULL;
	}

	//�������
	return head_node;
}

/* ɾ��˳��� */
void Delete_table(hn* head_node) {
	//ͷ�����ڣ�����ɾ��
	if (head_node != NULL) {
		//�ͷ�����
		if (head_node->p0 != NULL) {
			free(head_node->p0);
		}

		//�ͷ�ͷ���
		free(head_node);
		head_node = NULL;
	}
	
	//ɾ�����
	return;
}

/* ���˳������������ */
hn* Clear_contents(hn* head_node) {
	//ͷ������
	if (head_node != NULL) {
		//˳������
		if (head_node->p0 != NULL) {
			//�ͷ�˳�������
			free(head_node->p0);
			head_node->p0 = NULL;
			
			//����Ԫ��������Ϊ0
			head_node->total_element = 0;
		}
	}

	//������
	return head_node;
}

/* �ж�˳����Ƿ�Ϊ�� */
bool Is_empty(hn* head_node) {
	//ͷ������
	if (head_node != NULL) {
		//����Ԫ������Ϊ0���ǿձ�
		if (head_node->total_element == 0) {
			return 0;
		}

		//˳���Ϊ��
		return 1;
	}
}

/* ����˳���������Ԫ�ص����� */
int Calculate_total(hn* head_node) {
	//ͷ������
	if (head_node != NULL) {
		//����˳���������Ԫ�ص�����
		return head_node->total_element;
	}
	else {
		//ͷ��㲻���ڣ�û��˳�������û������Ԫ��
		return -1;
	}
}

/* ��ȡ��ͷ���� */
int Get_first(hn* head_node) {
	//ͷ������
	if (head_node != NULL) {
		//˳������������Ԫ���������ڵ���1
		if (head_node->p0 != NULL && head_node->total_element >= 1) {
			//���ر�ͷԪ�ص�����
			return *head_node->p0;
		}
	}
}

/* ��ȡ��β���� */
int Get_end(hn* head_node) {
	//ͷ������
	if (head_node != NULL) {
		//�����������Ԫ���������ڵ���1
		if (head_node->p0 != NULL && head_node->total_element >= 1) {
			//���ر�βԪ�ص�����
			return *(head_node->p0 + head_node->total_element - 1);
		}
	}		
}

/* ��ȡĳһԪ�ص�ǰ�� */
int Get_front(hn* head_node, int n) {
	//ͷ�������ұ������������Ԫ��
	if (head_node != NULL && head_node->p0 != NULL && head_node->total_element >= 1) {
		//��nָ�����ǵ�һ������Ԫ�أ��޷���ȡ��ǰ��
		if (n == 1) {
			return fail;
		}
		else {
			//��nָ���Ĳ��ǵ�һ������Ԫ�أ�����ǰ��
			return *(head_node->p0 + n - 2);
		}
	}
}

/* ��ȡĳһԪ�صĺ�� */
int Get_rear(hn* head_node, int n) {
	//ͷ�������ұ������������Ԫ��
	if (head_node != NULL && head_node->p0 != NULL && head_node->total_element >= 1) {
		//��nָ���������һ������Ԫ�أ��޷���ȡ����
		if (n == head_node->total_element) {
			return fail;
		}
		else {
			//��nָ���Ĳ������һ������Ԫ�أ����غ��
			return *(head_node->p0 + n);
		}
	}
}

/* ��ȡĳһλ�õ�����Ԫ�ص�ֵ */
int Read_values(hn* head_node, int n) {
	//ͷ�����ڡ���Ҳ���ڡ�������Ԫ��
	if (head_node != NULL && head_node->p0 != NULL && head_node->total_element >= 1) {
		//���ض�ȡ����ֵ
		return *(head_node->p0 + n - 1);
	}
	else {
		//��ʧ��
		return fail;
	}
}

/* ���ұ����Ƿ����ĳ��ֵ����ƥ�䣬�����������Ԫ�ص�λ�� */
void Find_value(hn* head_node, int x) {
	//ͷ�����ڡ�����ڡ�������Ԫ��
	if (head_node != NULL && head_node->p0 != NULL && head_node->total_element >= 1) {
		//�ҳ�ƥ���ֵ
		for (int i = 0; i < head_node->total_element; i++) {
			if (x == *(head_node->p0 + i)) {
				printf("%d ", i);
			}
		}
		putchar('\n');
	}
	else {
		//���ܲ���
		return;
	}
}

/* ��ӡ˳��� */
void Print_table(hn* head_node) {
	//ͷ�����ڡ�����ڡ���������Ԫ��
	if (head_node != NULL && head_node->p0 != NULL && head_node->total_element >= 1) {
		//��ӡ
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

/* ��������Ԫ�� */
hn* Insert_elements(hn* head_node, int n, int x) {
	//ͷ�����ڡ������
	if (head_node != NULL && head_node->p0 != NULL) {
		//����

	}

}

/* ɾ������Ԫ�� */
hn* Remove_elements(hn* head_node, int n) {
	//ͷ�����ڡ�����ڡ�������Ԫ��

}


