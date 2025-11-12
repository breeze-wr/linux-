      
#include <stdio.h>
#include <unistd.h>  // 包含 usleep 函数（Linux 系统）

// 进度条函数：percent 为当前进度（0-100）
void progress_bar(int percent) {
    // 进度条长度（可自定义）
    const int bar_length = 50;
    // 已完成的长度
    int completed = (int)(bar_length * percent / 100.0);
    // 未完成的长度
    int remaining = bar_length - completed;

    // \r 使光标回到行首，覆盖之前的内容
    printf("\r[");
    
    // 打印已完成部分（用 # 表示）
    for (int i = 0; i < completed; i++) {
        printf("#");
    }
    
    // 打印未完成部分（用空格表示）
    for (int i = 0; i < remaining; i++) {
        printf(" ");
    }
    
    // 打印进度百分比
    printf("] %d%%", percent);
    
    // 强制刷新缓冲区（否则可能不会实时显示）
    fflush(stdout);
}

int main() {
    // 模拟进度从 0% 到 100%
    for (int i = 0; i <= 100; i++) {
        progress_bar(i);
        // 休眠 50 毫秒（模拟任务执行时间）
        usleep(50000);  // Linux 系统用 usleep（微秒）
        // Windows 系统可替换为 Sleep(50); 并包含 <windows.h>
    }
    // 进度完成后换行
    printf("\n");
    return 0;
}
