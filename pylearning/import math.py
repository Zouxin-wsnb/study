import math

def calculate(x,n):
    result = 0
    for i in range(n):
        result += math.pow(x, i) / math.factorial(i)
    return result

x=float(input())
n=int(input())
approximation=calculate(x,n)
exact_value = math.exp(x)

# Print the results
print(f"Approximation of e^{x} using {n} terms: {approximation:.5f}")
print(f"Exact value using math.exp: {exact_value:.5f}")

# Check if the approximation is close to the exact value
if abs(approximation - exact_value) < 0.001:
    print("The approximation is sufficiently accurate.")
else:
    print("The approximation is not sufficiently accurate.")
