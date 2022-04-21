# Ford-Fulkerson 알고리즘 (최대 유량 알고리즘)

## 목차

1. 개요
2. 문제
3. 알고리즘 분석
4. 소스 구현
5. 알고리즘 성능 분석

## 개요

- Ford-Fulkerson 알고리즘에 대한 레포트이다.

  C 언어를 이용하여 구현했으며, 인터넷 검색과 관련 교재를 통해 공부하고 최대한 스스로 구현해보고자 하였다.

  알고리즘 이해 후 모두가 이해하기 쉬운 내 눈높이에서 설명될 수 있도록 노력했다.

  레포트는 개요, 문제, 알고리즘 분석, 소스 구현, 알고리즘 성능 분석의 구성을 가진다.

## 문제

- 두 정점 S, T가 존재하는 그래프가 있다.

  S 는 source의 약자로 유량을 발생시키는 정점, T는 최종 목적지이며 최대 유량을 구하는 정점이다.

  정점 S, T 사이의 특정 개수의 정점과 정점을 이어주는 간선의 개수는 입력받는다.

  S, T를 제외한 나머지 정점은 각각 용량 C(capacity), 유량 F(flow)를 가진다.

  S → a는 2의 용량, S → b는 1, a → T는 2, b → T는 1, a → b는 2의 용량을 가진다.

  아래 그래프를 Ford-Fulkerson 알고리즘을 이용하여 구현해보고자 한다.

 <p align="center"><img src="https://github.com/donggyunhuh/Ford-Fulkerson/blob/master/1.png?raw=true" height="250px" width="350px"></p>

## 알고리즘 분석

<p align="center"><img src="https://github.com/donggyunhuh/Ford-Fulkerson/blob/master/2.png?raw=true" height="250px" width="350px"></p>
