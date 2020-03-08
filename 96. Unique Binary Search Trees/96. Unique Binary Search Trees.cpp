class Solution {
public:
    int numTrees(int n) {
        vector<int> table;      // table[i] -> for i nodes, how many trees can be constructed.

        /*
            For table[i],
                Choose 1 as root, there are 0 node for left tree, i-1 nodes for right tree;
                Choose 2 as root, there are 1 node for left tree, i-2 nodes for right tree;
                ...
                Choose i as root, there are i-1 nodes for left tree, 0 node for right tree.
            So, table[i] = SUM(table[j]*table[i-1-j]), j->[0, i-1].
        */

        table.push_back(1);     // Set table[0]=0.

        for (int i = 1; i <= n; i++) {
            int treeNum = 0;
            for (int j = 0; j < i; j++) {
                treeNum += table[j] * table[i - 1 - j];
            }

            table.push_back(treeNum);
        }

        return table[n];
    }
};