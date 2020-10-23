# Algorithm Sample

<!-- MarkdownTOC autolink="true" -->

- [bfs](#bfs)
- [dfs](#dfs)
- [lower_bound](#lower_bound)

<!-- /MarkdownTOC -->


## bfs

```cpp
public void bfs(int s, int t) {
	if (s == t) return;

	boolean[] visited = new boolean[v];
	visited[s]=true;

	Queue<Integer> queue = new LinkedList<>();
	queue.add(s);

	int[] prev = new int[v];
	for (int i = 0; i < v; ++i) {
		prev[i] = -1;
	}

	while (queue.size() != 0) {
		int w = queue.poll();
		for (int i = 0; i < adj[w].size(); ++i) {
			int q = adj[w].get(i);
			if (!visited[q]) {
				prev[q] = w;
				if (q == t) {
					print(prev, s, t);
					return;
				}
				visited[q] = true;
				queue.add(q);
			}
		}
	}
}

private void print(int[] prev, int s, int t) { // 递归打印s->t的路径
	if (prev[t] != -1 && t != s) {
		print(prev, s, prev[t]);
	}
	System.out.print(t + " ");
}

```

## dfs

```cpp
boolean found = false; // 全局变量或者类成员变量

public void dfs(int s, int t) {
  found = false;
  boolean[] visited = new boolean[v];
  int[] prev = new int[v];
  for (int i = 0; i < v; ++i) {
    prev[i] = -1;
  }
  recurDfs(s, t, visited, prev);
  print(prev, s, t);
}

private void recurDfs(int w, int t, boolean[] visited, int[] prev) {
  if (found == true) return;
  visited[w] = true;
  if (w == t) {
    found = true;
    return;
  }
  for (int i = 0; i < adj[w].size(); ++i) {
    int q = adj[w].get(i);
    if (!visited[q]) {
      prev[q] = w;
      recurDfs(q, t, visited, prev);
    }
  }
]}
```


## lower_bound

```cpp
template <class ForwardIterator, class T>
  ForwardIterator lower_bound (ForwardIterator first, ForwardIterator last, const T& val)
{
  ForwardIterator it;
  iterator_traits<ForwardIterator>::difference_type count, step;
  count = distance(first,last);
  while (count>0)
  {
    it = first; step=count/2; advance (it,step);
    if (*it<val) {                 // or: if (comp(*it,val)), for version (2)
      first=++it;
      count-=step+1;
    }
    else count=step;
  }
  return first;
}
```




















