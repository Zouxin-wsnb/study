#list有序的、可更改的，并且允许重复的值。
#Tuple 是一个有序且不可更改的集合。允许重复的成员。
#Set 是无序、不可更改且*未编制索引*的集合。没有重复的成员。
#Dictionary 是一个有序且可变的集合。没有重复的成员。


#----------------------------------------------------------------------------------------------
#list[]
thislist = list(("apple", "banana", "cherry")) # note the double round-brackets，创建list
print(thislist)

if "apple" in thislist:
  print("Yes, 'apple' is in the fruits list")  #检查列表中是否存在 “apple” 用关键字in

thislist[1:2] = ["blackcurrant", "watermelon"]
print(thislist)  #通过将第二个值替换为两个新的值，列表的长度将发生变化

thislist.insert(2, "watermelon")
print(thislist)  #插入用 insert

thislist.append("orange")
print(thislist)  #使用方法追加项目到末尾：.append()

tropical = ["mango", "pineapple", "papaya"]
thislist.extend(tropical)
print(thislist)  #要将其他列表中的元素追加到当前列表，使用 .extend()
thistuple = ("kiwi", "orange")
thislist.extend(thistuple)
print(thislist)  #可以添加任何可迭代对象（元组、集合、字典 等）

thislist = ["apple", "banana", "cherry", "banana", "kiwi"]
thislist.remove("banana")
print(thislist)  #删除第一次出现的 “banana”

thislist.pop(1)
print(thislist)  #删除指定项，不指定索引，该方法将删除最后一项

del thislist[0]
print(thislist)  #同样删除指定项，用[]
del thislist  #删除整个列表

thislist = ["apple", "banana", "cherry"]
thislist.clear()
print(thislist)  #清空列表，该列表仍然存在，但没有内容。

newlist = [expression for item in iterable if condition == True]  #返回值是一个新列表，旧列表保持不变。
newlist = [x for x in range(10) if x < 5]  #可以是任何可迭代对象，如列表、元组、集合等。
newlist = [x.upper() for x in fruits]  #将新列表中的值设置为大写

thislist = ["orange", "mango", "kiwi", "pineapple", "banana"]
thislist.sort(reverse = True)  #要按降序排序，使用 keyword 参数 ：reverse = True
print(thislist)
thislist.sort(key = str.lower)  #如果想要一个不区分大小写的排序函数，使用 str.lower 作为关键函数
print(thislist)
thislist.reverse()  #颠倒列表的顺序
print(thislist)

mylist = thislist.copy()
print(mylist)
mylist = list(thislist)
print(mylist)
mylist = thislist[:]
print(mylist)  #三种复制列表的方法

fruits = ["apple", "banana", "cherry"]
mylist=fruits*2  #将内容复制一次

'''
append() 在列表末尾添加一个元素
clear() 从列表中删除所有元素
copy() 返回列表的副本
count() 返回具有指定值的元素数量
extend() 将列表（或任何可迭代对象）的元素添加到当前列表的末尾
index() 返回具有指定值的第一个元素的索引
insert() 在指定位置添加一个元素
pop() 删除指定位置的元素
remove() 删除具有指定值的项目
reverse() 反转列表的顺序
sort() 对列表进行排序
'''
#---------------------------------------------------------------------------------
#Tuple()
#从现在开始很多与list一样便不记录

x = ("apple", "banana", "cherry")
y = list(x)
y[1] = "kiwi"
x = tuple(y)  #将 Tuples 转换为 list 以便能够更改它

thistuple = ("apple", "banana", "cherry")
y = list(thistuple)
y.append("orange")
thistuple = tuple(y)  #1.添加可以转换为list
y = ("wow",)
thistuple += y  #2.还可以将元组添加到元组

del thistuple  #删除元组

fruits = ("apple", "banana", "cherry")
(green, yellow, red) = fruits  #解包元组
print(green)  #apple
print(yellow)  #banana
print(red)  #cherry
fruits = ("apple", "banana", "cherry", "strawberry", "raspberry")
(green, yellow, *red) = fruits
print(green)
print(yellow)
print(red)  #如果变量个数小于值个数，其余值分配给带 * 的list
(green, *tropic, red) = fruits  #Python 将为变量赋值，直到剩余值的数量与剩余的变量数量相匹配。
print(green)
print(tropic)
print(red)

'''
count() 返回元组中指定值出现的次数
index() 在元组中搜索指定值并返回找到该值的位置
'''
#----------------------------------------------------------------------------------
#Set{}

thisset = {"apple", "banana", "cherry", True, 1, 2}  #True和1被视为重复项，False和0同理
print(thisset)

thisset = {"apple", "banana", "cherry"}
thisset.add("orange")  #将项目添加到集合中用 add()
print(thisset)
tropical = {"pineapple", "mango", "papaya"}
thisset.update(tropical)  #另一个集中的项目添加到当前集中用 update()，元组、列表、字典也可添加
print(thisset)

