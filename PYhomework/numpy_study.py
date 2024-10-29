import numpy as np

ori_arr=np.random.randint(1,100,size=(3,3))
print(ori_arr)

print("max:",np.max(ori_arr))
print("min:",np.min(ori_arr))
print("mean:",np.mean(ori_arr))

print("sum of each row:",np.sum(ori_arr,axis=1))
print("sum of each column:",np.sum(ori_arr,axis=0))

print("-10:",ori_arr-10)
print("*2:",ori_arr*2)

print("flip rows and columns:",np.transpose(ori_arr))
