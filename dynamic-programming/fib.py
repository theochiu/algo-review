
import time, sys, functools

# need more stack frames!
sys.setrecursionlimit(150000)

############################################################################
# You can run each function and see the time it takes to complete.         #
# fib1 is fastest since it doesn't recurse and requires no additional      #
# stack frames (pushing/popping stack has additional overhead). fib2       #
# is slightly slower since it keeps a table but invokes recursion to       #
# populate the table, fib1 and fib2 are still in linear time though.       #
# fib3 is the naive implementation that beginners to recursion use.        #
# It performs the worst since it's exponential, while the other two        #
# functions can calculate the 10000th fibonacci number with ease, fib1     #
# taps out at around 30 depending on your cpu.                             #
############################################################################

# bottom up implementation (tabulation)
def fib1(n):
	tab = [0, 1, 0]
	for i in range(2, n+1):
		tab[2] = tab[0] + tab[1]
		# shift
		tab[0] = tab[1]
		tab[1] = tab[2]
	return tab[2]


# top down implementation (memoizaton)
# O(n)
def fib2(n):
	memotable = {} 

	def f(n):
		if n in memotable:
			return memotable[n]
		if n <= 1:
			return n
		ans = f(n - 1) + f(n - 2)
		memotable[n] = ans 		# store in memotable
		return ans

	return f(n)

# inefficiently exponential recursion (very bad)
# O(2^n)
def fib3(n):
	if n <= 1:
		return n
	return fib3(n - 1) + fib3(n - 2)

if __name__ == '__main__':
	n = 1000000
	start = time.time()
	ans = fib1(n)
	print("Execution time: {}".format(time.time() - start))
	print("{}th fibonacci number is {}".format(n, ans))
