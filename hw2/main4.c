#include <stdio.h>

// 書籍結構的 typedef 定義
typedef struct Books {
    int id;
    int price;
    char title[100];
} book_t;

// 函數：計算總金額
void total_price(book_t *books, int size) {
    int total = 0;
    for (int i = 0; i < size; i++) {
        total += books[i].price;
    }
    printf("%d\n", total);
}

// 函數：輸出書籍資料
void list_books(book_t *books, int size, int book_id) {
    for (int i = 0; i < size; i++) {
        if (books[i].id == book_id) {
            printf("%d %s\n", books[i].price, books[i].title, book_id);
            return;
        }
    }
    printf("Book not found.\n");
}

// 主函數
int main() {
    // 書籍數組的初始化
    book_t books[] = {
        {1, 1000, "All the Light We Cannot See"},
        {2, 300, "The 38 Letters from J.D. Rockefeller to his son"},
        {3, 1000, "The Ballad of Songbirds and Snakes"},
        {4, 550, "Killers of the Flower Moon"},
        {5, 870, "Elon Musk"},
        {6, 1344, "Milk and Honey 12-Month 2024"}
    };

    int N;
    scanf("%d", &N);

    if (N == 0) {
        total_price(books, sizeof(books) / sizeof(books[0]));
    } else if (N >= 1 && N <= 6) {
        list_books(books, sizeof(books) / sizeof(books[0]), N);
    } else {
        printf("Invalid input.\n");
    }

    return 0;
}
