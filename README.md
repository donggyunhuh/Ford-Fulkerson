# Ford-Fulkerson �˰��� (�ִ� ���� �˰���)

201901730 �㵿��

## ����

1. ����
2. ����
3. �˰��� �м�
4. �ҽ� ����
5. �˰��� ���� �м�

<br/>

## ����

- Ford-Fulkerson �˰��� ���� ����Ʈ�̴�.

  c���� �����Ϸ� ������, �� ������ C++ �� �̿��Ͽ� ����������, ���ͳ� �˻��� ���� ���縦 ���� �����ϰ� �ִ��� ������ �����غ����� ����Ͽ���.

  �˰��� ���� �� ��ΰ� �����ϱ� ���� �� �����̿��� ����� �� �ֵ��� ����ߴ�.

  �ڵ� �����κ��� �ٸ������ �ڵ带 ���� �� ���̴�.

  �˰��� �м� �κ��� ��� �׸� �ڷ�� ���� ������ �ڷ��̴�.

  ����Ʈ�� ����, ����, �˰��� �м�, �ҽ� ����, �˰��� ���� �м��� ������ ������.

<br/>

## ����

- �� ���� S, T�� �����ϴ� �׷����� �ִ�.

  S �� source�� ���ڷ� ������ �߻���Ű�� ����, T�� ���� �������̸� ������ �����ϴ� �����̴�.

  ���� S, T ������ Ư�� ������ ������ ������ �̾��ִ� ������ ������ �Է¹޴´�.

  S, T�� ������ ������ ������ ���� �뷮 C(capacity), ���� F(flow)�� ������.

  S �� a�� 2�� �뷮, S �� b�� 1, a �� T�� 2, b �� T�� 1, a �� b�� 2�� �뷮�� ������.

  �Ʒ� �׷����� Ford-Fulkerson �˰����� �̿��Ͽ� �����غ����� �Ѵ�.

   <br/>  
  <p align="center"><img src="https://github.com/donggyunhuh/Ford-Fulkerson/blob/master/1.png?raw=true" height="250px" width="350px"></p>

## �˰��� �м�

- �� ������ �뷮�� �׷����� ��Ÿ���� ������ ����.

<p align="center"><img src="https://github.com/donggyunhuh/Ford-Fulkerson/blob/master/2.png?raw=true" height="250px" width="350px"></p>

<br/>

a �� b ������ ������ b �� a ���·ε� �带 �� �ִ�.

������ ������ �뷮(capacity), ����(flow)�� �Լ��� �÷� ��Ÿ������

> c(a,b) : ���� a���� ���� b�� ���� �� �ִ� �ִ� �뷮

> f(a,b) : ���� a���� ���� b�� ���� �帣�� ����

> �׷��������� (flow, capacity) ���·� ǥ��

- �˰��� �⺻ �Ӽ�

1. ���� a���� b�� �帣�� ������ �뷮���ٴ� ���ų� ���� : _f(a,b) <= c(a,b)_
2. �� ������ ���� ������ ������ ���� 0�̴�. (������ ���� ����)

<br/>

- �� �׷����� ���� ������ (flow, capacity)�� �÷� ��Ÿ������ (���� �帣�� ������ 0���� �ʱ�ȭ�Ѵ�.)

<p align="center"><img src="https://github.com/donggyunhuh/Ford-Fulkerson/blob/master/3.png?raw=true" height="250px" width="350px"></p>

<br/>

�̰� �� �׷������� T�� �����ϴ� �ִ� ������ ����Ѵ�.

---

### S �� a �� T , S �� b �� T �� ���� Ž���ϴ� ���

<br/>

S �� a �� T �� ���

- S �� a : �ִ� �带 �� �ִ� ������ 2 (�� c = 2)
- a �� T : �ִ� �带 �� �ִ� ������ 2 (�� c = 2)

�� T�� �����ϴ� �ִ� ������ 2

<br/>

S �� b �� T �� ���

