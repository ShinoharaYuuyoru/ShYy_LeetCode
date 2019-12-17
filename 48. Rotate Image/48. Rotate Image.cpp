class Solution {
public:
	void rotate(vector<vector<int>>& matrix) {
		int size = matrix.size();

		// Save right upper triangle
		vector<int> saveLine;
		for (int saveItr = 0; saveItr < size; saveItr++) {
			for (int subSaveItr = saveItr - 1; subSaveItr >= 0; subSaveItr--) {
				saveLine.insert(saveLine.begin(), matrix[subSaveItr][saveItr]);
			}
		}

		for (int bigItr = 0; bigItr < size; bigItr++) {
			vector<int> copyLine;
			for (int copyItr = size - 1; copyItr >= 0; copyItr--) {
				if (copyItr < bigItr) {
					copyLine.push_back(saveLine.back());
					saveLine.pop_back();
				}
				else {
					copyLine.push_back(matrix[copyItr][bigItr]);
				}
			}

			matrix[bigItr] = copyLine;
		}
	}
};