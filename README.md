# 打印一个日历
## 有效范围2010~N
### 如何计算某一年某个月的第一天是星期几？
- 计算从2010年1月1日到该年1月1日的总天数（闰年为366天，平年为365天），
- 计算从该年1月1日到选定的月份1日的天数，考虑使用switch语句和for循环搭配，1,3,5,7,8,10,12月是31天，2月是28（闰年为29）天，其他月份为30  天。
- 求出总天数被7除的余数，做相应的处理，可得到该月第一天为星期几。
- 例如，余数为1，则那个月的第一天为星期六（因为2010年的1月1日是星期五）
## 值得注意的是scanf()被忽略情况
```
scanf("%d",&a);
    getchar();/*吃掉回车*/
```
``` 
scanf("%d",&a);
    fflush(stdin);/*清除输入缓冲区*/    
 ```
推荐以上方法,防止第二个scanf()无法正常运行(在字符型输入时尤为突出)
