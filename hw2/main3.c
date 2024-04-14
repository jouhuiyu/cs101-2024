#include <stdio.h>
#include <string.h>

int main()
{
    FILE *fp_in, *fp_out;
    char line[1000]; // 用於存儲讀取的每行內容
    int line_number = 0; // 記錄行數
    int found = 0; // 標記是否找到目標字串

    // 打開輸入文件
    fp_in = fopen("main3.c", "r");
    if (fp_in == NULL) {
        printf("無法打開輸入文件。\n");
        return 1;
    }

    // 打開輸出文件
    fp_out = fopen("main3.txt", "w");
    if (fp_out == NULL) {
        printf("無法打開輸出文件。\n");
        fclose(fp_in);
        return 1;
    }

    // 逐行讀取文件內容並查找目標字串
    while (fgets(line, sizeof(line), fp_in)) {
        line_number++; // 更新行數
        if (strstr(line, "int main") != NULL) {
            found = 1; // 找到目標字串
            break;
        }
    }

    // 如果找到目標字串，將行數寫入輸出文件，否則寫入錯誤消息
    if (found) {
        fprintf(fp_out, "%d\n", line_number);
    } else {
        fprintf(fp_out, "錯誤：檔案中找不到'int main'。\n");
    }

    // 關閉文件
    fclose(fp_in);
    fclose(fp_out);

    return 0;
}
