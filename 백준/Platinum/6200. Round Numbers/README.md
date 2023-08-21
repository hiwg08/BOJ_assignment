# [Platinum III] Round Numbers - 6200 

[문제 링크](https://www.acmicpc.net/problem/6200) 

### 성능 요약

메모리: 2032 KB, 시간: 0 ms

### 분류

조합론, 다이나믹 프로그래밍, 수학

### 문제 설명

<p>The cows, as you know, have no fingers or thumbs and thus are unable to play 'Scissors, Paper, Stone' (also known as 'Rock, Paper, Scissors', 'Ro, Sham, Bo', and a host of other names) in order to make arbitrary decisions such as who gets to be milked first. They can't even flip a coin because it's so hard to toss using hooves.</p>

<p>They have thus resorted to "round number" matching. The first cow picks an integer less than two billion. The second cow does the same.  If the numbers are both "round numbers", the first cow wins, otherwise the second cow wins.</p>

<p>A positive integer N is said to be a "round number" if the binary representation of N has as many or more zeroes than it has ones. For example, the integer 9, when written in binary form, is 1001. 1001 has two zeroes and two ones; thus, 9 is a round number. The integer 26 is 11010 in binary; since it has two zeroes and three ones, it is not a round number.</p>

<p>Obviously, it takes cows a while to convert numbers to binary, so the winner takes a while to determine.  Bessie wants to cheat and thinks she can do that if she knows how many "round numbers" are in a given range.</p>

<p>Help her by writing a program that tells how many round numbers appear in the inclusive range given by the input (1 <= Start < Finish <= 2,000,000,000).</p>

### 입력 

 <ul>
	<li>Line 1: Two space-separated integers, respectively Start and Finish.</li>
</ul>

### 출력 

 <ul>
	<li>Line 1: A single integer that is the count of round numbers in the inclusive range Start..Finish</li>
</ul>

