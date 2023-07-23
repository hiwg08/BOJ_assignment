# [Platinum I] Counting Stairs - 16650 

[문제 링크](https://www.acmicpc.net/problem/16650) 

### 성능 요약

메모리: 354368 KB, 시간: 524 ms

### 분류

조합론, 다이나믹 프로그래밍, 수학

### 문제 설명

<p>Remember Barney from problem B? Barney’s older sister Cecilia often watches him play with his set of cubes. She also joins Barney in his games and prevails most of the time, shaking his confidence on a daily basis.</p>

<p>One day Cecilia noticed Barney struggling to build a symmetric stair with his n cubes. She immediately told him she could not just build a symmetric stair, but even calculate the number of different symmetric stairs consisting of n cubes! Can you?</p>

<p>Recall that a symmetric stair consists of one or more towers of cubes, where the heights of towers are non-increasing from left to right, and is symmetric with respect to the x = y line (where the x-axis is horizontal and oriented to the right, and the y-axis is vertical and oriented upwards). For a more detailed explanation, please refer to problem B statement.</p>

<p>The number of different symmetric stairs can be quite large, so you need to calculate it modulo 998 244 353.</p>

### 입력 

 <p>The input contains multiple test cases.</p>

<p>The first line of the input contains a single integer t — the number of test cases (1 ≤ t ≤ 10<sup>4</sup>). Each of the following t lines contains a single integer n<sub>i</sub> — the number of cubes in the i-th test case (1 ≤ n<sub>i</sub> ≤ 2 · 10<sup>5</sup>).</p>

### 출력 

 <p>For each test case, output a line with a single integer — the number of symmetric stairs with exactly n<sub>i</sub> cubes, modulo 998 244 353.</p>

