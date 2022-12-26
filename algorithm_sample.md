# Algorithm Sample

1. [sort](#sort)
   1. [quick sort](#quick-sort)
   2. [heap sort](#heap-sort)
2. [bfs](#bfs)
3. [dfs](#dfs)
4. [lower\_bound](#lower_bound)
5. [Binary search](#binary-search)

------------------

## sort

### quick sort

- O(n*log(n))

```cpp
void quickSort(vector<int>& nums, int l, int r) {
  if (l > r) return;

  int pos = l;
  // random pick pivot
  swap(nums[(rand() % (r-l+1) + l)], nums[r]);
  int pivot = nums[r];


  for (int s = l; s < r; s++) {
      if (nums[s] < pivot) {
          swap(nums[s], nums[pos++]);
      }
  }

  swap(nums[r], nums[pos]);

  // 1. normal algorithm
  quickSort(nums, l, pos-1);
  quickSort(nums, pos+1, r);

  /*// 2. handle the case when many same values
  int newr = firstBiggerThanPivot;
  while (newr > l && nums[newr] == nums[newr-1]) newr--;
  int newl = firstBiggerThanPivot;
  while (newl < r && nums[newl] == nums[newl+1]) newl++;

  quickSort(nums, l, newr-1);
  quickSort(nums, newl+1, r);
  */
}
```

### heap sort

- O(n*log(n))

- steps
  1. `heapify()` : top to bottom heapify
  2. `build()` : heapify from [n/2, end] to [0, end]
  3. `sort()` : repeat `swap(); heapify[0, end-1]`, `swap(); [0, end-2]` ... `[0, 1]`

```cpp
void heapify(vector<int>& v, int s, int e) {
    int n = v.size();

    int l = 2*s + 1, r = 2*s + 2;

    int k = s;
    if (l <= e && v[l] > v[s]) k = l;
    if (r <= e && v[r] > v[k]) k = r;

    if (k == s) return;

    swap(v[s], v[k]);
    heapify(v, k, e);
}

void heapSort(vector<int>& nums) {
   build(nums);
   //printV(nums);
   int n = nums.size();
   int end = n-1;

   while (end >= 0) {
       swap(nums[0], nums[end]);
       end--;
       heapify(nums, 0, end);
       //printV(nums);
   }

}

void build(vector<int>& v) {
   int n = v.size();
   int i = n/2;
   while (i >= 0) {
       heapify(v, i, n-1);
       i--;
   }
 }
```

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


## Binary search

  1. range `[l, r]`
  2. `while(l <= r)`
  3. `mid = l + (r-l)/2`
  4. `l = m+1` or `r = m-1`
















