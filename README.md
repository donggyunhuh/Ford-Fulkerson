# Ford-Fulkerson 알고리즘 (최대 유량 알고리즘)

## 목차

1. 개요
2. 문제
3. 알고리즘 분석
4. 소스 구현
5. 알고리즘 성능 분석

<br/>

## 개요

- Ford-Fulkerson 알고리즘에 대한 레포트이다.

  C 언어를 이용하여 구현했으며, 인터넷 검색과 관련 교재를 통해 공부하고 최대한 스스로 구현해보고자 하였다.

  알고리즘 이해 후 모두가 이해하기 쉬운 내 눈높이에서 설명될 수 있도록 노력했다.

  모든 그림 자료는 직접 제작한 자료이다.

  레포트는 개요, 문제, 알고리즘 분석, 소스 구현, 알고리즘 성능 분석의 구성을 가진다.

<br/>

## 문제

- 두 정점 S, T가 존재하는 그래프가 있다.

  S 는 source의 약자로 유량을 발생시키는 정점, T는 최종 목적지이며 유량이 도착하는 정점이다.

  정점 S, T 사이의 특정 개수의 정점과 정점을 이어주는 간선의 개수는 입력받는다.

  S, T를 제외한 나머지 정점은 각각 용량 C(capacity), 유량 F(flow)를 가진다.

  S → a는 2의 용량, S → b는 1, a → T는 2, b → T는 1, a → b는 2의 용량을 가진다.

  아래 그래프를 Ford-Fulkerson 알고리즘을 이용하여 구현해보고자 한다.

   <br/>  
  <p align="center"><img src="https://github.com/donggyunhuh/Ford-Fulkerson/blob/master/1.png?raw=true" height="250px" width="350px"></p>

## 알고리즘 분석

- 각 간선의 용량을 그래프에 나타나면 다음과 같다.

<p align="center"><img src="https://github.com/donggyunhuh/Ford-Fulkerson/blob/master/2.png?raw=true" height="250px" width="350px"></p>

<br/>

a → b 간선의 유량은 b → a 형태로도 흐를 수 있다.

위에서 정의한 용량(capacity), 유량(flow)를 함수의 꼴로 나타내보면

> c(a,b) : 정점 a에서 정점 b로 보낼 수 있는 최대 용량

> f(a,b) : 정점 a에서 정점 b로 현재 흐르는 유량

> 그래프에서는 (flow, capacity) 형태로 표현

- 알고리즘 기본 속성

1. 정점 a에서 b로 흐르는 유량은 용량보다는 적거나 같다 : _f(a,b) <= c(a,b)_
2. 각 정점에 들어가고 나오는 유량의 합은 0이다. (전류와 같은 개념)

<br/>

- 이 그래프를 위에 정의한 (flow, capacity)의 꼴로 나타내보면 (현재 흐르는 유량은 0으로 초기화한다.)

<p align="center"><img src="https://github.com/donggyunhuh/Ford-Fulkerson/blob/master/3.png?raw=true" height="250px" width="350px"></p>

<br/>

이고 이 그래프에서 T에 도달하는 최대 유량을 계산한다.

### S → a → T , S → b → T 를 먼저 탐색하는 경우

<br/>

S → a → T 인 경우

- S → a : 최대 흐를 수 있는 유량은 2 (∵ c = 2)
- a → T : 최대 흐를 수 있는 유량은 2 (∵ c = 2)

∴ T에 도달하는 최대 유량은 2

<br/>

S → b → T 인 경우

- S → a : 최대 흐를 수 있는 유량은 1 (∵ c = 1)
- a → T : 최대 흐를 수 있는 유량은 1 (∵ c = 1)

∴ T에 도달하는 최대 유량은 1

<br/>

**∴그러므로 T에 도착하는 최대 유량은 3**

<br/>

### S → a → b → T 를 먼저 탐색하는 경우

- S → a : 최대 흐를 수 있는 유량은 2 (∵ c = 2)
- a → b : 최대 흐를 수 있는 유량은 2 (∵ c = 2)
- b → T : 최대 흐를 수 있는 유량은 1 (∵ c = 1)

∴ T에 도달하는 유량은 1 (b → T의 최대 유량이 1이므로)

<br/>

<p align="center"><img src="https://github.com/donggyunhuh/Ford-Fulkerson/blob/master/4.png?raw=true" height="250px" width="350px"></p>

<br/>

**∴ 그러므로 T에 도착하는 최대 유량은 1**

<br/>

### S → b → a → T 를 먼저 탐색하는 경우

- S → b : 최대 흐를 수 있는 유량은 1 (∵ c = 1)
- b → a : 최대 흐를 수 있는 유량은 2 (∵ c = 2)
- a → T : 최대 흐를 수 있는 유량은 2 (∵ c = 2)

∴ T에 도달하는 유량은 1 (S → b 의 최대 유량이 1이므로)

<br/>

<p align="center"><img src="https://github.com/donggyunhuh/Ford-Fulkerson/blob/master/5.png?raw=true" height="250px" width="350px"></p>

<br/>

**∴ T에 도착하는 최대 유량은 1**

<br/>

**결론 : 주어진 그래프에서 T에서 받는 최대 유량은 3 이다**

