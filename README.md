# :woman_technologist: TIL
### :books: Today I Learned :books:
* **:file_folder:[PS](https://github.com/sooooojinlee/TIL/tree/master/PS)**
  * 2020/12/31 전에 코포 보라닉달기 :sunglasses:
  * 백준 [500등](https://www.acmicpc.net/user/jaq0424) 안에 들기
  * 매일 1문제 이상
  * **커밋하기전 다시 새로 풀기**
* **:file_folder:Data Structure**
  * 자료구조 구현 정리(C로 작성)
  * stl, 라이브러리 없이 구현하는거 연습하기
* **:file_folder:ML/DL**
  * deeplearning.ai 듣고 정리
* **:file_folder:git**
  * [Git 사용 중 자주 만나는 이슈 정리](https://parksb.github.io/article/28.html)
* **:file_folder:Java**
* **:file_folder:Javascript**
* **:file_folder:Python**
* **:file_folder:C++14/C++17**
* **:file_folder:CS**
* **:file_folder:Interview**
* **:file_folder:Paper**
* **:file_folder:Math**
  * 선형대수학(https://www.youtube.com/playlist?list=PLxMkK1K0XECOj2sZG-gCk-CjvZhJ_75I4) 듣고 정리(2019/09/04~2019/09/05)
* **:file_folder:etc**

### 1일 1커밋 :four_leaf_clover: 오늘 공부한건 오늘 정리:pencil:
<details>
 <summary> :calendar: 2020년 1월</summary>
<div markdown="1">
 
##### 200127 월
* 16924 십자가 찾기 다시 풂
##### 200128 화
* 16922 로마 숫자 만들기 다시 풂
* 16988 Baaaaaaaaaduk2 (Easy) 맞왜틀..
##### 200129 수
* 17070 파이프 옮기기, 15686 치킨배달, 16637 괄호 추가하기 다시 풂
* 1413 제 1종 스털링 수...? :thinking:
##### 200130 목
* 17406 배열 돌리기4
  * algorithm 헤더에 rotate 같은 것도 있던데... 
  for문으로 삽질안하고  
  ```rotate(group.rbegin(), group.rbegin()+1, group.rend())```  
  같은 방법도 있음...:innocent:
  * 기출 중에 톱니바퀴랑 비슷한 듯
  * algorithm, tuple 헤더 없이 하는 ps 머리에 쥐난다 :woman_facepalming:
* 15684 사다리 조작 다시 풂
* 16968 차량 번호판
##### 200131 금
* PPHUB 예쁘다.. 위젯에 잔디밭 깔리는거:relaxed:
</div>
</details>
<details>
 <summary> :calendar: 2020년 2월</summary>
<div markdown="1">
 
##### 200202 일
* 16917 양념 반 후라이드 반
* 16937 두 스티커
* 16988 Baaaaaaaaaduk2 (Easy)
* 16945 매직 스퀘어로 변경하기
* 크기 N * N 행렬 A의 B제곱 -> 시간복잡도 O(N^3logB)
* int 범위를 초과하는 피보나치 수 -> 피사노 주기
  * 피보나치 수를 k로 나눈 나머지는 주기를 갖는다
  * But, N번 째 피보나치 수 (N <= 1000000000000000) k가 매우 클 때 (k = 1000000007) 행렬 제곱 이용 
  
##### 200203 월
* 15683 다시 풂
* 16956 늑대와 양 
  * 울타리를 최소로 치는 문제가 아님 -> 인접한 칸에 늑대만 없으면 빈칸에 울타리를 전부 쳐 버리면 됨
* 16938 캠프준비
  * 문제를 선택하거나 안하거나 -> 재귀 or 비트마스크로 풀기
* 17085 십자가 2개 놓기
  * 첫번째 십자가를 놓고 두번째 십자가를 놓는데 첫번째 십자가를 다시 십자가를 놓을 수 있는 칸으로 바꾸는 과정 주의하기
  
##### 200204 화
* 16932 모양 만들기
  * N * M인 모든 칸에서 BFS를 수행하는데 걸리는 시간 복잡도 O(NMNM) -> 1<=N, M <=1000 이므로 O(1000^4)
  * 모든 칸을 1로 바꿔가면서 BFS를 할 수 없다
* 17086 아기 상어 2

##### 200205 수
* 4991 로봇 청소기
* 2003 수들의 합 2
  * O(N^3) -> i를 정하고 j를 정함  
  ```
  for(int i=0; i<n; i++) {
    for(int j=i; j<n; j++) {
      int sum=0;
      for(int k=i; k<=j; k++) {
       sum+=a[k];
      }
    }
  }
  ```
  * O(N^2) -> 각각의 i에 대해서 누적
  ```
  for(int i=0; i<n; i++) {
   int sum=0;
   for(int j=i; j<n; j++) {
    sum+=a[j];
   }
  }
  ```
  * O(N) -> 투 포인터
* 16948 데스 나이트

##### 200206 목
* 2151 거울 설치
* 2234 성곽
* 17089 세 친구

##### 200207 금
* 2206 벽 부수고 이동하기
  * 벽을 한번만 부수는 최소 이동 거리
* 14442 벽 부수고 이동하기 2
  * 벽을 k번까지 부술 수 있는 최소 이동 거리
* 16933 벽 부수고 이동하기 3
  * 맞왜틀:thinking: 계속 다시 풀어보기..
* 16942 벽 부수고 이동하기 4
  * 벽을 부쉈을 때 벽을 부순 칸에서 이동할 수 있는 칸의 개수 구하기
  * 16932 모양 만들기랑 출력형식만 다른 문제
* 16928 뱀과 사다리 게임
  * 다음 방문할 칸을 정하는 배열이름을 next로 했을 때 왜 next가 모호합니다라는 오류 발생하는지..:thinking:
* 16638 괄호 추가하기 2
  * 파이썬은 c++로 짠 120줄 짜리 코드를 30줄도 안되게 만들어 버린다:rofl:
  * ```eval()``` 함수는 string expression을 그대로 실행시켜 준다.
  * 단 표현식을 그대로 실행시키는 것이기 때문에 command injection flaws를 그대로 노출시킬 수 있는 위험성이 있다고함 -> 시스템 명령어를 그대로 실행시킬 수 있기 때문에 
  * ```literal_eval()``` 이라는 것도 있음. ```eval()``` 보다 안전하나 사용이 제한적임
  
##### 2002208 토
* 17141 연구소 2
* 17142 연구소 3
* 17088 등차수열 변환
</div>
</details>
