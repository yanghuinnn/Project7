#include "../include/list.h"

#define ADD 50

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
	//ͷ�����ڡ�����ڡ�Ҫ�����λ�ú������ܲ���
	if (head_node != NULL && head_node->p0 != NULL && n >= 0 && n <= (head_node->total_element + 1)) {
		int i;
		//��û��
		if (head_node->total_element < head_node->length) {
			//ͷ������
			if (n == 1) {
				//�����ʼ���Ȱ�����Ԫ��������һλ
				for (i = head_node->total_element - 1; i >= 0; i--) {
					*(head_node->p0 + i + 1) = *(head_node->p0 + i);
				}
				//��ֵx������Ԫ��
				*(head_node->p0) = x;
			}
			else if (n == head_node->total_element) {	//β������
				//ֱ�Ӹ�ֵ
				*(head_node->p0 + head_node->total_element) = x;
			}
			else {	//�м����
				//�����һ��Ԫ�ؿ�ʼ��ֱ��������λ�õ�Ԫ�أ���������������ƶ�һλ
				for (i = head_node->total_element - 1; i >= n - 1; i--) {
					*(head_node->p0 + i + 1) = *(head_node->p0 + i);
				}
				//��n������x
				*(head_node->p0 + n - 1) = x;
			}
		}
		else {	//������
			//������
			type new_p = (type)malloc(sizeof(type) * (head_node->length + ADD));
			//����
			if (n == 1) {
				//�Ƚ�x�����±����Ԫ��
				*new_p = x;
				//�ٽ��ɱ�����ݴ�ͷ��ʼ���ο������±���
				for (i = 0; i < head_node->total_element; i++) {
					*(new_p + i + 1) = *(head_node->p0 + i);
				}
			}
			else if (n == head_node->total_element) {	//��β
				//���ɱ�����ݴ�ͷ��ʼ���ο������±���
				for (i = 0; i < head_node->total_element; i++) {
					*(new_p + i) = *(head_node->p0 + i);
				}
				//��x�����±��βԪ��
				*(new_p + head_node->total_element) = x;
			}
			else {	//���м�
				//�ȿ���Ҫ����λǰ������Ԫ��
				for (i = 0; i < n - 1; i++) {
					*(new_p + i) = *(head_node->p0 + i);
				}
				//��ֵx������λ
				*(new_p + i) = x;
				//�ٿ�������λ���Ԫ��
				for (; i < head_node->total_element; i++) {
					*(new_p + i + 1) = *(head_node->p0 + i);
				}
			}

			//�Ѿɱ��ͷ�
			free(head_node->p0);

			//��new_p����head_node->p0
			head_node->p0 = new_p;

			//��Ҫ��
			head_node->length += ADD;
		}
		
		//��������Ԫ������Ҫ��
		head_node->total_element++;
	}
	else {	//���ܲ���

	}
	
	//�������
	return head_node;

}

/* ɾ������Ԫ�� */
hn* Remove_elements(hn* head_node, int n) {
	//ͷ�����ڡ�����ڡ�������Ԫ�ء�ɾ��λ�ú�����ɾ��
	if (head_node != NULL && head_node->p0 != NULL && head_node->total_element >= 1 && n >= 1 && n <= head_node->total_element) {
		int i;
		//ɾ��ͷ
		if (n == 1) {
			//ֱ�Ӵӵڶ���Ԫ�ؿ�ʼ��ǰ����
			for (i = 1; i < head_node->total_element; i++) {
				*(head_node->p0 + i - 1) = *(head_node->p0 + i);
			}
		}
		else if (n == head_node->total_element) {	//ɾ��β
			//ɾ��β������Ҫ���κβ�������Ԫ��������1�����൱�ڰ����һ��Ԫ�ظ�ɾ���ˣ������ǵ�����У�
			//total_element�����Ĳ�����Ч��ֵ������֮�����Ȼ���Է��ʣ�������Ϊ����Ч�ķ��ʡ�
		}
		else {	//ɾ���м�
			//��ɾ��λ�ĺ�һλ��ʼ��ǰ�ƶ�һλ
			for (i = n; i < head_node->total_element; i++) {
				*(head_node->p0 + i - 1) = *(head_node->p0 + i);
			}
		}
		
		//��Ԫ��������1
		head_node->total_element--;
	}
	else {	//����ɾ��

	}

	//ɾ������
	return head_node;
}

/* �޸�����Ԫ�� */
hn* Modify_element(hn* head_node, int n, int x) {
	//ͷ�����ڡ�����ڡ�������Ԫ�ء��޸�λ�ú������޸�
	if (head_node != NULL && head_node->p0 != NULL && head_node->total_element >= 1 && n >= 1 && n <= head_node->total_element) {
		//�޸�ֵ
		*(head_node->p0 + n - 1) = x;
	}

	//�޸����
	return head_node;
}