- S �� a : �ִ� �带 �� �ִ� ������ 1 (�� c = 1)
- a �� T : �ִ� �带 �� �ִ� ������ 1 (�� c = 1)

�� T�� �����ϴ� �ִ� ������ 1

<br/>

**�� T�� �����ϴ� �ִ� ������ 3**

---

### S �� a �� b �� T �� ���� Ž���ϴ� ���

- S �� a : �ִ� �带 �� �ִ� ������ 2 (�� c = 2)
- a �� b : �ִ� �带 �� �ִ� ������ 2 (�� c = 2)
- b �� T : �ִ� �带 �� �ִ� ������ 1 (�� c = 1)

�� T�� �����ϴ� ������ 1 (b �� T�� �ִ� ������ 1�̹Ƿ�)

<br/>

<p align="center"><img src="https://github.com/donggyunhuh/Ford-Fulkerson/blob/master/4.png?raw=true" height="250px" width="350px"></p>

<br/>

**�� T�� �����ϴ� �ִ� ������ 1**

---

### S �� b �� a �� T �� ���� Ž���ϴ� ���

- S �� b : �ִ� �带 �� �ִ� ������ 1 (�� c = 1)
- b �� a : �ִ� �带 �� �ִ� ������ 2 (�� c = 2)
- a �� T : �ִ� �带 �� �ִ� ������ 2 (�� c = 2)

�� T�� �����ϴ� ������ 1 (S �� b �� �ִ� ������ 1�̹Ƿ�)

<br/>

<p align="center"><img src="https://github.com/donggyunhuh/Ford-Fulkerson/blob/master/5.png?raw=true" height="250px" width="350px"></p>

<br/>

**�� T�� �����ϴ� �ִ� ������ 1**

<br/>

**��� : �־��� �׷������� T���� �޴� �ִ� ������ 3 �̴�.**

---

## �� ������ �뷮�� �ٸ� ���

<br/>

- S �� b �� �뷮�� 2 �̰� , a �� T �� �뷮�� 3���� �־����� ��  
  �׷����� ��Ÿ����

<br/>

<p align="center"><img src="https://github.com/donggyunhuh/Ford-Fulkerson/blob/master/6.png?raw=true" height="250px" width="350px"></p>

<br/>
 
�� ������ ���� ������� �ִ� ������ ���ϸ�

> S �� a �� T, S �� b �� T �� ���� Ž���ϴ� ��� **3**

> S �� a �� b �� T �� ���� Ž���ϴ� ��� **1**

> S �� b �� a �� T �� ���� Ž���ϴ� ��� **2**

<br/>

- ������ �߻�

����, S �� a �� b �� T, S �� b �� a �� T �� ���� ���� Ž�� �� ��쿡  
S �� a �� T, S �� b �� T �� ���� Ž���ϴ� ��캸�� ������ �������� �ұ��ϰ� Ž���� ����ǰ� �ȴ�.(1,2�� 3���� ����)

<br/>

### �� ������ �ذ��ϱ����� **�ܿ�����** , **�������**�� ������ ����Ѵ�.

<br/>

#### �ܿ������� ��������� ������ ����ϱ� �� �˰����� �Ӽ��� �����ϰڴ�.

<br/>

> ������ ���� a,b�� ���Ͽ� f(a,b) = -f(b,a)�� ����

<br/>

<p align="center"><img src="https://github.com/donggyunhuh/Ford-Fulkerson/blob/master/7.png?raw=true" height="200px" width="300px"></p>

<br/>

�� ������ ������ ����ѵ�, �� �׷����� ���� ��� �����ϰڴ�.

���� a���� b�� �帣�� ������ f(a,b)�� ǥ�� �� �� ������ �� ������ �׷����� ������ �Ʒ��� �帥��.

�ݴ�� f(b,a)�� ���� b���� a�� �帣�� �����̸�, �׷����� �Ʒ����� ���� �帥��.

�׷��Ƿ� f(a,b), f(b,a)�� ��ȣ ������ �����ϸ� _f(a,b) = -f(b,a)_ �� �����Ѵ�.

