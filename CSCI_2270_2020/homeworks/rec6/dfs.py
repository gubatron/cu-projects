GRAPH = {1 : [2,3],
         2:[4,5],
         3:[6],
         4:None,
         5:[7,8],
         6:None,
         7:None,
         8:None}

def DFS(start, target, GRAPH):
  'Use a STACK to search.'
  print("Start:",start,"Target:",target)
  stack = [start]
  visited = []
  while len(stack) > 0:
    x = stack.pop(0)
    if x == target:
      visited.append(x)
      return visited
    elif x not in visited:
      visited = visited+[x]
      if GRAPH[x] is not None:
        'add nodes at the top of the stack'
        stack = GRAPH[x] + stack

  return visited

def BFS(start, target, GRAPH):
  'Use a STACK to search.'
  print("Start:",start,"Target:",target)
  queue = [start]
  visited = []
  while len(queue) > 0:
    x = queue.pop(0)
    if x == target:
      visited.append(x)
      return visited
    elif x not in visited:
      visited = visited+[x]
      if GRAPH[x] is not None:
        'add nodes at the top of the stack'
        queue = queue + GRAPH[x]

  return visited

print("DFS Path",DFS(1,7,GRAPH))
print("="*80)
print("DFS Path",DFS(1,3,GRAPH))
print()
print("="*80)
print("BFS Path",BFS(1,7,GRAPH))
print("="*80)
print("BFS Path",BFS(1,3,GRAPH))
