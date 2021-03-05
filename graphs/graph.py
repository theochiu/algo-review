
class Graph(object):
	'''graph implemented with adjacency list'''
	def __init__(self, vertices):
		self.vertices = vertices
		self.adjacency_list = [[] for _ in range(vertices)]

	def insert_to_adjacency(self, vertex, val):

		self.adjacency_list[vertex].append(val)

	def __str__(self):
		res = "Graph has " + str(self.vertices) + " vertices\n"
		for i, sublist in enumerate(self.adjacency_list):
			res += str(i) + " is connected to: "
			for item in sublist:
				res += str(item) + " "

			res += "\n"
		return res

if __name__ == '__main__':
	g = Graph(5)

	g.insert_to_adjacency(0, 2)
	g.insert_to_adjacency(0, 3)

	g.insert_to_adjacency(2, 4)

	g.insert_to_adjacency(3, 1)

	g.insert_to_adjacency(4, 2)
	g.insert_to_adjacency(4, 4)

	print(g)
