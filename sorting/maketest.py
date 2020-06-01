
from random import randint

def main(num):
	with open(str(num) + ".txt", "w") as f:
		for i in range(num):
			num = randint(-10000, 10000)
			f.write(str(num) + "\n")

if __name__ == '__main__':
	main(10)
	main(100)
	main(10000)
	main(1000000)

