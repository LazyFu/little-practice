#include"LineEditor.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
	//获取输入输出文件名
	char inputfile[256], outputfile[256];
	getInOutFile(inputfile, outputfile, sizeof(inputfile));

	//定义基本变量
	int lineNum = 1;	//行号
	int position = 0;	//活区行数
	long filePos = 0;	//文件指针位置
	int isEndOfFile = 0;//是否到达文件末尾
	//读取文件到链表
	LineNode* head = NULL;
	head = readFileToLine(inputfile, head, &position, &lineNum, &filePos, &isEndOfFile);

	LineNode* page = head;

	displayHelp();
	while (1)
	{
		char command[20] = { 0 };	//随便加入命令最多20个字符
		printf("Enter command: \n");
		fgets(command, sizeof(command), stdin);

		//处理命令
		int line = 0, line1 = 0, line2 = 0;
		switch (command[0])
		{
		//行插入
		case 'i':
		{
			char content[MAXSIZE] = { 0 };
			if (sscanf_s(command + 1, "%d", &line) == 1 && !checkLineOut(head, &lineNum, line))
			{
				printf("Enter words below:\n");
				fgets(content, sizeof(content), stdin);
				head = insertLine(head, &position, outputfile, line, &lineNum, content);
				page = head;
			}
			break;
		}
		//行删除
		case 'd':
		{
			if (sscanf_s(command, "d%d %d", &line1, &line2) == 2 && !checkDeleteLineOut(head, &lineNum, line1) && !checkDeleteLineOut(head, &lineNum, line2))
			{
				head = deleteLines(head, line1, line2, &position, &lineNum);
			}
			else if (sscanf_s(command, "d%d", &line1) == 1 && !checkDeleteLineOut(head, &lineNum, line1))
			{
				head = deleteLine(head, line1, &position, &lineNum);
			}
			else
			{
				printf("Invalid delete command\n");
			}
			page = head;
			break;
		}
		//活区切换
		case 'n':
		{
			head = switchActiveZone(outputfile, head, &position, isEndOfFile);
			head = readFileToLine(inputfile, head, &position, &lineNum, &filePos, &isEndOfFile);
			page = head;
			break;
		}
		//换页
		case 'p':
		{
			showLine(&page);
			break;
		}
		//显示帮助
		case '?':
		{
			displayHelp();
			break;
		}
		default:
		{
			printf("Unknown command\n");
			displayHelp();
			break;
		}
		}
	}
	freeLinkList(head);
	freeLinkList(page);
	return 0;
}