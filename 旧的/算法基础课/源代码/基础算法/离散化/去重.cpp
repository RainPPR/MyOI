// �洢
vector<int> alls;
// ����
sort(alls.begin(), alls.end());
// ȥ��
alls.erase(unique(alls.begin(), alls.end()), alls.end());
