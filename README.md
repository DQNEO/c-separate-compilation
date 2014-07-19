# c-separate-compilation

C言語の分割コンパイルのチュートリアル

## includeの役割
まず分割コンパイルの前に、includeの役割を知ろう。

### 00 - return 数字 するだけのプログラム
ディレクトリ`00`の`main.c`を実行すると、ステータスコード120が得られます。

```shell
$ cd 00
$ gcc main.c && ./a.out ; echo $?
```

ここまでは何の変哲もないC言語のプログラムです。

### 01 - include 命令のはたらきを確認しよう

次に、ディレクトリ`01`の`main.c`の中身を見てから、実行してみてください。
`00`のときと同じ結果になるはずです。


```shell
$ cd 01
$ gcc main.c && ./a.out ; echo $?
```

includeがファイルを単純に挿入しているだけであることがわかりましたね。
下記のようにすれば、プリプロセスの結果を見ることができます。

```shell
$ gcc -E main.c
```

どうですか？
プリプロセッサがinclude命令をファイルの中身に置き換えた結果を見ることができましたね。

## 分割コンパイル
### 10 - helloするだけのプログラム
ディレクトリ`10`の`main.c`を実行すると、"hello"と表示されます。

```shell
$ cd 10
$ gcc main.c && ./a.out
```

何の変哲もないC言語のプログラムです。

### 11 - *.cファイルを分割してみる

先ほどのmain.cから、hello関数を別ファイルに分離してみましょう。

そしてgccでコンパイルしてみます。
```shell
$ cd 11
$ gcc -Wall main.c hello.c
main.c: In function ‘main’:
main.c:3: 警告: implicit declaration of function ‘hello’
$ ./a.out
```
警告は出ますが、コンパイルは成功してa.outが出力されます。

(なお、`#include　<stdio.h>`をhello.cに書いてるのは、printfがhello.cにあるからです。)

### 12 - `implicit declaration of function`を解決する

警告が出た原因は、main.cの中でhello()のプロトタイプ宣言を見つけられなかったからです。
なので、main.cの中に単純にhello()のプロトタイプ宣言を書けば警告は消えます。

```shell
$ cd 12
$ gcc -Wall main.c hello.c
$ ./a.out
```

### 13 - もっと多数の.cファイルがあるケースを考えてみる

多数の.cファイルが、ユーティリティ関数p()を呼び出しているケースを考えてみましょう。
さっきと同じやり方で警告を回避しようとすると、それぞれの.cファイルでプロトタイプ宣言をいちいち記述しないといけません。

```shell
$ gcc -Wall main.c morning.c night.c evening.c util.c && ./a.out
good morning
good evening
good night
```
しかしこの方法には問題があります。
* pの引数や戻り値の型が変わった場合に、それぞれの.cファイルについて同じ修正を適用する必要がある。
* ユーティリティ関数が増えた場合に、コピペすべきプロトタイプの数が大量になる

つまりはコードが重複しているということです。
