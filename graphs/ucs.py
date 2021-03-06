
from graph import *
from queue import PriorityQueue
		

def ucs(g, start):
	q = PriorityQueue() # use .pur and .get

	# initialize all distances to infinity
	# and we haven't visited anything
	distances = [float("inf")] * g.vertices
	visited = [False] * g.vertices

	# the source node is trivially visited with 0 
	# distance to itself
	distances[start] = 0
	q.put((0, start))
	
	while not q.empty():
		# dequeue 
		distance, closest = q.get()
		visited[closest] = True

		for node in g.adjacency_list[closest]:
			# if we haven't visited the node and we can
			# put it on the list since we can get to it now
			# the distance is closest's distance to the source
			# plus the distance between closest and node
			if not visited[node]:
				q.put((distance + 1, node)) 	# assumes uniform edge weight 

			# distance to node thru closest is smaller than previously
			# discovered paths
			if distance + 1 < distances[node]:
				distances[node] = distance + 1


	return distances

if __name__ == '__main__':
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

	distances = ucs(g, 0)
	print(distances)
