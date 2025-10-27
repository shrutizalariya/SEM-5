#include <stdio.h>

int main() {
    int n, W;
    printf("Enter number of items: ");
    scanf("%d", &n);

    int weight[n], value[n];
    float ratio[n];

    for (int i = 0; i < n; i++) {
        printf("Enter weight and value for item %d: ", i + 1);
        scanf("%d %d", &weight[i], &value[i]);
        ratio[i] = (float)value[i] / weight[i];
    }

    printf("Enter capacity of knapsack: ");
    scanf("%d", &W);

    // sort items by ratio (descending)
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (ratio[i] < ratio[j]) {
                // swap ratio
                float temp = ratio[i];
                ratio[i] = ratio[j];
                ratio[j] = temp;
                // swap value
                int t = value[i];
                value[i] = value[j];
                value[j] = t;
                // swap weight
                t = weight[i];
                weight[i] = weight[j];
                weight[j] = t;
            }
        }
    }

    float totalValue = 0.0;
    int curWeight = 0;

    for (int i = 0; i < n; i++) {
        if (curWeight + weight[i] <= W) {
            curWeight += weight[i];
            totalValue += value[i];
        } else {
            int remain = W - curWeight;
            totalValue += value[i] * ((float)remain / weight[i]);
            break;
        }
    }

    printf("Maximum value in knapsack = %.2f\n", totalValue);

    return 0;
}



// #include <stdio.h>

// // structure for items
// struct Item {
//     int weight, value;
//     float ratio;
// };

// void sortByRatio(struct Item arr[], int n) {
//     for (int i = 0; i < n-1; i++) {
//         for (int j = i+1; j < n; j++) {
//             if (arr[i].ratio < arr[j].ratio) {
//                 struct Item temp = arr[i];
//                 arr[i] = arr[j];
//                 arr[j] = temp;
//             }
//         }
//     }
// }

// int main() {
//     int n, W;
//     printf("Enter number of items: ");
//     scanf("%d", &n);

//     struct Item items[n];

//     for (int i = 0; i < n; i++) {
//         printf("Enter weight and value for item %d: ", i+1);
//         scanf("%d %d", &items[i].weight, &items[i].value);
//         items[i].ratio = (float)items[i].value / items[i].weight;
//     }

//     printf("Enter capacity of knapsack: ");
//     scanf("%d", &W);

//     // sort items by value/weight ratio
//     sortByRatio(items, n);

//     float totalValue = 0.0;
//     int curWeight = 0;

//     for (int i = 0; i < n; i++) {
//         if (curWeight + items[i].weight <= W) {
//             curWeight += items[i].weight;
//             totalValue += items[i].value;
//         } else {
//             int remain = W - curWeight;
//             totalValue += items[i].value * ((float)remain / items[i].weight);
//             break;
//         }
//     }

//     printf("Maximum value in knapsack = %.2f\n", totalValue);

//     return 0;
// }
