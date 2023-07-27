# OJ-Judger

## 简介

一个在线判题系统（Online Judge）系统的判题机，用来评判参赛选手提交的程序，并给出结果反馈（AC, WA, PE, RE, TLE...）

## 代码规范

1. 结构体、类：大驼峰`UpperCamelCase`

2. 局部变量：小驼峰`lowerCamelCase`

3. 全局变量：`g_`开头 `g_eps`

4. 静态变量：`s_`开头

5. 常量：全大写，下划线分隔`ALL_UPPER_CASE`

6. 类的成员变量：`m_`开头的小驼峰

7. 类的静态变量：`s_`开头的小驼峰

8. 类的成员方法：大驼峰`GetName()`

9. 宏定义：全大写，下划线分隔`#define ALL_UPPER_CASE `，必要时使用`do{}while(0);`

10. 尽可能使用`boost`库

11. 传参使用`pass by reference` 而不是 `pass by value`

12. RESTful风格接口，参考学长[建议](https://github.com/winterant/restful-api-specification)

13. 接口前应包含参数含义相关注释

14. 尽可能不写注释，让代码自说明，即能够达到在没有只是的情况下，读完代码能清楚这句代码的实际作用

15. 尽可能让代码看上去“显然没问题”

16. 采用`TAB`（4空格）缩进

    