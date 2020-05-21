# 解題心得
[NCU OJ連結](http://140.115.50.98/)

這裡面有目前為止在NCUOJ上我寫過的題目的題解以及心得，雖然我的解法有些不是那麼好，但希望能幫助到想了解這些題目背後的演算法的人。

## 目錄
- NCU競程題解
    - [數學](#數學)
        - [x的k次方(快速冪)](#x的k次方)
    - [枚舉](#動態規劃)
    - [貪心法](#動態規劃)
    - [動態規劃](#動態規劃)
        - [又是硬幣問題](#又是硬幣問題)
        - [01背包問題](#01背包問題)
        - [費氏數列+快速冪](#費氏數列+快速冪)
## 數學
### x的k次方
[Code]()

[參考](https://zh.wikipedia.org/wiki/%E5%B9%B3%E6%96%B9%E6%B1%82%E5%B9%82)

這個題目運用到了快速冪。快速冪的公式大概長這樣![](https://wikimedia.org/api/rest_v1/media/math/render/svg/46fe9e68c70c04df4c3d22c469a57d4655b50539)

## 動態規劃
一般在思考動態規劃的問題，都會先觀察題目，接著再定義出適合的狀態以及轉移式。
### 又是硬幣問題
[Code](https://github.com/flyotlin/practice-cpp/blob/master/algorithm/dynamic%20programming/coin-dp.cpp)

這題一開始給定了數種硬幣的面額，接著給定一個金額，希望你可以求出能夠組成該金額的最少硬幣總數。

比較天真的想法是先將硬幣面額由大排到小，接著從大到小拿硬幣來組合出該金額。如此一來看起來可以解決這個問題。這種方法運用了貪心法的概念，每次都選擇最佳解或者最大解，但
#### 狀態:

#### 轉移式:

### Note:

希望之後會補上~
### 01背包問題
[Code](https://github.com/flyotlin/practice-cpp/blob/master/algorithm/dynamic%20programming/01knapsack_problem.cpp)

名稱中的01聽說是代表物品放或不放的意思。題目給定背包的大小，以及若干物品。為了讓狀態更好定義，我們可以把給定的背包大小假設為m。編號若干物品為Wi，從0開始算起。其中n為物品的總數量-1(因為從0開始編號)。
#### 狀態: 
> **dp(m, n)** 

空間為m時，從物品W0-Wn，選擇放或者不放的**最大價值**。一般dp的n=0都定義為沒有物品。如果n=0定義成W0~W0，則需要另外判斷沒有物品的狀況。
dp可以想像成一個二維陣列，列(row)為m，行(column)為n。
#### 轉移式:
> **dp(m, n) = max{dp(m, n-1), dp(m-第n個物品所占空間, n-1)+第n個物品的價值}**

* **dp(m, n-1)**

不放Wn的狀況，因此最大價值則跟dp(m, n-1)相同。

* **dp(m-第n個物品所占空間, n-1)+第n個物品的價值**

放Wn的狀況，因此我們需要騰出Wn所站的空間(m-Wn的空間)。

#### 初始值:
動態規劃的題目在定義好狀態以及轉移式之後，還需要給定初始值。如此一來才能由初始值，依照上面定義好的狀態以及轉移式來求解。

01背包問題的初始值，也就是我們可以事先定義好的值，包括了二維陣列dp中的第一列以及第一行。dp第一列代表空間為0，所以最大價值都是0。dp第一行代表沒有物品可以選擇，所以整行的最大價值也都是0。


#### Note:
這題算是動態規劃中比較進階一點的題目，我一開始在寫的時候也覺得滿不直覺的。特別是這題狀態的定義dp(m, n)，第一次寫的時候也覺得這個定義很tricky。

邊界的判斷也是這題常常會出錯的地方。在寫之前我都習慣用紙筆先草擬一遍，把整個程式的大致流程在紙上走過一遍，這樣在寫code的時候，比較有穩固的背後基礎。

### 費氏數列+快速冪
[Code](https://github.com/flyotlin/practice-cpp/blob/master/algorithm/dynamic%20programming/%E8%B2%BB%E6%B0%8F%E6%95%B8%E5%88%97%2B%E5%BF%AB%E9%80%9F%E5%86%AA.cpp)

我們都知道費氏數列的遞迴式是![](image/CodeCogsEqn.gif)。比較一般的做法，也就是用for迴圈來計算![](image/CodeCogsEqn1.gif)的話，時間複雜度大約是![](image/CodeCogsEqn2.gif)。但其實我們可以先計算出費氏數列的**轉移矩陣**，接著再利用**快速冪**的方式來計算![](image/CodeCogsEqn1.gif)的數值，這個方法可以將時間複雜度優化到![](image/CodeCogsEqn3.gif)。

#### 什麼是快速冪?
假設現在要你計算![](image/CodeCogsEqn4.gif)你會怎麼算?是將5連乘100次?還是先算出![](image/CodeCogsEqn5.gif)，再把![](image/CodeCogsEqn5.gif)平方來得到![](image/CodeCogsEqn4.gif)?

數學課計算時我們的確時常會運用這樣的技巧，而這種技巧就是快速冪的概念。只可惜我們在寫程式的時候卻常常直接用for迴圈來暴力解決這類型的指數問題，時間複雜度因而變為![](image/CodeCogsEqn2.gif)，但只要運用快速冪這類的概念，就能將時間複雜度降低為![](image/CodeCogsEqn3.gif)了。

將快速冪寫成比較數學的形式大概是以下這樣:

>![](image/CodeCogsEqn6.gif)

#### 費氏數列的轉移矩陣
我們已經知道![](image/CodeCogsEqn7.gif)，關係式為![](image/CodeCogsEqn8.gif)。可以先假設轉移矩陣為![](image/CodeCogsEqn9.gif)，帶入兩組已知的數值，再經過高中數學教過的計算可以得到**轉移矩陣**:![](image/CodeCogsEqn10.gif)。

從![](image/CodeCogsEqn11.gif)開始計算的話，就會變成
![](image/CodeCogsEqn12.gif)
，其中指數n就是這次快速冪的主角，透過快速冪將指數計算的時間複雜度降為![](image/CodeCogsEqn3.gif)而提升費氏數列的計算速度。