## 다른 경우 (용량 다른 경우)

<br/>

- S → b 의 용량이 2 이고 , a → T 의 용량이 3으로 주어졌을 때  
  그래프로 나타내면

<br/>

<p align="center"><img src="https://github.com/donggyunhuh/Ford-Fulkerson/blob/master/6.png?raw=true" height="250px" width="350px"></p>

<br/>
 
→ 위에서 구한 방식으로 최대 유량을 구하면

> S → a → T, S → b → T 를 먼저 탐색하는 경우 **3**

> S → a → b → T 를 먼저 탐색하는 경우 **1**

> S → b → a → T 를 먼저 탐색하는 경우 **2**

<br/>

- 문제점 발생

만약, S → a → b → T, S → b → a → T 를 각각 먼저 탐색 할 경우에  
S → a → T, S → b → T 를 먼저 탐색하는 경우보다 유량이 적음에도 불구하고 탐색이 종료되게 된다.(1,2는 3보다 작음)

<br/>

### 위 문제를 해결하기위해 **잔여유량** , **유량상쇄**의 개념을 사용한다.

<br/>

#### 잔여유량과 유량상쇄의 개념을 사용하기 전 알고리즘의 속성을 정의하겠다.

<br/>

> 임의의 정점 a,b에 대하여 f(a,b) = -f(b,a)가 성립

<br/>

<p align="center"><img src="https://github.com/donggyunhuh/Ford-Fulkerson/blob/master/7.png?raw=true" height="200px" width="300px"></p>

<br/>

→ 전류의 성질과 비슷한데, 위 그래프를 예를 들어 설명하겠다.

정점 a에서 b로 흐르는 유량은 f(a,b)로 표현 할 수 있으며 이 유량은 그래프상 위에서 아래로 흐른다.

반대로 f(b,a)는 정점 b에서 a로 흐르는 유량이며, 그래프상 아래에서 위로 흐른다.

그러므로 f(a,b), f(b,a)에 부호 개념을 도입하면 _f(a,b) = -f(b,a)_ 가 성립한다.

> f(a,b) = -f(b,a)

<br/>
<br/>

- 잔여유량(Residual Flow)

함수꼴로 나타내면

> r(a,b) : 임의의 두 정점을 잇는 간선에서의 잔여유량

<br/>

임의의 두 정점을 잇는 간선에서의 잔여유량 = 최대용량 - 현재흐르는 유량을 의미한다.

> r(a,b) = c(a,b) - f(a,b) 가 성립

<br/>

- **유량상쇄**

Ford-Fulkerson 알고리즘 이해에 있어서 가장 중요한 부분이다.  
 위 용량이 다른 경우를 예시로 들어 설명 하겠다.
<br/>

<p align="center"><img src="https://github.com/donggyunhuh/Ford-Fulkerson/blob/master/6.png?raw=true" height="250px" width="350px"></p>

<br/>

앞서 구했듯이, 위 그래프에서 T에 도달하는 최대 유량은 3이다.

또한, S → a → b → T, S → b → a → T 를 먼저 탐색한경우 최대 유량을 구하지 못하고 탐색이 종료됨을 알 수 있다.

이 문제는 **유량상쇄**의 개념으로 해결할 수 있다.

유량 상쇄란, 쉽게 말해 각 간선에 유량이 흐르는 반대 방향으로 음의 유량을 흘려 보냄으로써 유량을 상쇄 시키는 것을 의미한다.

위 그래프를 이용해 설명하겠다.

S → a → b → T로 유량을 흘려 보낼때, 겹치는 정점의 노드인 a → b의 유량은 f(a,b) 로 나타낼 수 있으며 f(a,b) 는 1 이다.

이때 b → a로 흐르는 유량 f(b,a) 는 반대 방향이므로 -1 로 생각 할 수 있다.

이때 역방향 간선의 용량은 실제 존재하는 간선이 아니므로 c(b,a) 는 0 이다.

여기서 잔여용량 개념을 사용하여 나타내보면 b → a 의 잔여용량 r(b,a) = c(b,a) - f(b,a), 즉 0 - (-1) = 1 이다.

이제 b → a 의 잔여용량이 1 존재함으로 b에서 a로 1 만큼의 유량을 추가로 흘려보낼 수 있다.

즉, S → b → a → T 의 경로를 탐색할 수 있다.

결국 처음에 S → a → T, S → b → T 를 각각 탐색 후 T에 도착하는 용량, 즉 최대용량를 구하는 탐색경로와 같은 꼴이 된다. 아래 그래프에 설명되어 있다.

<br/>

<p align="center"><img src="https://github.com/donggyunhuh/Ford-Fulkerson/blob/master/8.png?raw=true" height="270px" width="450px"></p>

<br/>

# **정리**

 <br/>

Ford-Fulkerson 알고리즘 탐색과정을 크게 4 단계로 나누어 보았다.

1. 잔여 용량이 남은 간선을 탐색한다.

2. 각 간선의 잔여 용량을 확인 한 후 각 정점으로 유량을 흘려 보낸다.

3. 각 간선의 반대방향으로 음의 유량을 보낸다.

4. 1~3을 반복하며 최댓값 확인시 알고리즘을 종료한다.
