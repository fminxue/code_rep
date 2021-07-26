/*problem
升序排列的整数数组 nums 在预先未知的某个点上进行了旋转（例如， [0,1,2,4,5,6,7] 经旋转后可能变为 [4,5,6,7,0,1,2] ）。

请你在数组中搜索 target ，如果数组中存在这个目标值，则返回它的索引，否则返回 -1 。

示例 1：

输入：nums = [4,5,6,7,0,1,2], target = 0
输出：4
示例 2：

输入：nums = [4,5,6,7,0,1,2], target = 3
输出：-1
示例 3：

输入：nums = [1], target = 0
输出：-1 */


int find_aux(vector<int> &nums, int left, int right, int &target) {
  if (left > right || nums.empty()) return -1;

  int mid = left + (right - left) >> 1; // 防止left + right溢出

  if (nums[mid] == target) return mid;

  if (nums[mid] > nums[left]) { // 说明左边一定有序
    if (target >= nums[left] && target < nums[mid]) // target在有序的左边
      return find_aux(nums, left, mid - 1, target);

    return find_aux(nums, mid + 1, right, target);
  } else { // 说明右边一定有序
    if (target > nums[mid] && target <= nums[right]) // target在有序的右边
      return find_aux(nums, mid + 1, right, target);

    return find_aux(nums, left, mid - 1, target);
  }
}

int find(vector<int> &nums, int target) {
  if (nums.empty()) return -1;

  return find_aux(nums, 0, nums.size() - 1, target);
}

