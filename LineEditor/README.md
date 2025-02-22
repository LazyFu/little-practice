# 简单行编辑

**[问题描述]**

文本编辑程序是利用计算机进行文字加工的基本软件工具，实现对文本文件的插入、删除等修改操作。限制这些操作以行为单位进行的编辑程序称为行编辑程序。 被编辑的文本文件可能很大，全部读入编辑程序的数据空间（内存）的做法既不经济，也不总能实现。一种解决方法是逐段地编辑。任何时刻只把待编辑文件的一段放在内存，称为活区。试按照这种方法实现一个简单的行编辑程序。设文件每行不超过320个字符，很少超过80字符。

**[基本要求]**

实现以下4条基本编辑命令：

1. 行插入。格式：`i<行号><回车><文本><回车>`；将插入活区中第行之后
2. 行删除。格式：`d<行号 1>[ <行号 2>]<回车>`；删除活区中第<行号1>行（到第<行号2>行）。两种格式的例子是：`d10↙`和`d10 14↙`
3. 活区切换。格式：`n<回车>`；将活区写入输出文件，并从输入文件中读入下一段，作为新的活区。
4. 活区显示。格式：`p<回车>`；逐页地（每页20行）显示活区内容，每显示一页之后请用户决定是否继续显示以后各页（如果存在）。印出的每一行要前置以行号和一个空格符，行号固定占4位，增量为1。各条命令中的行号均须在活区中各行行号范围之内，只有插入命令的行号可以等于活区第一行行号减1，表示插入当前屏幕中第一行之前，否则命令参数非法。

**[实现提示]**

1. 设活区的大小用行数`activemaxlen`（可设为100）来描述。考虑到文本文件行长通常为正态分布，且峰值在60到70之间，用`320*activemaxlen`大小的字符数组实现存储将造成大量浪费。可以以标准行块为单位为各行分配存储，每个标准行块含81个字符。这些行块可以组成一个数组，也可以利用动态链表连接起来。一行文字可能占多个行块。行尾可用一个特殊的ASCII字符（如(012)8）标识。此外，还应记住活区起始行号。行插入将引起随后各行行号的顺序下推。
2. 初始化过程包括：请用户提供输入文件名（空串表示无输入文件）和输出文件名，两者不能相同。然后尽可能多地从输入文件中读入各行，但不超过`activemaxlen-x`。x的值可以自定，例如20。
3. 在执行行插入命令的过程中，每接收到一行时到要检查活区大小是否已达`activemaxlen`。如果是，则为了在插入这一行之后仍保持活区大小不超过`activemaxlen`，应将插入点之前的活区部分中第一行输出到输出文件中；若插入点为第一行之前，则只得将新插入的这一行输出。
4. 若输入文件尚未读完，活区切换命令可将原活区中最后几行留在活区顶部，以保持阅读连续性；否则，它意味着结束编辑或开始编辑另一个文件。
5. 可令前三条命令执行后自动调用活区显示。

**[选作内容]**

1. 对于命令格式非法等一切错误作严格检查和适当处理。
2. 加入更复杂的编辑操作，如对某行进行串替换；在活区内进行模式匹配等，格式可以为S@@和m。

## 行插入

读取i，insert，行数n，回车后输入内容，回车结束输入。

使用链表表示的串，定位到第n行。将输入加入这一行。后续行号**顺序加1**。行号改变如何实现？？？？？？？

~~~c
typedef struct LineNode
{
    int LineNumber;
    char *content;
    //char content[LINE_SIZE];
    struct LineNode* next;
}LineNode;
~~~

尝试动态分配内存，不使用行块，先观察一下性能再说。

## 行删除

读取d，delete，行数n，回车开始删除。

**重点：** 改变行号？？？？？？

链表改变指针即可。

## 活区切换

读取n，将活区内容输入到输出文件。如果输入文件未读完，可保留几行。

## 活区显示

读取p，print，切换活区显示行数，输出。

## 文件IO

模式匹配KMP算法

[KMP算法](https://juejin.cn/post/7445521596456779812)

[next数组](https://www.cnblogs.com/aninock/p/13796006.html)

## 释放内存

**不会**。在`LineEditor.c`的`switchActiveZone`函数中尝试释放内存，在354行，如注释所示，结果不能正确释放，导致指针地址混乱。

在Visual Studio中如注释所示释放内存没有出现错误，用gcc编译就不行。MS还是太智能了。
