
a = "Hello, World!"
print(a[1])  #Python 中的字符串是表示 Unicode 字符的字节数组。
for x in a:
  print(x)  #遍历

b = "Hello, World!"
print(b[2:5])  #使用 slice 语法进行切片

print(a.upper())  #返回大写
print(a.lower())  #返回小写

a = " Hello, World! "
print(a.strip())  # returns "Hello,World!"（删除空格）
print(a.replace("H", "J"))  #将H替换为J
print(a.split(","))  #返回一个列表，其中指定分隔符之间的文本成为列表项，这里以‘,’为分隔符

price = 59
txt = f"The price is {price} dollars"  #为变量添加占位符，使用F-String格式化字符串
print(txt)

'''
\' 单引号
\\ 反斜杠
\n 新行
\r 回车
\t 制表符
\b 退格键
\f 换页符
\ooo 八进制值
\xhh 十六进制值

capitalize() 将第一个字符转换为大写
casefold() 将字符串转换为小写
center() 返回居中字符串
count() 返回字符串中指定值出现的次数
encode() 返回字符串的编码版本
endswith() 如果字符串以指定值结尾，则返回 true
expandtabs() 设置字符串的制表符大小
find() 在字符串中搜索指定值并返回找到该值的位置
format() 格式化字符串中的指定值
format_map() 格式化字符串中的指定值
index() 在字符串中搜索指定值并返回找到该值的位置
isalnum() 如果字符串中的所有字符都是字母数字，则返回 True
isalpha() 如果字符串中的所有字符都是字母，则返回 True
isascii() 如果字符串中的所有字符都是 ascii 字符，则返回 True
isdecimal() 如果字符串中的所有字符都是小数，则返回 True
isdigit() 如果字符串中的所有字符都是数字，则返回 True
isidentifier() 如果字符串是标识符
islower() 如果字符串中的所有字符都是小写，则返回 True
isnumeric() 如果字符串中的所有字符都是数字，则返回 True
isprintable() 如果字符串中的所有字符都是可打印的，则返回 True
isspace() 如果字符串中的所有字符都是空格，则返回 True
istitle() 如果字符串遵循标题规则，则返回 True
isupper() 如果字符串中的所有字符都是大写，则返回 True
join() 将可迭代对象的元素连接到字符串的末尾
ljust() 返回字符串的左对齐版本
lower() 将字符串转换为小写
lstrip() 返回字符串的左修剪版本
maketrans() 返回用于翻译的翻译表
partition() 返回将字符串分成三部分的元组
replace() 返回将指定值替换为指定值的字符串
rfind() 在字符串中搜索指定值并返回找到该值的最后位置
rindex() 在字符串中搜索指定值并返回找到该值的最后位置found
rjust() 返回字符串的右对齐版本
rpartition() 返回将字符串分成三部分的元组
rsplit() 在指定的分隔符从右开始处拆分字符串并返回列表
rstrip() 返回字符串的右修剪版本
split() 在指定的分隔符处拆分字符串并返回列表
splitlines() 在换行符处拆分字符串并返回列表
startswith() 如果字符串以指定值开头，则返回 true
strip() 返回字符串的修剪版本
swapcase() 交换大小写，小写变为大写，反之亦然
title() 将每个单词的第一个字符转换为大写
translate() 返回翻译后的字符串
upper() 将字符串转换为大写
zfill() 在开头用指定数量的 0 值填充字符串
'''