> f(a,b) = -f(b,a)

<br/>
<br/>

- �ܿ�����(Residual Flow)

�Լ��÷� ��Ÿ����

> r(a,b) : ������ �� ������ �մ� ���������� �ܿ�����

<br/>

������ �� ������ �մ� ���������� �ܿ����� = �ִ�뷮 - �����帣�� ������ �ǹ��Ѵ�.

> r(a,b) = c(a,b) - f(a,b) �� ����

---

- **�������**

Ford-Fulkerson �˰��� ���ؿ� �־ ���� �߿��� �κ��̴�.  
 �� �뷮�� �ٸ� ��츦 ���÷� ��� �����ϰڴ�.
<br/>

<p align="center"><img src="https://github.com/donggyunhuh/Ford-Fulkerson/blob/master/6.png?raw=true" height="250px" width="350px"></p>

<br/>

�ռ� ���ߵ���, �� �׷������� T�� �����ϴ� �ִ� ������ 3�̴�.

����, S �� a �� b �� T, S �� b �� a �� T �� ���� Ž���Ѱ�� �ִ� ������ ������ ���ϰ� Ž���� ������� �� �� �ִ�.

�� ������ **�������**�� �������� �ذ��� �� �ִ�.

���� ����, ���� ���� �� ������ ������ �帣�� �ݴ� �������� ���� ������ ��� �������ν� ������ ��� ��Ű�� ���� �ǹ��Ѵ�.

�� �׷����� �̿��� �����ϰڴ�.

S �� a �� b �� T�� ������ ��� ������, ��ġ�� ������ ����� a �� b�� ������ f(a,b) �� ��Ÿ�� �� ������ f(a,b) �� 1 �̴�.

�̶� b �� a�� �帣�� ���� f(b,a) �� �ݴ� �����̹Ƿ� -1 �� ���� �� �� �ִ�.

�̶� ������ ������ �뷮�� ���� �����ϴ� ������ �ƴϹǷ� c(b,a) �� 0 �̴�.

���⼭ �ܿ��뷮 ������ ����Ͽ� ��Ÿ������ b �� a �� �ܿ��뷮 r(b,a) = c(b,a) - f(b,a), �� 0 - (-1) = 1 �̴�.

���� b �� a �� �ܿ��뷮�� 1 ���������� b���� a�� 1 ��ŭ�� ������ �߰��� ������� �� �ִ�.

��, S �� b �� a �� T �� ��θ� Ž���� �� �ִ�.

�ᱹ ó���� S �� a �� T, S �� b �� T �� ���� Ž�� �� T�� �����ϴ� �뷮, �� �ִ�뷮�� ���ϴ� Ž����ο� ���� ���� �ȴ�.

�������ڸ�, a �� b�� �̹� �帥 ������ ���������� ����Ѵٰ� �����ϴ� ���̴�.

�Ʒ� �׷����� ����Ǿ� �ִ�.

<br/>

<p align="center"><img src="https://github.com/donggyunhuh/Ford-Fulkerson/blob/master/8.png?raw=true" height="270px" width="450px"></p>

<br/>

# **����**

 <br/>

Ford-Fulkerson �˰��� Ž�������� ũ�� 4 �ܰ�� ������ ���Ҵ�.

1. ��� ������ ���� f(a,b)�� 0���� �ʱ�ȭ �Ѵ�.

2. �ܿ� �뷮�� ���� ������ Ž���Ѵ�.

3. �� ������ �ܿ� �뷮�� Ȯ�� �� �� �� �������� ������ ��� ������.

4. �� ������ �ݴ�������� ���� ������ �����ٰ� �����Ѵ�.

5. 2~4�� �ݺ��ϸ� �ִ� Ȯ�ν� �˰����� �����Ѵ�.

<br/>

# �˰��� �ҽ� ����

<br/>

