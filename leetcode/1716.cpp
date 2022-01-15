class Solution {
public:
    int totalMoney(int n) {
		int week_num = n / 7;
		int first_week_money = (1 + 7) * 7 / 2;
		int last_week_money = first_week_money + 7 * (week_num - 1);
		int week_money = (first_week_money + last_week_money) * week_num / 2;

		int day_num = n % 7;
		int first_day_money = 1 + week_num;
		int last_day_money = first_day_money + day_num - 1；
		int day_money = (first_day_money + last_day_money) * day_num / 2;
		return week_money + day_money;
    }
};