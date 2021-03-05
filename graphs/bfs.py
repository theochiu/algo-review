from graph import *

def bfs(g, start_node, visited):
	# list of visited nodes
	if not visited:
		visited = [False] * g.vertices

	visited[start_node] = True
	print(start_node)

	queue = []
	queue.append(start_node)

	# loop through the adjacency list
	while queue:
		node = queue[0]
		queue = queue[1:]

		for adjacent_node in g.adjacency_list[node]:
			if not visited[adjacent_node]:
				visited[adjacent_node] = True
				print(adjacent_node)
				queue.append(adjacent_node)


if __name__ == '__main__':
	# test dag
	g = Graph(6)
	g.insert_to_adjacency(0, 1)
	g.insert_to_adjacency(0, 2)

	g.insert_to_adjacency(1, 3)
	g.insert_to_adjacency(1, 2)

	g.insert_to_adjacency(2, 3)

	g.insert_to_adjacency(3, 4)

	g.insert_to_adjacency(4, 1)
	g.insert_to_adjacency(4, 0)
	g.insert_to_adjacency(4, 5)

	bfs(g, 0, None)