<p align="center"><img src="https://github.com/donggyunhuh/Ford-Fulkerson/blob/master/6.png?raw=true" height="250px" width="350px"></p>

<br/>

�� �׷����� �����Ͽ� ���ڴ�.

���ǻ� S�� 1, a�� 2, b�� 3, T�� 4��� �����Ѵ�.

queue�� �̿��Ͽ� �����Ѵ�.

DFS�� �̿��Ѵ�.

<br/>
�׷��� �Է� �κ�

```c++
#include <bits/stdc++.h>   // ������� ����

constexpr int MAX = 10 + 1;
constexpr int INF = 999999999;

std::vector<int> adj[MAX];
int c[MAX][MAX], f[MAX][MAX];

void makeGraph(int a, int b, int capacity) { //�׷����� �Է� �� �迭�� ����
	adj[a].push_back(b);
	adj[b].push_back(a);
	c[a][b] = capacity;
	c[b][a] = 0;
}

```

<br/>

���� �Լ� ����

```c++
int FordFulkerson(int start, int end) { // ���� ����, ���� ���� �Է� (S, T)
	int result = 0;

	while (true) { // queue �� �̿��Ͽ� ���� Ž��
		std::vector<int> dist(MAX, -1);
		std::queue<int> q;
		q.push(start);

		while (!q.empty()) {
			int current = q.front();
			q.pop();

			for (int i = 0; i < adj[current].size(); ++i) {
				int next = adj[current][i];

				if (c[current][next] - f[current][next] > 0 && dist[next] == -1) {
					dist[next] = current;
					q.push(next);
					if (next == end)
						break;
				}
			}
		}

		if (dist[end] == -1)
			break;

		int flow = INF;
		for (int i = end; i != start; i = dist[i])
			flow = std::min(flow, c[dist[i]][i] - f[dist[i]][i]);

		for (int i = end; i != start; i = dist[i]) {
			f[dist[i]][i] += flow;
			f[i][dist[i]] -= flow;
		}

		result += flow;
	}

	return result;
}
```

<br/>

��� �κ�

```c++
int main() {
	makeGraph(1, 2, 2);
	makeGraph(1, 3, 2);
	makeGraph(2, 4, 3);
	makeGraph(3, 4, 1);
	makeGraph(2, 3, 2);


	std::cout << FordFulkerson(1, 4); // ���
}
```

## �˰��� ���� ���

������ ���� 3�� ����� ��µ�!

<br/>
 
<p align="center"><img src="https://github.com/donggyunhuh/Ford-Fulkerson/blob/master/9.png?raw=true" height="550px" width="700px"></p>
����ȯ�� - ������ 11, �¶��� repl.it c++ 17 ���

# �˰��� �м�

DFS Ž���� ��������Ƿ� O(V+E) �� ����ð��� �ҿ�ȴ�.

�ִ������� f�� �������� ��, �ð����⵵�� O((V +E)f)�� �ȴ�.

f���� ���� �ð����⵵�� ���� �ǹǷ�, f ���� ũ�� �־��� ��Ȳ�� �߻��Ѵ�.

## �־��� ��Ȳ

<br/>

<p align="center"><img src="https://github.com/donggyunhuh/Ford-Fulkerson/blob/master/10.png?raw=true" height="250px" width="350px"></p>

<br/>

> ���: 1�� ������ �����°��� 10000�� �ݺ��Ѵ�.

<br/>

S �� a �� b �� T���� 1�� ����, S �� b �� a �� T�� 1�� ������ ������ �Ǵµ�, a �� b b �� a������ ������ �����̹Ƿ� �ʱ�ȭ �ȴ�.

�ᱹ 10000���� �ݺ� ���� �˰����� ����Ǵ� ���̴�.

�̰��� DFSŽ���� �̿��� �� �˰����� �����̴�.

- �ִ��������� Ŭ ����, ���� �ʾƵ� �� Ž���� �����Ѵ�.

---

<br/>

### ����

�Ȱ����� ������(https://m.blog.naver.com/ndb796/221237111220)
