#list有序的、可更改的，并且允许重复的值。
#Tuple 是一个有序且不可更改的集合。允许重复的成员。
#Set 是无序、不可更改且*未编制索引*的集合。没有重复的成员。
#Dictionary 是一个有序且可变的集合。没有重复的成员。

#list
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
