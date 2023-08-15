# [Platinum II] 컵 쌓기 - 27234 

[문제 링크](https://www.acmicpc.net/problem/27234) 

### 성능 요약

메모리: 2200 KB, 시간: 1200 ms

### 분류

조합론, 다이나믹 프로그래밍, 수학

### 문제 설명

<p> </p>

<p><img alt="" src="https://upload.acmicpc.net/15a2917e-b107-4fed-acc7-e30bcfde7b3b/-/preview/" style="display: block; margin-left: auto; margin-right: auto; width: 100%; max-width: 400px;"></p>

<p>스포츠스태킹은 <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D441 TEX-I"></mjx-c></mjx-mi></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mi>N</mi></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$N$</span></mjx-container>개의 컵을 다양한 방법으로 빠르게 쌓는 스포츠 경기다. BOJ 스포츠스태킹 협회의 회장 한나는 이번에 새롭게 출시한 빨간 컵의 판매량을 늘리기 위해 새로운 스포츠스태킹 종목을 도입하고자 한다. (문제의 그림에서 빨간 컵은 가로줄이 그려져 있는 컵이다.) 그 규칙은 다음과 같다.</p>

<p>참가자는 빨간 컵 <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D441 TEX-I"></mjx-c></mjx-mi></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mi>N</mi></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$N$</span></mjx-container>개와 파란 컵 <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D441 TEX-I"></mjx-c></mjx-mi></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mi>N</mi></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$N$</span></mjx-container>개를 준비한다. 참가자는 이 중 <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D441 TEX-I"></mjx-c></mjx-mi></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mi>N</mi></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$N$</span></mjx-container>개의 컵을 쌓아서 규칙에 맞는 배치를 아무거나 만들어야 한다. 컵을 쌓는 규칙은 다음과 같다.</p>

<ul>
	<li>맨 아랫층에는 컵이 일렬로 연속해 있어야 한다.</li>
	<li>두 이웃한 컵의 중앙 위쪽에 다른 컵을 쌓을 수 있다. 이를 반복해서 여러 층을 쌓을 수도 있다.</li>
	<li>두 이웃한 컵 위에 다른 컵을 쌓으려면, 두 컵 중 적어도 하나는 빨간 컵이어야 한다.</li>
</ul>

<p><img alt="" src="https://upload.acmicpc.net/12f47177-3446-470c-8a64-e42af06df5a4/-/preview/" style="display: block; margin-left: auto; margin-right: auto; width: 100%; max-width: 300px;"></p>

<p>색깔이 같은 컵끼리는 구분할 수 없다고 할 때, 컵을 쌓을 수 있는 경우의 수를 주어지는 소수 <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D443 TEX-I"></mjx-c></mjx-mi></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mi>P</mi></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$P$</span></mjx-container>로 나눈 나머지를 구하시오. 두 배치가 서로 대칭이어도, 서로 다른 배치로 센다.</p>

### 입력 

 <p>첫 번째 줄에 쌓을 컵의 개수를 나타내는 정수 <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D441 TEX-I"></mjx-c></mjx-mi></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mi>N</mi></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$N$</span></mjx-container>과 나누어 출력할 소수 <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D443 TEX-I"></mjx-c></mjx-mi></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mi>P</mi></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$P$</span></mjx-container>가 공백을 사이에 두고 주어진다.</p>

### 출력 

 <p>규칙을 만족하도록 <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D441 TEX-I"></mjx-c></mjx-mi></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mi>N</mi></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$N$</span></mjx-container>개의 컵을 쌓는 경우의 수를 <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D443 TEX-I"></mjx-c></mjx-mi></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mi>P</mi></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$P$</span></mjx-container>로 나눈 나머지를 출력한다.</p>

