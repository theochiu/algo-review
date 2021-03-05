from graph import *

def dfs(g, start_node, visited):
	# list of visited nodes
	if not visited:
		visited = [False] * g.vertices

	visited[start_node] = True
	print(start_node)

	# loop through the adjacency list
	for node in g.adjacency_list[start_node]:
		if not visited[node]:
			dfs(g, node, visited)


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

	dfs(g, 0, None)
