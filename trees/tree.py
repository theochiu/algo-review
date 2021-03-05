
COUNT = 10

class Tree(object):

	def __init__(self, val):
		super(Tree, self).__init__()
		self.val = val
		self.left = None
		self.right = None

	def __repr__(self, space=0):
		if self.left == None and self.right == None:
			return str(self.val)
		space += COUNT;

		# recurse right
		res = self.right.__repr__()

		# actual printing
		res += "\n"
		for i in range(COUNT, space):
			res += " "
		res += str(self.val)

		# recurse left
		res += self.left.__repr__()
		return res

if __name__ == '__main__':
	tree = Tree(5)
	tree.left = Tree(2)
	tree.right = Tree(20)
	print(tree)
