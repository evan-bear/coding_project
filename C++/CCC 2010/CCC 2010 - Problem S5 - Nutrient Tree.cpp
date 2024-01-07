#include <bits/stdc++.h>

using namespace std;

class TreeNode
{
public:
    int *maxNutrients;
    int value;
    TreeNode *left, *right;

public:
    TreeNode(TreeNode *l, TreeNode *r)
    {
        value = 0;
        left = l;
        right = r;
    }
    TreeNode(int v)
    {
        value = v;
        left = NULL;
        right = NULL;
    }
};

string trim(string s)
{
    while (s[0] == ' ')
        s = s.substr(1);
    while (s[s.size() - 1] == ' ')
        s = s.substr(0, s.size() - 2);
    return s;
}

TreeNode createTreeNode(string s)
{
    trim(s);
    if (s[0] != '(')
        return TreeNode(stoi(s));
    s = trim(s.substr(1, s.size() - 1));
    int i;
    if (s[0] == '(')
    {
        int count = 1;
        i = 1;
        while (count > 0)
        {
            if (s[i] == '(')
                count++;
            else if (s[i] == ')')
                count--;
            i++;
        }
    }
    else
        i = s.find(" ");
    return TreeNode(&createTreeNode(s.substr(0, i)), &createTreeNode(s.substr(i + 1)));
}

void optimize(TreeNode node, int growth)
{
    if (node.left == NULL)
    {
        TreeNode leaf = node;
        leaf.maxNutrients = new int[growth + 1];
        for (int i = 0; i <= growth; i++)
            leaf.maxNutrients[i] = leaf.value + 1;
    }
    else
    {
        TreeNode n = node;
        int max, tmp;

        optimize(*n.left, growth);
        int optL[growth + 1];
        for (int i = 0; i <= growth; i++)
        {
            max = 0;
            for (int j = 0; j <= i; j++)
            {
                tmp = min((1 + j) * (1 + j), n.left.maxNutrients[i - j]);
                if (tmp > max)
                    max = tmp;
            }
            optL[i] = max;
        }

        optimize(*n.right, growth);
        int optR[growth + 1];
        for (int i = 0; i <= growth; i++)
        {
            max = 0;
            for (int j = 0; j <= i; j++)
            {
                tmp = min((1 + j) * (1 + j), n.right.maxNutrients[i - j]);
                if (tmp > max)
                    max = tmp;
            }
            optR[i] = max;
        }

        n.maxNutrients = new int[growth + 1];
        for (int i = 0; i <= growth; i++)
        {
            max = 0;
            for (int j = 0; j <= i; j++)
            {
                tmp = optL[j] + optR[i - j];
                if (tmp > max)
                    max = tmp;
            }
            n.maxNutrients[i] = max;
        }
    }
}

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);

    string input;
    getline(cin, input);
    TreeNode root = createTreeNode(input);
    int growth;
    cin >> growth;

    optimize(root, growth);
    cout << root.maxNutrients[growth] << '\n';

    return 0;
}
