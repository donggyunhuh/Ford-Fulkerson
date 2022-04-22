# Ford-Fulkerson 알고리즘 (최대 유량 알고리즘)

## 목차

<br/>

1. 개요
2. 문제
3. 알고리즘 분석
4. 소스 구현
5. 알고리즘 성능 분석

<br/>

## 개요

<br/>

- Ford-Fulkerson 알고리즘에 대한 레포트이다.

  C 언어를 이용하여 구현했으며, 인터넷 검색과 관련 교재를 통해 공부하고 최대한 스스로 구현해보고자 하였다.

  알고리즘 이해 후 모두가 이해하기 쉬운 내 눈높이에서 설명될 수 있도록 노력했다.

  레포트는 개요, 문제, 알고리즘 분석, 소스 구현, 알고리즘 성능 분석의 구성을 가진다.

<br/>

## 문제

<br/>

- 두 정점 S, T가 존재하는 그래프가 있다.

  S 는 source의 약자로 유량을 발생시키는 정점, T는 최종 목적지이며 유량이 도착하는 정점이다.

  정점 S, T 사이의 특정 개수의 정점과 정점을 이어주는 간선의 개수는 입력받는다.

  S, T를 제외한 나머지 정점은 각각 용량 C(capacity), 유량 F(flow)를 가진다.

  S → a는 2의 용량, S → b는 1, a → T는 2, b → T는 1, a → b는 2의 용량을 가진다.

  아래 그래프를 Ford-Fulkerson 알고리즘을 이용하여 구현해보고자 한다.

   <br/>  
   <br/>
  <p align="center"><img src="https://github.com/donggyunhuh/Ford-Fulkerson/blob/master/1.png?raw=true" height="250px" width="350px"></p>

 <br/>
 <br/>

## 알고리즘 분석

- 각 간선의 용량을 그래프에 나타나면 다음과 같다.

<p align="center"><img src="https://github.com/donggyunhuh/Ford-Fulkerson/blob/master/2.png?raw=true" height="250px" width="350px"></p>

<br/>
<br/>

a → b 간선의 유량은 b → a 형태로도 흐를 수 있다.

위에서 정의한 용량(capacity), 유량(flow)를 함수의 꼴로 나타내보면

> c(a,b) : 정점 a에서 정점 b로 보낼 수 있는 최대 용량

> f(a,b) : 정점 a에서 정점 b로 현재 흐르는 유량

> 그래프에서는 (flow, capacity) 형태로 표현

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

<p align="center"><img src="5" height="250px" width="350px"></p>

<br/>

**∴ 그러므로 T에 도착하는 최대 유량은 1**

<br/>

**결론 : 주어진 그래프에서 T에서 받는 최대 유량은 3 이다**

### 다른 경우

<br/>

- S → b 의 용량이 2 이고 , a → T 의 용량이 3으로 주어졌을 때  
  그래프로 나타내면

<br/>

<p align="center"><img src="6" height="250px" width="350px"></p>
 
→ 위에서 구한 방식으로 최대 유량을 구하면

> S → a → T, S → b → T 를 먼저 탐색하는 경우 **3**

> S → a → b → T 를 먼저 탐색하는 경우 **1**

> S → b → a → T 를 먼저 탐색하는 경우 **2**

<br/>

- 문제점 발생

만약, S → a → b → T, S → b → a → T 를 각각 먼저 탐색 할 경우에  
S → a → T, S → b → T 를 먼저 탐색하는 경우보다 유량이 적음에도 불구하고 탐색이 종료되게 된다.(1,2는 3보다 작음)

<br/>

### 위 문제를 해결하기위해 **잔여용량** , **유량상쇄**의 개념을 사용한다.
