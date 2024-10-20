#holy pythen

#变量
x, y, z = "Orange", "Banana", "Cherry"  #一次赋多个值
def GloVariable():
    global x    #在结构内用“globle”定义全局变量

#随机数
import random
print(random.randrange(1, 10))

#字符串
a = """Lorem ipsum dolor sit amet,
consectetur adipiscing elit,
sed do eiusmod tempor incididunt
ut labore et dolore magna aliqua."""  #使用三个引号（单双都可）将多行字符串分配给变量

b = "Hello, World!"
print(b[2:5])  #切片，包前不包后（负索引最右为-1）

age = 36
txt = f"My name is John, I am {age}"  #将字符串指定为 f 字符串
print(txt)
