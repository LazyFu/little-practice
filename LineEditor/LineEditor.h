#ifndef LINEEDITOR_H
#define LINEEDITOR_H

#ifdef _WIN32
#include<Windows.h>	//Windows
#else
#include<unistd.h>	//Unix/Linux
#endif // _WIN32

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define ACTIVEMAXLEN 100	//活区最大长度
#define MAXSIZE 320			//每行最大长度

//定义行结点结构体
typedef struct LineNode
{
	int LineNumber;		//行号
	char* content;		//每行内容
	struct LineNode* next;
}LineNode;

void displayHelp();
void getInOutFile(char* input, char* output,int size);
LineNode* createLineNode();
LineNode* readFileToLine(const char* filename, LineNode* head, int* position, int* lineNum, long* filePos,int* isEndOfFile);
void outPutLine(const char* outfile, char* content);
int checkLineOut(LineNode* head, int* lineNum, int line);
int checkDeleteLineOut(LineNode* head, int* lineNum, int line);
LineNode* insertLine(LineNode* head, int* position, const char* outfile, int line, int* lineNum, char content[]);
LineNode* deleteLines(LineNode* head, int line1, int line2, int* position, int* lineNum);
LineNode* deleteLine(LineNode* head, int line1, int* position, int* lineNum);
LineNode* switchActiveZone(const char* outfile, LineNode* head, int* position, int isEndOfFile);
void addLineNode(LineNode* head, LineNode* nextLine);
void deleteLineNode(LineNode* head);
void showLine(LineNode** page);
void clearConsole();
void freeLineNode(LineNode* node);
void freeLinkList(LineNode* head);

#endif // LINEEDITOR_H