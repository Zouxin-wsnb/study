import pandas as pd

# 1.创建一个Series
s1=pd.Series([1,2,3,4,5])
print(s1)
print(s1.index)
print(s1.values)
s1.index=['a','b','c','d','e']  # 修改索引
print(s1)
print(s1['a'])
s1['f']=6  # 添加元素
print(s1['a':'c'])  # 切片
print(s1[0:3])
print(s1[(s1>2)&(s1<5)])  # 布尔索引
print(s1[['a','b','c']])  # 花式索引

# 2.创建一个DataFrame
population_dict={'California':38332521,
                    'Texas':26448193,
                    'New York':19651127,
                    'Florida':19552860,
                    'Illinois':12882135}
population=pd.Series(population_dict)
area_dict={'California':423967,
            'Texas':695662,
            'New York':141297,
            'Florida':170312,
            'Illinois':149995}
area=pd.Series(area_dict)
states=pd.DataFrame({'population':population,'area':area})
print(states)
states['average_density']=states['population']/states['area']
print(states)

# 显示索引和隐式索引
s2=pd.Series(['a','b','c','d','e'],index=[1,2,3,4,5])
print(s2.loc[1:3])  # 显示索引
print(s2.iloc[1:3])  # 隐式索引
