// Question 2 Solution in Java:

import java.util.HashMap;

public class CountPairsWithSum {

    public static int countPairsWithSum(int[] nums, int target) {
        HashMap<Integer, Integer> numMap = new HashMap<>();
        int count = 0;

        for (int num : nums) {
            int complement = target - num;
            if (numMap.getOrDefault(complement, 0) > 0) {
                count += numMap.get(complement);
            }
            numMap.put(num, numMap.getOrDefault(num, 0) + 1);
        }
        return count;
    }

    public static void main(String[] args) {
        int[] nums = {1, 5, 7, -1, 5};
        int target = 6;
        System.out.println("Count of pairs is " + countPairsWithSum(nums, target));
    }
}
