bool check(int x)
{
	// ���x�Ƿ�����ĳ������
}
// ģ��1������[l, r]�����ֳ�[l, mid]��[mid + 1, r]ʱʹ�ã�
int bsearch_1(int l, int r)
{
	while (l < r)
	{
		//�� mid = l + (r - l) >> 1;
		int mid = l + r >> 1;
		// check()�ж�mid�Ƿ���������
		if (check(mid))
			r = mid;
		else
			l = mid + 1;
	}
	return l;
}
// ģ��2������[l, r]�����ֳ�[l, mid - 1]��[mid, r]ʱʹ�ã�
int bsearch_2(int l, int r)
{
	while (l < r)
	{
		//�� mid = l + (r - l + 1) >> 1;
		int mid = l + r + 1 >> 1;
		// check()�ж�mid�Ƿ���������
		if (check(mid))
			l = mid;
		else
			r = mid - 1;
	}
	return l;
}
// ע��ģ��1����������chek()���������ҵ���߽磬ģ��2������check()���������ҵ��ұ߽硣
// �٣� ��l��r���ر��ʱ����д�� mid = l + (r - l) >> 1 �� mid = l + (r - l + 1) >> 1
