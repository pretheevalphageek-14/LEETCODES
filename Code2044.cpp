class Solution
{
public:
  int countMaxOrSubsets(vector<int> &nums)
  {

    int count = 0, maxOr = 0;
    vector<int> subsets;
    for (int i : nums)
    {
      maxOr |= i;
    }
    checkSubsets(count, 0, nums, 0, maxOr);
    return count;
  }
    int getMaxOR(vector<int>& nums){
        int ans = 0;
        for(int i : nums) ans = ans | i;
        return ans;
    }

  void checkSubsets(int &count, int subOr, vector<int> mainSet, int i, int maxOr)
  {
    if (i == mainSet.size())
    {
      if (subOr == maxOr)
        count++;
      return;
    }
    else {
    checkSubsets(count, subOr, mainSet, i + 1, maxOr);
    checkSubsets(count, (subOr | mainSet[i]), mainSet, i + 1, maxOr);
    }
  }
};