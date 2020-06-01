
import sys

# need more stack frames!
sys.setrecursionlimit(150000)

class Node:

	def __init__(self, val):
		self.val = val
		self.next = None

	def print_list(self):
		print(self.val)
		temp = self.next
		while (temp):
			print(temp.val)
			temp = temp.next

def read_file(filename):
	list_head = None
	with open(filename, "r") as f:
		for line in f:
			val = int(line)

			this_node = Node(val)

			# empty list
			if not list_head:
				list_head = this_node
				temp = this_node

			# unempty list
			else:
				temp.next = this_node
				temp = this_node

	return list_head

def insertion_sort(input_list):
	# first element is trivially sorted
	# just remove it from unsorted and put it in sorted
	sorted_list = input_list
	input_list = input_list.next
	sorted_list.next = None

	# loop thru unsorted list until empty
	while (input_list):
		# pull a node 
		pulled_node = input_list
		# separate from unsorted
		input_list = input_list.next
		pulled_node.next = None
		
		# find insertion_point
		insertion_point = sorted_list
		insertion_point_prev = None
		while (insertion_point and insertion_point.val < pulled_node.val):
			insertion_point_prev = insertion_point
			insertion_point = insertion_point.next

		if insertion_point_prev:
			insertion_point_prev.next = pulled_node
	
		pulled_node.next = insertion_point

	return sorted_list

def merge(left, right):
	# base case
	if not left:
		return right
	if not right:
		return left

	if (left.val < right.val):
		left.next = merge(left.next, right)
		return left

	else:
		right.next = merge(left, right.next)
		return right


def mergesort(input_list):
	# base case
	if not input_list or not input_list.next:
		return input_list

	temp = input_list
	right = input_list


	# traverse until you find the midpoint for 
	# the "right" list
	while (temp and temp.next):
		temp = temp.next.next
		right_prev = right
		right = right.next

	# cut link between left and right
	right_prev.next = None

	left = mergesort(input_list)
	right = mergesort(right)

	return merge(left, right)

def check_sortedness(input_list):
	prev = input_list.val
	input_list = input_list.next

	while input_list:
		if input_list.val < prev:
			return False
		prev = input_list.val
		input_list = input_list.next

	return True

if __name__ == '__main__':

	if len(sys.argv) > 1:
		filename = sys.argv[1]
	else:
		filename = "10000.txt"

	l1 = read_file(filename)
	# l1 = mergesort(l1)
	l1 = mergesort(l1)
	l1.print_list()
	print("sorted") if check_sortedness(l1) else print("NOT sorted")

