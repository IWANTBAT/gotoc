class Solution {
	int count[10000];
public:
	bool hasGroupsSizeX(vector<int>& deck) {
		int N = (int)deck.size();
		for (int c : deck) count[c]++;

		vector<int> values;
		for (int i = 0; i < 10000; ++i) {
			if (count[i] > 0) {
				values.emplace_back(count[i]);
			}
		}

		for (int X = 2; X <= N; ++X) {
			if (N % X == 0) {
				bool flag = 1;
				for (int v : values) {
					if (v % X != 0) {
						flag = 0;
						break;
					}
				}
				if (flag) return true;
			}
		}
		return false;
	}
};
