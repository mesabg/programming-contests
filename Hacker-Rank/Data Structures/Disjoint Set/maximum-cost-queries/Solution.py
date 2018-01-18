import itertools
import bisect

class DisjointSet:

  def __init__(self, N):
    self.parent = [i for i in range(N)]
    self.total = [1] * N
    self.path_total = [0] * N
    print(self.total, self.path_total, self.parent)
  
  def union(self, a, b):
    a_parent = self.find(a)
    b_parent = self.find(b)
    if a_parent != b_parent:
      self.parent[b_parent] = a_parent
      new_paths = self.total[a_parent] * self.total[b_parent]
      self.path_total[a_parent] += self.path_total[b_parent] + new_paths
      self.total[a_parent] += self.total[b_parent]
      return new_paths
    else:
      return 0
    
  def find(self, a):
    if self.parent[a] != a:
      self.parent[a] = self.find(self.parent[a])
    return self.parent[a]
  
  def get_total(self, a):
    return self.total[self.find(a)]
  
N, Q = map(int, input().split())
ds = DisjointSet(N)
paths = [list(map(int, input().split())) for i in range(N - 1)]
paths.sort(key=lambda x: x[2])
print(paths)
path_lengths, path_count_le = [0], [0]
for length, l in itertools.groupby(paths, key=lambda x: x[2]):
  total = path_count_le[-1]
  for path in l:
    union = ds.union(path[0] - 1, path[1] - 1)
    total += union
    print(path, "New paths ", union, " Total ", total)
  print('-------')
  path_lengths.append(length)
  path_count_le.append(total)
print("Paths lenghts ", path_lengths)
print("Paths count lenghts ", path_count_le)
for i in range(Q):
  L, R = map(int, input().split())
  Li = bisect.bisect(path_lengths, L - 1) - 1
  Ri = bisect.bisect(path_lengths, R) - 1
  print("(Li, Ri)", Li, Ri)
  print(path_count_le[Ri] - path_count_le[Li]) 