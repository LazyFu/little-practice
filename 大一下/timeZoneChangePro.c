#include <stdio.h>
#include <string.h>

// 定义每个时区相对于 UTC 的偏移量（以分钟为单位）
typedef struct {
    char abbreviation[5];
    int offset;
} TimeZone;

TimeZone timezones[] = {
    {"UTC", 0}, {"GMT", 0}, {"BST", 60}, {"IST", 60},
    {"WET", 0}, {"WEST", 60}, {"CET", 60}, {"CEST", 120},
    {"EET", 120}, {"EEST", 180}, {"MSK", 180}, {"MSD", 240},
    {"AST", -240}, {"ADT", -180}, {"NST", -210}, {"NDT", -150},
    {"EST", -300}, {"EDT", -240}, {"CST", -360}, {"CDT", -300},
    {"MST", -420}, {"MDT", -360}, {"PST", -480}, {"PDT", -420},
    {"HST", -600}, {"AKST", -540}, {"AKDT", -480},
    {"AEST", 600}, {"AEDT", 660}, {"ACST", 570}, {"ACDT", 630},
    {"AWST", 480}
};

// 根据时区缩写找到相对于UTC的偏移量
int find_offset(char* abbr) {
    for (int i = 0; i < sizeof(timezones) / sizeof(TimeZone); i++) {
        if (strcmp(timezones[i].abbreviation, abbr) == 0) {
            return timezones[i].offset;
        }
    }
    return 0; // 默认 UTC
}

// 将时间从a.m./p.m.格式转换为24小时制
void convert_to_24_hour(int* hour, int* minute, char* period) {
    if (strcmp(period, "a.m.") == 0 && *hour == 12) {
        *hour = 0;
    } else if (strcmp(period, "p.m.") == 0 && *hour != 12) {
        *hour += 12;
    }
}

// 将时间从24小时制转换为a.m./p.m.格式
void format_to_12_hour(int hour, int minute, char* result) {
    char period[6];
    if (hour == 0) {
        sprintf(result, "midnight");
    } else if (hour == 12) {
        sprintf(result, "noon");
    } else if (hour < 12) {
        if (hour == 0) hour = 12;
        sprintf(result, "%d:%02d a.m.", hour, minute);
    } else {
        if (hour > 12) hour -= 12;
        sprintf(result, "%d:%02d p.m.", hour, minute);
    }
}

int main() {
    int N;
    scanf("%d", &N);
    getchar(); // 吃掉换行符

    for (int i = 0; i < N; i++) {
        char time[16], from_tz[5], to_tz[5];
        fgets(time, sizeof(time), stdin);

        // 去掉换行符
        time[strcspn(time, "\n")] = '\0';

        // 处理特殊时间 noon 和 midnight
        if (strstr(time, "noon") != NULL) {
            sscanf(time, "noon %s %s", from_tz, to_tz);
            int from_offset = find_offset(from_tz);
            int to_offset = find_offset(to_tz);
            int new_time = 12 * 60 + to_offset - from_offset;
            new_time = (new_time + 24 * 60) % (24 * 60);
            char result[16];
            format_to_12_hour(new_time / 60, new_time % 60, result);
            printf("%s\n", result);
            continue;
        } else if (strstr(time, "midnight") != NULL) {
            sscanf(time, "midnight %s %s", from_tz, to_tz);
            int from_offset = find_offset(from_tz);
            int to_offset = find_offset(to_tz);
            int new_time = 0 + to_offset - from_offset;
            new_time = (new_time + 24 * 60) % (24 * 60);
            char result[16];
            format_to_12_hour(new_time / 60, new_time % 60, result);
            printf("%s\n", result);
            continue;
        }

        int hour, minute;
        char period[6];
        sscanf(time, "%d:%d %s %s %s", &hour, &minute, period, from_tz, to_tz);

        int from_offset = find_offset(from_tz);
        int to_offset = find_offset(to_tz);

        convert_to_24_hour(&hour, &minute, period);
        int total_minutes = hour * 60 + minute;
        int new_time = total_minutes + to_offset - from_offset;
        new_time = (new_time + 24 * 60) % (24 * 60);

        char result[16];
        format_to_12_hour(new_time / 60, new_time % 60, result);
        printf("%s\n", result);
    }

    return 0;
}