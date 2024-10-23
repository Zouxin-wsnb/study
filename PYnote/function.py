
def my_function():  #在 Python 中，使用 def 关键字定义函数
  print("Hello from a function")

def my_function(*kids):  #不知道将传递给函数的参数数量，则在函数定义中的参数名称前添加 * ，这样，该函数将接收一个参数元组
  print("The youngest child is " + kids[2])
my_function("Emil", "Tobias", "Linus")

def my_function(child3, child2, child1):
  print("The youngest child is " + child3)
my_function(child1 = "Emil", child2 = "Tobias", child3 = "Linus")  #可以使用 key = value 语法

def my_function(**kid):  #不知道有多少key，就用 **
  print("His last name is " + kid["lname"])
my_function(fname = "Tobias", lname = "Refsnes")

def my_function(country = "Norway"):  #使用默认参数值
  print("I am from " + country)

#可以将任何数据类型的参数（字符串、数字、列表、字典等）发送到函数中， 它将 被视为函数内的相同数据类型。

def myfunction(): 
  pass  #如果定义没有内容，放入pass预防错误

def my_function(a, b, /, *, c, d):  # / 之前仅限位置参数， * 后仅限关键字参数
  print(a + b + c + d)
my_function(5, 6, c = 7, d = 8)

def tri_recursion(k):  #递归计算k!
  if(k > 0):
    result = k + tri_recursion(k - 1)
    print(result)
  else:
    result = 0
  return result
print("\n\nRecursion Example Results")
tri_recursion(6)