thisset.remove("banana")  #如果要删除的项目不存在，将引发错误
thisset.discard("banana")  #如果要删除的项目不存在，则不会引发错误
thisset.pop()  #删除随机项

'''
'|' 方法连接两个集合中的所有项。union()update()
该方法仅保留重复项。intersection()
该方法保留第一个集合中不属于其他集合的项。difference()
该方法保留除重复项之外的所有项。symmetric_difference()
'''
set1 = {"a", "b", "c"}
set2 = {1, 2, 3}
set3 = set1.union(set2)  #将 set1 和 set2 联接到一个新集合中
set3 = set1 | set2  #效果一样
set3 = {"John", "Elena"}
set4 = {"apple", "bananas", "cherry"}
myset = set1.union(set2, set3, set4)
myset = set1 | set2 | set3 |set4  #链接多个集
#'|'运算符只允许 sets 与 sets 联接，与其他数据类型联接可以用union()

set1 = {"apple", "banana", "cherry"}
set2 = {"google", "microsoft", "apple"}
set3 = set1.intersection(set2)  #该方法将返回一个新集合，该集合仅包含两个集合中都存在的项
print(set3)  #{'apple'}
set3 = set1 & set2  #效果一样，从上一个开始往下运算符都不允许用于与其他数据类型联接

set3 = set1.difference(set2)
set3 = set1 - set2  #两种方法将返回一个新 Set，该 Set 包含第一个 Set 中存在而另一个 Set 中不存在的项目。
print(set3)  #{'banana', 'cherry'}
set1.difference_update(set2)  #更改原始集，而不是返回新集

set3 = set1.symmetric_difference(set2)  #返回两 set 中所有不同的元素
set3 = set1 ^ set2  #效果相同
set1.symmetric_difference_update(set2)  #更改原始集

'''
add() 向集合中添加一个元素
clear() 从集合中删除所有元素
copy() 返回集合的副本
difference() - 返回包含两个或多个集合之间差异的集合
difference_update() 或 -= 删除此集合中也包含在另一个指定集合中的项
discard() 删除指定项
intersection() 或 & 返回一个集合，即两个其他集合的交集
intersection_update() 或 &= 删除此集合中不存在于其他指定集合中的项
isdisjoint() 返回两个集合是否有交集
issubset() 或 <= 返回另一个集合是否包含此集合
< 返回此集合中的所有项是否存在于其他指定集合中
issuperset() 或 >= 返回此集合是否包含另一个集合
> 返回此集合中是否存在其他指定集合中的所有项
pop() 从集合中删除一个元素
remove() 删除指定元素
symmetric_difference() 或 ^ 返回具有对称性的集合两个集合的差异
symmetric_difference_update() 或 ^= 插入此集合和另一个集合的对称差异
union() 或 | 返回包含集合并集的集合
update() 或 |= 使用此集合和其他集合的并集更新集合
'''
#----------------------------------------------------------------------------
#dict{}

thisdict = {
  "brand": "Ford",
  "model": "Mustang",
  "year": 1964
}
x = thisdict["model"]
x = thisdict.get("model")  #访问值的两种方法

x = thisdict.keys()  #返回字典中所有关键字的列表
x = thisdict.values()  #返回字典中所有值的列表
x = thisdict.items()  #该方法将返回字典中的每个项目，作为*列表中的元组*。

thisdict["year"] = 2018  #更改
thisdict.update({"year": 2020})  #更新汽车的 “year”，如果没有，则为添加
thisdict["color"] = "red"  #添加项目

thisdict.pop("model")  #删除具有指定键名称的项目
thisdict.popitem()  #删除最后一个
del thisdict["model"]  #也是删除具有指定键名称的项目

for x in thisdict:
  print(x)  #逐个打印字典中的所有键名称
  print(thisdict[x])  #逐个打印字典中的所有值
for x, y in thisdict.items():
  print(x, y)  #遍历 key 和 value

myfamily = {
  "child1" : {
    "name" : "Emil",
    "year" : 2004
  },
  "child2" : {
    "name" : "Tobias",
    "year" : 2007
  },
  "child3" : {
    "name" : "Linus",
    "year" : 2011
  }
}  #嵌套字典
print(myfamily["child2"]["name"])  #打印child2的名称
for x, obj in myfamily.items():
  print(x)
  for y in obj:
    print(y + ':', obj[y])  #遍历所有嵌套词典的键和值

'''
clear() 从字典中删除所有元素
copy() 返回字典的副本
fromkeys() 返回具有指定键和值的字典
get() 返回指定键的值
items() 返回包含每个键值对的元组的列表
keys() 返回包含字典键的列表
pop() 删除具有指定键的元素
popitem() 删除最后插入的键值对
setdefault() 返回指定键的值。如果键不存在：插入具有指定值的键
update() 使用指定的键值对更新字典
values() 返回字典中所有值的列表
'''
#------------------------------------------------------------------------------------------
