bool check(int x)
{
	// 检查x是否满足某种性质
}
// 模板1：区间[l, r]被划分成[l, mid]和[mid + 1, r]时使用：
int bsearch_1(int l, int r)
{
	while (l < r)
	{
		//① mid = l + (r - l) >> 1;
		int mid = l + r >> 1;
		// check()判断mid是否满足性质
		if (check(mid))
			r = mid;
		else
			l = mid + 1;
	}
	return l;
}
// 模板2：区间[l, r]被划分成[l, mid - 1]和[mid, r]时使用：
int bsearch_2(int l, int r)
{
	while (l < r)
	{
		//① mid = l + (r - l + 1) >> 1;
		int mid = l + r + 1 >> 1;
		// check()判断mid是否满足性质
		if (check(mid))
			l = mid;
		else
			r = mid - 1;
	}
	return l;
}
// 注：模板1就是在满足chek()的区间内找到左边界，模板2在满足check()的区间内找到右边界。
// ①： 在l和r都特别大时，可写作 mid = l + (r - l) >> 1 或 mid = l + (r - l + 1) >> 1
