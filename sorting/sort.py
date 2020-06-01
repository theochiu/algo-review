
import sys

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

def mergesort(input_list):
	# base case
	if not input_list or not input_list.next:
		return input_list

	



if __name__ == '__main__':

	if len(sys.argv) > 1:
		filename = sys.argv[1]
	else:
		filename = "10.txt"

	l1 = read_file(filename)
	l1 = insertion_sort(l1)
	l1.print_list()

