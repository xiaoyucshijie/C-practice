#include <stdio.h>

int main() {
    int distance;      // 飞行距离 (整数)
    int price;         // 全价机票价格 (整数)
    int is_new;        // 是否为新客户 (1表示是, 0表示否)
    double discount;   // 折扣率
    double final_price;// 最终折后价格

    // 1. 输入数据
    printf("请输入飞行距离(整数): ");
    scanf("%d", &distance);
    printf("请输入全价机票价格(整数): ");
    scanf("%d", &price);
    printf("请输入是否为新客户(1为是, 0为否): ");
    scanf("%d", &is_new);

    // 2. 根据规则确定折扣率
    // 判断是否为新客户
    if (is_new == 1) { 
        // 新客户折扣规则
        if (distance >= 0 && distance < 1200) {
            discount = 0.8;
        } else if (distance >= 1200 && distance < 2000) {
            discount = 0.7;
        } else if (distance >= 2000) {
            discount = 0.5;
        } else {
            printf("输入的飞行距离无效。\n");
            return 1; // 距离不能为负数
        }
    } else { 
        // 老客户折扣规则 (is_new == 0)
        if (distance >= 0 && distance < 1200) {
            discount = 0.9;
        } else if (distance >= 1200 && distance < 2000) {
            discount = 0.8;
        } else if (distance >= 2000) {
            discount = 0.75;
        } else {
            printf("输入的飞行距离无效。\n");
            return 1; // 距离不能为负数
        }
    }

    // 3. 计算折后价格
    final_price = price * discount;

    // 4. 输出结果 (保留2位小数)
    printf("该机票的折扣价格为: %.2f\n", final_price);

    return 0;
}